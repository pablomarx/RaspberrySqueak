/* Set up stack and jump to C code */

.global	_start
.globl _start
_start:
    ldr pc,reset_handler
    ldr pc,undefined_handler
    ldr pc,swi_handler
    ldr pc,prefetch_handler
    ldr pc,data_handler
    ldr pc,unused_handler
    ldr pc,irq_handler
    ldr pc,fiq_handler
reset_handler:      .word reset
undefined_handler:  .word hang
swi_handler:        .word hang
prefetch_handler:   .word hang
data_handler:       .word hang
unused_handler:     .word hang
irq_handler:        .word irq
fiq_handler:        .word hang

reset:
	ldr sp, =_start
	push {r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,lr}
	
    ldr r0, =_start
    mov r1,#0x0000
    ldmia r0!,{r2,r3,r4,r5,r6,r7,r8,r9}
    stmia r1!,{r2,r3,r4,r5,r6,r7,r8,r9}
    ldmia r0!,{r2,r3,r4,r5,r6,r7,r8,r9}
    stmia r1!,{r2,r3,r4,r5,r6,r7,r8,r9}

    pop  {r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,lr}
	b main

hang: b hang

.globl dummy
dummy:
    bx lr

.globl enable_irq
enable_irq:
    mrs r0,cpsr
    bic r0,r0,#0x80
    msr cpsr_c,r0
    bx lr

irq:
	;@ Store the return link.
	sub r14, r14, #4
	stmfd sp!, {r0,r1,r2,r3,r4,r14}

	;@ Invoke our C++ irq handler.
	bl c_irq_handler

	;@ Restore to the original caller.
	ldmfd sp!, {r0,r1,r2,r3,r4,pc}^
	bx lr

.globl arm_read_cr1
arm_read_cr1:
	mrc		p15, 0, r0, c1, c0, 0
	bx		lr

.globl arm_write_cr1
arm_write_cr1:
	mcr		p15, 0, r0, c1, c0, 0
	bx		lr
	
.globl arm_write_ttbr
arm_write_ttbr:
	mcr 	p15, 0, r0, c2, c0, 0
	bx		lr

.globl arm_write_dacr
arm_write_dacr:
	mcr 	p15, 0, r0, c3, c0, 0
	bx		lr

.globl arm_invalidate_tlb
arm_invalidate_tlb:
	mov		r0, #0
	mcr 	p15, 0, r0, c8, c7, 0
	bx		lr

.globl arch_disable_cache
arch_disable_cache:
	mov		r12, #0						// zero register
	mrs		r3, cpsr					// save the old interrupt state
	cpsid 	iaf							// interrupts disabled

.Ldcache_disable:
	tst		r0, #2						// dcache = 2
	beq		.Licache_disable
	mrc     p15, 0, r1, c1, c0, 0		// cr1
	tst		r1, #(1<<2)					// is the dcache already disabled?
	beq		.Licache_disable

	bic		r1, #(1<<2)
	mcr		p15, 0, r1, c1, c0, 0		// disable dcache

    mcr     p15, 0, r12, c7, c14, 0     // clean & invalidate dcache
	mcr		p15, 0, r0, c7, c10, 4		// data sync barrier (formerly drain write buffer)

.Licache_disable:
	tst		r0, #1						// icache = 1
	beq		.Ldone_disable

	mrc     p15, 0, r1, c1, c0, 0		// cr1
	bic		r1, #(1<<12)
	mcr		p15, 0, r1, c1, c0, 0		// disable icache

	mcr		p15, 0, r12, c7, c5, 0		// invalidate icache

.Ldone_disable:
	msr		cpsr, r3
	bx		lr

.globl arch_enable_cache
arch_enable_cache:
	mov		r12, #0						// zero register
	mrs		r3, cpsr					// save the old interrupt state
	cpsid iaf							// interrupts disabled
	orr		r3, r3, #(1<<7)
	msr		cpsr, r3

.Ldcache_enable:
	tst		r0, #2						// dcache = 2
	beq		.Licache_enable
	mrc     p15, 0, r1, c1, c0, 0		// cr1
	tst		r1, #(1<<2)					// is the dcache already enabled?
	bne		.Licache_enable

    mcr     p15, 0, r12, c7, c6, 0      // invalidate dcache

	orr		r1, #(1<<2)
	mcr		p15, 0, r1, c1, c0, 0		// enable dcache

.Licache_enable:
	tst		r0, #1						// icache = 1
	beq		.Ldone_enable

	mcr		p15, 0, r12, c7, c5, 0		// invalidate icache

	mrc     p15, 0, r1, c1, c0, 0		// cr1
	orr		r1, #(1<<12)
	mcr		p15, 0, r1, c1, c0, 0		// enable icache

.Ldone_enable:
	msr		cpsr, r3
	bx		lr
