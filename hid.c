/******************************************************************************
*	device/hid/hid.c
*	 by Alex Chadwick
*
*	A light weight implementation of the USB protocol stack fit for a simple
*	driver.
*
*	device/hid/hid.c contains code relating to the generic USB human interface 
*	device driver. Human interface devices have another standard on top of USB
*	(oh boy!) which is actually very neat. It allows human interface devices to
*	describe their buttons, sliders and dials in great detail, and allows a 
*	flexible driver to handle them all. This driver merely provides methods to
*	deal with these reports. More abstracted drivers for keyboards and mice and
*	whatnot would no doubt be very useful.
******************************************************************************/
#include "hid.h"
#include "report.h"
#include "descriptors.h"
#include "device.h"
#include "types.h"
#include "usbd.h"
#include "memutils.h"
#include "platform.h"

#define HidMessageTimeout 10

Result (*HidUsageAttach[HidUsageAttachCount])(struct UsbDevice *device, uint32_t interfaceNumber);

void HidLoad() 
{
	LOG_DEBUG("CSUD: HID driver version 0.1\n"); 
	InterfaceClassAttach[InterfaceClassHid] = HidAttach;
}

Result HidGetReport(struct UsbDevice *device, enum HidReportType reportType, 
	uint8_t reportId, uint8_t interface, uint32_t bufferLength, void* buffer) {
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
		bufferLength,
		&(struct UsbDeviceRequest) {
			.Request = GetReport,
			.Type = 0xa1,
			.Index = interface,
			.Value = (uint16_t)reportType << 8 | reportId,
			.Length = bufferLength,
		},
		HidMessageTimeout)) != OK) 
		return result;

	return OK;
}

Result HidSetReport(struct UsbDevice *device, enum HidReportType reportType, 
	uint8_t reportId, uint8_t interface, uint32_t bufferLength, void* buffer) {
	Result result;
	
	if ((result = UsbControlMessage(
		device, 
		(struct UsbPipeAddress) { 
			.Type = Control, 
			.Speed = device->Speed, 
			.EndPoint = 0 , 
			.Device = device->Number, 
			.Direction = Out,
			.MaxSize = SizeFromNumber(device->Descriptor.MaxPacketSize0),
		},
		buffer,
		bufferLength,
		&(struct UsbDeviceRequest) {
			.Request = SetReport,
			.Type = 0x21,
			.Index = interface,
			.Value = (uint16_t)reportType << 8 | reportId,
			.Length = bufferLength,
		},
		HidMessageTimeout)) != OK) 
		return result;

	return OK;
}

void BitSet(void* buffer, uint32_t offset, uint32_t length, uint32_t value) {
	uint8_t* bitBuffer;
	uint8_t mask;

	bitBuffer = buffer;
	for (uint32_t i = offset / 8, j = 0; i < (offset + length + 7) / 8; i++) {
		if (offset / 8 == (offset + length - 1) / 8) {
			mask = (1 << ((offset % 8) + length)) - (1 << (offset % 8));		
			bitBuffer[i] = (bitBuffer[i] & ~mask) |
				((value << (offset % 8)) & mask);
		} if (i == offset / 8) {
			mask = 0x100 - (1 << (offset % 8));		
			bitBuffer[i] = (bitBuffer[i] & ~mask) |
				((value << (offset % 8)) & mask);
			j += 8 - (offset % 8);
		} else if (i == (offset + length - 1) / 8) {
			mask = (1 << ((offset % 8) + length)) - 1;		
			bitBuffer[i] = (bitBuffer[i] & ~mask) |
				((value >> j) & mask);
		} else {			
			bitBuffer[i] = (value >> j) & 0xff;
			j += 8;
		}			 
	}
}

uint32_t BitGetUnsigned(void* buffer, uint32_t offset, uint32_t length) {
	uint8_t* bitBuffer;
	uint8_t mask;
	uint32_t result;
	
	bitBuffer = buffer;
	result = 0;
	for (uint32_t i = offset / 8, j = 0; i < (offset + length + 7) / 8; i++) {
		if (offset / 8 == (offset + length - 1) / 8) {
			mask = (1 << ((offset % 8) + length)) - (1 << (offset % 8));		
			result = (bitBuffer[i] & mask) >> (offset % 8);
		} else if (i == offset / 8) {
			mask = 0x100 - (1 << (offset % 8));		
			j += 8 - (offset % 8);
			result = ((bitBuffer[i] & mask) >> (offset % 8)) << (length - j);
		} else if (i == (offset + length - 1) / 8) {
			mask = (1 << ((offset % 8) + length)) - 1;		
			result |= bitBuffer[i] & mask;
		} else {			
			j += 8;
			result |= bitBuffer[i] << (length - j);
		}	
	}
	return result;
}

