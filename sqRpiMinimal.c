#include "sq.h"
#include "atags.h"
#include "barrier.h"
#include "framebuffer.h"
#include "mailbox.h"
//#include "strings.h"
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

/*** Variables -- image and path names ***/
#define IMAGE_NAME_SIZE 300
char imageName[IMAGE_NAME_SIZE + 1];  /* full path to image */

#define SHORTIMAGE_NAME_SIZE 100
char shortImageName[SHORTIMAGE_NAME_SIZE + 1];  /* just the image file name */

#define VMPATH_SIZE 300
char vmPath[VMPATH_SIZE + 1];  /* full path to interpreter's directory */


/*** VM Home Directory Path ***/

int vmPathSize(void) {
	return strlen(vmPath);
}

int vmPathGetLength(int sqVMPathIndex, int length) {
	char *stVMPath = (char *) sqVMPathIndex;
	int count, i;

	count = strlen(vmPath);
	count = (length < count) ? length : count;

	/* copy the file name into the Squeak string */
	for (i = 0; i < count; i++) {
		stVMPath[i] = vmPath[i];
	}
	return count;
}

int ioExit(void) {
	printf("ioExit()\n");
	printf("ioMSecs()=%i\n", ioMSecs());
	while(1) __asm__("nop");
}

int ioFormPrint(int bitsAddr, int width, int height, int depth, double hScale, double vScale, int landscapeFlag) {
	/* experimental: print a form with the given bitmap, width, height, and depth at
	   the given horizontal and vertical scales in the given orientation */

		printf("%s\n", __PRETTY_FUNCTION__);
	success(false);  
}

#define BCM2835_TIMER_PHYSADDR	0x20003000

// Number of milliseconds
int ioMSecs(void) {
#if 1
	return current_time();
#else
	volatile uint64_t* timeStamp = (uint64_t*)(BCM2835_TIMER_PHYSADDR + 4);
	uint64_t microseconds = *timeStamp;
	return ((uint32_t)microseconds) / 1000;
#endif
}

int ioLowResMSecs(void)
{
  /* already have millisecond resolution */
  return ioMSecs();
}

int ioMicroMSecs(void)
{
  /* already have millisecond resolution */
  return ioMSecs();
}

int ioRelinquishProcessorForMicroseconds(int microSeconds) {
	/* This operation is platform dependent. On the Mac, it simply calls
	 * HandleEvents(), which gives other applications a chance to run.
	 */
	return microSeconds;
}

int ioScreenSize(void) {
	return (fb_x << 16) | (fb_y & 0xFFFF);  /* w is high 16 bits; h is low 16 bits */
}

int ioSeconds(void) {
	return ioMSecs() / 1000;
}

/*** Image File Naming ***/

int imageNameSize(void) {
	return strlen(imageName);
}

int imageNameGetLength(int sqImageNameIndex, int length) {
	char *sqImageName = (char *) sqImageNameIndex;
	int count, i;

	count = strlen(imageName);
	count = (length < count) ? length : count;

	/* copy the file name into the Squeak string */
	for (i = 0; i < count; i++) {
		sqImageName[i] = imageName[i];
	}
	return count;
}

int imageNamePutLength(int sqImageNameIndex, int length) {
	char *sqImageName = (char *) sqImageNameIndex;
	int count, i, ch, j;
	int lastColonIndex = -1;

	count = (IMAGE_NAME_SIZE < length) ? IMAGE_NAME_SIZE : length;

	/* copy the file name into a null-terminated C string */
	for (i = 0; i < count; i++) {
		ch = imageName[i] = sqImageName[i];
		if (ch == ':') {
			lastColonIndex = i;
		}
	}
	imageName[count] = 0;

	/* copy short image name into a null-terminated C string */
	for (i = lastColonIndex + 1, j = 0; i < count; i++, j++) {
		shortImageName[j] = imageName[i];
	}
	shortImageName[j] = 0;

	return count;
}

/*** Directory ***/

