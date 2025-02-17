/*
 * stm32f103x6.h
 *
 *  Created on: Dec 14, 2024
 *      Author: Lenovo
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

//------------------------------------------//
//---------------- INCLUDES ----------------//
//------------------------------------------//
#include "stdlib.h"
#include <stdint.h>
//----------------------------------------------------------//
//---------------- BASE ADRESESS OF MEMORY ----------------//
//----------------------------------------------------------//
#define FLASH_MEMORY_BASE 			0x08000000UL
#define SYSTEM_MEMORY_BASE		 	0x1ffff000UL
#define PERIPHERALS_BASE 			0x40000000UL
#define CORTEX_M3_PERIPHERALS_BASE 	0xE0000000UL
//------------------------------------------------------------//
//---------------- PERIPHERALS BASE ADRESESS  ----------------//
//------------------------------------------------------------//

//---------------- AHB ----------------//
// RCC //
#define 	RCC_BASE 				0x40021000UL
//---------------- APB2 ----------------//
// GPIO //
// IN LQFP48
// GPIOA and GPIOB fully included
#define 	GPIOA_BASE 				0x40010800UL
#define 	GPIOB_BASE 				0x40010C00UL
// GPIOC and GPIOD partially included
#define 	GPIOC_BASE 				0x40011000UL
#define 	GPIOD_BASE 				0x40011400UL
// GPIOE not included
#define 	GPIOE_BASE 				0x40011800UL
// EXTI //
#define 	EXTI_BASE 				0x40010400L
// AFIO //
#define 	AFIO_BASE 				0x40010000UL
//================================================================//
//--------------------------------------------------------//
//---------------- PERIPHERALS REGISTERS ----------------//
//------------------------------------------------------//
// GPIO REGISTERS //
typedef struct {
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_TypeDef;
// AFIO REGISTERS //
typedef struct {
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
			 uint32_t RESERVED;
	volatile uint32_t MAPR2;
}AFIO_TypeDef;
// EXTI REGISTERS //
typedef struct {
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_TypeDef;
// RCC REGISTERS //
typedef struct {
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t AHBSTR;
	volatile uint32_t CFGR2;
}RCC_TypeDef;

//================================================================//
//--------------------------------------------------------//
//---------------- PERIPHERALS INSTANTS ----------------//
//------------------------------------------------------//
#define GPIOA 	((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB 	((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC 	((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD 	((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE 	((GPIO_TypeDef *)GPIOE_BASE)
#define RCC 	((RCC_TypeDef *)RCC_BASE)
#define EXTI 	((EXTI_TypeDef *)EXTI_BASE)
#define AFIO 	((AFIO_TypeDef *)AFIO_BASE)
//================================================================//
//--------------------------------------------------------//
//---------------- CLK ENABLE MACROS ----------------//
//------------------------------------------------------//
#define  GPIOA_CLK_EN() 	(RCC->APB2ENR |= 1<<2)
#define  GPIOB_CLK_EN() 	(RCC->APB2ENR |= 1<<3)
#define  GPIOC_CLK_EN() 	(RCC->APB2ENR |= 1<<4)
#define  GPIOD_CLK_EN() 	(RCC->APB2ENR |= 1<<5)
#define  GPIOE_CLK_EN() 	(RCC->APB2ENR |= 1<<6)
#define  AFIO_CLK_EN() 		(RCC->APB2ENR |= 1<<0)


#endif /* INC_STM32F103X6_H_ */
