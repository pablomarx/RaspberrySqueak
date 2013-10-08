/******************************************************************************
*	hcd/dwc/designware20.c
*	 by Alex Chadwick
*
*	A light weight implementation of the USB protocol stack fit for a simple
*	driver.
*
*	hcd/dwc/designware20.c contains code to control the DesignWare® Hi-Speed
*	USB 2.0 On-The-Go (HS OTG) Controller.
*
*	THIS SOFTWARE IS NOT AFFILIATED WITH NOR ENDORSED BY SYNOPSYS IP.
******************************************************************************/
#include "hcd.h"
#include "types.h"
#include "device.h"
#include "devicerequest.h"
#include "pipe.h"
#include "usbd.h"

#ifndef HCD_DESIGNWARE_BASE
#error Missing required definition HCD_DESIGNWARE_BASE. Should be of the form ((void*)0xhhhhhhhh). Should be defined after HCD_DESIGNWARE_20 in the platform.
#endif

volatile struct CoreGlobalRegs *CorePhysical, *Core = NULL;
volatile struct HostGlobalRegs *HostPhysical, *Host = NULL;
volatile struct PowerReg *PowerPhysical, *Power = NULL;
bool PhyInitialised = false;
uint8_t* databuffer = NULL;

void DwcLoad() 
{
	LOG_DEBUG("CSUD: DesignWare Hi-Speed USB 2.0 On-The-Go (HS OTG) Controller driver version 0.1\n"); 
}

void WriteThroughReg(volatile const void* reg) {
	WriteThroughRegMask(reg, 0);
}
void WriteThroughRegMask(volatile const void* reg, uint32_t maskOr) {
	if ((uint32_t)reg - (uint32_t)Core < sizeof(struct CoreGlobalRegs)) {
		maskOr |= 0xffffffff;
		*(uint32_t*)((uint32_t)reg - (uint32_t)Core + (uint32_t)CorePhysical) = *((uint32_t*)reg) & maskOr;
	} else if ((uint32_t)reg - (uint32_t)Host < sizeof(struct HostGlobalRegs)) {
		switch ((uint32_t)reg - (uint32_t)Host) {
		case 0x40: // Host->Port
			maskOr |= 0x1f140;
			break;
		default:
			maskOr |= 0xffffffff;
			break;
		}
		*(uint32_t*)((uint32_t)reg - (uint32_t)Host + (uint32_t)HostPhysical) = *((uint32_t*)reg) & maskOr;
	} else if ((uint32_t)reg == (uint32_t)Power) {
		maskOr |= 0xffffffff;
		*(uint32_t*)PowerPhysical = *(uint32_t*)Power & maskOr;
	}
}
void ReadBackReg(volatile const void* reg) {
	if ((uint32_t)reg - (uint32_t)Core < sizeof(struct CoreGlobalRegs)) {
		switch ((uint32_t)reg - (uint32_t)Core) {
		case 0x44: // Core->Hardware
			*((uint32_t*)reg + 0) = *((uint32_t*)((uint32_t)reg - (uint32_t)Core + (uint32_t)CorePhysical) + 0);
			*((uint32_t*)reg + 1) = *((uint32_t*)((uint32_t)reg - (uint32_t)Core + (uint32_t)CorePhysical) + 1);
			*((uint32_t*)reg + 2) = *((uint32_t*)((uint32_t)reg - (uint32_t)Core + (uint32_t)CorePhysical) + 2);
			*((uint32_t*)reg + 3) = *((uint32_t*)((uint32_t)reg - (uint32_t)Core + (uint32_t)CorePhysical) + 3);
			break;
		default:
			*(uint32_t*)reg = *(uint32_t*)((uint32_t)reg - (uint32_t)Core + (uint32_t)CorePhysical);
		}
	} else if ((uint32_t)reg - (uint32_t)Host < sizeof(struct HostGlobalRegs)) {
		*(uint32_t*)reg = *(uint32_t*)((uint32_t)reg - (uint32_t)Host + (uint32_t)HostPhysical);
	} else if ((uint32_t)reg == (uint32_t)Power) {
		*(uint32_t*)Power = *(uint32_t*)PowerPhysical;
	}
}
void ClearReg(volatile const void* reg) {
	if ((uint32_t)reg - (uint32_t)Core < sizeof(struct CoreGlobalRegs)) {
		switch ((uint32_t)reg - (uint32_t)Core) {
		case 0x44: // Core->Hardware
			*((uint32_t*)reg + 0) = 0;
			*((uint32_t*)reg + 1) = 0;
			*((uint32_t*)reg + 2) = 0;
			*((uint32_t*)reg + 3) = 0;
			break;
		default:
			*(uint32_t*)reg = 0;
		}
	} else if ((uint32_t)reg - (uint32_t)Host < sizeof(struct HostGlobalRegs)) {
		*(uint32_t*)reg = 0;
	} else if ((uint32_t)reg == (uint32_t)Power) {
		*(uint32_t*)Power = 0;
	}
}
void SetReg(volatile const void* reg) {
	uint32_t value;
	if ((uint32_t)reg - (uint32_t)Core < sizeof(struct CoreGlobalRegs)) {
		value = 0xffffffff;
		switch ((uint32_t)reg - (uint32_t)Core) {
		case 0x44: // Core->Hardware
			*((uint32_t*)reg + 0) = value;
			*((uint32_t*)reg + 1) = value;
			*((uint32_t*)reg + 2) = value;
			*((uint32_t*)reg + 3) = value;
			break;
		default:
			*(uint32_t*)reg = value;
		}
	} else if ((uint32_t)reg - (uint32_t)Host < sizeof(struct HostGlobalRegs)) {
		if ((uint32_t)reg - (uint32_t)Host > 0x100 && (uint32_t)reg - (uint32_t)Host < 0x300) {
			switch (((uint32_t)reg - (uint32_t)Host) & 0x1f) {
			case 0x8:
				value = 0x3fff;
				break;
			default:
				value = 0xffffffff;
				break;
			}
		} else
			value = 0xffffffff;

		*(uint32_t*)reg = value;
	} else if ((uint32_t)reg == (uint32_t)Power) {
		value = 0xffffffff;
		*(uint32_t*)Power = value;
	}
}


