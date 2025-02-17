/*
 * SPI_Wiht_MAX7221.c
 *
 * Created: 2/13/2025 10:41:49 AM
 * Author : Lenovo
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
void execute(unsigned char cmd , unsigned char data)
{
	PORTB &= ~(1<<4); // set ss to be low to allow transmit
	SPDR = cmd ; // send first byte (cmd)
	while(!(SPSR & (1 << SPIF))); // wait until the transmit  is done  
	SPDR = data ; // send first byte (data)
	while(!(SPSR & (1 << SPIF))); // wait until the transmit  is done
	PORTB |= (1<<4); // set ss to be high to end transmit

}
int main(void)
{
	unsigned char counter =0;
	unsigned char indx_display ;
	// set mosi & ss & clck as output
	DDRB |= (1<<4) | (1<<5) | (1<<7);
	// enabel spi & and set as a master & set clock speed to 16
	SPCR |= (1 << SPE ) | ( 1<< MSTR) | (1 << SPR0);
    /* Replace with your application code */
	execute(0x09,0xff); // decode 0-7 digits
	execute(0x0B,0x07); // scan limit 
	execute(0x0A,0x0f); // set the Intensity
	execute(0x0C,0x01); // decode 0-7 digits

    while (1) 
    {
		for (indx_display=1 ; indx_display < 9 ; indx_display++)
		{
			
			execute(indx_display,counter++);
			_delay_ms(1000);
		}
		
    }
}

