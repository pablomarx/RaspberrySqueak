/******************************************************************************
*	device/hid/keyboard.h
*	 by Alex Chadwick
*
*	A light weight implementation of the USB protocol stack fit for a simple
*	driver.
*
*	device/hid/keyboard.h contains definitions relating to keyboards.
******************************************************************************/
#include "device.h"
#include "types.h"

extern unsigned char KeysNormal[104];
extern unsigned char KeysShift[104];

/** 
	\brief The current state of keyboard modifier keys.

	Encapsulates the current state of the keyboard modifier keys. Strucutre 
	mimics the most common keyboard ordering.
*/
struct KeyboardModifiers {
	bool LeftControl : 1; // @0
	bool LeftShift : 1; // @1
	bool LeftAlt : 1; // @2
	bool LeftGui : 1; // the 'windows' key @3
	bool RightControl : 1;  // @4
	bool RightShift : 1; // @5
	bool RightAlt : 1; // 'alt gr' @6
	bool RightGui : 1; // @7
};

/** 
	\brief The current state of keyboard leds.

	Encapsulates the current state of the keyboard leds. Strucutre mimics the 
	most common lights and ordering. Not all keyboards may support all lights.
*/
struct KeyboardLeds {
	bool NumberLock : 1;
	bool CapsLock : 1;
	bool ScrollLock : 1;
	bool Compose : 1;
	bool Kana : 1;
	bool Power : 1;
	bool Mute : 1;
	bool Shift : 1;
};

/** The DeviceDriver field in UsbDriverDataHeader for keyboard devices. */
#define DeviceDriverKeyboard 0x4B424430
/** The maximum number of keys a keyboard can report at once. Should be 
	multiple of 2. */
#define KeyboardMaxKeys 6

/** 
	\brief Keyboard specific data.

	The contents of the driver data field for keyboard devices. Placed in
	HidDevice, as this driver is built atop that.
*/
struct KeyboardDevice {
	/** Standard driver data header. */
	struct UsbDriverDataHeader Header;
	/** Internal - Index in keyboard arrays. */
	uint32_t Index;
	/** Number of keys currently held down. */
	uint32_t KeyCount;
	/** Keys currently held down. */
	uint16_t Keys[KeyboardMaxKeys];
	/** Modifier keys currently held down. */
	struct KeyboardModifiers Modifiers;
	/** Which LEDs this keyboard supports. */
	struct KeyboardLeds LedSupport;
	/** Which fields in the LED report are for what LEDs. */
	struct HidParserField *LedFields[8];
	/** Which fields in the Input report are for what modifiers and keys. */
	struct HidParserField *KeyFields[8 + 1];
	/** The LED report. */
	struct HidParserReport *LedReport;
	/** The input report. */
	struct HidParserReport *KeyReport;
};

/**
	\brief Enumerates a device as a keyboard.

	Checks a device already checked by HidAttach to see if it appears to be a 
	keyboard, and, if so, builds up necessary information to enable the 
	keyboard methods.
*/
Result KeyboardAttach(struct UsbDevice *device, uint32_t interface);

/**
	\brief Returns the number of keyboards connected to the system.	
*/
uint32_t KeyboardCount();

/**
	\brief Sets the keyboard LEDs to the state given in leds.

	Sets the keyboard LEDs to the state given in leds. Unimplemented LEDs are 
	ignored silently. 
*/
Result KeyboardSetLeds(uint32_t keyboardAddress, struct KeyboardLeds leds); 

struct KeyboardLeds KeyboardGetLeds(uint32_t keyboardAddress);

/**
	\brief Gets a list of available keyboard LEDs.

	Reads the availablility of keyboard LEDs from the report descriptor. LEDs 
	that are present are set to 1, and those than are not are set to 0.
*/
struct KeyboardLeds KeyboardGetLedSupport(uint32_t keyboardAddress); 

/**
	\brief Checks a given keyboard.

	Reads back the report from a given keyboard and parses it into the internal
	fields. These can be accessed with KeyboardGet... methods
*/
Result KeyboardPoll(uint32_t keyboardAddress);

/**
	\brief Reads the modifier keys from a keyboard.

	Reads back the state of the modifier keys from the last sucessfully 
	received report. Zeros out by default.
*/
struct KeyboardModifiers KeyboardGetModifiers(uint32_t keyboardAddress);

/**
	\brief Returns the number of keys currently held down.

	Reads back the number of keys that were held down in the last report. If 
	the keyboard reaches its key limit, this reports the last sensible report 
	received.
*/
uint32_t KeyboardGetKeyDownCount(uint32_t keyboardAddress);

/**
	\brief Returns whether or not a particular key is held down.

	Reads back whether or not a key was held on the last successfully received 
	report.
*/
bool KeyboardGetKeyIsDown(uint32_t keyboardAddress, uint16_t key);

/**
	\brief Returns the nth key that is held down.

	Reads back the number of the nth key that was held down in the last 
	successfully received report.
*/
uint16_t KeyboardGetKeyDown(uint32_t keyboardAddress, uint32_t index);

/** 
	\brief Returns the device address of the nth connected keyboard.

	Keyboards that are connected are stored in an array, and this method 
	retrieves the nth item from that array. Returns 0 on error.
*/
uint32_t KeyboardGetAddress(uint32_t index);