/** 
	\brief Triggers the core soft reset.

	Raises the core soft reset signal high, and then waits for the core to 
	signal that it is ready again.
*/
Result HcdReset() {
	uint32_t count = 0;
	
	do {
		ReadBackReg(&Core->Reset);
		if (count++ >= 0x100000) {
			LOG("HCD: Device Hang!\n");
			return ErrorDevice;
		}
	} while (Core->Reset.AhbMasterIdle == false);

	Core->Reset.CoreSoft = true;
	WriteThroughReg(&Core->Reset);
	count = 0;
	
	do {
		ReadBackReg(&Core->Reset);
		if (count++ >= 0x100000) {
			LOG("HCD: Device Hang!\n");
			return ErrorDevice;
		}
	} while (Core->Reset.CoreSoft == true || Core->Reset.AhbMasterIdle == false);

	return OK;
}

/** 
	\brief Triggers the fifo flush for a given fifo.

	Raises the core fifo flush signal high, and then waits for the core to 
	signal that it is ready again.
*/
Result HcdTransmitFifoFlush(enum CoreFifoFlush fifo) {
	uint32_t count = 0;
	
	if (fifo == FlushAll)
		LOG_DEBUG("HCD: TXFlush(All)\n");
	else if (fifo == FlushNonPeriodic)
		LOG_DEBUG("HCD: TXFlush(NP)\n");
	else
		LOG_DEBUGF("HCD: TXFlush(P%u)\n", fifo);

	ClearReg(&Core->Reset);
	Core->Reset.TransmitFifoFlushNumber = fifo;
	Core->Reset.TransmitFifoFlush = true;
	WriteThroughReg(&Core->Reset);
	count = 0;
	
	do {
		ReadBackReg(&Core->Reset);
		if (count++ >= 0x100000) {
			LOG("HCD: Device Hang!\n");
			return ErrorDevice;
		}
	} while (Core->Reset.TransmitFifoFlush == true);

	return OK;
}

/** 
	\brief Triggers the receive fifo flush for a given fifo.

	Raises the core receive fifo flush signal high, and then waits for the core to 
	signal that it is ready again.
*/
Result HcdReceiveFifoFlush() {
	uint32_t count = 0;
	
	LOG_DEBUG("HCD: RXFlush(All)\n");
	
	ClearReg(&Core->Reset);
	Core->Reset.ReceiveFifoFlush = true;
	WriteThroughReg(&Core->Reset);
	count = 0;
	
	do {
		ReadBackReg(&Core->Reset);
		if (count++ >= 0x100000) {
			LOG("HCD: Device Hang!\n");
			return ErrorDevice;
		}
	} while (Core->Reset.ReceiveFifoFlush == true);

	return OK;
}

