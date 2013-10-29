void mmu_init(void);
void arm_mmu_map_section(uint32_t paddr, uint32_t vaddr, uint32_t flags);

#define MMU_FLAG_CACHED 0x1
#define MMU_FLAG_BUFFERED 0x2
#define MMU_FLAG_READWRITE 0x4