int dir_Delimitor(void) {
	return '/';
}

/*** System Attributes ***/

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

/*** Image File Operations ***/

void sqImageFileClose(sqImageFile f) {
	printf("%s\n", __PRETTY_FUNCTION__);
	f->current = f->base;
}

sqImageFile sqImageFileOpen(char *fileName, char *mode) {
	printf("%s %s %s\n", __PRETTY_FUNCTION__, fileName, mode);
	sqImageFile file = (sqImageFile)malloc(sizeof(sqImageFile));
	return file;
}

int sqImageFilePosition(sqImageFile f) {
	printf("%s\n", __PRETTY_FUNCTION__);
	return f->current - f->base;
}

int sqImageFileRead(void *ptr, int elementSize, int count, sqImageFile f) {
	//printf("%s ptr=0x%08x, elementSize=%i, count=%i\n", __PRETTY_FUNCTION__, ptr, elementSize, count);
	//printf("  1. file->base=0x%08x, file->length=%i, file->current=0x%08x\n", f->base, f->length, f->current);
	memcpy(ptr, f->current, count * elementSize);
	f->current += count * elementSize;
	//printf("  2. file->base=0x%08x, file->length=%i, file->current=0x%08x\n", f->base, f->length, f->current);
	return count;
}

void sqImageFileSeek(sqImageFile f, int pos) {
	//printf("%s pos=%i\n", __PRETTY_FUNCTION__, pos);
	//printf("  1. file->base=0x%08x, file->length=%i, file->current=0x%08x\n", f->base, f->length, f->current);
	f->current = f->base + pos;
	//printf("  2. file->base=0x%08x, file->length=%i, file->current=0x%08x\n", f->base, f->length, f->current);
}

int sqImageFileWrite(void *ptr, int elementSize, int count, sqImageFile f) {
	//printf("%s elementSize=%i, count=%i\n", __PRETTY_FUNCTION__, elementSize, count);
	return 0;
}


#define ScreenDepth       32
#define BytesPerComponent (ScreenDepth / 8)

/*** Display stubs ***/
unsigned char underCursorData[16 * 16 * BytesPerComponent];
int lastCursorX, lastCursorY;

struct SqCursor  {
	unsigned char size, depth, y, x;
	unsigned short data[16], mask[16];
};

struct SqCursor SqueakCursor;

void hideCursor(void) {
	int bytesPerComponent = BytesPerComponent; //depth/8;
	int bytesPerRow = bytesPerComponent * fb_x;
	int rowLength = SqueakCursor.size * bytesPerComponent;

	for (int y=0; y<SqueakCursor.size; y++) {
		int row = (lastCursorY + y) * bytesPerRow;
		int col = lastCursorX * bytesPerComponent;
		unsigned char *oldScreen = &underCursorData[y * rowLength];
		memcpy((unsigned char *)screenbase + row + col, oldScreen, rowLength);
	}
}

void showCursor(void) {
	int bytesPerComponent = BytesPerComponent; //depth/8;
	int bytesPerRow = bytesPerComponent * fb_x;
	int rowLength = SqueakCursor.size * bytesPerComponent;
	
	for (int y=0; y<SqueakCursor.size; y++) {
		int row = (lastCursorY + y) * bytesPerRow;
		int col = lastCursorX * bytesPerComponent;

		unsigned char *rowData = (unsigned char *)screenbase + row + col;
		unsigned char *oldScreen = &underCursorData[y * rowLength];
		memcpy(oldScreen, rowData, rowLength);
		for (int x=SqueakCursor.size; x>0; x--) {
			int cursor = SqueakCursor.data[y] & 1<<x;
			if (cursor) {
				if (bytesPerComponent > 3) {
					*rowData++ = 0xff;
				}
				if (bytesPerComponent > 2) {
					*rowData++ = 0x00;
				}
				*rowData++ = 0x00;
				*rowData++ = 0x00;
			}
			else {
				rowData+=bytesPerComponent;
			}
		}
	}
}