/**
	\brief Prepares a channel to communicated with a device.

	Prepares a channel to communicated with the device specified in pipe.
*/
Result HcdPrepareChannel(struct UsbDevice *device, uint8_t channel,
	uint32_t length, enum PacketId type, struct UsbPipeAddress *pipe) {
	if (channel > Core->Hardware.HostChannelCount) {
		LOGF("HCD: Channel %d is not available on this host.\n", channel);
		return ErrorArgument;
	}

	// Clear all existing interrupts.
	SetReg(&Host->Channel[channel].Interrupt);
	WriteThroughReg(&Host->Channel[channel].Interrupt);

	// Program the channel.
	ClearReg(&Host->Channel[channel].Characteristic);
	Host->Channel[channel].Characteristic.DeviceAddress = pipe->Device;
	Host->Channel[channel].Characteristic.EndPointNumber = pipe->EndPoint;
	Host->Channel[channel].Characteristic.EndPointDirection = pipe->Direction;
	Host->Channel[channel].Characteristic.LowSpeed = pipe->Speed == Low ? true : false;
	Host->Channel[channel].Characteristic.Type = pipe->Type;
	Host->Channel[channel].Characteristic.MaximumPacketSize = SizeToNumber(pipe->MaxSize);
	Host->Channel[channel].Characteristic.Enable = false;
	Host->Channel[channel].Characteristic.Disable = false;
	WriteThroughReg(&Host->Channel[channel].Characteristic);

	// Clear split control.
	ClearReg(&Host->Channel[channel].SplitControl);
	if (pipe->Speed != High) {
		Host->Channel[channel].SplitControl.SplitEnable = true;
		Host->Channel[channel].SplitControl.HubAddress = device->Parent->Number;
		Host->Channel[channel].SplitControl.PortAddress = device->PortNumber;			
	}
	WriteThroughReg(&Host->Channel[channel].SplitControl);

	ClearReg(&Host->Channel[channel].TransferSize);
	Host->Channel[channel].TransferSize.TransferSize = length;
	if (pipe->Speed == Low)
		Host->Channel[channel].TransferSize.PacketCount = (length + 7) / 8;
	else
		Host->Channel[channel].TransferSize.PacketCount = (length + Host->Channel[channel].Characteristic.MaximumPacketSize -  1) / Host->Channel[channel].Characteristic.MaximumPacketSize;
	if (Host->Channel[channel].TransferSize.PacketCount == 0)
		Host->Channel[channel].TransferSize.PacketCount = 1;
	Host->Channel[channel].TransferSize.PacketId = type;
	WriteThroughReg(&Host->Channel[channel].TransferSize);
	
	return OK;
}

void HcdTransmitChannel(uint8_t channel, void* buffer) {	
	ReadBackReg(&Host->Channel[channel].SplitControl);
	Host->Channel[channel].SplitControl.CompleteSplit = false;
	WriteThroughReg(&Host->Channel[channel].SplitControl);

	if (((uint32_t)buffer & 3) != 0)
		LOG_DEBUGF("HCD: Transfer buffer 0x%08x is not DWORD aligned. Ignored, but dangerous.\n", buffer);
	Host->Channel[channel].DmaAddress = buffer;
	WriteThroughReg(&Host->Channel[channel].DmaAddress);

	ReadBackReg(&Host->Channel[channel].Characteristic);
	Host->Channel[channel].Characteristic.PacketsPerFrame = 1;
	Host->Channel[channel].Characteristic.Enable = true;
	Host->Channel[channel].Characteristic.Disable = false;
	WriteThroughReg(&Host->Channel[channel].Characteristic);	
}

Result HcdChannelInterruptToError(struct UsbDevice *device, struct ChannelInterrupts interrupts, bool isComplete) {
	Result result;

	result = OK;
	if (interrupts.AhbError) {
		device->Error = AhbError;
		LOG("HCD: AHB error in transfer.\n");
		return ErrorDevice;
	}
	if (interrupts.Stall) {
		device->Error =  Stall;
		LOG("HCD: Stall error in transfer.\n");
		return ErrorDevice;
	}
	if (interrupts.NegativeAcknowledgement) {
		device->Error =  NoAcknowledge;
		LOG("HCD: NAK error in transfer.\n");
		return ErrorDevice;
	}
	if (!interrupts.Acknowledgement) {
		LOG("HCD: Transfer was not acknowledged.\n");
		result = ErrorTimeout;
	}
	if (interrupts.NotYet) {
		device->Error =  NotYetError;
		LOG("HCD: Not yet error in transfer.\n");
		return ErrorDevice;
	}
	if (interrupts.BabbleError) {
		device->Error =  Babble;
		LOG("HCD: Babble error in transfer.\n");
		return ErrorDevice;
	}
	if (interrupts.FrameOverrun) {
		device->Error =  BufferError;
		LOG("HCD: Frame overrun in transfer.\n");
		return ErrorDevice;
	}
	if (interrupts.DataToggleError) {
		device->Error =  BitError;
		LOG("HCD: Data toggle error in transfer.\n");
		return ErrorDevice;
	}
	if (interrupts.TransactionError) {
		device->Error =  ConnectionError;
		LOG("HCD: Transaction error in transfer.\n");
		return ErrorDevice;
	}
	if (!interrupts.TransferComplete && isComplete) {
		LOG("HCD: Transfer did not complete.\n");
		result = ErrorTimeout;
	}
	return result;
}