int32_t BitGetSigned(void* buffer, uint32_t offset, uint32_t length) {
	uint32_t result = BitGetUnsigned(buffer, offset, length);

	if (result & (1 << (length - 1)))
		result |= 0xffffffff - ((1 << length) - 1);

	return result;
}

Result HidReadDevice(struct UsbDevice *device, uint8_t reportNumber) {
	struct HidDevice *data;
	struct HidParserResult *parse;
	struct HidParserReport *report;
	struct HidParserField *field;
	Result result;
	uint32_t size;
	
	data = (struct HidDevice*)device->DriverData;
	parse = data->ParserResult;
	report = parse->Report[reportNumber];
	size = ((report->ReportLength + 7) / 8);
	if ((report->ReportBuffer == NULL) && (report->ReportBuffer = (uint8_t*)malloc(size)) == NULL) {
		return ErrorMemory;
	}
	if ((result = HidGetReport(device, report->Type, report->Id, data->ParserResult->Interface, size, report->ReportBuffer)) != OK) {
		if (result != ErrorDisconnected)
			LOGF("HID: Could not read %s report %d.\n", UsbGetDescription(device), reportNumber);
		return result;
	}
	
	// Uncomment this for a quick hack to view 8 bytes worth of report.
#if 0
	printf("HidReadDevice %s %i: ", UsbGetDescription(device), reportNumber + 1);
	for (uint32_t i=0; i<report->ReportLength; i++) {
		printf("%02x ", *(report->ReportBuffer + i));
	}
	printf("\n");
#endif
	/*
	LOGF("HID: %s.Report%d: %02x%02x%02x%02x %02x%02x%02x%02x.\n", UsbGetDescription(device), reportNumber + 1,
		*(report->ReportBuffer + 0), *(report->ReportBuffer + 1), *(report->ReportBuffer + 2), *(report->ReportBuffer + 3),
		*(report->ReportBuffer + 4), *(report->ReportBuffer + 5), *(report->ReportBuffer + 6), *(report->ReportBuffer + 7));
	*/

	for (uint32_t i = 0; i < report->FieldCount; i++) {
		field = &report->Fields[i];
		if (field->Attributes.Variable) {
			if (field->LogicalMinimum < 0)
				field->Value.S32 = BitGetSigned(report->ReportBuffer, field->Offset, field->Size);
			else
				field->Value.U32 = BitGetUnsigned(report->ReportBuffer, field->Offset, field->Size);
		} else {
			for (uint32_t j = 0; j < field->Count; j++) {
				BitSet(
						field->Value.Pointer,
						j * field->Size, 
						field->Size, 
						field->LogicalMinimum < 0 ? BitGetSigned(
							report->ReportBuffer, 
							field->Offset + j * field->Size, 
							field->Size
						) : BitGetUnsigned(
							report->ReportBuffer, 
							field->Offset + j * field->Size, 
							field->Size
						)
					);				
			}
		}
	}

	return OK;
}

Result HidWriteDevice(struct UsbDevice *device, uint8_t reportNumber) {
	struct HidDevice *data;
	struct HidParserResult *parse;
	struct HidParserReport *report;
	struct HidParserField *field;
	Result result;
	uint32_t size;
	
	data = (struct HidDevice*)device->DriverData;
	parse = data->ParserResult;
	report = parse->Report[reportNumber];
	size = ((report->ReportLength + 7) / 8);
	if ((report->ReportBuffer == NULL) && (report->ReportBuffer = (uint8_t*)malloc(size)) == NULL) {
		return ErrorMemory;
	}
	for (uint32_t i = 0; i < report->FieldCount; i++) {
		field = &report->Fields[i];
		if (field->Attributes.Variable) {
			BitSet(
					report->ReportBuffer, 
					field->Offset, 
					field->Size,
					field->Value.S32
				);
		} else {
			for (uint32_t j = 0; j < field->Count; j++) {
				BitSet(
						report->ReportBuffer,
						field->Offset + j * field->Size, 
						field->Size,
						BitGetSigned(
							field->Value.Pointer, 
							j * field->Size, 
							field->Size
						)
					);				
			}
		}
	}
	
	if ((result = HidSetReport(device, report->Type, report->Id, data->ParserResult->Interface, size, report->ReportBuffer)) != OK) {
		if (result != ErrorDisconnected)
			LOGF("HID: Coult not read %s report %d.\n", UsbGetDescription(device), report);
		return result;
	}

	return OK;
}

