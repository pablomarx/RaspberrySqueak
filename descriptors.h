/******************************************************************************
*	usbd/descriptors.h
*	 by Alex Chadwick
*
*	A light weight implementation of the USB protocol stack fit for a simple
*	driver.
*
*	usbd/descriptors.h contains structures defined in the USB standard that
*	describe various aspects of USB.
******************************************************************************/
#ifndef _USBD_DESCRIPTORS_H
#define _USBD_DESCRIPTORS_H

#include "types.h"

/**
	\brief The descriptor type field from the header of USB descriptors.

	The descriptor type in the header of all USB descriptor sturctures defined
	in the USB 2.0 manual in 9.6.
*/
enum DescriptorType {
	Device = 1,
	Configuration = 2,
	String = 3,
	Interface = 4,
	Endpoint = 5,
	DeviceQualifier = 6,
	OtherSpeedConfiguration = 7,
	InterfacePower = 8,
	Hid = 33,
	HidReport = 34,
	HidPhysical = 35,	
	Hub = 41,
};

/**
	\brief The header of USB descriptor information.

	The header of all USB descriptor sturctures defined in the USB 2.0 manual 
	in 9.6.
*/
struct UsbDescriptorHeader {
	uint8_t DescriptorLength; // +0x0
	enum DescriptorType DescriptorType : 8; // +0x1
};

/**
	\brief The device descriptor information.

	The device descriptor sturcture defined in the USB 2.0 manual in 9.6.1.
*/
struct UsbDeviceDescriptor {
	uint8_t DescriptorLength; // +0x0
	enum DescriptorType DescriptorType : 8; // +0x1
	uint16_t UsbVersion; // (in BCD 0x210 = USB2.10) +0x2
	enum DeviceClass {
		DeviceClassInInterface = 0x00,
		DeviceClassCommunications = 0x2,
		DeviceClassHub = 0x9,
		DeviceClassDiagnostic = 0xdc,
		DeviceClassMiscellaneous = 0xef,
		DeviceClassVendorSpecific = 0xff,
	} Class : 8; // +0x4
	uint8_t SubClass; // +0x5
	uint8_t Protocol; // +0x6
	uint8_t MaxPacketSize0; // +0x7
	uint16_t VendorId; // +0x8
	uint16_t ProductId; // +0xa
	uint16_t Version; // +0xc
	uint8_t Manufacturer; // +0xe
	uint8_t Product; // +0xf
	uint8_t SerialNumber; // +0x10
	uint8_t ConfigurationCount; // +0x11
} __attribute__ ((__packed__));

/**
	\brief The device qualifier descriptor information.

	The device descriptor qualifier sturcture defined in the USB 2.0 manual in 
	9.6.2.
*/
struct UsbDeviceQualifierDescriptor {
	uint8_t DescriptorLength; // +0x0
	enum DescriptorType DescriptorType : 8; // +0x1
	uint16_t UsbVersion; // (in BCD 0x210 = USB2.10) +0x2
	enum DeviceClass Class : 8; // +0x4
	uint8_t SubClass; // +0x5
	uint8_t Protocol; // +0x6
	uint8_t MaxPacketSize0; // +0x7
	uint8_t ConfigurationCount; // +0x8
	uint8_t _reserved9; // +0x9
} __attribute__ ((__packed__));

/**
	\brief The configuration descriptor information.

	The configuration descriptor structure defined in the USB2.0 manual section
	9.6.3.
*/
struct UsbConfigurationDescriptor {
	uint8_t DescriptorLength; // +0x0
	enum DescriptorType DescriptorType : 8; // +0x1
	uint16_t TotalLength; // +0x2
	uint8_t InterfaceCount; // +0x4
	uint8_t ConfigurationValue; // +0x5
	uint8_t StringIndex; // +0x6
	struct {
		unsigned _reserved0_4 : 5; // @0
		bool RemoteWakeup : 1; // @5
		bool SelfPowered : 1; // @6
		unsigned _reserved7 : 1; // @7
	} Attributes; // +0x7
	uint8_t MaximumPower; // +0x8
} __attribute__ ((__packed__));

