#include "strings.h"

#if 0
void*
memcpy(void *a1, void *a2, unsigned long n)
{
	return memmove(a1, a2, n);
}
#endif
char*
strchr(char *s, int c)
{
	char c1;

	if(c == 0) {
		while(*s++)
			;
		return s-1;
	}

	while(c1 = *s++)
		if(c1 == c)
			return s-1;
	return 0;
}
#define	N	10000

char*
strcpy(char *s1, char *s2)
{
	char *os1;

	os1 = s1;
	while(!memccpy(s1, s2, 0, N)) {
		s1 += N;
		s2 += N;
	}
	return os1;
}


long
strlen(char *s)
{

	return strchr(s, 0) - s;
}
