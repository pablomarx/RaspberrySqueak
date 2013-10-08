#ifndef BARRIER_H
#define BARRIER_H

/*
 * Data memory barrier
 * No memory access after the DMB can run until all memory accesses before it
 * have completed
 */
#define dmb() __asm__ volatile \
		("mcr p15, #0, %[zero], c7, c10, #5" : : [zero] "r" (0) )


/*
 * Data synchronisation barrier
 * No instruction after the DSB can run until all instructions before it have
 * completed
 */
#define dsb() __asm__ volatile \
		("mcr p15, #0, %[zero], c7, c10, #4" : : [zero] "r" (0) )


/*
 * Clean and invalidate entire cache
 * Flush pending writes to main memory
 * Remove all data in data cache
 */
#define flushcache() __asm__ volatile \
		("mcr p15, #0, %[zero], c7, c14, #0" : : [zero] "r" (0) )

#endif	/* BARRIER_H */
