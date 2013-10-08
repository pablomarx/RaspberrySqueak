#ifndef __UMALLOC_H_
#define __UMALLOC_H_ 

#include "types.h"

void malloc_init(char *base, int length);
void free(void *ap);
void* malloc(unsigned int nbytes);
void* valloc(unsigned int nbytes);
void* calloc(size_t count, size_t size);

#endif
