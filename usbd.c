/******************************************************************************
*	usbd/usbd.c
*	 by Alex Chadwick
*
*	A light weight implementation of the USB protocol stack fit for a simple
*	driver.
*
*	usbd.c contains code relating to the generic USB driver. USB
*	is designed such that this driver's interface would be virtually the same
*	across all systems, and in fact its implementation varies little either.
******************************************************************************/
#include "hcd.h"
#include "descriptors.h"
#include "usbd.h"
#include "timer.h"
#include "memutils.h"

/** The default timeout in ms of control transfers. */
#define ControlMessageTimeout 10
/** The maximum number of devices that can be connected. */
#define MaximumDevices 32

struct UsbDevice *Devices[MaximumDevices];
Result (*InterfaceClassAttach[InterfaceClassAttachCount])(struct UsbDevice *device, uint32_t interfaceNumber);
void ConfigurationLoad();

/**
	\brief Scans the bus for hubs.

	Enumerates the devices on the bus, performing necessary initialisation and 
	building a device tree for later reference.
*/
Result UsbAttachRootHub();

struct UsbDevice *UsbGetRootHub() { return Devices[0]; }

void UsbLoad()
{	
	LOG("CSUD: USB driver version 0.1\n"); 
	for (uint32_t i = 0; i < MaximumDevices; i++)
		Devices[i] = NULL;
	for (uint32_t i = 0; i < InterfaceClassAttachCount; i++)
		InterfaceClassAttach[i] = NULL;
}

Result UsbInitialise() {
	Result result;

	ConfigurationLoad();
	result = OK;

	if (sizeof(struct UsbDeviceRequest) != 0x8) {
		LOGF("USBD: Incorrectly compiled driver. UsbDeviceRequest: %#x (0x8).\n", 
			sizeof(struct UsbDeviceRequest));
		return ErrorCompiler; // Correct packing settings are required.
	}

	if ((result = HcdInitialise()) != OK) {
		LOG("USBD: Abort, HCD failed to initialise.\n");
		goto errorReturn;
	}
	if ((result = HcdStart()) != OK) {
		LOG("USBD: Abort, HCD failed to start.\n");
		goto errorDeinitialise;
	}
	if ((result = UsbAttachRootHub()) != OK) {
		LOG("USBD: Failed to enumerate devices.\n");
		goto errorStop;
	}

	return result;
errorStop:
	HcdStop();
errorDeinitialise:
	HcdDeinitialise();
errorReturn:
	return result;
}

Result UsbControlMessage(struct UsbDevice *device, 
	struct UsbPipeAddress pipe, void* buffer, uint32_t bufferLength,
	struct UsbDeviceRequest *request, uint32_t timeout) {
	Result result;

	if (((uint32_t)buffer & 0x3) != 0)
		LOG_DEBUG("USBD: Warning message buffer not word aligned.\n");
	result = HcdSumbitControlMessage(device, pipe, buffer, bufferLength, request);

	if (result != OK) {
		LOG_DEBUGF("USBD: Failed to send message to %s: %d.\n", UsbGetDescription(device), result);
		return result;
	}

	while (timeout-- > 0 && (device->Error & Processing))
		MicroDelay(1000);

	if ((device->Error & Processing)) {
		LOG_DEBUGF("USBD: Message to %s timeout reached.\n", UsbGetDescription(device));
		return ErrorTimeout;
	}

	if (device->Error & ~Processing) {
		if (device->Parent != NULL && device->Parent->DeviceCheckConnection != NULL) {
			// Check we're still connected!
			LOG_DEBUGF("USBD: Verifying %s is still connected.\n", UsbGetDescription(device));
			if ((result = device->Parent->DeviceCheckConnection(device->Parent, device)) != OK) {
				return ErrorDisconnected;
			}		
			LOG_DEBUGF("USBD: Yes, %s is still connected.\n", UsbGetDescription(device));
		}
		result = ErrorDevice;
	}

	return result;
}

