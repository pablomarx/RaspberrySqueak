#include "types.h"
#include "hardware.h"

unsigned int uart_lcr ( void )
{
    return(READ32(AUX_MU_LSR_REG));
}

void uart_flush ( void )
{
    while(1)
    {
        if((READ32(AUX_MU_LSR_REG)&0x100)==0) break;
    }
}

unsigned int uart_recv ( void )
{
    while(1)
    {
        if(READ32(AUX_MU_LSR_REG)&0x01) break;
    }
    return(READ32(AUX_MU_IO_REG)&0xFF);
}

void uart_putc ( unsigned int c )
{
    while(1)
    {
        if(READ32(AUX_MU_LSR_REG)&0x20) break;
    }
    WRITE32(AUX_MU_IO_REG,c);

	/* send a \r for compatibility */
	if (c == '\n')
		uart_putc('\r');
}


void uart_puts(const char *s) {
	while(*s != '\0') { /* Loop until end of string */
		uart_putc((unsigned int)(*s)); /* Transmit char */
		s++; /* Next char */
	}
}

void hexstrings ( unsigned int d )
{
    //unsigned int ra;
    unsigned int rb;
    unsigned int rc;

    rb=32;
    while(1)
    {
        rb-=4;
        rc=(d>>rb)&0xF;
        if(rc>9) rc+=0x37; else rc+=0x30;
        uart_putc(rc);
        if(rb==0) break;
    }
    uart_putc(0x20);
}
//------------------------------------------------------------------------
void hexstring ( unsigned int d )
{
    hexstrings(d);
    uart_putc(0x0A);
}


void uart_init ( void )
{
    unsigned int ra;

    WRITE32(AUX_ENABLES,1);
    WRITE32(AUX_MU_IER_REG,0);
    WRITE32(AUX_MU_CNTL_REG,0);
    WRITE32(AUX_MU_LCR_REG,3);
    WRITE32(AUX_MU_MCR_REG,0);
    WRITE32(AUX_MU_IER_REG,0);
    WRITE32(AUX_MU_IIR_REG,0xC6);
    WRITE32(AUX_MU_BAUD_REG,270);
    ra=READ32(GPFSEL1);
    ra&=~(7<<12); //gpio14
    ra|=2<<12;    //alt5
    ra&=~(7<<15); //gpio15
    ra|=2<<15;    //alt5
    WRITE32(GPFSEL1,ra);
    WRITE32(GPPUD,0);
    for(ra=0;ra<150;ra++) dummy(ra);
    WRITE32(GPPUDCLK0,(1<<14)|(1<<15));
    for(ra=0;ra<150;ra++) dummy(ra);
    WRITE32(GPPUDCLK0,0);
    WRITE32(AUX_MU_CNTL_REG,3);
}