void moveCursor(int x, int y) {
	if (x == lastCursorX && y == lastCursorY) {
		return;
	}
	hideCursor();
	lastCursorX = x;
	lastCursorY = y;
	showCursor();
}

int ioMousePoint(void) {
	int mouseCount = MouseCount();
	if (mouseCount > 0) {
		uint32_t mouse = MouseGetAddress(0);
		int point = MouseGetPosition(mouse);
		moveCursor((point >> 16) & 0xffff, point & 0xffff);
		return point;
	}
	int x=0, y=0;
	return (x << 16) | (y & 0xFFFF);  /* x is high 16 bits; y is low 16 bits */
}

int ioGetButtonState(void) {
	int result = 0;
	int mouseCount = MouseCount();
	if (mouseCount > 0) {
		uint32_t mouse = MouseGetAddress(0);
		int buttonState = MouseGetButtons(mouse);

		if (buttonState & 0x01) {
			result |= 1 << 2;
		}
		if (buttonState & 0x02) {
			result |= 1 << 0;
		}
		if (buttonState & 0x04) {
			result |= 1 << 1;
		}
	}

	return result;
}

/*** Variables -- Event Recording ***/
#define KEYBUF_SIZE 64
int keyBuf[KEYBUF_SIZE];        /* circular buffer */
int keyBufGet = 0;                      /* index of next item of keyBuf to read */
int keyBufPut = 0;                      /* index of next item of keyBuf to write */
int keyBufOverflows = 0;        /* number of characters dropped */

/*** Variables -- Imported from Virtual Machine ***/
extern int interruptCheckCounter;
extern int interruptKeycode;
extern int interruptPending;  /* set to true by RecordKeystroke if interrupt key is pressed */

void RecordKeystroke(unsigned char key, struct KeyboardModifiers modifiers) {
	int keystate;

	/* keystate: low byte is the ascii character; next 4 bits are modifier bits */ 
	int keyModifier = 0;
	if (modifiers.LeftControl || modifiers.RightControl) {
		keyModifier = 1 << 9;
	}
	if (modifiers.LeftShift || modifiers.RightShift) {
		keyModifier = 1 << 8;
	}
	if (modifiers.LeftAlt || modifiers.RightAlt) {
		keyModifier = 1 << 10;
	}
	if (modifiers.LeftGui || modifiers.RightGui) {
		keyModifier = 1 << 11;
	}
	keystate = (keyModifier) | (key & 0xff);

	if (keystate == interruptKeycode) {
	/* Note: interrupt key is "meta"; it not reported as a keystroke */
		interruptPending = true; 
		interruptCheckCounter = 0;
	} else {
		keyBuf[keyBufPut] = keystate;
		keyBufPut = (keyBufPut + 1) % KEYBUF_SIZE;
		if (keyBufGet == keyBufPut) {
		     /* buffer overflow; drop the last character */
		     keyBufGet = (keyBufGet + 1) % KEYBUF_SIZE;
		     keyBufOverflows++;
		}       
	}       
}

int ioGetKeystrokeAndAdvance(bool advance) {
	/* return the next keystroke from the buffer or -1 if the buffer is empty */
	int keystate;

//	ioProcessEvents();  /* process all pending events */
	if (keyBufGet == keyBufPut) {
		return -1;  /* keystroke buffer is empty */
	} else {
		keystate = keyBuf[keyBufGet];
		if (advance == true) {
			keyBufGet = (keyBufGet + 1) % KEYBUF_SIZE;
		}
		/* set modifer bits in buttonState to reflect the last keystroke fetched */
		//                buttonState = ((keystate >> 5) & 0xF8) | (buttonState & 0x7); 
	}       
	return keystate;
}

int ioGetKeystroke(void) {
	return ioGetKeystrokeAndAdvance(true);
}

int ioPeekKeystroke(void) {
	return ioGetKeystrokeAndAdvance(false);
}

