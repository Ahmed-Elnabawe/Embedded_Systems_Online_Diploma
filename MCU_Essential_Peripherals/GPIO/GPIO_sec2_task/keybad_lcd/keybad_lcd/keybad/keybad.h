/*
 * keybad.h
 *
 * Created: 12/12/2024 8:53:57 PM
 *  Author: Lenovo
 */ 


#ifndef KEYBAD_H_
#define KEYBAD_H_
#define F_CPU 100000000UL
#include <avr/io.h>
#include <util/delay.h>


#define KEYBAD_PORT	PORTC
#define KEYBAD_DATA_DIRECTION DDRC
#define KEYBAD_PIN	PINC

#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define c0 4
#define c1 5
#define c2 6
#define c3 7


void KEYBAD_INIT();
char KEYBAD_GET_KEY();


#endif /* KEYBAD_H_ */