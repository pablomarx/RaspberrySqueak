/* Set up stack and jump to C code */

.global	_start

_start:
	/* kernel.img is loaded at 0x8000, so area under that can be the
	 * stack
	 */
	mov sp, #0x8000

    # switch to supervisor mode
    mrs r4, cpsr
    orr r3, r4, #0x13
    msr cpsr_c, r3

    mcr     p15, 0, r12, c7, c6, 0      /* invalidate dcache */
	mcr		p15, 0, r12, c7, c5, 0		/* invalidate icache */

	mrc p15, #0, r4, c1, c0, #0
	orr r4, #(1 << 11)  /* Turn on branch predictor in control register */
	orr r4, #(1 << 12)  /* Enable icache */
	orr	r4, #(1 <<  2)  /* Enable dcache */
	mcr p15, #0, r4, c1, c0, #0

	MRC p15, 0, r4, c1, c0, #1
	orr r4, #(1 << 1)  /* Turn on branch predictor in ACR */
	MCR p15, 0, r4, c1, c0, #1

	b main

hang: b hang

.globl dummy
dummy:
    bx lr
