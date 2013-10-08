/******************************************************************************
*	device/hid/mouse.h
*	 by Alex Chadwick
*
*	A light weight implementation of the USB protocol stack fit for a simple
*	driver.
*
*	device/hid/mouse.h contains definitions relating to mouses.
******************************************************************************/
#include "device.h"
#include "types.h"

/** The DeviceDriver field in UsbDriverDataHeader for mouse devices. */
#define DeviceDriverMouse 0xB4424431
/** The maximum number of keys a mouse can report at once. Should be 
	multiple of 2. */
#define MouseMaxKeys 6

enum {
	MouseDeviceButtonLeft,
	MouseDeviceButtonRight,
	MouseDeviceButtonMiddle,
	MouseDeviceButtonSide,
	MouseDeviceButtonExtra,
};

/** 
	\brief Mouse specific data.

	The contents of the driver data field for mouse devices. Placed in
	HidDevice, as this driver is built atop that.
*/
struct MouseDevice {
	/** Standard driver data header. */
	struct UsbDriverDataHeader Header;
	/** Internal - Index in mouse arrays. */
	uint32_t Index;

	uint8_t buttonState;
	int16_t mouseX;
	int16_t mouseY;
	int16_t wheel;

	/** The input report. */
	struct HidParserReport *MouseReport;
};

/**
	\brief Enumerates a device as a mouse.

	Checks a device already checked by HidAttach to see if it appears to be a 
	mouse, and, if so, builds up necessary information to enable the 
	mouse methods.
*/
Result MouseAttach(struct UsbDevice *device, uint32_t interface);

/**
	\brief Returns the number of mouses connected to the system.	
*/
uint32_t MouseCount();

/**
	\brief Checks a given mouse.

	Reads back the report from a given mouse and parses it into the internal
	fields. These can be accessed with MouseGet... methods
*/
Result MousePoll(uint32_t mouseAddress);

/** 
	\brief Returns the device address of the nth connected mouse.

	Mouses that are connected are stored in an array, and this method 
	retrieves the nth item from that array. Returns 0 on error.
*/
uint32_t MouseGetAddress(uint32_t index);


uint16_t MouseGetPositionX(uint32_t mouseAddress);
uint16_t MouseGetPositionY(uint32_t mouseAddress);
uint16_t MouseGetWheel(uint32_t mouseAddress);
uint32_t MouseGetPosition(uint32_t mouseAddress);
uint8_t MouseGetButtons(uint32_t mouseAddress);
bool MouseGetButtonIsPressed(uint32_t mouseAddress, int button);
