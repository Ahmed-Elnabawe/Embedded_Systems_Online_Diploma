/*
 * I2C.c
 *
 * Created: 2/21/2025 9:22:10 AM
 *  Author: Lenovo
 */ 
#include "I2C.h"
void I2C_Init (unsigned char SCL_Clock)
{
	TWBR =(unsigned char) (((F_CPU / SCL_Clock)-16)/(2*prescaler));
	if(prescaler == 1) TWSR =0 ;
	else if (prescaler == 4) TWSR =1;
	else if (prescaler == 16) TWSR =2;
	else if (prescaler == 64) TWSR =3;
}
void I2C_Start (void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while((TWCR & (1<<7)) == 0); // whait until the job compelet
	while (TWSR != 0x08);
	
}
void I2C_write(unsigned char ch )
{
	TWDR = ch;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while ((TWCR & (1<<TWINT)) == 0);
}
unsigned char I2C_Read(unsigned char ach)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(ack<<TWEA);
	while((TWCR & (1<<7))==0);
	while(TWSR != 0x80);
	return TWDR;
	
}
void I2C_Stop(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}