Result HidSetProtocol(struct UsbDevice *device, uint8_t interface, uint16_t protocol) {
	Result result;
	
	if ((result = UsbControlMessage(
		device, 
		(struct UsbPipeAddress) { 
			.Type = Control, 
			.Speed = device->Speed, 
			.EndPoint = 0 , 
			.Device = device->Number, 
			.Direction = Out,
			.MaxSize = SizeFromNumber(device->Descriptor.MaxPacketSize0),
		},
		NULL,
		0,
		&(struct UsbDeviceRequest) {
			.Request = SetProtocol,
			.Type = 0x21,
			.Index = interface,
			.Value = protocol,
			.Length = 0,
		},
		HidMessageTimeout)) != OK) 
		return result;

	return OK;
}

Result HidSetIdle(struct UsbDevice *device, uint32_t ms) {
	Result result;
	
	if ((result = UsbControlMessage(
		device, 
		(struct UsbPipeAddress) { 
			.Type = Control, 
			.Speed = device->Speed, 
			.EndPoint = 0 , 
			.Device = device->Number, 
			.Direction = Out,
			.MaxSize = SizeFromNumber(device->Descriptor.MaxPacketSize0),
		},
		NULL,
		0,
		&(struct UsbDeviceRequest) {
			.Request = SetIdle,
			.Type = 0x21,
			.Index = 0,
			.Value = (ms/4)<<8,
			.Length = 0,
		},
		HidMessageTimeout)) != OK) 
		return result;

	return OK;
}

void HidEnumerateReport(void* descriptor, uint16_t length, void(*action)(void* data, uint16_t tag, uint32_t value), void* data) {
	struct HidReportItem *item, *current;
	uint16_t parsedLength, currentIndex, currentLength;
	uint16_t tag; // tags for short items will be stored in the low 6 bits, tags for long items will be in the top 8 bits.
	int32_t value;
	
	item = descriptor;	
	current = NULL;
	parsedLength = 0;
	
	while (parsedLength < length) {
		if (current == NULL) {
			current = item;
			currentIndex = 0;
			currentLength = 1 << (current->Size - 1);
			value = 0;
			tag = current->Tag;
			if (currentLength == 0)
				current = NULL;
		} else {
			if (current->Tag == TagLong && currentIndex < 2) {
				if (currentIndex == 0) currentLength += *(uint8_t*)item;				
				else tag |= (uint16_t)*(uint8_t*)item << 8;
			} else {
				value |= (uint32_t)*(uint8_t*)item << (8 * currentIndex);
			}
			if (++currentIndex == currentLength)
				current = NULL;
		}

		if (current == NULL) {
			if ((tag & 0x3) == 0x1) {
				if (currentLength == 1 && (value & 0x80))
					value |= 0xffffff00;
				else if (currentLength == 2 && (value & 0x8000))
					value |= 0xffff0000;
			}

			action(data, tag, value);
		}

		item++;
		parsedLength++;
	}
}

