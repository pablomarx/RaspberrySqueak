#include "types.h"

void uart_putc ( const unsigned int c );
void uart_puts(const char *s);
void uart_init ( void );
void hexstrings ( unsigned int d );
void hexstring ( unsigned int d );
unsigned int uart_recv ( void );
unsigned int uart_lcr ( void );
void uart_flush ( void );
