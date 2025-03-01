/*
 * I2C_section1_lab1_slave.c
 *
 * Created: 2/21/2025 10:07:36 AM
 * Author : Lenovo
 */ 


#include "I2C.h"


int main(void)
{
    /* Replace with your application code */
	DDRA = 0xff;
	I2C_Set_Address(0b11010000);
    while (1) 
    {
		PORTA = I2C_Read(1);
    }
}