#if DEBUG
void HidEnumerateActionCountReport(void* data, uint16_t tag, uint32_t value) {
	struct {
		uint8_t reportCount;
		uint8_t indent;
		bool input, output, feature;
	} *reports = data;

	switch (tag) {
	case TagMainInput:
		if (!reports->input) { reports->reportCount++; reports->input = true; }
		LOG_DEBUGF("HID: %.*sInput(%03o)\n", reports->indent, "           ", value);
		break;
	case TagMainOutput:
		if (!reports->output) { reports->reportCount++; reports->output = true; }
		LOG_DEBUGF("HID: %.*sOutput(%03o)\n", reports->indent, "           ", value);
		break;
	case TagMainFeature:
		if (!reports->feature) { reports->reportCount++; reports->feature = true; }
		LOG_DEBUGF("HID: %.*sFeature(%03o)\n", reports->indent, "           ", value);
		break;
	case TagMainCollection:
		LOG_DEBUGF("HID: %.*sCollection(%d)\n", reports->indent, "           ", value);
		reports->indent++;
		break;
	case TagMainEndCollection:
		reports->indent--;
		LOG_DEBUGF("HID: %.*sEnd Collection\n", reports->indent, "           ");
		break;
	case TagGlobalUsagePage:
		LOG_DEBUGF("HID: %.*sUsage Page(%d)\n", reports->indent, "           ", value);
		break;
	case TagGlobalLogicalMinimum:
		LOG_DEBUGF("HID: %.*sLogical Minimum(%d)\n", reports->indent, "           ", value);
		break;
	case TagGlobalLogicalMaximum:
		LOG_DEBUGF("HID: %.*sLogical Maximum(%d)\n", reports->indent, "           ", value);
		break;
	case TagGlobalPhysicalMinimum:
		LOG_DEBUGF("HID: %.*sPhysical Minimum(%d)\n", reports->indent, "           ", value);
		break;
	case TagGlobalPhysicalMaximum:
		LOG_DEBUGF("HID: %.*sPhysical Maximum(%d)\n", reports->indent, "           ", value);
		break;
	case TagGlobalUnitExponent:
		LOG_DEBUGF("HID: %.*sUnit Exponent(%d)\n", reports->indent, "           ", value);
		break;
	case TagGlobalUnit:
		LOG_DEBUGF("HID: %.*sUnit(%d)\n", reports->indent, "           ", value);
		break;
	case TagGlobalReportSize:
		LOG_DEBUGF("HID: %.*sReport Size(%d)\n", reports->indent, "           ", value);
		break;
	case TagGlobalReportId:
		reports->input = reports->output = reports->feature = false;
		LOG_DEBUGF("HID: %.*sReport ID(%d)\n", reports->indent, "           ", value);
		break;
	case TagGlobalReportCount:
		LOG_DEBUGF("HID: %.*sReport Count(%d)\n", reports->indent, "           ", value);
		break;
	case TagGlobalPush:
		LOG_DEBUGF("HID: %.*sPush\n", reports->indent, "           ");
		break;
	case TagGlobalPop:
		LOG_DEBUGF("HID: %.*sPop\n", reports->indent, "           ");
		break;
	case TagLocalUsage:
		LOG_DEBUGF("HID: %.*sUsage(%u)\n", reports->indent, "           ", value);
		break;
	case TagLocalUsageMinimum:
		LOG_DEBUGF("HID: %.*sUsage Minimum(%u)\n", reports->indent, "           ", value);
		break;
	case TagLocalUsageMaximum:
		LOG_DEBUGF("HID: %.*sUsage Maximum(%u)\n", reports->indent, "           ", value);
		break;
	case TagLocalDesignatorIndex:
		LOG_DEBUGF("HID: %.*sDesignator Index(%u)\n", reports->indent, "           ", value);
		break;
	case TagLocalDesignatorMinimum:
		LOG_DEBUGF("HID: %.*sDesignator Minimum(%u)\n", reports->indent, "           ", value);
		break;
	case TagLocalDesignatorMaximum:
		LOG_DEBUGF("HID: %.*sDesignator Maximum(%u)\n", reports->indent, "           ", value);
		break;
	case TagLocalStringIndex:
		LOG_DEBUGF("HID: %.*sString Index(%u)\n", reports->indent, "           ", value);
		break;
	case TagLocalStringMinimum:
		LOG_DEBUGF("HID: %.*sString Minimum(%u)\n", reports->indent, "           ", value);
		break;
	case TagLocalStringMaximum:
		LOG_DEBUGF("HID: %.*sString Maximum(%u)\n", reports->indent, "           ", value);
		break;
	case TagLocalDelimiter:
		LOG_DEBUGF("HID: %.*sDelimiter\n", reports->indent, "           ");
		break;
	default:
		LOG_DEBUGF("HID: Unexpected tag in report %d = %x.\n", tag, value);
		break;
	}
}
#else
void HidEnumerateActionCountReport(void* data, uint16_t tag, uint32_t value) {
	struct {
		uint8_t reportCount;
		uint8_t indent;
		bool input, output, feature;
	} *reports = data;

	switch (tag) {
	case TagMainInput:
		if (!reports->input) { reports->reportCount++; reports->input = true; }
		break;
	case TagMainOutput:
		if (!reports->output) { reports->reportCount++; reports->output = true; }
		break;
	case TagMainFeature:
		if (!reports->feature) { reports->reportCount++; reports->feature = true; }
		break;
	case TagGlobalReportId:
		reports->input = reports->output = reports->feature = false;
		break;
	default:
		break;
	}
}
#endif

