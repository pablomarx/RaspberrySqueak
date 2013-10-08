#include "types.h"

void* MemoryReserve(uint32_t length, void* physicalAddress) {
	printf("%s length=%i, physicalAddress=0x%08x\n", __PRETTY_FUNCTION__, length, physicalAddress);
	return physicalAddress;
}
