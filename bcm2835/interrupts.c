#include "types.h"

extern void enable_irq ();

static volatile uint32_t ticks = 0;
static int periodic_interval = 10;

#define REG32(addr) ((volatile uint32_t *)(addr))
#define writel(v, a) (*REG32(a) = (v))
#define readl(a) (*REG32(a))

/* Start of memory-mapped peripherals address space  */
#define PERIPHERALS_BASE 0x20000000

/* Interrupt controller (for ARM)  */
#define INTERRUPT_REGS_BASE    (PERIPHERALS_BASE + 0xB200)

/* System timer  */
#define SYSTEM_TIMER_REGS_BASE	(PERIPHERALS_BASE + 0x3000)
#define SYSTIMER_CLO			(SYSTEM_TIMER_REGS_BASE + 0x04)
#define SYSTIMER_C0				(SYSTEM_TIMER_REGS_BASE + 0x0c)
#define SYSTIMER_C1				(SYSTEM_TIMER_REGS_BASE + 0x10)
#define SYSTIMER_C2				(SYSTEM_TIMER_REGS_BASE + 0x14)
#define SYSTIMER_C3				(SYSTEM_TIMER_REGS_BASE + 0x18)

#define	BCM2835_INTC_IRQBPENDING	(INTERRUPT_REGS_BASE + 0x00)	/* IRQ Basic pending */
#define	BCM2835_INTC_IRQ1PENDING	(INTERRUPT_REGS_BASE + 0x04)	/* IRQ pending 1 */
#define	BCM2835_INTC_IRQ2PENDING	(INTERRUPT_REGS_BASE + 0x08)	/* IRQ pending 2 */
#define	BCM2835_INTC_FIQCTL			(INTERRUPT_REGS_BASE + 0x0c)	/* FIQ control */
#define	BCM2835_INTC_IRQ1ENABLE		(INTERRUPT_REGS_BASE + 0x10)	/* Enable IRQs 1 */
#define	BCM2835_INTC_IRQ2ENABLE		(INTERRUPT_REGS_BASE + 0x14)	/* Enable IRQs 2 */
#define	BCM2835_INTC_IRQBENABLE		(INTERRUPT_REGS_BASE + 0x18)	/* Enable Basic IRQs */
#define	BCM2835_INTC_IRQ1DISABLE	(INTERRUPT_REGS_BASE + 0x1c)	/* Disable IRQ 1 */
#define	BCM2835_INTC_IRQ2DISABLE	(INTERRUPT_REGS_BASE + 0x20)	/* Disable IRQ 2 */
#define	BCM2835_INTC_IRQBDISABLE	(INTERRUPT_REGS_BASE + 0x24)	/* Disable Basic IRQs */

void interrupts_init(void) {
	// mask all interrupts
	writel(0x00000000, BCM2835_INTC_IRQ1DISABLE);
	writel(0x00000000, BCM2835_INTC_IRQ2DISABLE);
	writel(0x00000000, BCM2835_INTC_IRQBDISABLE);
	
	// clear any pending interrupts
	writel(0x00000000, BCM2835_INTC_IRQBPENDING);
	writel(0x00000000, BCM2835_INTC_IRQ1PENDING);
	writel(0x00000000, BCM2835_INTC_IRQ2PENDING);

	// unmask all interrupts
	writel(0x00000000, BCM2835_INTC_IRQ1ENABLE);
	writel(0x00000000, BCM2835_INTC_IRQ2ENABLE);
	writel(0x00000000, BCM2835_INTC_IRQBENABLE);

    volatile uint32_t rx = readl(SYSTIMER_CLO);
    rx += periodic_interval * 1000;
	writel(rx, SYSTIMER_C1);
	writel(2,  SYSTEM_TIMER_REGS_BASE);

	writel(1 << 1, BCM2835_INTC_IRQ1ENABLE);

	enable_irq();
}

void c_irq_handler() {
	ticks++;

    volatile uint32_t rx = readl(SYSTIMER_CLO);
    rx += periodic_interval * 1000;
	writel(rx, SYSTIMER_C1);

    //clear/ack the interrupt
	writel(2,  SYSTEM_TIMER_REGS_BASE);
}

long current_time(void) {
	long time = ticks * periodic_interval;
	return time;
}