Result HcdChannelSendWaitOne(struct UsbDevice *device, 
	struct UsbPipeAddress *pipe, uint8_t channel, void* buffer, uint32_t bufferLength, uint32_t bufferOffset,
	struct UsbDeviceRequest *request) {
	Result result;
	uint32_t timeout, tries, globalTries, actualTries;
	
	for (globalTries = 0, actualTries = 0; globalTries < 3 && actualTries < 10; globalTries++, actualTries++) {
		SetReg(&Host->Channel[channel].Interrupt);
		WriteThroughReg(&Host->Channel[channel].Interrupt);
		ReadBackReg(&Host->Channel[channel].TransferSize);
		ReadBackReg(&Host->Channel[channel].SplitControl);
						
		HcdTransmitChannel(channel, (uint8_t*)buffer + bufferOffset);

		timeout = 0;
		do {
			if (timeout++ == RequestTimeout) {
				LOGF("HCD: Request to %s has timed out.\n", UsbGetDescription(device));
				device->Error = ConnectionError;
				return ErrorTimeout;
			}
			ReadBackReg(&Host->Channel[channel].Interrupt);
			if (!Host->Channel[channel].Interrupt.Halt) MicroDelay(10);
			else break;
		} while (true);
		ReadBackReg(&Host->Channel[channel].TransferSize);
		
		if (Host->Channel[channel].SplitControl.SplitEnable) {
			if (Host->Channel[channel].Interrupt.Acknowledgement) {
				for (tries = 0; tries < 3; tries++) {
					SetReg(&Host->Channel[channel].Interrupt);
					WriteThroughReg(&Host->Channel[channel].Interrupt);

					ReadBackReg(&Host->Channel[channel].SplitControl);
					Host->Channel[channel].SplitControl.CompleteSplit = true;
					WriteThroughReg(&Host->Channel[channel].SplitControl);
					
					Host->Channel[channel].Characteristic.Enable = true;
					Host->Channel[channel].Characteristic.Disable = false;
					WriteThroughReg(&Host->Channel[channel].Characteristic);

					timeout = 0;
					do {
						if (timeout++ == RequestTimeout) {
							LOGF("HCD: Request split completion to %s has timed out.\n", UsbGetDescription(device));
							device->Error = ConnectionError;
							return ErrorTimeout;
						}
						ReadBackReg(&Host->Channel[channel].Interrupt);
						if (!Host->Channel[channel].Interrupt.Halt) MicroDelay(100);
						else break;
					} while (true);
					if (!Host->Channel[channel].Interrupt.NotYet) break;
				}

				if (tries == 3) {
					MicroDelay(25000);
					continue;
				} else if (Host->Channel[channel].Interrupt.NegativeAcknowledgement) {
					globalTries--;
					MicroDelay(25000);
					continue;
				} else if (Host->Channel[channel].Interrupt.TransactionError) {
					MicroDelay(25000);
					continue;
				} 
	
				if ((result = HcdChannelInterruptToError(device, Host->Channel[channel].Interrupt, false)) != OK) {
					LOG_DEBUGF("HCD: Control message to 0x%08x: %02x%02x%02x%02x %02x%02x%02x%02x.\n", *(uint32_t*)pipe, 
						((uint8_t*)request)[0], ((uint8_t*)request)[1], ((uint8_t*)request)[2], ((uint8_t*)request)[3],
						((uint8_t*)request)[4], ((uint8_t*)request)[5], ((uint8_t*)request)[6], ((uint8_t*)request)[7]);
					LOGF("HCD: Request split completion to %s failed.\n", UsbGetDescription(device));
					return result;
				}
			} else if (Host->Channel[channel].Interrupt.NegativeAcknowledgement) {
				globalTries--;
				MicroDelay(25000);
				continue;
			} else if (Host->Channel[channel].Interrupt.TransactionError) {
				MicroDelay(25000);
				continue;
			}				
		} else {				
			if ((result = HcdChannelInterruptToError(device, Host->Channel[channel].Interrupt, !Host->Channel[channel].SplitControl.SplitEnable)) != OK) {
				LOG_DEBUGF("HCD: Control message to 0x%08x: %02x%02x%02x%02x %02x%02x%02x%02x.\n", *(uint32_t*)pipe, 
					((uint8_t*)request)[0], ((uint8_t*)request)[1], ((uint8_t*)request)[2], ((uint8_t*)request)[3],
					((uint8_t*)request)[4], ((uint8_t*)request)[5], ((uint8_t*)request)[6], ((uint8_t*)request)[7]);
				LOGF("HCD: Request to %s failed.\n", UsbGetDescription(device));
				return ErrorRetry;
			}
		}

		break;
	}

	if (globalTries == 3 || actualTries == 10) {
		LOGF("HCD: Request to %s has failed 3 times.\n", UsbGetDescription(device));
		if ((result = HcdChannelInterruptToError(device, Host->Channel[channel].Interrupt, !Host->Channel[channel].SplitControl.SplitEnable)) != OK) {
			LOG_DEBUGF("HCD: Control message to 0x%08x: %02x%02x%02x%02x %02x%02x%02x%02x.\n", *(uint32_t*)pipe, 
				((uint8_t*)request)[0], ((uint8_t*)request)[1], ((uint8_t*)request)[2], ((uint8_t*)request)[3],
				((uint8_t*)request)[4], ((uint8_t*)request)[5], ((uint8_t*)request)[6], ((uint8_t*)request)[7]);
			LOGF("HCD: Request to %s failed.\n", UsbGetDescription(device));
			return result;
		}
		device->Error = ConnectionError;
		return ErrorTimeout;
	}

	return OK;
}