void HidEnumerateActionCountField(void* data, uint16_t tag, uint32_t value) {
	struct reportFields_t {
		uint32_t count;
		uint8_t current;
		uint8_t report;
		struct reportFields_inner_t {
			uint8_t reportId;
			uint8_t fieldCount;
			enum HidReportType type;
		} reports[];
	} *reportFields = data;
	struct reportFields_inner_t *inner;
	enum HidReportType type;
	
	type = 0;
	switch (tag) {
	case TagMainFeature: type++;
	case TagMainOutput: type++;
	case TagMainInput: type++;
		inner = NULL;
		for (uint32_t i = 0; i < reportFields->current; i++) {
			if (reportFields->reports[i].reportId == reportFields->report &&
				reportFields->reports[i].type == type) {
				inner = &reportFields->reports[i];
				break; 
			}
		}
		if (inner == NULL) {
			inner = &reportFields->reports[reportFields->current++];
			inner->reportId = reportFields->report;
			inner->fieldCount = 0;
			inner->type = type;
		}
		if (((struct HidMainItem*)&value)->Variable) inner->fieldCount += reportFields->count;
		else inner->fieldCount++;
		break;
	case TagGlobalReportCount:
		reportFields->count = value;
		break;
	case TagGlobalReportId:
		reportFields->report = value;
		break;
	default: break;
	}
}

void HidEnumerateActionAddField(void* data, uint16_t tag, uint32_t value) {
	struct fields_t {
		struct HidParserResult *result;
		uint32_t count;
		uint32_t size;
		struct HidFullUsage *usage;
		struct HidFullUsage physical;
		int32_t logicalMinimum;
		int32_t logicalMaximum;	
		int32_t physicalMinimum;
		int32_t physicalMaximum;
		struct HidUnit unit;
		int32_t unitExponent;		
		enum HidUsagePage page;
		uint8_t report;
	} *fields = data;
	enum HidReportType type;
	struct HidParserReport *report;
	uint32_t i;

	type = 0;
	switch (tag) {
	case TagMainFeature: type++;
	case TagMainOutput: type++;
	case TagMainInput: type++;
		report = NULL;
		for (i = 0; i < fields->result->ReportCount; i++)
			if (fields->result->Report[i]->Id == fields->report &&
				fields->result->Report[i]->Type == type) {
				report = fields->result->Report[i];
				break; 
			}
		while (fields->count > 0) {
			if (*(uint32_t*)fields->usage == 0xffffffff) fields->usage++;
			*(uint32_t*)&(report->Fields[report->FieldCount].Attributes) = value;
			report->Fields[report->FieldCount].Count = report->Fields[report->FieldCount].Attributes.Variable ? 1 : fields->count;
			report->Fields[report->FieldCount].LogicalMaximum = fields->logicalMaximum;
			report->Fields[report->FieldCount].LogicalMinimum = fields->logicalMinimum;
			report->Fields[report->FieldCount].Offset = report->ReportLength;
			report->Fields[report->FieldCount].PhysicalMaximum = fields->physicalMaximum;
			report->Fields[report->FieldCount].PhysicalMinimum = fields->physicalMinimum;
			*(uint32_t*)&report->Fields[report->FieldCount].PhysicalUsage = *(uint32_t*)&fields->physical;
			report->Fields[report->FieldCount].Size = fields->size;
			*(uint32_t*)&report->Fields[report->FieldCount].Unit = *(uint32_t*)&fields->unit;
			report->Fields[report->FieldCount].UnitExponent = fields->unitExponent;
			if ((uint16_t)fields->usage->Page == 0xffff) {
				*(uint32_t*)&report->Fields[report->FieldCount].Usage = *(uint32_t*)&fields->usage[-1];
				if (fields->usage->Desktop == fields->usage[-1].Desktop ||
					!report->Fields[report->FieldCount].Attributes.Variable)
					fields->usage -= 2;
				else
					fields->usage[-1].Desktop++;
			} else {
				*(uint32_t*)&report->Fields[report->FieldCount].Usage = *(uint32_t*)(fields->usage--);
			}
			if (report->Fields[report->FieldCount].Attributes.Variable) {
				fields->count--;
				report->ReportLength += report->Fields[report->FieldCount].Size;
				report->Fields[report->FieldCount].Value.U32 = 0;
			}
			else {
				fields->count = 0;
				report->ReportLength += report->Fields[report->FieldCount].Size * report->Fields[report->FieldCount].Count;
				report->Fields[report->FieldCount].Value.Pointer = malloc(report->ReportLength / 8);
			}
			report->FieldCount++;
		}
		*(uint32_t*)&fields->usage[1] = 0;
		break;
	case TagMainCollection:
		if (*(uint32_t*)fields->usage == 0xffffffff) fields->usage++;
		switch ((enum HidMainCollection)value) {
		case Application:			
			*(uint32_t*)&fields->result->Application = *(uint32_t*)fields->usage;
			break;
		case Physical:
			*(uint32_t*)&fields->physical = *(uint32_t*)fields->usage;
			break;
		default:
			break;
		}
		fields->usage--;
		break;
	case TagMainEndCollection:
		switch ((enum HidMainCollection)value) {
		case Physical:
			*(uint32_t*)&fields->physical = 0;
			break;
		default:
			break;
		}
		break;
	case TagGlobalUsagePage:		
		fields->page = (enum HidUsagePage)value;
		break;
	case TagGlobalLogicalMinimum:
		fields->logicalMinimum = value;
		break;
	case TagGlobalLogicalMaximum:
		fields->logicalMaximum = value;
		break;
	case TagGlobalPhysicalMinimum:
		fields->physicalMinimum = value;
		break;
	case TagGlobalPhysicalMaximum:
		fields->physicalMaximum = value;
		break;
	case TagGlobalUnitExponent:
		fields->unitExponent = value;
		break;
	case TagGlobalUnit:
		*(uint32_t*)&fields->unit = value;
		break;
	case TagGlobalReportSize:
		fields->size = value;
		break;
	case TagGlobalReportId:
		fields->report = (uint8_t)value;
		break;
	case TagGlobalReportCount:
		fields->count = value;
		break;
	case TagLocalUsage:
		fields->usage++;
		if (value & 0xffff0000)
			*(uint32_t*)&fields->usage = value;
		else {
			fields->usage->Desktop = (enum HidUsagePageDesktop)value;
			fields->usage->Page = fields->page;
		}
		break;
	case TagLocalUsageMinimum:
		fields->usage++;
		if (value & 0xffff0000)
			*(uint32_t*)&fields->usage = value;
		else {
			fields->usage->Desktop = (enum HidUsagePageDesktop)value;
			fields->usage->Page = fields->page;
		}
		break;
	case TagLocalUsageMaximum:
		fields->usage++;
		fields->usage->Desktop = (enum HidUsagePageDesktop)value;
		fields->usage->Page = (enum HidUsagePage)0xffff;
		break;
	default: break;
	}
}

