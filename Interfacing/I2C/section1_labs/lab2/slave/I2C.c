/*
 * I2C.c
 *
 * Created: 2/21/2025 10:10:14 AM
 *  Author: Lenovo
 */ 
#include "I2C.h"

void I2C_Set_Address(unsigned char address)
{
	TWAR = address;
}
unsigned char I2C_Read(unsigned char ack)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(ack<<TWEA);
	while((TWCR & (1<<7))==0);
	while(TWSR != 0xA8);
	//TWCR = (1<<TWINT)|(1<<TWEN)|(ack<<TWEA);
	//while((TWCR & (1<<7))==0);
	//while(TWSR != 0x80);
	return TWDR;
}
void I2C_write(unsigned char ch )
{
	TWDR = ch;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while ((TWCR & (1<<TWINT)) == 0);
}