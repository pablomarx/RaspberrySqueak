#include "sq.h"
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
extern int interruptCheckCounter;
extern int interruptKeycode;
extern int interruptPending;  /* set to true by RecordKeystroke if interrupt key is pressed */

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
	keystate = (keyModifier) | (key & 0xff);

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
		//int position = MouseGetPosition(mouse);
		//printf("mouse: x=%i, y=%i\n", ((position>>16)&0xffff), (position&0xffff));
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