Result HcdChannelSendWait(struct UsbDevice *device, 
	struct UsbPipeAddress *pipe, uint8_t channel, void* buffer, uint32_t bufferLength, 
	struct UsbDeviceRequest *request, enum PacketId packetId) {
	Result result;
	uint32_t packets, transfer, tries;
	
	tries = 0;
retry:
	if (tries++ == 3) {
		LOGF("HCD: Failed to send to %s after 3 attempts.\n", UsbGetDescription(device));
		return ErrorTimeout;
	} 

	if ((result = HcdPrepareChannel(device, channel, bufferLength, packetId, pipe)) != OK) {		
		device->Error = ConnectionError;
		LOGF("HCD: Could not prepare data channel to %s.\n", UsbGetDescription(device));
		return result;
	}
		
	transfer = 0;
	do {
		packets = Host->Channel[channel].TransferSize.PacketCount;
		if ((result = HcdChannelSendWaitOne(device, pipe, channel, buffer, bufferLength, transfer, request)) != OK) {
			if (result == ErrorRetry) goto retry;
			return result;
		}
		
		ReadBackReg(&Host->Channel[channel].TransferSize);		
		transfer = bufferLength - Host->Channel[channel].TransferSize.TransferSize;
		if (packets == Host->Channel[channel].TransferSize.PacketCount) break;
	} while (Host->Channel[channel].TransferSize.PacketCount > 0);

	if (packets == Host->Channel[channel].TransferSize.PacketCount) {
		device->Error = ConnectionError;
		LOGF("HCD: Transfer to %s got stuck.\n", UsbGetDescription(device));
		return ErrorDevice;
	}

	if (tries > 1) {
		LOGF("HCD: Transfer to %s succeeded on attempt %d/3.\n", UsbGetDescription(device), tries);
	}

	return OK;
}

Result HcdSumbitControlMessage(struct UsbDevice *device, 
	struct UsbPipeAddress pipe, void* buffer, uint32_t bufferLength,
	struct UsbDeviceRequest *request) {
	Result result;
	struct UsbPipeAddress tempPipe;
	if (pipe.Device == RootHubDeviceNumber) {
		return HcdProcessRootHubMessage(device, pipe, buffer, bufferLength, request);
	}

	device->Error = Processing;
	device->LastTransfer = 0;
			
	// Setup
	tempPipe.Speed = pipe.Speed;
	tempPipe.Device = pipe.Device;
	tempPipe.EndPoint = pipe.EndPoint;
	tempPipe.MaxSize = pipe.MaxSize;
	tempPipe.Type = Control;
	tempPipe.Direction = Out;
	
	if ((result = HcdChannelSendWait(device, &tempPipe, 0, request, 8, request, Setup)) != OK) {		
		LOGF("HCD: Could not send SETUP to %s.\n", UsbGetDescription(device));
		return OK;
	}

	// Data
	if (buffer != NULL) {
		if (pipe.Direction == Out) {
			memcpy(databuffer, buffer, bufferLength);
		}
		tempPipe.Speed = pipe.Speed;
		tempPipe.Device = pipe.Device;
		tempPipe.EndPoint = pipe.EndPoint;
		tempPipe.MaxSize = pipe.MaxSize;
		tempPipe.Type = Control;
		tempPipe.Direction = pipe.Direction;
		
		if ((result = HcdChannelSendWait(device, &tempPipe, 0, databuffer, bufferLength, request, Data1)) != OK) {		
			LOGF("HCD: Could not send DATA to %s.\n", UsbGetDescription(device));
			return OK;
		}
						
		ReadBackReg(&Host->Channel[0].TransferSize);
		if (pipe.Direction == In) {
			if (Host->Channel[0].TransferSize.TransferSize <= bufferLength)
				device->LastTransfer = bufferLength - Host->Channel[0].TransferSize.TransferSize;
			else{
				LOG_DEBUGF("HCD: Weird transfer.. %d/%d bytes received.\n", Host->Channel[0].TransferSize.TransferSize, bufferLength);
				LOG_DEBUGF("HCD: Message %02x%02x%02x%02x %02x%02x%02x%02x %02x%02x%02x%02x %02x%02x%02x%02x ...\n", 
					((uint8_t*)databuffer)[0x0],((uint8_t*)databuffer)[0x1],((uint8_t*)databuffer)[0x2],((uint8_t*)databuffer)[0x3],
					((uint8_t*)databuffer)[0x4],((uint8_t*)databuffer)[0x5],((uint8_t*)databuffer)[0x6],((uint8_t*)databuffer)[0x7],
					((uint8_t*)databuffer)[0x8],((uint8_t*)databuffer)[0x9],((uint8_t*)databuffer)[0xa],((uint8_t*)databuffer)[0xb],
					((uint8_t*)databuffer)[0xc],((uint8_t*)databuffer)[0xd],((uint8_t*)databuffer)[0xe],((uint8_t*)databuffer)[0xf]);
				device->LastTransfer = bufferLength;
			}
			memcpy(buffer, databuffer, device->LastTransfer);
		}
		else {
			device->LastTransfer = bufferLength;
		}
	}

	// Status
	tempPipe.Speed = pipe.Speed;
	tempPipe.Device = pipe.Device;
	tempPipe.EndPoint = pipe.EndPoint;
	tempPipe.MaxSize = pipe.MaxSize;
	tempPipe.Type = Control;
	tempPipe.Direction = ((bufferLength == 0) || pipe.Direction == Out) ? In : Out;
	
	if ((result = HcdChannelSendWait(device, &tempPipe, 0, databuffer, 0, request, Data1)) != OK) {		
		LOGF("HCD: Could not send STATUS to %s.\n", UsbGetDescription(device));
		return OK;
	}

	ReadBackReg(&Host->Channel[0].TransferSize);
	if (Host->Channel[0].TransferSize.TransferSize != 0)
		LOG_DEBUGF("HCD: Warning non zero status transfer! %d.\n", Host->Channel[0].TransferSize.TransferSize);

	device->Error = NoError;

	return OK;
}
	