Result UsbGetDescriptor(struct UsbDevice *device, enum DescriptorType type, 
	uint8_t index, uint16_t langId, void* buffer, uint32_t length, uint32_t minimumLength, uint8_t recipient) {
	Result result;

	if ((result = UsbControlMessage(
		device, 
		(struct UsbPipeAddress) { 
			.Type = Control, 
			.Speed = device->Speed, 
			.EndPoint = 0 , 
			.Device = device->Number, 
			.Direction = In,
			.MaxSize = SizeFromNumber(device->Descriptor.MaxPacketSize0),
		},
		buffer,
		length,
		&(struct UsbDeviceRequest) {
			.Request = GetDescriptor,
			.Type = 0x80 | recipient,
			.Value = (uint16_t)type << 8 | index,
			.Index = langId,
			.Length = length,
		},
		ControlMessageTimeout)) != OK) {
			LOGF("USBD: Failed to get descriptor %#x:%#x for device %s. Result %#x.\n", type, index, UsbGetDescription(device), result);
		return result;
	}

	if (device->LastTransfer < minimumLength) {
		LOGF("USBD: Unexpectedly short descriptor (%d/%d) %#x:%#x for device %s. Result %#x.\n", device->LastTransfer, minimumLength, type, index, UsbGetDescription(device), result);
		return ErrorDevice;
	}

	return OK;
}
	
Result UsbGetString(struct UsbDevice *device, uint8_t stringIndex, uint16_t langId, void* buffer, uint32_t length) {
	Result result;
	
	// Apparently this tends to fail a lot.
	for (uint32_t i = 0; i < 3; i++) {
		result = UsbGetDescriptor(device, String, stringIndex, langId, buffer, length, length, 0);

		if (result == OK)
			break;
	}

	return result;
}

Result UsbReadStringLang(struct UsbDevice *device, uint8_t stringIndex, uint16_t langId, void* buffer, uint32_t length) {
	Result result;
	
	result = UsbGetString(device, stringIndex, langId, buffer, Min(2, length, uint32_t));

	if (result == OK && device->LastTransfer != length)
		result = UsbGetString(device, stringIndex, langId, buffer, Min(((uint8_t*)buffer)[0], length, uint32_t));

	return result;
}

Result UsbReadString(struct UsbDevice *device, uint8_t stringIndex, char* buffer, uint32_t length) {
	Result result; 
	uint32_t i; uint8_t descriptorLength;

	if (buffer == NULL || stringIndex == 0)
		return ErrorArgument;
	uint16_t langIds[2];
	struct UsbStringDescriptor *descriptor;

	result = UsbReadStringLang(device, 0, 0, &langIds, 4);

	if (result != OK) {
		LOGF("USBD: Error getting language list from %s.\n", UsbGetDescription(device));
		return result;
	}
	else if (device->LastTransfer < 4) {
		LOGF("USBD: Unexpectedly short language list from %s.\n", UsbGetDescription(device));
		return ErrorDevice;
	}

	descriptor = (struct UsbStringDescriptor*)buffer;
	if (descriptor == NULL)
		return ErrorMemory;
	if ((result = UsbReadStringLang(device, stringIndex, langIds[1], descriptor, length)) != OK)
		return result;
 
	descriptorLength = descriptor->DescriptorLength;
	for (i = 0; i < length - 1 && i < (descriptorLength - 2) >> 1; i++) {
		if (descriptor->Data[i] > 0xff)
			buffer[i] = '?';
		else {
			buffer[i] = descriptor->Data[i];
		}

	};

	if (i < length)
		buffer[i++] = '\0';

	return result;
}

Result UsbReadDeviceDescriptor(struct UsbDevice *device) {
	Result result;
	if (device->Speed == Low) {
		device->Descriptor.MaxPacketSize0 = 8;
		if ((result = UsbGetDescriptor(device, Device, 0, 0, (void*)&device->Descriptor, sizeof(device->Descriptor), 8, 0)) != OK)
			return result;
		if (device->LastTransfer == sizeof(struct UsbDeviceDescriptor))
			return result;
		return UsbGetDescriptor(device, Device, 0, 0, (void*)&device->Descriptor, sizeof(device->Descriptor), sizeof(device->Descriptor), 0);
	} else if (device->Speed == Full) {
		device->Descriptor.MaxPacketSize0 = 64;
		if ((result = UsbGetDescriptor(device, Device, 0, 0, (void*)&device->Descriptor, sizeof(device->Descriptor), 8, 0)) != OK)
			return result;
		if (device->LastTransfer == sizeof(struct UsbDeviceDescriptor))
			return result;
		return UsbGetDescriptor(device, Device, 0, 0, (void*)&device->Descriptor, sizeof(device->Descriptor), sizeof(device->Descriptor), 0);
	} else {
		device->Descriptor.MaxPacketSize0 = 64;
		return UsbGetDescriptor(device, Device, 0, 0, (void*)&device->Descriptor, sizeof(device->Descriptor), sizeof(device->Descriptor), 0);
	}
}

