/*
 * I2C.h
 *
 * Created: 2/21/2025 10:10:30 AM
 *  Author: Lenovo
 */ 


#ifndef I2C_H_
#define I2C_H_
#include <avr/io.h>
#define F_CPU	8000000UL

void I2C_Set_Address(unsigned char address);
unsigned char I2C_Read(unsigned char ack);

void I2C_write(unsigned char ch );


#endif /* I2C_H_ */