/**
	\breif The other speed configuration descriptor.

	The other speed configuration descriptor defined in the USB2.0 manual section 
	9.6.4.
*/
struct UsbOtherSpeedConfigurationDescriptor {
	uint8_t DescriptorLength; // +0x0
	enum DescriptorType DescriptorType : 8; // +0x1
	uint16_t TotalLength; // +0x2
	uint8_t InterfaceCount; // +0x4
	uint8_t ConfigurationValue; // +0x5
	uint8_t StringIndex; // +0x6
	struct {
		unsigned _reserved0_4 : 5; // @0
		bool RemoteWakeup : 1; // @5
		bool SelfPowered : 1; // @6
		enum {
			Valid = 1,
		} _reserved7 : 1; // @7
	} Attributes; // +0x7
	uint8_t MaximumPower; // +0x8
} __attribute__ ((__packed__));

/**
	\brief The interface descriptor information.

	The interface descriptor structure defined in the USB2.0 manual section 
	9.6.5.
*/
struct UsbInterfaceDescriptor {
	uint8_t DescriptorLength; // +0x0
	enum DescriptorType DescriptorType : 8; // +0x1
	uint8_t Number; // +0x2
	uint8_t AlternateSetting; // +0x3
	uint8_t EndpointCount; // +0x4
	enum InterfaceClass {
		InterfaceClassReserved = 0x0,
		InterfaceClassAudio = 0x1,
		InterfaceClassCommunications = 0x2,
		InterfaceClassHid = 0x3,
		InterfaceClassPhysical = 0x5,
		InterfaceClassImage = 0x6,
		InterfaceClassPrinter = 0x7,
		InterfaceClassMassStorage = 0x8,
		InterfaceClassHub = 0x9,
		InterfaceClassCdcData = 0xa,
		InterfaceClassSmartCard = 0xb,
		InterfaceClassContentSecurity = 0xd,
		InterfaceClassVideo = 0xe,
		InterfaceClassPersonalHealthcare = 0xf,
		InterfaceClassAudioVideo = 0x10,
		InterfaceClassDiagnosticDevice = 0xdc,
		InterfaceClassWirelessController = 0xe0,
		InterfaceClassMiscellaneous = 0xef,
		InterfaceClassApplicationSpecific = 0xfe,
		InterfaceClassVendorSpecific = 0xff,
	} Class : 8; // +x05
	uint8_t SubClass;
	uint8_t Protocol;
	uint8_t StringIndex;
} __attribute__ ((__packed__));

/**
	\brief The endpoint descriptor information.

	The endpoint descriptor structure defined in the USB2.0 manual section 
	9.6.6.
*/
struct UsbEndpointDescriptor {
	uint8_t DescriptorLength; // +0x0
	enum DescriptorType DescriptorType : 8; // +0x1
	struct {
		unsigned Number : 4; // @0
		unsigned _reserved4_6 : 3; // @4
		UsbDirection Direction : 1; // @7
	} EndpointAddress; // +0x2
	struct {
		UsbTransfer Type : 2; // @0
		enum {
			NoSynchronisation = 0,
			Asynchronous = 1,
			Adaptive = 2,
			Synchrouns = 3,
		} Synchronisation : 2; // @2
		enum {
			Data = 0,
			Feeback = 1,
			ImplicitFeebackData = 2,
		} Usage : 2; // @4
		unsigned _reserved6_7 : 2; // @6
	} Attributes; // +0x3
	struct {
		unsigned MaxSize : 11; // @0
		enum {
			None = 0,
			Extra1 = 1,
			Extra2 = 2,
		} Transactions : 2; // @11
		unsigned _reserved13_15 : 3; // @13
	} Packet; // +0x4
	uint8_t Interval; // +0x6
} __attribute__ ((__packed__));

/**
	\brief The string descriptor information.

	The string descriptor structure defined in the USB2.0 manual section 
	9.6.7.
*/
struct UsbStringDescriptor {
	uint8_t DescriptorLength; // +0x0
	enum DescriptorType DescriptorType : 8; // +0x1
	uint16_t Data[]; // +0x2 amount varies
} __attribute__ ((__packed__));

#endif // _USBD_DESCRIPTORS_H
