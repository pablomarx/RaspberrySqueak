/******************************************************************************
*	platform/platform.h
*	 by Alex Chadwick
*
*	A light weight implementation of the USB protocol stack fit for a simple
*	driver.
*
*	platform/platform.h contains definitions pertaining to the platform that
*	the system will run on.
******************************************************************************/

#ifndef _PLATFORM_H
#define _PLATFORM_H

#include "configuration.h"
#include "types.h"
#include "memutils.h"
#include "strings.h"
#include "printf.h"

#define DEBUG 1

void* MemoryReserve(uint32_t length, void* physicalAddress);

#ifdef NO_LOG
#define LOG(x)
#define LOGL(x, len) 
#define LOGF(x, ...) 
#define LOGFL(x, len, ...) 
#else

#define LOG(x) printf(x)
#define LOGL(x) printf(x) 
#define LOGF(x, ...) (printf(x, __VA_ARGS__))
#define LOGFL(x, ...) (printf(x, __VA_ARGS__))
#endif
#ifdef DEBUG
#define LOG_DEBUG(x) LOG(x)
#define LOG_DEBUGL(x) LOGL(x)
#define LOG_DEBUGF(x, ...) LOGF(x, __VA_ARGS__)
#define LOG_DEBUGFL(x, ...) LOGFL(x, __VA_ARGS__)
#else
#define LOG_DEBUG(x) 
#define LOG_DEBUGL(x) 
#define LOG_DEBUGF(x, ...) 
#define LOG_DEBUGFL(x, ...) 
#endif

/**
	\brief Turns on the USB host controller.

	Notifies the parent system that the USB contorller now requires power. 
*/
Result PowerOnUsb();
/**
	\brief Turns on the USB host controller.

	Notifies the parent system that the USB contorller no longer requires power. 
*/
void PowerOffUsb();

/**
	\brief Delays for delay microseconds.

	Delays for a number of microseconds. 	
*/
void MicroDelay(uint32_t delay);


#include "broadcom2835.h"

#endif
