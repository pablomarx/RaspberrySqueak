#include "hardware.h"
#include "types.h"

void  timer_init ( void )
{
    //0xF9+1 = 250
    //250MHz/250 = 1MHz
   //WRITE32(ARM_TIMER_CTL,0x00F90000);
   //WRITE32(ARM_TIMER_CTL,0x00F90200);
}

void MicroDelay(uint32_t delay) {
        volatile uint64_t* timeStamp = (uint64_t*)0x20003004;
        uint64_t stop = *timeStamp + delay;

        while (*timeStamp < stop) 
                __asm__("nop");
}

#define WDT_REGS 0x20100000
#define PM_RSTC				0x1c
#define PM_WDOG				0x24

#define PM_PASSWORD			0x5a000000
#define PM_RSTC_WRCFG_MASK		0x00000030
#define PM_RSTC_WRCFG_FULL_RESET	0x00000020

void watchdog_reset(void) {
	WRITE32(WDT_REGS + PM_WDOG, 5000000/*ms*/ | PM_PASSWORD);
	uint32_t val = READ32(WDT_REGS + PM_RSTC);
	val &= ~PM_RSTC_WRCFG_MASK;
	val |= PM_PASSWORD | PM_RSTC_WRCFG_FULL_RESET;
	WRITE32(WDT_REGS + PM_RSTC, val);
}