Result UsbSetAddress(struct UsbDevice *device, uint8_t address) {
	Result result;
	
	if (device->Status != Default) {
		LOGF("USBD: Illegal attempt to configure device %s in state %#x.\n", UsbGetDescription(device), device->Status);
		return ErrorDevice;
	}

	if ((result = UsbControlMessage(
		device, 
		(struct UsbPipeAddress) { 
			.Type = Control, 
			.Speed = device->Speed, 
			.EndPoint = 0, 
			.Device = 0, 
			.Direction = Out,
			.MaxSize = SizeFromNumber(device->Descriptor.MaxPacketSize0),
		},
		NULL,
		0,
		&(struct UsbDeviceRequest) {
			.Request = SetAddress,
			.Type = 0,
			.Value = address,
		},
		ControlMessageTimeout)) != OK) 
		return result;

	MicroDelay(10000); // Allows the address to propagate.
	device->Number = address;
	device->Status = Addressed;
	return OK;
}

Result UsbSetConfiguration(struct UsbDevice *device, uint8_t configuration) {
	Result result;
	
	if (device->Status != Addressed) {
		LOGF("USBD: Illegal attempt to configure device %s in state %#x.\n", UsbGetDescription(device), device->Status);
		return ErrorDevice;
	}

	if ((result = UsbControlMessage(
		device, 
		(struct UsbPipeAddress) { 
			.Type = Control, 
			.Speed = device->Speed, 
			.EndPoint = 0, 
			.Device = device->Number, 
			.Direction = Out,
			.MaxSize = SizeFromNumber(device->Descriptor.MaxPacketSize0),
		},
		NULL,
		0,
		&(struct UsbDeviceRequest) {
			.Request = SetConfiguration,
			.Type = 0,
			.Value = configuration,
		},
		ControlMessageTimeout)) != OK)
		return result;

	device->ConfigurationIndex = configuration;
	device->Status = Configured;
	return OK;	
}

Result UsbClearStall(struct UsbDevice *device, struct UsbPipeAddress *pipe) {
	Result result;
	
	printf("%s %s device->Error=%i ", __PRETTY_FUNCTION__, UsbGetDescription(device), device->Error);
	//HubPortReset(device->parent);
	
	result = UsbControlMessage(
		device, 
		(struct UsbPipeAddress) { 
			.Type = Control, 
			.Speed = device->Speed, 
			.EndPoint = 0, 
			.Device = device->Number, 
			.Direction = pipe->Direction,
			.MaxSize = SizeFromNumber(device->Descriptor.MaxPacketSize0),
		},
		NULL,
		0,
		&(struct UsbDeviceRequest) {
			.Request = ClearFeature,
			.Type = 0x02, // kUSBEndpoint
			.Value = 0, //kUSBFeatureEndpointStall
		},
		ControlMessageTimeout);

	printf(" => result=%i, Device->Error=%i\n", result, device->Error);
	if (result == OK) {
//		HubChildReset(device->Parent, device);
	}
	return result;
}

