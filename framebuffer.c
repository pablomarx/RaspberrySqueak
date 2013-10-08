#include "framebuffer.h"
#include "barrier.h"
#include "mailbox.h"
#include "memutils.h"
#include "strings.h"
#include "printf.h"

/* Framebuffer initialisation failure codes
 * If the FB can't be initialised, one of the following numbers will be
 * flashed on the OK LED
 */

/* Mailbox call to get screen resolution failed */
#define FBFAIL_GET_RESOLUTION		1
/* Mailbox call returned bad resolution */
#define FBFAIL_GOT_INVALID_RESOLUTION	2
/* Mailbox call to setup FB failed */
#define FBFAIL_SETUP_FRAMEBUFFER	3
/* Setup call FB returned an invalid list of response tags */
#define FBFAIL_INVALID_TAGS		4
/* Setup FB call returned an invalid response for the framebuffer tag */
#define FBFAIL_INVALID_TAG_RESPONSE	5
/* Setup FB call returned an invalid address/size */
#define FBFAIL_INVALID_TAG_DATA		6
/* Read FB pitch call returned an invalid response */
#define FBFAIL_INVALID_PITCH_RESPONSE	7
/* Read FB pitch call returned an invalid pitch value */
#define FBFAIL_INVALID_PITCH_DATA	8

/* Character cells are 6x10 */
#define CHARSIZE_X	6
#define CHARSIZE_Y	10

/* Screen parameters set in fb_init() */
unsigned int screenbase, screensize, screendepth;
unsigned int fb_x, fb_y, pitch;
/* Max x/y character cell */
unsigned int max_x, max_y;

extern void memset(void *a1, int c, unsigned int n);

/* Framebuffer initialisation failed. Can't display an error, so flashing
 * the OK LED will have to do
 */
static void fb_fail(unsigned int num)
{
}

void fb_init(int depth)
{
	unsigned int var;
	unsigned int count;
	volatile unsigned int *mailbuffer = (unsigned int *)memalign(16, 32);

	/* Get the display size */
	mailbuffer[0] = 8 * 4;		// Total size
	mailbuffer[1] = 0;		// Request
	mailbuffer[2] = BCM2835_MBOX_TAG_GET_PHYSICAL_W_H;	// Display size
	mailbuffer[3] = 8;		// Buffer size
	mailbuffer[4] = 0;		// Request size
	mailbuffer[5] = 0;		// Space for horizontal resolution
	mailbuffer[6] = 0;		// Space for vertical resolution
	mailbuffer[7] = 0;		// End tag

	writemailbox(BCM2835_MBOX_CHANNEL_PROPERTY, (unsigned int)mailbuffer);

	var = readmailbox(BCM2835_MBOX_CHANNEL_PROPERTY);

	/* Valid response in data structure */
	if(mailbuffer[1] != BCM2835_MBOX_RESP_CODE_SUCCESS)
		fb_fail(FBFAIL_GET_RESOLUTION);	

	fb_x = mailbuffer[5];
	fb_y = mailbuffer[6];

	if(fb_x==0 || fb_y==0)
		fb_fail(FBFAIL_GOT_INVALID_RESOLUTION);


	/* Set up screen */

	unsigned int c = 1;
	mailbuffer[c++] = 0;		// Request

	mailbuffer[c++] = BCM2835_MBOX_TAG_SET_PHYSICAL_W_H;	// Tag id (set physical size)
	mailbuffer[c++] = 8;		// Value buffer size (bytes)
	mailbuffer[c++] = 8;		// Req. + value length (bytes)
	mailbuffer[c++] = fb_x;		// Horizontal resolution
	mailbuffer[c++] = fb_y;		// Vertical resolution

	mailbuffer[c++] = BCM2835_MBOX_TAG_SET_VIRTUAL_W_H;	// Tag id (set virtual size)
	mailbuffer[c++] = 8;		// Value buffer size (bytes)
	mailbuffer[c++] = 8;		// Req. + value length (bytes)
	mailbuffer[c++] = fb_x;		// Horizontal resolution
	mailbuffer[c++] = fb_y;		// Vertical resolution

	mailbuffer[c++] = BCM2835_MBOX_TAG_SET_DEPTH;	// Tag id (set depth)
	mailbuffer[c++] = 4;		// Value buffer size (bytes)
	mailbuffer[c++] = 4;		// Req. + value length (bytes)
	mailbuffer[c++] = depth;	// X bpp

	mailbuffer[c++] = BCM2835_MBOX_TAG_ALLOCATE_BUFFER;	// Tag id (allocate framebuffer)
	mailbuffer[c++] = 8;		// Value buffer size (bytes)
	mailbuffer[c++] = 4;		// Req. + value length (bytes)
	mailbuffer[c++] = 16;		// Alignment = 16
	mailbuffer[c++] = 0;		// Space for response

	mailbuffer[c++] = 0;		// Terminating tag

	mailbuffer[0] = c*4;		// Buffer size

	writemailbox(BCM2835_MBOX_CHANNEL_PROPERTY, (unsigned int)mailbuffer);

	var = readmailbox(BCM2835_MBOX_CHANNEL_PROPERTY);

	/* Valid response in data structure */
	if(mailbuffer[1] != BCM2835_MBOX_RESP_CODE_SUCCESS)
		fb_fail(FBFAIL_SETUP_FRAMEBUFFER);	

	count=2;	/* First tag */
	while((var = mailbuffer[count]))
	{
		if(var == BCM2835_MBOX_TAG_ALLOCATE_BUFFER)
			break;

		/* Skip to next tag
		 * Advance count by 1 (tag) + 2 (buffer size/value size)
		 *                          + specified buffer size
		*/
		count += 3+(mailbuffer[count+1]>>2);

		if(count>c)
			fb_fail(FBFAIL_INVALID_TAGS);
	}

	/* 8 bytes, plus MSB set to indicate a response */
	if(mailbuffer[count+2] != 0x80000008)
		fb_fail(FBFAIL_INVALID_TAG_RESPONSE);

	/* Framebuffer address/size in response */
	screenbase = mailbuffer[count+3];
	screensize = mailbuffer[count+4];

	if(screenbase == 0 || screensize == 0)
		fb_fail(FBFAIL_INVALID_TAG_DATA);

	/* Get the framebuffer pitch (bytes per line) */
	mailbuffer[0] = 7 * 4;		// Total size
	mailbuffer[1] = 0;		// Request
	mailbuffer[2] = BCM2835_MBOX_TAG_GET_PITCH;	// Display size
	mailbuffer[3] = 4;		// Buffer size
	mailbuffer[4] = 0;		// Request size
	mailbuffer[5] = 0;		// Space for pitch
	mailbuffer[6] = 0;		// End tag

	writemailbox(BCM2835_MBOX_CHANNEL_PROPERTY, (unsigned int)mailbuffer);

	var = readmailbox(BCM2835_MBOX_CHANNEL_PROPERTY);

	/* 4 bytes, plus MSB set to indicate a response */
	if(mailbuffer[4] != 0x80000004)
		fb_fail(FBFAIL_INVALID_PITCH_RESPONSE);

	pitch = mailbuffer[5];
	if(pitch == 0)
		fb_fail(FBFAIL_INVALID_PITCH_DATA);

	/* Need to set up max_x/max_y before using console_write */
	max_x = fb_x / CHARSIZE_X;
	max_y = fb_y / CHARSIZE_Y;

	printf("Framebuffer initialised. Address = 0x%08x", screenbase);
	printf(", size = 0x%04x", screensize);
	printf(", resolution = %u x %u", fb_x, fb_y);
	printf("\n");
}

