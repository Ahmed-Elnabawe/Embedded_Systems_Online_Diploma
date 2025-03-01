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
	I2C_Init(0x48);
    while (1) 
    {
		_delay_ms(500);
		I2C_Start();
		I2C_write(0b11010000+0);  // send the address to the slave
		while(TWSR != 0x18);	 // wait until the address is transmitted
		I2C_write(ch++);		// send the data 
		while(TWSR != 0x28);	// wait until the data is sent
		I2C_Stop();
    }
}