Result HcdInitialise() {	
	volatile Result result;

	if (sizeof(struct CoreGlobalRegs) != 0x400 || sizeof(struct HostGlobalRegs) != 0x400 || sizeof(struct PowerReg) != 0x4) {
		LOGF("HCD: Incorrectly compiled driver. HostGlobalRegs: 0x%08x (0x400), CoreGlobalRegs: 0x%08x (0x400), PowerReg: 0x%08x (0x4).\n", 
			sizeof(struct HostGlobalRegs), sizeof(struct CoreGlobalRegs), sizeof(struct PowerReg));
		return ErrorCompiler; // Correct packing settings are required.
	}
	LOG_DEBUG("HCD: Reserving memory.\n");
        CorePhysical = MemoryReserve(sizeof(struct CoreGlobalRegs), HCD_DESIGNWARE_BASE);
        Core = malloc(sizeof(struct CoreGlobalRegs));

        HostPhysical = MemoryReserve(sizeof(struct HostGlobalRegs), (void*)((uint8_t*)HCD_DESIGNWARE_BASE + 0x400));
        Host = malloc(sizeof(struct HostGlobalRegs));

        PowerPhysical = MemoryReserve(sizeof(struct PowerReg), (void*)((uint8_t*)HCD_DESIGNWARE_BASE + 0xe00));
        Power = malloc(sizeof(struct PowerReg));

#ifdef BROADCOM_2835
	ReadBackReg(&Core->VendorId);
	ReadBackReg(&Core->UserId);
	if ((Core->VendorId & 0xfffff000) != 0x4f542000) { // 'OT'2 
		LOGF("HCD: Hardware: %c%c%x.%x%x%x (BCM%.5x). Driver incompatible. Expected OT2.xxx (BCM2708x).\n",
			(Core->VendorId >> 24) & 0xff, (Core->VendorId >> 16) & 0xff,
			(Core->VendorId >> 12) & 0xf, (Core->VendorId >> 8) & 0xf,
			(Core->VendorId >> 4) & 0xf, (Core->VendorId >> 0) & 0xf, 
			(Core->UserId >> 12) & 0xFFFFF);
		result = ErrorIncompatible;
		goto deallocate;
	}
	else {
		LOGF("HCD: Hardware: %c%c%x.%x%x%x (BCM%.5x).\n",
			(Core->VendorId >> 24) & 0xff, (Core->VendorId >> 16) & 0xff,
			(Core->VendorId >> 12) & 0xf, (Core->VendorId >> 8) & 0xf,
			(Core->VendorId >> 4) & 0xf, (Core->VendorId >> 0) & 0xf, 
			(Core->UserId >> 12) & 0xFFFFF);
	}
#else
	if ((Core->VendorId & 0xfffff000) != 0x4f542000) { // 'OT'2 
		LOGF("HCD: Hardware: %c%c%x.%x%x%x. Driver incompatible. Expected OT2.xxx.\n",
			(Core->VendorId >> 24) & 0xff, (Core->VendorId >> 16) & 0xff,
			(Core->VendorId >> 12) & 0xf, (Core->VendorId >> 8) & 0xf,
			(Core->VendorId >> 4) & 0xf, (Core->VendorId >> 0) & 0xf);
		return ErrorIncompatible;
	}
	else {
		LOGF("HCD: Hardware: %c%c%x.%x%x%x.\n",
			(Core->VendorId >> 24) & 0xff, (Core->VendorId >> 16) & 0xff,
			(Core->VendorId >> 12) & 0xf, (Core->VendorId >> 8) & 0xf,
			(Core->VendorId >> 4) & 0xf, (Core->VendorId >> 0) & 0xf);
	}
#endif

	ReadBackReg(&Core->Hardware);
	if (Core->Hardware.Architecture != InternalDma) {
		LOG("HCD: Host architecture is not Internal DMA. Driver incompatible.\n");
		result = ErrorIncompatible;
		goto deallocate;
	}
	LOG_DEBUG("HCD: Internal DMA mode.\n");
	if (Core->Hardware.HighSpeedPhysical == NotSupported) {
		LOG("HCD: High speed physical unsupported. Driver incompatible.\n");
		result = ErrorIncompatible;
		goto deallocate;
	}
	LOG_DEBUGF("HCD: Hardware configuration: %08x %08x %08x %08x\n", *(uint32_t*)&Core->Hardware, *((uint32_t*)&Core->Hardware + 1), *((uint32_t*)&Core->Hardware + 2), *((uint32_t*)&Core->Hardware + 3));
	ReadBackReg(&Host->Config);
	LOG_DEBUGF("HCD: Host configuration: %08x\n", *(uint32_t*)&Host->Config);
	
	LOG_DEBUG("HCD: Disabling interrupts.\n");
	ReadBackReg(&Core->Ahb);
	Core->Ahb.InterruptEnable = false;
	ClearReg(&Core->InterruptMask);
	WriteThroughReg(&Core->InterruptMask);
	WriteThroughReg(&Core->Ahb);
	
	LOG_DEBUG("HCD: Powering USB on.\n");
	if ((result = PowerOnUsb()) != OK) {
		LOG("HCD: Failed to power on USB Host Controller.\n");
		result = ErrorIncompatible;
		goto deallocate;
	}
	
	LOG_DEBUG("HCD: Load completed.\n");

	return OK;
deallocate:
	if (Core != NULL) free((void *)Core);
	if (Host != NULL) free((void *)Host);
	if (Power != NULL) free((void *)Power);
	return result;
}

