/*
 * I2C_section1_lab1.c
 *
 * Created: 2/21/2025 9:16:06 AM
 * Author : Lenovo
 */ 

#include <avr/io.h>
#include "I2C.h"
#include <util/delay.h>
int main(void)
{
	unsigned char ch=0;
	DDRA = 0xff;
	I2C_Init(0x48);
    while (1) 
    {
		_delay_ms(500);
		I2C_Start();
		I2C_write(0b11010000+1);  // send the address to the slave
		ch = I2C_Read(0);		// read form slave and send not ack 
		I2C_Stop();
		PORTA=ch;
    }
}

