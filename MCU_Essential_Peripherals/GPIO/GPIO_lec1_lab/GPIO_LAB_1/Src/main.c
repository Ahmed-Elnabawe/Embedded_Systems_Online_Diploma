#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
//-----------------clock registers---------//
#define RCC_BASE (0x40021000)
#define RCC_APB2ENR  *(volatile uint32_t*)(RCC_BASE+0x18)
//---------------GPIOA registers---------------------//
#define GPIOA_BASE (0x40010800)
#define GPIOA_CRL  *(volatile uint32_t*)(GPIOA_BASE+0x00)
#define GPIOA_CRH  *(volatile uint32_t*)(GPIOA_BASE+0x04)
#define GPIOA_IDR  *(volatile uint32_t*)(GPIOA_BASE+0x08)
//---------------GPIOB registers---------------------//
#define GPIOB_BASE (0x40010C00)
#define GPIOB_CRL  *(volatile uint32_t*)(GPIOB_BASE+0x00)
#define GPIOB_CRH  *(volatile uint32_t*)(GPIOB_BASE+0x04)
#define GPIOB_ODR  *(volatile uint32_t*)(GPIOB_BASE+0x0c)

void wait(int x)
{
	int i , j ;
	for (i = 0; i < x; ++i) {
		for (j = 0; j < 255; ++j);
	}
}
void clock_init()
{
	// allow clocking for GPIO PORT B
	//Bit 3 IOPBEN: IO port B clock enable
	//Set and cleared by software.
	//0: IO port B clock disabled
	//1: IO port B clock enabled
	RCC_APB2ENR|=(1<<3);
	// allow clocking for GPIO PORT A
	RCC_APB2ENR|=(1<<2);
}
void GPIO_init()
{
	// for portA
	// pin1 input with external pull up
	GPIOA_CRL=0; // reset all register
	GPIOA_CRL|= 1<<6;
	// pin13 input with external pull down
	GPIOA_CRH=0; // reset all register
	GPIOA_CRH|=1<<22;
	// for portB
	GPIOB_CRL=0; // reset all register
	GPIOB_CRH=0; // //
	// pin1 output push-pull
	GPIOB_CRL|=0b01<<4;
	GPIOB_CRL&=~(0b11<<6);
	// pin13 output push-pull
	GPIOB_CRH|=0b01<<20;
	GPIOB_CRH&=~(0b11<<22);
}
int main(void)
{
	clock_init();
	GPIO_init();
	while(1)
	{
		if(((GPIOA_IDR&(1<<1))>>1)==0)
		{
			GPIOB_ODR^=1<<1;
			while(((GPIOA_IDR&(1<<1))>>1)==0);
		}
		if(((GPIOA_IDR&(1<<13))>>13)==1)
		{
			GPIOB_ODR^=1<<13;

		}
		wait(1);
	}
}
