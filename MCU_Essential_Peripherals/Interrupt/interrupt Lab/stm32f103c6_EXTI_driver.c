/*
 * stm32f103c6_EXTI_driver.c
 *
 *  Created on: Jan 27, 2025
 *      Author: Ahmed Elnabawe
 */

#include "stm32f103c6_EXTI_driver.h"
//=============================================================//
//==================== Generic Macros =========================//
//=============================================================//
#define GET_GPIO_VAL(x)			(	(x==GPIOA)?0:\
									(x==GPIOB)?1:\
									(x==GPIOC)?2:\
									(x==GPIOD)?3:0	)
//=============================================================//
//==================== Generic Variables ======================//
//=============================================================//
void (*GP_Call_Back[16])(void) ;
//=============================================================//
//==================== Generic Functions ======================//
//=============================================================//
void Enable_NVIC(uint16_t EXTI_Line)
{
	switch(EXTI_Line)
	{
	case 0:
		NVIC_IQR6_EXTI0_Enable;
		break;
	case 1:
		NVIC_IQR7_EXTI1_Enable;
		break;
	case 2:
		NVIC_IQR8_EXTI2_Enable;
		break;
	case 3:
		NVIC_IQR9_EXTI3_Enable;
		break;
	case 4:
		NVIC_IQR10_EXTI4_Enable;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IQR23_EXTI5_9_Enable;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IQR40_EXTI10_15_Enable;
		break;

	}
}
void Disable_NVIC(uint16_t EXTI_Line)
{
	switch(EXTI_Line)
	{
	case 0:
		NVIC_IQR6_EXTI0_Disable;
		break;
	case 1:
		NVIC_IQR7_EXTI1_Disable;
		break;
	case 2:
		NVIC_IQR8_EXTI2_Disable;
		break;
	case 3:
		NVIC_IQR9_EXTI3_Disable;
		break;
	case 4:
		NVIC_IQR10_EXTI4_Disable;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IQR23_EXTI5_9_Disable;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IQR40_EXTI10_15_Disable;
		break;

	}
}
void update (EXTI_PinConfig_t * EXTI_Config)
{
	//1- init GPIO Pin to be input floating
	GPIO_PinConfig_t pincnfg ;
	pincnfg.PinNumber=EXTI_Config->EXTI_PIN.GPIO_PIN;
	pincnfg.PinMode=GPIO_MODE_Input_FLO;
	MCAL_GPIO_Init(EXTI_Config->EXTI_PIN.GPIO_Port, &pincnfg);
	//2- Update AFIO to rout EXTI line to port A,B,C,D
	uint8_t AFIO_index =EXTI_Config->EXTI_PIN.EXTI_InputLineNumber/4;
	uint8_t AFIO_position =(EXTI_Config->EXTI_PIN.EXTI_InputLineNumber%4)*4;
	// clear the 4 bits to prepare it to write on
	AFIO->EXTICR[AFIO_index]&=~(0xf<<AFIO_position);
	// select the port
	AFIO->EXTICR[AFIO_index]|=((GET_GPIO_VAL(EXTI_Config->EXTI_PIN.GPIO_Port) & 0xf)<<AFIO_position);
	//3- select trigger
	if(EXTI_Config->trigger_case==EXTI_Trigger_Rising)
	{
		EXTI->RTSR |= (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}
	else if (EXTI_Config->trigger_case==EXTI_Trigger_Falling)
	{
		EXTI->FTSR |= (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}
	else if(EXTI_Config->trigger_case==EXTI_Trigger_Rising_Falling)
	{
		EXTI->RTSR |= (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		EXTI->FTSR |= (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}
	//4- update call back function
	GP_Call_Back[EXTI_Config->EXTI_PIN.EXTI_InputLineNumber]=EXTI_Config->P_IRQ_CallBack;
	//5- enable mask for EXTI and NVIC
	if(EXTI_Config->IRQ_EN==EXTI_IRQ_Enable)
	{
		// enable mask for EXTI
		EXTI->IMR |= 1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber;
		// enable mask for NVIC
		Enable_NVIC(EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}
	else if(EXTI_Config->IRQ_EN==EXTI_IRQ_Disable)
	{
		// enable mask for EXTI
		EXTI->IMR &= ~(1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		// enable mask for NVIC
		Disable_NVIC(EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}

}
//======================================================================//

void MCAL_EXTI_GPIO_DeInit(void)
{
	// set registers values with reset values
	EXTI->IMR=0x00000000;
	EXTI->EMR=0x00000000;
	EXTI->RTSR=0x00000000;
	EXTI->FTSR=0x00000000;
	EXTI->PR=0xffffffff; // write one to clear
	// disable IRQ in NVIC
	NVIC_IQR6_EXTI0_Disable;
	NVIC_IQR7_EXTI1_Disable;
	NVIC_IQR8_EXTI2_Disable;
	NVIC_IQR9_EXTI3_Disable;
	NVIC_IQR10_EXTI4_Disable;
	NVIC_IQR23_EXTI5_9_Disable;
	NVIC_IQR40_EXTI10_15_Disable;
}
void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t * EXTI_Config)
{
	update(EXTI_Config);
}
void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t * EXTI_Config)
{
	update(EXTI_Config);
}




void EXTI0_IRQHandler (void)
{
	// clear pending  by writing 1
	EXTI->PR |= 1<<0;
	// calling user handler
	GP_Call_Back[0]();
}

void EXTI1_IRQHandler (void)
{
	// clear pending  by writing 1
	EXTI->PR |= 1<<1;
	// calling user handler
	GP_Call_Back[1]();
}
void EXTI2_IRQHandler (void)
{
	// clear pending  by writing 1
	EXTI->PR |= 1<<2;
	// calling user handler
	GP_Call_Back[2]();
}
void EXTI3_IRQHandler (void)
{
	// clear pending  by writing 1
	EXTI->PR |= 1<<3;
	// calling user handler
	GP_Call_Back[3]();
}
void EXTI4_IRQHandler (void)
{
	// clear pending  by writing 1
	EXTI->PR |= 1<<4;
	// calling user handler
	GP_Call_Back[4]();
}

void EXTI9_5_IRQHandler (void)
{
	if( EXTI->PR & 1<<5 ){	EXTI->PR |= 1<<5  ; GP_Call_Back[5]() ; }
	if( EXTI->PR & 1<<6 ){	EXTI->PR |= 1<<6  ; GP_Call_Back[6]() ; }
	if( EXTI->PR & 1<<7 ){	EXTI->PR |= 1<<7  ; GP_Call_Back[7]() ; }
	if( EXTI->PR & 1<<8 ){	EXTI->PR |= 1<<8  ; GP_Call_Back[8]() ; }
	if( EXTI->PR & 1<<9 ){	EXTI->PR |= 1<<9  ; GP_Call_Back[9]() ; }
}
void EXTI15_10_IRQHandler (void)
{
	if( EXTI->PR & 1<<10 ){	EXTI->PR |= 1<<10  ; GP_Call_Back[10]() ; }
	if( EXTI->PR & 1<<11 ){	EXTI->PR |= 1<<11  ; GP_Call_Back[11]() ; }
	if( EXTI->PR & 1<<12 ){	EXTI->PR |= 1<<12  ; GP_Call_Back[12]() ; }
	if( EXTI->PR & 1<<13 ){	EXTI->PR |= 1<<13  ; GP_Call_Back[13]() ; }
	if( EXTI->PR & 1<<14 ){	EXTI->PR |= 1<<14  ; GP_Call_Back[14]() ; }
	if( EXTI->PR & 1<<15 ){	EXTI->PR |= 1<<15  ; GP_Call_Back[15]() ; }

}