Result UsbConfigure(struct UsbDevice *device, uint8_t configuration) {
	Result result;
	void* fullDescriptor;
	struct UsbDescriptorHeader *header;
	struct UsbInterfaceDescriptor *interface;
	struct UsbEndpointDescriptor *endpoint;
	uint32_t lastInterface, lastEndpoint;
	bool isAlternate;
		
	if (device->Status != Addressed) {
		LOGF("USBD: Illegal attempt to configure device %s in state %#x.\n", UsbGetDescription(device), device->Status);
		return ErrorDevice;
	}
		
	if ((result = UsbGetDescriptor(device, Configuration, configuration, 0, (void*)&device->Configuration, sizeof(device->Configuration), sizeof(device->Configuration), 0)) != OK) {
		LOGF("USBD: Failed to retrieve configuration descriptor %#x for device %s.\n", configuration, UsbGetDescription(device));
		return result;
	} 

	if ((fullDescriptor = malloc(device->Configuration.TotalLength)) == NULL) {
		LOG("USBD: Failed to allocate space for descriptor.\n");
		return ErrorMemory;
	}
	if ((result = UsbGetDescriptor(device, Configuration, configuration, 0, fullDescriptor, device->Configuration.TotalLength, device->Configuration.TotalLength, 0)) != OK) {
		LOGF("USBD: Failed to retrieve full configuration descriptor %#x for device %s.\n", configuration, UsbGetDescription(device));
		goto deallocate;
	}

	device->ConfigurationIndex = configuration;
	configuration = device->Configuration.ConfigurationValue;

	header = fullDescriptor;
	lastInterface = MaxInterfacesPerDevice;
	lastEndpoint = MaxEndpointsPerDevice;
	isAlternate = false;

	for (header = (struct UsbDescriptorHeader*)((uint8_t*)header + header->DescriptorLength);
		(uint32_t)header - (uint32_t)fullDescriptor < device->Configuration.TotalLength;
		header = (struct UsbDescriptorHeader*)((uint8_t*)header + header->DescriptorLength)) {
		switch (header->DescriptorType) {
		case Interface:
			interface = (struct UsbInterfaceDescriptor*)header;
			if (lastInterface != interface->Number) {
				memcpy((void*)&device->Interfaces[lastInterface = interface->Number], (void*)interface, sizeof(struct UsbInterfaceDescriptor));
				lastEndpoint = 0;
				isAlternate = false;
			}
			else isAlternate = true;
			break;
		case Endpoint:
			if (isAlternate) break;
			if (lastInterface == MaxInterfacesPerDevice || lastEndpoint >= device->Interfaces[lastInterface].EndpointCount) {
				LOG_DEBUGF("USBD: Unexpected endpoint descriptor in %s.Interface%d.\n", UsbGetDescription(device), lastInterface + 1);
				break;
			}
			endpoint = (struct UsbEndpointDescriptor*)header;
			memcpy((void*)&device->Endpoints[lastInterface][lastEndpoint++], (void*)endpoint, sizeof(struct UsbEndpointDescriptor));
			break;
		default:
			if (header->DescriptorLength == 0)
				goto headerLoopBreak;

			break;
		}
		
		LOG_DEBUGF("USBD: Descriptor %d length %d, interface %d.\n", header->DescriptorType, header->DescriptorLength, lastInterface);
	}
headerLoopBreak:

	if ((result = UsbSetConfiguration(device, configuration)) != OK) {		
		goto deallocate;
	}
	LOG_DEBUGF("USBD: %s configuration %d. Class %d, subclass %d.\n", UsbGetDescription(device), configuration, device->Interfaces[0].Class, device->Interfaces[0].SubClass);

	device->FullConfiguration = fullDescriptor;
	 
	return OK;
deallocate:
	free(fullDescriptor);
	return result;
}

