#include "printf.h"

unsigned int malloc_base;
unsigned int malloc_size;

extern void abort(void);

#define ROUND_UP(a,b)              (((a) + (b) - 1) & ~((b) - 1))
void * malloc ( unsigned int size )
{
    void *ret;
//	printf("malloc(%i now:", size);
	size = ROUND_UP(size, 8);
//	printf("%i) => ", size);

    ret=(void *)malloc_base;

//	printf("0x%08x\n", ret);

    malloc_base+=size;
    
	return(ret);
}

void *calloc(unsigned int nmemb, unsigned int size) {
	void *result = malloc(nmemb * size);
	memclr(result, nmemb * size);
	return result;
}

void *memalign(unsigned int alignment, unsigned int n) {
    void *ret;
//	printf("malloc(%i) => (malloc_base was: 0x%08x, ", n, malloc_base);
	
	ret = (void *)ROUND_UP(malloc_base, alignment);
	
	malloc_base += n;
	malloc_base = ROUND_UP(malloc_base, alignment);

//	printf("malloc_base now: 0x%08x) ret => 0x%08x\n", malloc_base, ret);
	return ret;
}

void free (void *mem) {
	printf("free(0x%08x)\n", mem);
}

void*
memccpy(void *a1, void *a2, int c, unsigned long n)
{
	unsigned char *s1, *s2;

	s1 = a1;
	s2 = a2;
	c &= 0xFF;
	while(n > 0) {
		if((*s1++ = *s2++) == c)
			return s1;
		n--;
	}
	return 0;
}


void
memset(void *a1, int c, unsigned int n)
{
	int m = (int)n;
	unsigned char *d;

	d = a1;
	while(--m >= 0)
		*d++ = c;
}

void
memclr(void *a1, unsigned int n) 
{
	memset(a1, 0x00, n);
}
