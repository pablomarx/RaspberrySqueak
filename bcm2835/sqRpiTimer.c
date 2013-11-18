#include "sq.h"
#include "interrupts.h"

// Number of milliseconds
int ioMSecs(void) {
	return current_time();
}

int ioLowResMSecs(void)
{
  /* already have millisecond resolution */
  return ioMSecs();
}

int ioMicroMSecs(void)
{
  /* already have millisecond resolution */
  return ioMSecs();
}

int ioRelinquishProcessorForMicroseconds(int microSeconds) {
	/* This operation is platform dependent. On the Mac, it simply calls
	 * HandleEvents(), which gives other applications a chance to run.
	 */
	return microSeconds;
}

int ioSeconds(void) {
	return ioMSecs() / 1000;
}

