/*
 * SPI_Slave.c
 *
 * Created: 2/13/2025 10:01:36 AM
 * Author : Lenovo
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

void SPI_Slave_Init(void)
{
	// set mosi & ss & clck as input
	DDRB &= ~(1<<4)  & ~(1<<5) & ~(1<<7);
	// set miso as output
	DDRB  |=  (1<<6) ;
	// enabel spi & and set as a master & set clock speed to 16
	SPCR  = (1 << SPE ) ;
	
}
unsigned char SPI_Slave_Recevie(unsigned char data )
{
	SPDR = data ; // set the data to be transmit to the master
	while(!(SPSR & (1 << SPIF))); // wait until the transmit and receive is done
	return SPDR;  // return the data received from the master
}

int main(void)
{
	/* Replace with your application code */
	unsigned char ch =0;
	DDRA = 0xff; // configure port A as output for 7_segment
	SPI_Slave_Init();
	for(ch =255 ; ch >= 0 ;ch--)
	{
		PORTA = SPI_Slave_Recevie(ch);
	}
}


