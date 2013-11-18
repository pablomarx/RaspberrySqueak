/******************************************************************************
*	platform/arm/broadcom2835.c
*	 by Alex Chadwick
*
*	A light weight implementation of the USB protocol stack fit for a simple
*	driver.
*
*	platform/arm/broadcom2835.c contains code for the broadcom2835 chip, used 
*	in the Raspberry Pi. Compiled conditionally on LIB_BCM2835=1.
******************************************************************************/
#include "configuration.h"
#include "types.h"

void Bcm2835Load()
{
	printf("CSUD: Broadcom2835 driver version 0.1.\n");
}

#ifndef TYPE_DRIVER

Result PowerOnUsb() {
	volatile uint32_t* mailbox;
	uint32_t result;

	mailbox = (uint32_t*)0x2000B880;
	while (mailbox[6] & 0x80000000);
	mailbox[8] = 0x80;
	do {
		while (mailbox[6] & 0x40000000);		
	} while (((result = mailbox[0]) & 0xf) != 0);
	return result == 0x80 ? OK : ErrorDevice;
}

#endif
