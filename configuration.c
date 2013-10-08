/******************************************************************************
*	configuration.c
*	 by Alex Chadwick
*
*	A light weight implementation of the USB protocol stack fit for a simple
*	driver.
*
*	configuration.c contains code to load all components. In order to
*	allow the actual source files to be completely independent, one file must
*	exist which depends upon all of them, to perform static initialisation.
*	Each separate 'library' provides a Load method, which ConfigurationLoad
*	simply invoeks all of.
******************************************************************************/

#include "device.h"
#include "descriptors.h"

// Add load methods for new modules wrapped in ifdefs here:
void UsbLoad();
void PlatformLoad();
void Bcm2835Load();
void DwcLoad();
void HidLoad();
void HubLoad();
void KbdLoad();
void MouseLoad();

void ConfigurationLoad() {
	// Call each libraries load method here. Watch out for the order, load more
	// generic libraries first.
	Bcm2835Load();
	UsbLoad();
	DwcLoad();
	HidLoad();
	HubLoad();
	KbdLoad();
	MouseLoad();
}