Result HidParseReportDescriptor(struct UsbDevice *device, void* descriptor, uint16_t length) {
	Result result;
	struct HidDevice *data;
	struct HidParserResult *parse = NULL;
	struct {
		uint8_t reportCount;
		uint8_t indent;
		bool input, output, feature;
	} reports = { .reportCount = 0, .indent = 0, .input = false, .output = false, .feature = false };
	struct reportFields_t {
		uint32_t count;
		uint8_t current;
		uint8_t report;
		struct reportFields_inner_t {
			uint8_t reportId;
			uint8_t fieldCount;
			enum HidReportType type;
		} reports[];
	} *reportFields = NULL;
	struct fields_t {
		struct HidParserResult *result;
		uint32_t count;
		uint32_t size;
		struct HidFullUsage *usage;
		struct HidFullUsage physical;
		int32_t logicalMinimum;
		int32_t logicalMaximum;	
		int32_t physicalMinimum;
		int32_t physicalMaximum;
		struct HidUnit unit;
		int32_t unitExponent;		
		enum HidUsagePage page;
		uint8_t report;
	} *fields = NULL;
	void* usageStack = NULL;

	data = (struct HidDevice*)device->DriverData;

	HidEnumerateReport(descriptor, length, HidEnumerateActionCountReport, &reports);
	LOG_DEBUGF("HID: Found %d reports.", reports.reportCount);

	if ((parse = malloc(sizeof(struct HidParserResult) + 4 * reports.reportCount)) == NULL) {
		result = ErrorMemory;
		goto deallocate;
	}
	for (uint32_t i = 0; i < reports.reportCount; i++) {
		parse->Report[i] = NULL;
	}
	if ((reportFields = malloc(sizeof(struct reportFields_t) + sizeof(struct reportFields_inner_t) * reports.reportCount)) == NULL) {
		result = ErrorMemory;
		goto deallocate;
	}
	parse->ReportCount = reports.reportCount;
	reportFields->count = 0;
	reportFields->current = 0;
	reportFields->report = 0;

	HidEnumerateReport(descriptor, length, HidEnumerateActionCountField, reportFields);
	for (uint32_t i = 0; i < reports.reportCount; i++) {
		if ((parse->Report[i] = malloc(sizeof(struct HidParserReport) + sizeof(struct HidParserField) * reportFields->reports[i].fieldCount)) == NULL) {
			result = ErrorMemory;
			goto deallocate;
		}
		parse->Report[i]->Index = i;
		parse->Report[i]->FieldCount = 0;
		parse->Report[i]->Id = reportFields->reports[i].reportId;
		parse->Report[i]->Type = reportFields->reports[i].type;
		parse->Report[i]->ReportLength = 0;
		parse->Report[i]->ReportBuffer = NULL;
	}	
	free(reportFields);
	reportFields = NULL;

	if ((fields = malloc(sizeof(struct fields_t))) == NULL) {
		result = ErrorMemory;
		goto deallocate;
	}
	if ((fields->usage = usageStack = malloc(16 * sizeof(struct HidFullUsage*))) == NULL) {
		result = ErrorMemory;
		goto deallocate;
	}	
	fields->count = 0;
	fields->logicalMaximum = 0;
	fields->logicalMinimum = 0;
	fields->physicalMaximum = 0;
	fields->physicalMinimum = 0;
	fields->report = 0;
	fields->size = 0;
	*(uint32_t*)fields->usage = 0xffffffff;
	fields->result = parse;
	HidEnumerateReport(descriptor, length, HidEnumerateActionAddField, fields);
	
	data->ParserResult = parse;
	parse = NULL;
	result = OK;
deallocate:
	if (usageStack != NULL) free(usageStack);
	if (fields != NULL) free(fields);
	if (reportFields != NULL) free(reportFields);
	if (parse != NULL) {
		for (uint32_t i = 0; i < reports.reportCount; i++)
			if (parse->Report[i] != NULL) free(parse->Report[i]);
		free(parse);
	}
	return result;
}

