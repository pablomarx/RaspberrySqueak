#include "printf.h"

int __errno = 0;

void raise(void)
{
	printf("Error: division by zero attempted\n");
	printf("STOPPED\n");

	while(1) __asm__("nop");
}

void abort()
{
	printf("Abort abort abort\n");
	while(1) __asm__("nop");
}
