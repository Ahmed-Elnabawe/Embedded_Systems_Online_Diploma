/*
 * main.c
 *
 * Created: 11/25/2024 9:17:33 PM
 *  Author: Lenovo
 */ 

#define F_CPU  8000000UL

#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/delay.h>


#define IO_BASE 0x20
#define PORTD_DR *(volatile uint32_t*)(IO_BASE+0x12)
#define PORTD_DDR *(volatile uint32_t*)(IO_BASE+0x11)
#define PORTB_DR *(volatile uint32_t*)(IO_BASE+0x18)
#define PORTB_DDR *(volatile uint32_t*)(IO_BASE+0x17)
#define MCUCR *(volatile uint32_t*)(IO_BASE+0x35)
#define MCUCSR *(volatile uint32_t*)(IO_BASE+0x34)
#define GICR *(volatile uint32_t*)(IO_BASE+0x3B)
#define GIFR *(volatile uint32_t*)(IO_BASE+0x3A)
#define SREG *(volatile uint32_t*)(IO_BASE+0x3f)

int main(void)
{
	sei();
	// set bins for port D as output
	//PORTD_DDR|=(1<<2); // INT 0
	//PORTD_DDR|=(1<<3); // INT 1
	PORTD_DDR|=(1<<5); // led 1
	PORTD_DDR|=(1<<6); // led 2
	PORTD_DDR|=(1<<7); // led 3
	// set bin for port b as output 
	//PORTB_DR|=(1<<2); // INT 2
	// set INT 0 as faling and rising detection 
	MCUCR|=(1<<0);
	// set INT 1 as rising detection
	MCUCR|=(1<<2);
	MCUCR|=(1<<3);
	// set INT 2 as faling detection
	MCUCSR&=~(1<<6);
	// masking the three INTs
	GICR|=(1<<5);
	GICR|=(1<<6);
	GICR|=(1<<7);

    while(1)
    {
       PORTD_DR &= ~(1<<5);
	   PORTD_DR &= ~(1<<6);
	   PORTD_DR &= ~(1<<7);
    }
}



ISR(INT0_vect)
{
	 PORTD_DR |= (1<<5);
	 _delay_ms(100);
}
ISR(INT1_vect)
{
	PORTD_DR |= (1<<6);
	_delay_ms(100);
}
ISR(INT2_vect)
{
	PORTD_DR |= (1<<7);
	_delay_ms(100);
}