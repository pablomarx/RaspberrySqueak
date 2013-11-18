#include "sq.h"
#include "atags.h"
#include "barrier.h"
#include "framebuffer.h"
#include "mailbox.h"
#include "printf.h"
#include "uart.h"
#include "types.h"
#include "usbd.h"
#include "keyboard.h"
#include "mouse.h"
#include "memutils.h"
#include "timer.h"
#include "interrupts.h"
#include "mmu.h"

extern void *end;

extern void arch_enable_cache(uint flags);
extern void arch_disable_cache(uint flags);


int ioExit(void) {
	printf("ioExit()\n");
	printf("ioMSecs()=%i\n", ioMSecs());
	while(1) __asm__("nop");
}

/*** System Attributes ***/
extern char vmPath[];
extern char shortImageName[];

char * GetAttributeString(int id) {
	/* This is a hook for getting various status strings back from
	   the OS. In particular, it allows Squeak to be passed arguments
	   such as the name of a file to be processed. Command line options
	   are reported this way as well, on platforms that support them.
	*/

	// id #0 should return the full name of VM; for now it just returns its path
	if (id == 0) return vmPath;
	// id #1 should return imageName, but returns empty string in this release to
	// ease the transition (1.3x images otherwise try to read image as a document)
	if (id == 1) return "";  /* will be imageName */
	if (id == 2) return "";

	if (id == 1001) return "SqueakNOS";
	if (id == 1002) return "v1";
	if (id == 1003) return "ARM (Raspberry Pi)";

	/* attribute undefined by this platform */
	success(false);
	return "";
}

int attributeSize(int id) {
	return strlen(GetAttributeString(id));
}

int getAttributeIntoLength(int id, int byteArrayIndex, int length) {
	char *srcPtr, *dstPtr, *end;
	int charsToMove;

	srcPtr = GetAttributeString(id);
	charsToMove = strlen(srcPtr);
	if (charsToMove > length) {
		charsToMove = length;
	}

	dstPtr = (char *) byteArrayIndex;
	end = srcPtr + charsToMove;
	while (srcPtr < end) {
		*dstPtr++ = *srcPtr++;
	}
	return charsToMove;
}

int ioBeep(void) {
	printf("%s\n", __PRETTY_FUNCTION__);
	return true;
}

/*** Main ***/

void *sqAllocateMemory(int minHeapSize, int desiredHeapSize) {
	printf("sqAllocateMemory(%i, %i)\n", minHeapSize, desiredHeapSize); 
	return malloc(desiredHeapSize);
}

void cpu_init(void) {
	int alignedEnd = (unsigned int)&end;
	alignedEnd+=15;
	alignedEnd&=~15;
	
	volatile unsigned int *ptr = (unsigned int *)alignedEnd;
	memset(ptr, '\0', 13);
	
	unsigned int var;

	ptr[0] = 13 * 4;	// Total size
	ptr[1] = 0;		// Request

	ptr[2] = BCM2835_MBOX_TAG_GET_CLOCK_RATE;
	ptr[3] = 8;				// Buffer size
	ptr[4] = 4;				// Request size
	ptr[5] = BCM2835_MBOX_CLOCK_ID_ARM;
	ptr[6] = 0;

	writemailbox(BCM2835_MBOX_CHANNEL_PROPERTY, (unsigned int)ptr);

	var = readmailbox(BCM2835_MBOX_CHANNEL_PROPERTY);
	printf("CPU Frequency: %i MHz\n", ptr[6] / 1000 / 1000);
}

void dram_init(void) {
	int alignedEnd = (unsigned int)&end;
	alignedEnd+=15;
	alignedEnd&=~15;
	
	volatile unsigned int *ptr = (unsigned int *)alignedEnd;
	unsigned int var;

	ptr[0] = 13 * 4;	// Total size
	ptr[1] = 0;		// Request

	ptr[2] = BCM2835_MBOX_TAG_GET_ARM_MEMORY;	// ARM memory
	ptr[3] = 8;		// Buffer size
	ptr[4] = 0;		// Request size
	ptr[5] = 0;
	ptr[6] = 0;

	ptr[7] = BCM2835_MBOX_TAG_GET_GPU_MEMORY;	// VideoCore memory
	ptr[8] = 8;		// Buffer size
	ptr[9] = 0;		// Request size
	ptr[10] = 0;
	ptr[11] = 0;

	ptr[12] = 0;

	writemailbox(BCM2835_MBOX_CHANNEL_PROPERTY, (unsigned int)ptr);

	var = readmailbox(BCM2835_MBOX_CHANNEL_PROPERTY);

	printf("System memory: %i MB\n", ptr[6] / 1024 / 1024);
	printf("Video memory : %i MB\n", ptr[11] / 1024 / 1024);

	malloc_base = (unsigned int)ptr;
	malloc_size = ptr[6] - malloc_base;
}

void main(unsigned int r0, unsigned int machtype, unsigned int atagsaddr)
{
	uart_init();
	printf("Welcome to Raspberry Squeak!\n");
	printf("end=0x%08x\n", &end);

	cpu_init();
	dram_init();
	fb_init(ScreenDepth);

	mmu_init();

	arch_enable_cache(1/*ICACHE*/ | 2 /*DCACHE*/);

	interrupts_init();
	timer_init();

	unsigned int orig_malloc_base = malloc_base;
	unsigned int orig_malloc_size = malloc_size;

	malloc_base = (malloc_size - malloc_base) - (1024 * 1024);
	int usb_region = (malloc_base/1024/1024) * (1024 * 1024);
	arm_mmu_map_section(usb_region, usb_region, MMU_FLAG_READWRITE | MMU_FLAG_BUFFERED);

	UsbInitialise();
	UsbCheckForChange();
	
	malloc_base = orig_malloc_base;
	malloc_size = orig_malloc_size - (1024 * 1024);
	
	/* check the interpreter's size assumptions for basic data types */
	if (sizeof(int) != 4) {
		error("This C compiler's integers are not 32 bits.");
	}
	if (sizeof(double) != 8) {
		error("This C compiler's floats are not 64 bits.");
	}
	if (sizeof(time_t) != 4) {
		error("This C compiler's time_t's are not 32 bits.");
	}

	struct atag_initrd2 *ramdisk = (struct atag_initrd2 *)readAtagWithTag(atagsaddr, ATAG_INITRD2);
	if (ramdisk == NULL) {
		error("Couldn't read ATAG_INITRD2.");
	}
	
	sqImageFile file = malloc(sizeof(rpiImageFile));
	file->base = (unsigned char *)ramdisk->address;
	file->length = ramdisk->size;
	file->current = file->base;

	imageName[0] = shortImageName[0] = vmPath[0] = 0;
	strcpy(imageName, "squeak.image");
	strcpy(shortImageName, "squeak.image");

	int availableMemory = malloc_size;
	int reservedMemory = 5 * 1024 * 1024;

	printf("About to invoke readImageFromFileHeapSize(%u)\n", availableMemory - reservedMemory);
	readImageFromFileHeapSize(file, availableMemory - reservedMemory);
	free(file);

	/* run Squeak */
	printf("About to invoke interpret()\n");
	interpret();
}
