#ifndef __MEMUTILS_H_
#define __MEMUTILS_H_ 

extern unsigned int malloc_base;
extern unsigned int malloc_size;

//void memset(void *a1, int c, unsigned int n);
void memclr(void *a1, unsigned int n) ;
void *malloc ( unsigned int size );
void *memalign(unsigned int alignment, unsigned int n);
void free(void *);
void *memccpy(void *a1, void *a2, int c, unsigned long n);
//extern void *memcpy(void *a1, void *a2, unsigned long n);


#endif
