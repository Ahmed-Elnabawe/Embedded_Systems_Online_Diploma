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
	unsigned char ch =0 ;
	I2C_Set_Address(0b11010000);
    while (1) 
    {
		I2C_Read(1);
		I2C_write(ch++);
    }
}