const char* UsbGetDescription(struct UsbDevice *device) {
	if (device->Status == Attached)
		return "New Device (Not Ready)";
	else if (device->Status == Powered)
		return "Unknown Device (Not Ready)";
	else if (device == Devices[0])
		return "USB Root Hub";

	switch (device->Descriptor.Class) {
	case DeviceClassHub:
		if (device->Descriptor.UsbVersion == 0x210)
			return "USB 2.1 Hub";
		else if (device->Descriptor.UsbVersion == 0x200)
			return "USB 2.0 Hub";
		else if (device->Descriptor.UsbVersion == 0x110)
			return "USB 1.1 Hub";
		else if (device->Descriptor.UsbVersion == 0x100)
			return "USB 1.0 Hub";
		else
			return "USB Hub";
	case DeviceClassVendorSpecific:
		if (device->Descriptor.VendorId == 0x424 &&
			device->Descriptor.ProductId == 0xec00)
			return "SMSC LAN9512";
	case DeviceClassInInterface:
		if (device->Status == Configured) {
			switch (device->Interfaces[0].Class) {
			case InterfaceClassAudio:
				return "USB Audio Device";
			case InterfaceClassCommunications:
				return "USB CDC Device";
			case InterfaceClassHid:
				switch (device->Interfaces[0].Protocol) {
				case 1:
					return "USB Keyboard";
				case 2:
					return "USB Mouse";					
				default:
					return "USB HID";
				}
			case InterfaceClassPhysical:
				return "USB Physical Device";
			case InterfaceClassImage:
				return "USB Imaging Device";
			case InterfaceClassPrinter:
				return "USB Printer";
			case InterfaceClassMassStorage:
				return "USB Mass Storage Device";
			case InterfaceClassHub:
				if (device->Descriptor.UsbVersion == 0x210)
					return "USB 2.1 Hub";
				else if (device->Descriptor.UsbVersion == 0x200)
					return "USB 2.0 Hub";
				else if (device->Descriptor.UsbVersion == 0x110)
					return "USB 1.1 Hub";
				else if (device->Descriptor.UsbVersion == 0x100)
					return "USB 1.0 Hub";
				else
					return "USB Hub";
			case InterfaceClassCdcData:
				return "USB CDC-Data Device";
			case InterfaceClassSmartCard:
				return "USB Smart Card";
			case InterfaceClassContentSecurity:
				return "USB Content Secuity Device";
			case InterfaceClassVideo:
				return "USB Video Device";
			case InterfaceClassPersonalHealthcare:
				return "USB Healthcare Device";
			case InterfaceClassAudioVideo:
				return "USB AV Device";
			case InterfaceClassDiagnosticDevice:
				return "USB Diagnostic Device";
			case InterfaceClassWirelessController:
				return "USB Wireless Controller";
			case InterfaceClassMiscellaneous:
				return "USB Miscellaneous Device";
			case InterfaceClassVendorSpecific:
				return "Vendor Specific";
			default:
				return "Generic Device";
			}
		} else if (device->Descriptor.Class == DeviceClassVendorSpecific) 
			return "Vendor Specific";
		else	
			return "Unconfigured Device";		
	default:
		return "Generic Device";
	}
}

Result UsbAttachDevice(struct UsbDevice *device) {
	Result result;
	uint8_t address;
	char* buffer;

	// Store the address until it is actually assigned.
	address = device->Number;
	device->Number = 0;
	LOG_DEBUGF("USBD: Scanning %d. %s.\n", address, SpeedToChar(device->Speed));

	if ((result = UsbReadDeviceDescriptor(device)) != OK) {
		LOGF("USBD: Failed to read device descriptor for %d.\n", address);
		device->Number = address;
		return result;
	}
	device->Status = Default;

	if (device->Parent != NULL && device->Parent->DeviceChildReset != NULL) {
		// Reset the port for what will be the second time.
		if ((result = device->Parent->DeviceChildReset(device->Parent, device)) != OK) {
			LOGF("USBD: Failed to reset port again for new device %s.\n", UsbGetDescription(device));
			device->Number = address;
			return result;
		}
	}

	if ((result = UsbSetAddress(device, address)) != OK) {
		LOGF("USBD: Failed to assign address to %#x.\n", address);
		device->Number = address;
		return result;
	}
	device->Number = address;

	if ((result = UsbReadDeviceDescriptor(device)) != OK) {
		LOGF("USBD: Failed to reread device descriptor for %#x.\n", address);
		return result;
	}

	LOG_DEBUGF("USBD: Attach Device %s. Address:%d Class:%d Subclass:%d USB:%x.%x. %d configurations, %d interfaces.\n",
		UsbGetDescription(device), address, device->Descriptor.Class, device->Descriptor.SubClass, device->Descriptor.UsbVersion >> 8, 
		(device->Descriptor.UsbVersion >> 4) & 0xf, device->Descriptor.ConfigurationCount, device->Configuration.InterfaceCount);
		
	LOGF("USBD: Device Attached: %s.\n", UsbGetDescription(device));	
	buffer = NULL;
	
	if (device->Descriptor.Product != 0) {
		if (buffer == NULL) buffer = malloc(0x100);		
		if (buffer != NULL) {
			result = UsbReadString(device, device->Descriptor.Product, buffer, 0x100);
			if (result == OK) LOGF("USBD:  -Product:       %s.\n", buffer);	
		}
	}	
	if (device->Descriptor.Manufacturer != 0) {
		if (buffer == NULL) buffer = malloc(0x100);		
		if (buffer != NULL) {
			result = UsbReadString(device, device->Descriptor.Manufacturer, buffer, 0x100);
			if (result == OK) LOGF("USBD:  -Manufacturer:  %s.\n", buffer);	
		}
	}
	if (device->Descriptor.SerialNumber != 0) {
		if (buffer == NULL) buffer = malloc(0x100);		
		if (buffer != NULL) {
			result = UsbReadString(device, device->Descriptor.SerialNumber, buffer, 0x100);
			if (result == OK) LOGF("USBD:  -SerialNumber:  %s.\n", buffer);	
		}
	}
	
	if (buffer != NULL) { free(buffer); buffer = NULL; }
	
	LOG_DEBUGF("USBD:  -VID:PID:       %x:%x v%d.%x\n", device->Descriptor.VendorId, device->Descriptor.ProductId, device->Descriptor.Version >> 8, device->Descriptor.Version & 0xff);
	
	// We only support devices with 1 configuration for now.
	if ((result = UsbConfigure(device, 0)) != OK) {
		LOGF("USBD: Failed to configure device %#x.\n", address);
		return OK;
	}

	if (device->Configuration.StringIndex != 0) {
		if (buffer == NULL) buffer = malloc(0x100);			
		if (buffer != NULL) {
			result = UsbReadString(device, device->Configuration.StringIndex, buffer, 0x100);
			if (result == OK) LOGF("USBD:  -Configuration: %s.\n", buffer);	
		}
	}
	
	if (buffer != NULL) { free(buffer); buffer = NULL; }
					
	if (device->Interfaces[0].Class < InterfaceClassAttachCount &&
		InterfaceClassAttach[device->Interfaces[0].Class] != NULL) {		
		if ((result = InterfaceClassAttach[device->Interfaces[0].Class](device, 0)) != OK) {
			LOGF("USBD: Could not start the driver for %s.\n", UsbGetDescription(device));
		}
	}

	return OK;
}