int ioSetCursor(int cursorBitsIndex, int offsetX, int offsetY) {
	return ioSetCursorWithMask(cursorBitsIndex, 0, offsetX, offsetY);	
}

int ioSetCursorWithMask(int cursorBitsIndex, int cursorMaskIndex, int offsetX, int offsetY) 
{
	//printf("%s cursorBitsIndex=%i, cursorMaskIndex=%i, offsetX=%i, offsetY=%i\n", __PRETTY_FUNCTION__, cursorBitsIndex, cursorMaskIndex, offsetX, offsetY);

	hideCursor();

	/* Set the 16x16 cursor bitmap. If cursorMaskIndex is nil, then make the mask the same as
	   the cursor bitmap. If not, then mask and cursor bits combined determine how cursor is
	   displayed:
			mask	cursor	effect
			 0		  0		transparent (underlying pixel shows through)
			 1		  1		opaque black
			 1		  0		opaque white
			 0		  1		invert the underlying pixel
	*/
	SqueakCursor.size = 16;
	SqueakCursor.depth = 1;
	SqueakCursor.x = -offsetX;
	SqueakCursor.y = -offsetY; 
	
	for (int i = 0; i < SqueakCursor.size; i++) {
        SqueakCursor.data[i] = (checkedLongAt(cursorBitsIndex + (4 * i)) >> 16) & 0xFFFF;

		if (cursorMaskIndex == 0) {
			SqueakCursor.mask[i] = SqueakCursor.data[i];
		}
		else {
	        SqueakCursor.mask[i] = (checkedLongAt(cursorMaskIndex + (4 * i)) >> 16) & 0xFFFF;
		}
	}

	showCursor();
	return true;
}
	
int ioSetDisplayMode(int width, int height, int depth, int fullscreenFlag) {
	printf("%s width=%i, height=%i, depth=%i, fullscreenFlag=%i\n", __PRETTY_FUNCTION__, width, height, depth, fullscreenFlag);
	return 0;
}

int ioSetFullScreen(int fullScreen) {
	printf("%s fullScreen=%i\n", __PRETTY_FUNCTION__, fullScreen);
	return 0;
}

int ioHasDisplayDepth(int depth) {
	printf("%s depth=%i\n", __PRETTY_FUNCTION__, depth);
	if (depth == ScreenDepth) {
		return true;
	}
	return false;
}

int ioShowDisplay(
	int dispBitsIndex, int width, int height, int depth,
	int affectedL, int affectedR, int affectedT, int affectedB) 
{
  if(affectedR <= affectedL || affectedT >= affectedB) {
    return 1;
	}
	//printf("%s width=%i, height=%i, depth=%i, affectedL=%i, affectedR=%i, affectedT=%i, affectedB=%i\n", __PRETTY_FUNCTION__, width, height, depth, affectedL, affectedR, affectedT, affectedB);
	bool clippedCursor = false;
	if ((lastCursorX >= affectedL || lastCursorX + SqueakCursor.size >= affectedL) && (lastCursorX <= affectedR || lastCursorX + SqueakCursor.size <= affectedR) &&
		(lastCursorY >= affectedT || lastCursorY + SqueakCursor.size >= affectedT) && (lastCursorY <= affectedB || lastCursorY + SqueakCursor.size <= affectedB))
	{
		clippedCursor = true;
	}
	
	if (clippedCursor == true) {
		hideCursor();
	}
	
	int bytesPerComponent = depth/8;
	int rowLength = (affectedR - affectedL) * bytesPerComponent;

	int x,y;
	int sourceRow, sourceCol;
	int destRow, destCol;

	for (y = affectedT; y < affectedB; y++) {
		destRow = y * bytesPerComponent * fb_x;
		destCol = affectedL * bytesPerComponent;
		
		sourceRow = y * bytesPerComponent * width;
		sourceCol = affectedL * bytesPerComponent;
#if 1
		if (bytesPerComponent == 4) {
			uint32_t *toData = (uint32_t*)(screenbase + destRow + destCol);
			uint32_t *fromData = (uint32_t *)(dispBitsIndex + sourceRow + sourceCol);
			for (x = affectedL; x<affectedR; x++) {
				*toData = 
					0xff << 24 |  // alpha
					(((*fromData      ) & 0xff) << 16) |  // blue
					(((*fromData >>  8) & 0xff) <<  8) |  // green
					(((*fromData >> 16) & 0xff)      ) ;  // red
				toData++,fromData++;
			}
		}
		else if (bytesPerComponent == 2) {
			uint16_t *toData = (uint16_t*)(screenbase + destRow + destCol);
			uint16_t *fromData = (uint16_t *)(dispBitsIndex + sourceRow + sourceCol);

			// Use 16 bits to store each pixel:
			// the first 5 bit representing the intensity of the red channel
			// the next 6 bits representing the intensity of the green channel and
			// the final 5 bits representing the intensity of the blue channel.	
			for (x = affectedL; x<affectedR; x++) {
				*toData = 
					(((((*fromData & 0x7C00) >> 10) << 3) >> 3) << 11) |  // Red
					(((((*fromData & 0x3E0)  >>  5) << 3) >> 2) <<  5) |  // Green
					(((((*fromData & 0x1F)        ) << 3) >> 3) <<  0);   // Blue

				toData++,fromData++;
			}
		}
#else
		memcpy((unsigned char *)screenbase + row + col, (unsigned char *)dispBitsIndex + row + col, rowLength);
#endif
	}
	
	if (clippedCursor == true) {
		showCursor();
	}
	dmb();
	//printf(" => OK!\n");
	success(true);
}
	

