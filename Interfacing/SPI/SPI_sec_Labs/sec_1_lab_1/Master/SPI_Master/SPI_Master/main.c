/*
 * SPI_Master.c
 *
 * Created: 2/13/2025 9:29:57 AM
 * Author : Lenovo
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

void SPI_Master_Init(void)
{
	// set mosi & ss & clck as output 
	DDRB |= (1<<4) | (1<<5) | (1<<7);
	// set miso as input 
	DDRB  &= ~ (1<<6) ;
	// enabel spi & and set as a master & set clock speed to 16   
	SPCR |= (1 << SPE ) | ( 1<< MSTR) | (1 << SPR0);
	
}
unsigned char SPI_Master_send(unsigned char data )
{
	SPDR = data ; // set the data to be transmit in the register 
	while(!(SPSR & (1 << SPIF))); // wait until the transmit and receive is done    
	return SPDR;  // return the data received
}

int main(void)
{
    /* Replace with your application code */
	unsigned char ch =0;
	DDRA = 0xff; // configure port A as output for 7_segment
	SPI_Master_Init();
	for(ch =0 ; ch <= 255 ;ch ++)
	{
		_delay_ms(1000);
		 PORTA = SPI_Master_send(ch);
	}
}
