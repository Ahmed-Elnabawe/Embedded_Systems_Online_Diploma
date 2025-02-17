/*
 * keybad.h
 *
 * Created: 12/12/2024 8:53:57 PM
 *  Author: Lenovo
 */ 


#ifndef KEYBAD_H_
#define KEYBAD_H_
#include "stm32f103c6_gpio_driver.h"
#include "stm32f103x6.h"


#define KEYBAD_PORT	GPIOB
//#define KEYBAD_DATA_DIRECTION DDRC
//#define KEYBAD_PIN	GPIOB

#define R0 GPIO_PIN_0
#define R1 GPIO_PIN_1
#define R2 GPIO_PIN_3
#define R3 GPIO_PIN_4
#define c0 GPIO_PIN_5
#define c1 GPIO_PIN_6
#define c2 GPIO_PIN_7
#define c3 GPIO_PIN_8


void KEYBAD_INIT();
char KEYBAD_GET_KEY();


#endif /* KEYBAD_H_ */