//int lastBlinkTime;

int ioProcessEvents(void) {
	//printf("%s\n", __PRETTY_FUNCTION__);
	int keyboardCount = KeyboardCount();
	int mouseCount = MouseCount();
	if (keyboardCount == 0 || mouseCount == 0) {
		UsbCheckForChange();
		keyboardCount = KeyboardCount();
		mouseCount = MouseCount();
	}
	
	for (int kbdIndex=0; kbdIndex<keyboardCount; kbdIndex++) {
		uint32_t keyboard = KeyboardGetAddress(kbdIndex);
/*
		if (ioMSecs() - lastBlinkTime > 1000) {
			struct KeyboardLeds leds = KeyboardGetLeds(keyboard);
			leds.CapsLock = !leds.CapsLock;
			leds.ScrollLock = !leds.ScrollLock;
			leds.NumberLock = !leds.NumberLock;
			KeyboardSetLeds(keyboard, leds);
			lastBlinkTime = ioMSecs();
		}
*/		
		int result = KeyboardPoll(keyboard);
		if (result != OK) {
			continue;
		}

		int keysDown = KeyboardGetKeyDownCount(keyboard);
		if (keysDown == 0) {
			continue;
		}

		struct KeyboardModifiers modifiers = KeyboardGetModifiers(keyboard);
		for (int i=0; i<keysDown; i++) {
			int keyCode = KeyboardGetKeyDown(keyboard, i);
			RecordKeystroke((modifiers.LeftShift || modifiers.RightShift ? KeysShift[keyCode] : KeysNormal[keyCode]), modifiers);
		}
	}

	for (int mouseIndex=0; mouseIndex<mouseCount; mouseIndex++) {
		uint32_t mouse = MouseGetAddress(mouseIndex);
		MousePoll(mouse);
		//int position = MouseGetPosition(mouse);
		//printf("mouse: x=%i, y=%i\n", ((position>>16)&0xffff), (position&0xffff));
	}

	watchdog_reset();
	
	return true;
}

int ioBeep(void) {
	printf("%s\n", __PRETTY_FUNCTION__);
	return true;
}

int ioForceDisplayUpdate(void) {
	//printf("%s\n", __PRETTY_FUNCTION__);
	return true;
}


/*** Main ***/

void *      sqAllocateMemory(int minHeapSize, int desiredHeapSize) {
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
