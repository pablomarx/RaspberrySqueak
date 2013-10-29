#include "types.h"
#include "printf.h"
#include "memutils.h"
#include "framebuffer.h"

extern uint32_t arm_read_cr1(void);
extern void arm_write_cr1(uint32_t val);
extern void arm_write_ttbr(uint32_t val);
extern void arm_write_dacr(uint32_t val);
extern void arm_invalidate_tlb(void);

#define MB (1024*1024)

#define MMU_FLAG_CACHED 0x1
#define MMU_FLAG_BUFFERED 0x2
#define MMU_FLAG_READWRITE 0x4

static uint32_t tt[4096]  __attribute__((aligned(16384))) __attribute((section((".bss.prebss.translation_table"))));

void arm_mmu_map_section(uint32_t paddr, uint32_t vaddr, uint32_t flags)
{
	int index;
	uint32_t AP;
	uint32_t CB = 0;
	uint32_t TEX = 0;

	AP = (flags & MMU_FLAG_READWRITE) ? 0x3 : 0x2;
	CB = ((flags & MMU_FLAG_CACHED) ? 0x2 : 0) | ((flags & MMU_FLAG_BUFFERED) ? 0x1 : 0);

	index = vaddr / MB;

	// section mapping
	tt[index] = (paddr & ~(MB-1)) | (TEX << 12) | (AP << 10) | (0<<5) | (CB << 2) | (2<<0);

	arm_invalidate_tlb();
}

void arm_mmu_unmap_section(uint32_t vaddr)
{
	uint32_t index = vaddr / MB;
	tt[index] = 0;

	arm_invalidate_tlb();
}

void mmu_init(void)
{
	/* set some mmu specific control bits */
	arm_write_cr1(arm_read_cr1() & ~((1<<29)|(1<<28)|(1<<0))); // access flag disabled, TEX remap disabled, mmu disabled

	/* set up an identity-mapped translation table with cache disabled */
	for (uint32_t i=0; i < 4096; i++) {
		uint32_t flags = MMU_FLAG_READWRITE;
		if (i <= 256) {
			flags |= MMU_FLAG_CACHED;
		}
		else {
			flags |= MMU_FLAG_BUFFERED;
		}
		arm_mmu_map_section(i * MB, i * MB,  flags); // map everything uncached
	}

	/* set up the translation table base */
	arm_write_ttbr((uint32_t)tt);

	/* set up the domain access register */
	arm_write_dacr(0x00000001);

	/* turn on the mmu */
	arm_write_cr1(arm_read_cr1() | 0x1);
}

void arch_disable_mmu(void)
{
	arm_write_cr1(arm_read_cr1() & ~(1<<0)); // access flag disabled, TEX remap disabled, mmu disabled
}
