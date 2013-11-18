#include "atags.h"
#include "printf.h"

static void print_atag_core(struct atag_core *data)
{
	if(data->header.size == 5)
	{
		printf("  Flags: 0x%04x", data->flags);
		printf(", pagesize: 0x%04x", data->pagesize);
		printf(", root device: 0x%04x", data->rootdevice);
		printf("\n");
	}
	else
		printf("  No additional data\n");
}

static void print_atag_mem(struct atag_mem *data)
{
	printf("  Address: 0x%04x", data->address);
	printf(" - 0x%04x", data->address+data->size-1);
	printf(" (%u bytes)\n", data->size);
}

static void print_atag_ramdisk(struct atag_ramdisk *data)
{
	printf("  Flags: 0x%04x", data->flags);
	printf(", size: 0x%04x", data->size);
	printf(", start block: 0x%04x", data->start);
	printf("\n");
}

static void print_atag_initrd2(struct atag_initrd2 *data)
{
	printf("  Address: 0x%04x", data->address);
	printf(" - 0x%04x", data->address+data->size-1);
	printf(" (%u bytes)\n", data->size);
}

static void print_atag_serial(struct atag_serial *data)
{
	printf("  Serial number: 0x%04x%04x", data->high, data->low);
	printf("\n");
}

static void print_atag_revision(struct atag_revision *data)
{
	printf("  Board revision: %u\n", data->revision);
}

static void print_atag_videolfb(struct atag_videolfb *data)
{
	printf("  Size: %u x %u", data->width, data->height);
	printf(", depth: %u ", data->depth);
	printf("bpp, linelength: %u ", data->linelength);

	printf("\n  Address: 0x%04x", data->address);
	printf(" - 0x%04x", data->address+data->size-1);
	printf(" (%i bytes)\n", data->size);

	printf("  Pos/size: R %u / %u", data->redpos, data->redsize);
	printf(", G %u / %u", data->greenpos, data->greensize);
	printf(", B %u / %u", data->bluepos, data->bluesize);
	printf(", reserved %u / %u", data->reservedpos, data->reservedsize);
	printf("\n");
}

static void print_atag_cmdline(struct atag_cmdline *data)
{
	printf("  \"");
	printf(&data->commandline);
	printf("\"\n");
}

void print_atags(unsigned int address)
{
	struct atag_header *atags = (struct atag_header *)address;
	unsigned int tag;

	printf("Reading ATAGs\n\n");

	do
	{
		tag = atags->tag;
		printf("ATAG at address 0x%04x", (unsigned int) atags);
		printf(" is 0x%04x", tag);

		switch(tag)
		{
			case 0:
				printf(" (ATAG_NONE)\n\n");
				break;
			case ATAG_CORE:
				printf(" (ATAG_CORE)\n");
				print_atag_core((struct atag_core *)atags);
				break;
			case ATAG_MEM:
				printf(" (ATAG_MEM)\n");
				print_atag_mem((struct atag_mem *)atags);
				break;
			case ATAG_VIDEOTEXT:
				printf(" (ATAG_VIDEOTEXT)\n");
				break;
			case ATAG_RAMDISK:
				printf(" (ATAG_RAMDISK)\n");
				print_atag_ramdisk((struct atag_ramdisk *)atags);
				break;
			case ATAG_INITRD2:
				printf(" (ATAG_INITRD2)\n");
				print_atag_initrd2((struct atag_initrd2 *)atags);
				break;
			case ATAG_SERIAL:
				printf(" (ATAG_SERIAL)\n");
				print_atag_serial((struct atag_serial *)atags);
				break;
			case ATAG_REVISION:
				printf(" (ATAG_REVISION)\n");
				print_atag_revision((struct atag_revision *)atags);
				break;
			case ATAG_VIDEOLFB:
				printf(" (ATAG_VIDEOLFB)\n");
				print_atag_videolfb((struct atag_videolfb *)atags);
				break;
			case ATAG_CMDLINE:
				printf(" (ATAG_CMDLINE)\n");
				print_atag_cmdline((struct atag_cmdline *)atags);
				break;
			default:
				printf(" (UNKNOWN)\n");
				return;
		}

		atags = (struct atag_header *)((unsigned int)atags + (atags->size * 4));
	} while(tag);
}

struct atag_header *readAtagWithTag(unsigned int address, int tag) {
	struct atag_header *atags = (struct atag_header *)address;
	unsigned int currentTag;

	do
	{
		currentTag = atags->tag;
		if (currentTag == tag) {
			return atags;
		}
		atags = (struct atag_header *)((unsigned int)atags + (atags->size * 4));
	} while(currentTag);
	return 0;
}
