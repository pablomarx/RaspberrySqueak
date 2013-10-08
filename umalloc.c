// Memory allocator by Kernighan and Ritchie,
// The C programming Language, 2nd ed.  Section 8.7.

#include "umalloc.h"
#include "memutils.h"

typedef long Align;

union header {
  struct {
    union header *ptr;
    unsigned int size;
  } s;
  Align x;
};

typedef union header Header;

static Header base;
static Header *freep;

#define ROUNDUP(a,b)              (((a) + (b) - 1) & ~((b) - 1))

void
free(void *ap)
{
  Header *bp, *p;

printf("free(0x%08x)\n", ap);

  bp = (Header*)ap - 1;
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
      break;
  if(bp + bp->s.size == p->s.ptr){
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
  } else
    bp->s.ptr = p->s.ptr;
  if(p + p->s.size == bp){
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
  } else
    p->s.ptr = bp;
  freep = p;
}

void*
malloc(unsigned int nbytes)
{
  Header *p, *prevp;
  unsigned int nunits;

  printf("malloc(%i) => ", nbytes);

  nunits = (nbytes + sizeof(Header) - 1)/sizeof(Header) + 1;
  if((prevp = freep) == 0){
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
    if(p->s.size >= nunits){
      if(p->s.size == nunits)
        prevp->s.ptr = p->s.ptr;
      else {
        p->s.size -= nunits;
        p += p->s.size;
        p->s.size = nunits;
      }
      freep = prevp;
	printf("0x%08x\n", (p + 1));
      return (void*)(p + 1);
    }
    if(p == freep) {
		printf("0x%08x\n", 0);
        return 0;
	}
  }
}

void* valloc(unsigned int nbytes) {
	
}

void* calloc(size_t count, size_t size) {
	void *result = malloc(count * size);
	if (result != NULL) {
		memset(result, '\0', count * size);
	}
	return result;
}


void
malloc_init(char *base, int length) 
{
  Header *hp = (Header*)base;
  hp->s.size = length;
  free((void*)(hp + 1));
}
