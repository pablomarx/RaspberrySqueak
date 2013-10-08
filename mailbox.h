
#ifndef MAILBOX_H
#define MAILBOX_H

#define BCM2835_MBOX_CHANNEL_POWER    0 /* for use by the power management interface */
#define BCM2835_MBOX_CHANNEL_FB       1 /* for use by the frame buffer */
#define BCM2835_MBOX_CHANNEL_VCHIQ    3 /* for use by the VCHIQ interface */
#define BCM2835_MBOX_CHANNEL_PROPERTY 8 /* for use by the property channel */
#define BCM2835_MBOX_CHANNEL_COUNT    9

#define BCM2835_MBOX_STATUS_RD_EMPTY	0x40000000
#define BCM2835_MBOX_STATUS_WR_FULL	0x80000000

#define BCM2835_MBOX_RESP_CODE_SUCCESS	0x80000000

#define BCM2835_MBOX_TAG_GET_ARM_MEMORY		0x00010005
#define BCM2835_MBOX_TAG_GET_GPU_MEMORY		0x00010006

#define BCM2835_MBOX_TAG_GET_CLOCK_RATE        0x00030002

#define BCM2835_MBOX_TAG_ALLOCATE_BUFFER	0x00040001
#define BCM2835_MBOX_TAG_GET_PHYSICAL_W_H	0x00040003
#define BCM2835_MBOX_TAG_GET_PITCH		0x00040008

#define BCM2835_MBOX_TAG_SET_PHYSICAL_W_H	0x00048003
#define BCM2835_MBOX_TAG_SET_VIRTUAL_W_H	0x00048004
#define BCM2835_MBOX_TAG_SET_DEPTH		0x00048005

#define BCM2835_MBOX_CLOCK_ID_ARM      3
#define BCM2835_MBOX_CLOCK_ID_CORE     4

#if 0
/* Mailbox property tags */
enum {
	VCMSG_PROPERTY_END               = 0x00000000,
	VCMSG_GET_FIRMWARE_REVISION      = 0x00000001,
	VCMSG_GET_BOARD_MODEL            = 0x00010001,
	VCMSG_GET_BOARD_REVISION	 = 0x00020002,
	VCMSG_GET_BOARD_MAC_ADDRESS	 = 0x00020003,
	VCMSG_GET_BOARD_SERIAL		 = 0x00020004,
	VCMSG_GET_ARM_MEMORY		 = 0x00020005,
	VCMSG_GET_VC_MEMORY		 = 0x00020006,
	VCMSG_GET_CLOCKS		 = 0x00020007,
	VCMSG_GET_COMMAND_LINE           = 0x00050001,
	VCMSG_GET_DMA_CHANNELS           = 0x00060001,
	VCMSG_GET_POWER_STATE            = 0x00020001,
	VCMSG_GET_TIMING		 = 0x00020002,
	VCMSG_SET_POWER_STATE            = 0x00028001,
	VCMSG_GET_CLOCK_STATE            = 0x00030001,
	VCMSG_SET_CLOCK_STATE            = 0x00038001,
	VCMSG_GET_CLOCK_RATE             = 0x00030002,
	VCMSG_SET_CLOCK_RATE             = 0x00038002,
	VCMSG_GET_VOLTAGE                = 0x00030003,
	VCMSG_SET_VOLTAGE                = 0x00038003,
	VCMSG_GET_MAX_CLOCK              = 0x00030004,
	VCMSG_GET_MAX_VOLTAGE            = 0x00030005,
	VCMSG_GET_TEMPERATURE            = 0x00030006,
	VCMSG_GET_MIN_CLOCK              = 0x00030007,
	VCMSG_GET_MIN_VOLTAGE            = 0x00030008,
	VCMSG_GET_TURBO                  = 0x00030009,
	VCMSG_SET_TURBO                  = 0x00038009,
	VCMSG_SET_ALLOCATE_BUFFER        = 0x00040001,
	VCMSG_SET_RELEASE_BUFFER         = 0x00048001,
	VCMSG_SET_BLANK_SCREEN           = 0x00040002,
	VCMSG_TST_BLANK_SCREEN           = 0x00044002,
	VCMSG_GET_PHYSICAL_WIDTH_HEIGHT  = 0x00040003,
	VCMSG_TST_PHYSICAL_WIDTH_HEIGHT  = 0x00044003,
	VCMSG_SET_PHYSICAL_WIDTH_HEIGHT  = 0x00048003,
	VCMSG_GET_VIRTUAL_WIDTH_HEIGHT   = 0x00040004,
	VCMSG_TST_VIRTUAL_WIDTH_HEIGHT   = 0x00044004,
	VCMSG_SET_VIRTUAL_WIDTH_HEIGHT   = 0x00048004,
	VCMSG_GET_DEPTH                  = 0x00040005,
	VCMSG_TST_DEPTH                  = 0x00044005,
	VCMSG_SET_DEPTH                  = 0x00048005,
	VCMSG_GET_PIXEL_ORDER            = 0x00040006,
	VCMSG_TST_PIXEL_ORDER            = 0x00044006,
	VCMSG_SET_PIXEL_ORDER            = 0x00048006,
	VCMSG_GET_ALPHA_MODE             = 0x00040007,
	VCMSG_TST_ALPHA_MODE             = 0x00044007,
	VCMSG_SET_ALPHA_MODE             = 0x00048007,
	VCMSG_GET_PITCH                  = 0x00040008,
	VCMSG_TST_PITCH                  = 0x00044008,
	VCMSG_SET_PITCH                  = 0x00048008,
	VCMSG_GET_VIRTUAL_OFFSET         = 0x00040009,
	VCMSG_TST_VIRTUAL_OFFSET         = 0x00044009,
	VCMSG_SET_VIRTUAL_OFFSET         = 0x00048009,
	VCMSG_GET_OVERSCAN               = 0x0004000a,
	VCMSG_TST_OVERSCAN               = 0x0004400a,
	VCMSG_SET_OVERSCAN               = 0x0004800a,
	VCMSG_GET_PALETTE                = 0x0004000b,
	VCMSG_TST_PALETTE                = 0x0004400b,
	VCMSG_SET_PALETTE                = 0x0004800b,
	VCMSG_GET_LAYER                  = 0x0004000c,
	VCMSG_TST_LAYER                  = 0x0004400c,
	VCMSG_SET_LAYER                  = 0x0004800c,
	VCMSG_GET_TRANSFORM              = 0x0004000d,
	VCMSG_TST_TRANSFORM              = 0x0004400d,
	VCMSG_SET_TRANSFORM              = 0x0004800d,
};
//extern int /*rc*/ bcm_mailbox_read(unsigned chan, uint32_t *data28);
//extern int /*rc*/ bcm_mailbox_write(unsigned chan, uint32_t data28);
//extern int /*rc*/ bcm_mailbox_property(void *data, int size);
#endif
extern unsigned int readmailbox(unsigned int channel);
extern void writemailbox(unsigned int channel, unsigned int data);

#endif	/* MAILBOX_H */