void HidDetached(struct UsbDevice *device) {
	struct HidDevice *data;
	
	if (device->DriverData != NULL) {
		data = (struct HidDevice*)device->DriverData;

		if (data->HidDetached != NULL)
			data->HidDetached(device);
	}
}

void HidDeallocate(struct UsbDevice *device) {
	struct HidDevice *data;
	struct HidParserReport *report;
	
	if (device->DriverData != NULL) {
		data = (struct HidDevice*)device->DriverData;

		if (data->HidDeallocate != NULL)
			data->HidDeallocate(device);

		if (data->ParserResult != NULL) {
			for (uint32_t i = 0; i < data->ParserResult->ReportCount; i++) {
				if (data->ParserResult->Report[i] != NULL) {
					report = data->ParserResult->Report[i];
					if (report->ReportBuffer != NULL)
						free(report->ReportBuffer);
					for (uint32_t j = 0; j < report->FieldCount; j++) 
						if (!report->Fields[j].Attributes.Variable)
							free(report->Fields[j].Value.Pointer);
					free(data->ParserResult->Report[i]);
				}
			}
			free(data->ParserResult);
		}

		free(data);
	}
	device->DeviceDeallocate = NULL;
	device->DeviceDetached = NULL;
}

Result HidAttach(struct UsbDevice *device, uint32_t interfaceNumber) {
	struct HidDevice *data;
	struct HidDescriptor *descriptor;
	struct UsbDescriptorHeader *header;
	void* reportDescriptor = NULL;
	Result result;
	uint32_t currentInterface;

	if (device->Interfaces[interfaceNumber].Class != InterfaceClassHid) {
		return ErrorArgument;
	}
	if (device->Interfaces[interfaceNumber].EndpointCount < 1) {
		LOGF("HID: Invalid HID device with fewer than one endpoints (%d).\n", device->Interfaces[interfaceNumber].EndpointCount);
		return ErrorIncompatible;
	}
	if (device->Endpoints[interfaceNumber][0].EndpointAddress.Direction != In ||
		device->Endpoints[interfaceNumber][0].Attributes.Type != Interrupt) {
		LOG("HID: Invalid HID device with unusual endpoints (0).\n");
		return ErrorIncompatible;
	}
	if (device->Interfaces[interfaceNumber].EndpointCount >= 2) {
		if (device->Endpoints[interfaceNumber][1].EndpointAddress.Direction != Out ||
			device->Endpoints[interfaceNumber][1].Attributes.Type != Interrupt) {
			LOG("HID: Invalid HID device with unusual endpoints (1).\n");
			return ErrorIncompatible;
		}	
	}
	if (device->Status != Configured) {
		LOG("HID: Cannot start driver on unconfigured device!\n");
		return ErrorDevice;
	}
	if (device->Interfaces[interfaceNumber].SubClass == 1) {
		if (device->Interfaces[interfaceNumber].Protocol == 1)
			LOG_DEBUG("HID: Boot keyboard detected.\n");
		else if (device->Interfaces[interfaceNumber].Protocol == 2)
			LOG_DEBUG("HID: Boot mouse detected.\n");
		else 
			LOG_DEBUG("HID: Unknown boot device detected.\n");
		
		LOG_DEBUG("HID: Reverting from boot to normal HID mode.\n");
		if ((result = HidSetProtocol(device, interfaceNumber, 1)) != OK) {
			LOG("HID: Could not revert to report mode from HID mode.\n");
			return result;
		}
	}

	header = (struct UsbDescriptorHeader*)device->FullConfiguration;
	descriptor = NULL;
	currentInterface = interfaceNumber + 1; // Certainly different!
	do {		
		if (header->DescriptorLength == 0) break; // List end
		switch (header->DescriptorType) {
		case Interface:
			currentInterface = ((struct UsbInterfaceDescriptor*)header)->Number;
			break;
		case Hid:
			if (currentInterface == interfaceNumber)
				descriptor = (void*)header;
			break;
		default:
			break;
		}
		
		LOG_DEBUGF("HID: Descriptor %d length %d, interface %d.\n", header->DescriptorType, header->DescriptorLength, currentInterface);

		if (descriptor != NULL) break;
		header = (void*)((uint8_t*)header + header->DescriptorLength);
	} while (true);

	if (descriptor == NULL) {
		LOGF("HID: No HID descriptor in %s.Interface%d. Cannot be a HID device.\n", UsbGetDescription(device), interfaceNumber + 1);
		return ErrorIncompatible;
	}

	if (descriptor->HidVersion > 0x111) {
		LOGF("HID: Device uses unsupported HID version %x.%x.\n", descriptor->HidVersion >> 8, descriptor->HidVersion & 0xff);
		return ErrorIncompatible;
	}
	LOG_DEBUGF("HID: Device version HID %x.%x.\n", descriptor->HidVersion >> 8, descriptor->HidVersion & 0xff);
	
	device->DeviceDeallocate = HidDeallocate;
	device->DeviceDetached = HidDetached;
	if ((device->DriverData = malloc(sizeof (struct HidDevice))) == NULL) {
		result = ErrorMemory;
		goto deallocate;
	}
	device->DriverData->DataSize = sizeof(struct HidDevice);
	device->DriverData->DeviceDriver = DeviceDriverHid;
	data = (struct HidDevice*)device->DriverData;
	data->Descriptor = descriptor;
	data->DriverData = NULL;
	
	if ((reportDescriptor = malloc(descriptor->OptionalDescriptors[0].Length)) == NULL) {
		result = ErrorMemory;
		goto deallocate;
	}
	if ((result = UsbGetDescriptor(device, HidReport, 0, interfaceNumber, reportDescriptor, descriptor->OptionalDescriptors[0].Length, descriptor->OptionalDescriptors[0].Length, 1)) != OK) {
		free(reportDescriptor);
		LOGF("HID: Could not read report descriptor for %s.Interface%d.\n", UsbGetDescription(device), interfaceNumber + 1);
		goto deallocate;
	}
	if ((result = HidParseReportDescriptor(device, reportDescriptor, descriptor->OptionalDescriptors[0].Length)) != OK) {		
		free(reportDescriptor);
		LOGF("HID: Invalid report descriptor for %s.Interface%d.\n", UsbGetDescription(device), interfaceNumber + 1);
		goto deallocate;
	}

	free(reportDescriptor);
	reportDescriptor = NULL;

	data->ParserResult->Interface = interfaceNumber;
	if (data->ParserResult->Application.Page == GenericDesktopControl &&
		(uint16_t)data->ParserResult->Application.Desktop < HidUsageAttachCount &&
		HidUsageAttach[(uint16_t)data->ParserResult->Application.Desktop] != NULL) {
		HidUsageAttach[(uint16_t)data->ParserResult->Application.Desktop](device, interfaceNumber);
	}

	return OK;
deallocate:
	if (reportDescriptor != NULL) free(reportDescriptor);
	HidDeallocate(device);
	return result;
}

int32_t HidGetFieldValue(struct HidParserField *field, uint32_t index) {
	return BitGetSigned(field->Value.Pointer, index * field->Size, field->Size);
}
