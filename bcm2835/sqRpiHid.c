#include "sq.h"
#include "sqRpiDisplay.h"

#include "keyboard.h"
#include "mouse.h"
#include "timer.h" // watchdog
#include "usbd.h"

/*** Variables -- Event Recording ***/
#define KEYBUF_SIZE 64
int keyBuf[KEYBUF_SIZE];        /* circular buffer */
int keyBufGet = 0;                      /* index of next item of keyBuf to read */
int keyBufPut = 0;                      /* index of next item of keyBuf to write */
int keyBufOverflows = 0;        /* number of characters dropped */

/*** Variables -- Imported from Virtual Machine ***/
int interruptCheckCounter = 0;
int interruptKeycode = -1;
int interruptPending = 0;  /* set to true by RecordKeystroke if interrupt key is pressed */

/*** Variables -- Event Recording ***/
#define MillisecondClockMask 536870911
#define MAX_EVENT_BUFFER 64
static sqInputEvent eventBuffer[MAX_EVENT_BUFFER];
static int eventBufferGet = 0;
static int eventBufferPut = 0;

static char lastKeys[255];
static int lastMouseX = 0;
static int lastMouseY = 0;
static int lastMouseButton = 0;
static int lastPollTime = 0;

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
	keystate = (keyModifier << 8) | (key & 0xff);

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

sqInputEvent *nextEventPut(void) {
	sqInputEvent *evt;
	evt = eventBuffer + eventBufferPut;
	eventBufferPut = (eventBufferPut + 1) % MAX_EVENT_BUFFER;
	if (eventBufferGet == eventBufferPut) {
		/* buffer overflow; drop the last event */
		eventBufferGet = (eventBufferGet + 1) % MAX_EVENT_BUFFER;
	}
	return evt;
}

void rpiProcessMouseEvents(void) {
	int mouseCount = MouseCount();
	if (mouseCount == 0) {
		return;
	}
	
	uint32_t mouse = MouseGetAddress(0);
	int position = MouseGetPosition(mouse);
	int posX = (position >> 16) & 0xffff;
	int posY = position & 0xffff;

	int mouseButtons = MouseGetButtons(mouse);
	int buttonState = 0;
	if (mouseButtons & 0x01) {
		buttonState |= RedButtonBit;
	}
	if (mouseButtons & 0x02) {
		buttonState |= BlueButtonBit;
	}
	if (mouseButtons & 0x04) {
		buttonState |= YellowButtonBit;
	}

	if (posX != lastMouseX || posY != lastMouseY || buttonState != lastMouseButton) {
		lastMouseX = posX;
		lastMouseY = posY;
		lastMouseButton = buttonState;
		moveCursor(lastMouseX, lastMouseY);

		sqMouseEvent *event = (sqMouseEvent*) nextEventPut();

		/* first the basics */
		event->type = EventTypeMouse;
		event->timeStamp = ioMSecs() & MillisecondClockMask; 
		event->x = lastMouseX;
		event->y = lastMouseY;
		/* then the buttons */
		event->buttons = lastMouseButton & 0x07;
		/* then the modifiers */
		event->modifiers = 0; //buttonState >> 3;
		/* clean up reserved */
		event->reserved1 = 0;
	}
}

void rpiRegisterKeyboardEvent(int keyCode, int pressCode, int modifiers) {
	sqKeyboardEvent *evt = (sqKeyboardEvent*) nextEventPut();
	/* first the basics */
	evt->type = EventTypeKeyboard;
	evt->timeStamp = ioMSecs() & MillisecondClockMask;
	/* now the key code */
	/* press code must differentiate */
	evt->charCode = keyCode;
	evt->pressCode = pressCode;
	evt->modifiers = modifiers;

	evt->reserved1=/*evt->reserved2=*/ 0;
}

void rpiProcessKeyboardEvents(void) {
	int keyboardCount = KeyboardCount();
	if (keyboardCount == 0) {
		return;
	}

	uint32_t keyboard = KeyboardGetAddress(0);
	int keysDown = KeyboardGetKeyDownCount(keyboard);

	struct KeyboardModifiers keyModifiers = KeyboardGetModifiers(keyboard);
	int modifiers = 0;
	if (keyModifiers.LeftControl || keyModifiers.RightControl) {
		modifiers |= CtrlKeyBit;
	}
	if (keyModifiers.LeftShift || keyModifiers.RightShift) {
		modifiers |= ShiftKeyBit;
	}
	if (keyModifiers.LeftAlt || keyModifiers.RightAlt) {
		modifiers |= OptionKeyBit;
	}
	if (keyModifiers.LeftGui || keyModifiers.RightGui) {
		modifiers |= CommandKeyBit;
	}

	char theseKeys[keysDown];
	
	for (int i=0; i<keysDown; i++) {
		int keyCode = KeyboardGetKeyDown(keyboard, i);
		unsigned char key = (keyModifiers.LeftShift || keyModifiers.RightShift ? KeysShift[keyCode] : KeysNormal[keyCode]);
		theseKeys[i] = key;
		
		if (lastKeys[key] == 0) {
			lastKeys[key] = 1;
			rpiRegisterKeyboardEvent(key, EventKeyDown, modifiers);
			rpiRegisterKeyboardEvent(key, EventKeyChar, modifiers);
		}
	}	

	for (int i=0; i<255; i++) {
		if (lastKeys[i] != 0) {
			bool matched = false;
			for (int j=0; j<keysDown; j++) {
				if (theseKeys[j] == i) {
					matched = true;
				}
			}
			
			if (matched == false) {
				lastKeys[i] = 0;
				rpiRegisterKeyboardEvent(i, EventKeyUp, modifiers);
			}
		}
	}
}

int ioGetNextEvent(sqInputEvent *evt) {
	if (ioMSecs() - lastPollTime < 75) {
		return false;
	}
	lastPollTime = ioMSecs();

	ioProcessEvents();
	rpiProcessMouseEvents();
	rpiProcessKeyboardEvents();
	
	if (eventBufferGet == eventBufferPut) {
		return false;
	}
	*evt = eventBuffer[eventBufferGet];
	eventBufferGet = (eventBufferGet+1) % MAX_EVENT_BUFFER;
	return true;
}

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
	}

	watchdog_reset();
	
	return true;
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
