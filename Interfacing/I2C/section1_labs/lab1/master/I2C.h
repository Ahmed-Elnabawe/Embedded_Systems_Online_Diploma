/*
 * I2C.h
 *
 * Created: 2/21/2025 9:22:35 AM
 *  Author: Lenovo
 */ 


#ifndef I2C_H_
#define I2C_H_
#define F_CPU 8000000UL
#define prescaler 1
#include "avr/io.h"
void I2C_Init (unsigned char SCL_Clock);
void I2C_Start (void);
void I2C_write(unsigned char ch);
void I2C_Stop(void);
unsigned char I2C_Read(unsigned char ch );



#endif /* I2C_H_ */