Result HcdStart() {	
	Result result;
	uint32_t timeout;

	LOG_DEBUG("HCD: Start core.\n");
	if (Core == NULL) {
		LOG("HCD: HCD uninitialised. Cannot be started.\n");
		return ErrorDevice;
	}

	if ((databuffer = malloc(1024)) == NULL)
		return ErrorMemory;

	ReadBackReg(&Core->Usb);
	Core->Usb.UlpiDriveExternalVbus = 0;
	Core->Usb.TsDlinePulseEnable = 0;
	WriteThroughReg(&Core->Usb);
	
	LOG_DEBUG("HCD: Master reset.\n");
	if ((result = HcdReset()) != OK) {
		goto deallocate;
	}
	
	if (!PhyInitialised) {
		LOG_DEBUG("HCD: One time phy initialisation.\n");
		PhyInitialised = true;

		Core->Usb.ModeSelect = UTMI;
		LOG_DEBUG("HCD: Interface: UTMI+.\n");
		Core->Usb.PhyInterface = false;

		WriteThroughReg(&Core->Usb);
		HcdReset();
	}

	ReadBackReg(&Core->Usb);
	if (Core->Hardware.HighSpeedPhysical == Ulpi
		&& Core->Hardware.FullSpeedPhysical == Dedicated) {
		LOG_DEBUG("HCD: ULPI FSLS configuration: enabled.\n");
		Core->Usb.UlpiFsls = true;
		Core->Usb.ulpi_clk_sus_m = true;
	} else {
		LOG_DEBUG("HCD: ULPI FSLS configuration: disabled.\n");
		Core->Usb.UlpiFsls = false;
		Core->Usb.ulpi_clk_sus_m = false;
	}
	WriteThroughReg(&Core->Usb);

	LOG_DEBUG("HCD: DMA configuration: enabled.\n");
	ReadBackReg(&Core->Ahb);
	Core->Ahb.DmaEnable = true;
	Core->Ahb.DmaRemainderMode = Incremental;
	WriteThroughReg(&Core->Ahb);
	
	ReadBackReg(&Core->Usb);
	switch (Core->Hardware.OperatingMode) {
	case HNP_SRP_CAPABLE:
		LOG_DEBUG("HCD: HNP/SRP configuration: HNP, SRP.\n");
		Core->Usb.HnpCapable = true;
		Core->Usb.SrpCapable = true;
		break;
	case SRP_ONLY_CAPABLE:
	case SRP_CAPABLE_DEVICE:
	case SRP_CAPABLE_HOST:
		LOG_DEBUG("HCD: HNP/SRP configuration: SRP.\n");
		Core->Usb.HnpCapable = false;
		Core->Usb.SrpCapable = true;
		break;
	case NO_HNP_SRP_CAPABLE:
	case NO_SRP_CAPABLE_DEVICE:
	case NO_SRP_CAPABLE_HOST:
		LOG_DEBUG("HCD: HNP/SRP configuration: none.\n");
		Core->Usb.HnpCapable = false;
		Core->Usb.SrpCapable = false;
		break;
	}
	WriteThroughReg(&Core->Usb);
	LOG_DEBUG("HCD: Core started.\n");
	LOG_DEBUG("HCD: Starting host.\n");

	ClearReg(Power);
	WriteThroughReg(Power);

	ReadBackReg(&Host->Config);
	if (Core->Hardware.HighSpeedPhysical == Ulpi
		&& Core->Hardware.FullSpeedPhysical == Dedicated
		&& Core->Usb.UlpiFsls) {
		LOG_DEBUG("HCD: Host clock: 48Mhz.\n");
		Host->Config.ClockRate = Clock48MHz;
	} else {
		LOG_DEBUG("HCD: Host clock: 30-60Mhz.\n");
		Host->Config.ClockRate = Clock30_60MHz;
	}
	WriteThroughReg(&Host->Config);

	ReadBackReg(&Host->Config);
	Host->Config.FslsOnly = true;
	WriteThroughReg(&Host->Config);
		
	ReadBackReg(&Host->Config);
	if (Host->Config.EnableDmaDescriptor == 
		Core->Hardware.DmaDescription &&
		(Core->VendorId & 0xfff) >= 0x90a) {
		LOG_DEBUG("HCD: DMA descriptor: enabled.\n");
	} else {
		LOG_DEBUG("HCD: DMA descriptor: disabled.\n");
	}
	WriteThroughReg(&Host->Config);
		
	LOG_DEBUGF("HCD: FIFO configuration: Total=0x%08x Rx=0x%08x NPTx=0x%08x PTx=0x%08x.\n", ReceiveFifoSize + NonPeriodicFifoSize + PeriodicFifoSize, ReceiveFifoSize, NonPeriodicFifoSize, PeriodicFifoSize);
	ReadBackReg(&Core->Receive.Size);
	Core->Receive.Size = ReceiveFifoSize;
	WriteThroughReg(&Core->Receive.Size);

	ReadBackReg(&Core->NonPeriodicFifo.Size);
	Core->NonPeriodicFifo.Size.Depth = NonPeriodicFifoSize;
	Core->NonPeriodicFifo.Size.StartAddress = ReceiveFifoSize;
	WriteThroughReg(&Core->NonPeriodicFifo.Size);

	ReadBackReg(&Core->PeriodicFifo.HostSize);
	Core->PeriodicFifo.HostSize.Depth = PeriodicFifoSize;
	Core->PeriodicFifo.HostSize.StartAddress = ReceiveFifoSize + NonPeriodicFifoSize;
	WriteThroughReg(&Core->PeriodicFifo.HostSize);

	LOG_DEBUG("HCD: Set HNP: enabled.\n");
	ReadBackReg(&Core->OtgControl);
	Core->OtgControl.HostSetHnpEnable = true;
	WriteThroughReg(&Core->OtgControl);

	if ((result = HcdTransmitFifoFlush(FlushAll)) != OK) 
		goto deallocate;
	if ((result = HcdReceiveFifoFlush()) != OK)
		goto deallocate;

	if (!Host->Config.EnableDmaDescriptor) {
		for (uint32_t channel = 0; channel < Core->Hardware.HostChannelCount; channel++) {
			ReadBackReg(&Host->Channel[channel].Characteristic);
			Host->Channel[channel].Characteristic.Enable = false;
			Host->Channel[channel].Characteristic.Disable = true;
			Host->Channel[channel].Characteristic.EndPointDirection = In;
			WriteThroughReg(&Host->Channel[channel].Characteristic);
			timeout = 0;
		}

		// Halt channels to put them into known state.
		for (uint32_t channel = 0; channel < Core->Hardware.HostChannelCount; channel++) {
			ReadBackReg(&Host->Channel[channel].Characteristic);
			Host->Channel[channel].Characteristic.Enable = true;
			Host->Channel[channel].Characteristic.Disable = true;
			Host->Channel[channel].Characteristic.EndPointDirection = In;
			WriteThroughReg(&Host->Channel[channel].Characteristic);
			timeout = 0;
			do {
				ReadBackReg(&Host->Channel[channel].Characteristic);

				if (timeout++ > 0x100000) {
					LOGF("HCD: Unable to clear halt on channel %u.\n", channel);
				}
			} while (Host->Channel[channel].Characteristic.Enable);
		}
	}

	ReadBackReg(&Host->Port);
	if (!Host->Port.Power) {
		LOG_DEBUG("HCD: Powering up port.\n");
		Host->Port.Power = true;
		WriteThroughRegMask(&Host->Port, 0x1000);
	}
	
	LOG_DEBUG("HCD: Reset port.\n");
	ReadBackReg(&Host->Port);
	Host->Port.Reset = true;
	WriteThroughRegMask(&Host->Port, 0x100);
	MicroDelay(50000);
	Host->Port.Reset = false;
	WriteThroughRegMask(&Host->Port, 0x100);
	ReadBackReg(&Host->Port);
	
	LOG_DEBUG("HCD: Successfully started.\n");
		
	return OK;
deallocate:
	free(databuffer);
	return result;
}

Result HcdStop() {
	if (databuffer != NULL) free(databuffer);
	return OK;
}

Result HcdDeinitialise() {
	if (Core != NULL) free((void *)Core);
	if (Host != NULL) free((void *)Host);
	if (Power != NULL) free((void *)Power);
	return OK;
}

