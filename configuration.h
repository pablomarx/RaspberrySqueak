/******************************************************************************
*	configuration.h
*	 by Alex Chadwick
*
*	A light weight implementation of the USB protocol stack fit for a simple
*	driver.
*
*	configuration.h contains definitions for all optional components
*	The makefile defines three main categories of definitions:
*		CONFIG: Whether or not this is a DEBUG driver
*		TARGET: The target system
*		TYPE:	What sort of driver to compile (e.g. standalone)
*****************************************************************************/

// Check we have a CONFIG. Valid choices are DEBUG and FINAL. If neither of
// of these are specified, CONFIG_ERROR will be. If not, the haven't used the
// makefile.
#if defined DEBUG
#elif defined FINAL
#elif defined CONFIG_ERROR
#	error Please specify the CONFIG as either DEBUG or FINAL (default)
#else
#	error Please ensure you compile the driver with the makefile provided
#endif

// Check we have a target. This should either be RPI or NONE. If neither of
// these is specified, TARGET_ERROR will be. If not, the haven't used the
// makefile.
#define ARM
#define ARM_V6
#define ENDIAN_LITTLE
#define BROADCOM_2835
#define HCD_DESIGNWARE_20
#define HCD_DESIGNWARE_BASE ((void*)0x20980000)


