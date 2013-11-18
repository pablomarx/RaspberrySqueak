#ifndef __TYPES_H_
#define __TYPES_H_ 

typedef signed char         int8_t;
typedef signed short      int16_t;
typedef signed int         int32_t;
typedef signed long long int   int64_t;

typedef unsigned char      uint8_t;
typedef unsigned short      uint16_t;
typedef unsigned int      uint32_t;
typedef unsigned long long int   uint64_t;

typedef volatile signed char         vint8_t;
typedef volatile signed short int      vint16_t;
typedef volatile signed int            vint32_t;
typedef volatile signed long long int   vint64_t;

typedef volatile unsigned char         vuint8_t;
typedef volatile unsigned short int      vuint16_t;
typedef volatile unsigned int         vuint32_t;
typedef volatile unsigned long long int   vuint64_t;

typedef unsigned char bool;

#ifndef NULL
# define NULL ((void*)0)
#endif

#ifndef true
# define true	((bool) 1)
#endif

#ifndef false
# define false	((bool) 0)
#endif

#define READ32(addr) (*(vuint32_t*)(addr))
#define READ16(addr) (*(vuint16_t*)(addr))
#define READ8(addr) (*(vuint8_t*)(addr))

#define WRITE32(addr,value) (*(vuint32_t*)(addr) = (vuint32_t)(value))
#define WRITE16(addr,value) (*(vuint16_t*)(addr) = (vuint16_t)(value))

extern void dummy(int);

/**
	\brief Result of a method call.

	Negative results are errors.
	OK is for a general success.
	ErrorGeneral is an undisclosed failure.
	ErrorArgument is a bad input.
	ErrorRetry is a temporary issue that may disappear, the method should be rerun
		without modification (the caller is expected to limit number of retries as
		required).
	ErrorDevice is a more permenant hardware error (a reset procedure should be
		enacted before retrying).
	ErrorIncompatible is a device driver that will not support the detected
		device.
	ErrorCompiler is a problem with the configuration of the compiler generating
		unusable code.
	ErrorMemory is used when the memory is exhausted.
	ErrorTimeout is used when a maximum delay is reached when waiting and an 
		operation is unfinished. This does not necessarily mean the operationg 
		will not finish, just that it is unreasonably slow.
	ErrorDisconnected is used when a device is disconnected in transfer.
*/
typedef enum {
	OK = 0,
	ErrorGeneral = -1,
	ErrorArgument = -2,
	ErrorRetry = -3,
	ErrorDevice = -4,
	ErrorIncompatible = -5,
	ErrorCompiler = -6,
	ErrorMemory = -7,
	ErrorTimeout = -8,
	ErrorDisconnected = -9,
} Result;

/**
	\brief Direction of USB communication.

	Many and various parts of the USB standard use this 1 bit field to indicate
	in which direction information flows.
*/
typedef enum {
	HostToDevice = 0,
	Out = 0,
	DeviceToHost = 1,
	In = 1,
} UsbDirection;

/**
	\brief Speed of USB communication.

	Many and various parts of the USB standard use this 2 bit field to indicate
	in which direction information flows.
*/
typedef enum {
	High = 0,
	Full = 1,
	Low = 2,
} UsbSpeed;

static inline char* SpeedToChar(UsbSpeed speed) {
	if (speed == High) return "480 Mb/s";
	else if (speed == Low) return "1.5 Mb/s";
	else if (speed == Full) return "12 Mb/s";
	else return "Unknown Mb/s";
}

/**
	\brief Transfer type in USB communication.

	Many and various parts of the USB standard use this 2 bit field to indicate
	in what type of transaction to use.
*/
typedef enum {
	Control = 0,
	Isochronous = 1,
	Bulk = 2,
	Interrupt = 3,
} UsbTransfer;

/**
	\brief Transfer size in USB communication.

	Many and various parts of the USB standard use this 2 bit field to indicate
	in what size of transaction to use.
*/
typedef enum {
	Bits8,
	Bits16,
	Bits32,
	Bitint64_t,
} UsbPacketSize;

static inline UsbPacketSize SizeFromNumber(uint32_t size) {
	if (size <= 8) return Bits8;
	else if (size <= 16) return Bits16;
	else if (size <= 32) return Bits32;
	else return Bitint64_t;
}
static inline uint32_t SizeToNumber(UsbPacketSize size) {
	if (size == Bits8) return 8;
	else if (size == Bits16) return 16;
	else if (size == Bits32) return 32;
	else return 64;
}

/**
	\brief Returns the minimum of two inputs.

	Returns the minimum of two inputs, ensuring only one evaluation of each. To
	do so, the type must be supplied.
*/
#define Min(x, y, type) ({ type __x = (x); type __y = (y); __x < __y ? __x : __y; })
/**
	\brief Returns the maximum of two inputs.

	Returns the maximum of two inputs, ensuring only one evaluation of each. To
	do so, the type must be supplied.
*/
#define Max(x, y, type) ({ type __x = (x); type __y = (y); __x < __y ? __y : __x; })

#endif