Result UsbAllocateDevice(struct UsbDevice **device) {
	if ((*device = malloc(sizeof(struct UsbDevice))) == NULL)
		return ErrorMemory;

	for (uint32_t number = 0; number < MaximumDevices; number++) {
		if (Devices[number] == NULL) {
			Devices[number] = *device;
			(*device)->Number = number + 1;
			break;
		}
	}

	LOG_DEBUGF("USBD: Allocating new device, address %#x.\n", (*device)->Number);

	(*device)->Status = Attached;
	(*device)->Error = None;
	(*device)->PortNumber = 0;
	(*device)->Parent = NULL;
	(*device)->DriverData = NULL;
	(*device)->FullConfiguration = NULL;
	(*device)->ConfigurationIndex = 0xff;
	(*device)->DeviceDeallocate = NULL;
	(*device)->DeviceDetached = NULL;
	(*device)->DeviceCheckConnection = NULL;
	(*device)->DeviceCheckForChange = NULL;	
	(*device)->DeviceChildDetached = NULL;	
	(*device)->DeviceChildReset = NULL;
	return OK;
}

void UsbDeallocateDevice(struct UsbDevice *device) {
	LOG_DEBUGF("USBD: Deallocating device %d: %s.\n", device->Number, UsbGetDescription(device));
	
	if (device->DeviceDetached != NULL)
		device->DeviceDetached(device);
	if (device->DeviceDeallocate != NULL)
		device->DeviceDeallocate(device);
	
	if (device->Parent != NULL && device->Parent->DeviceChildDetached != NULL)
		device->Parent->DeviceChildDetached(device->Parent, device);

	if (device->Status == Addressed || device->Status == Configured)
		if (device->Number > 0 && device->Number <= MaximumDevices && Devices[device->Number - 1] == device)
			Devices[device->Number - 1] = NULL;
	
	if (device->FullConfiguration != NULL)
		free((void *)device->FullConfiguration);

	free(device);
}

Result UsbAttachRootHub() {
	Result result;
	struct UsbDevice *rootHub;
	LOG_DEBUG("USBD: Scanning for devices.\n");
	if (Devices[0] != NULL)
		UsbDeallocateDevice(Devices[0]);
	if ((result = UsbAllocateDevice(&rootHub)) != OK)
		return result;
		
	Devices[0]->Status = Powered;

	return UsbAttachDevice(Devices[0]);
}

void UsbCheckForChange() {
	if (Devices[0] != NULL &&
		Devices[0]->DeviceCheckForChange != NULL)
		Devices[0]->DeviceCheckForChange(Devices[0]);
}
