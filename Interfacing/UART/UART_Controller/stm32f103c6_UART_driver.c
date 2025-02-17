/*
 * stm32f103c6_UART_driver.c
 *
 *  Created on: Feb 5, 2025
 *      Author: Lenovo
 */

#include "stm32f103x6.h"
#include "stm32f103c6_UART_driver.h"
#include "stm32f103c6_gpio_driver.h"
#include "stm32f103c6_RCC_Partial_driver.h"
/*
 * =======================================================================================
 * 							Generic Variables
 * =======================================================================================
 */
USART_Config_t* Global_USART_Config[3]  = {NULL,NULL,NULL} ;
uint8_t index  ;
/*
 * =======================================================================================
 * 							Generic Macros
 * =======================================================================================
 */


/*
 * =======================================================================================
 * 							Generic Functions
 * =======================================================================================
 */



/**================================================================
 * @Fn				-MCAL_UART_Init
 * @brief 			- Initializes UART (Supported feature ASYNCH. Only)
 * @param [in] 		- USARTx: where x can be (1..3 depending on device used)
 * @param [in] 		- UART_Config: All UART Configuration EXTI_PinConfig_t
 * @retval 			-none
 * Note				-Support for Now Asynch mode & Clock 8 MHZ S
 */
void MCAL_USART_Init(USART_TypeDef* USARTx,USART_Config_t* USART_Cnfg)
{
	// check what USART we deal with
	// enable USART Clock
	if(USARTx==USART1)
	{
		index=0;
		Global_USART_Config[index]=USART_Cnfg;
		USART1_CLK_EN();
	}
	else if(USARTx==USART2)
	{
		index=1;
		Global_USART_Config[index]=USART_Cnfg;
		USART2_CLK_EN();
	}
	else if(USARTx==USART3)
	{
		index=2;
		Global_USART_Config[index]=USART_Cnfg;
		USART3_CLK_EN();
	}
	// enable USART Module
	//	Bit 13 UE: USART enable
	//	When this bit is cleared the USART prescalers and outputs are stopped and the end of the
	//	current
	//	byte transfer in order to reduce power consumption. This bit is set and cleared by software.
	//	0: USART prescaler and outputs disabled
	//	1: USART enabled
	USARTx->CR1|= 1<<13;
	//===================================================//
	//Set USART Mode
	USARTx->CR1 |= Global_USART_Config[index]->USART_Mode ;
	//===================================================//
	//Set USART Parity Mode
	USARTx->CR1 |= Global_USART_Config[index]->parity_bit ;
	//===================================================//
	//Set USART Stop Bit
	USARTx->CR1 |= Global_USART_Config[index]->stop_bit ;
	//===================================================//
	//Set USART Data Word Length
	USARTx->CR1 |= Global_USART_Config[index]->word_lenght ;
	//===================================================//
	//Set USART Flow Control
	USARTx->CR3 |= Global_USART_Config[index]->Flow_Ctrl ;
	//===================================================//
	//Set USART BaudRate
	uint32_t pClk , BRR;
	if(USARTx == USART1) pClk= MCAL_RCC_GetPCLK2Freq();
	else pClk = MCAL_RCC_GetPCLK1Freq();
	BRR=UART_BRR_Register(pClk,Global_USART_Config[index]->BuadRate);
	USARTx->BRR=BRR;
	//===================================================//
	//Set USART Interrupt enabel
	if(Global_USART_Config[index]->IRQ_Enable != USART_IRQ_Enable_NONE)
	{
		USARTx->CR1 |= Global_USART_Config[index]->IRQ_Enable ;
		// Enable NVIC
		if(USARTx == USART1) NVIC_IQR37_USART1_Enable;
		else if(USARTx == USART2) NVIC_IQR38_USART2_Enable;
		else if(USARTx == USART3) NVIC_IQR39_USART3_Enable;
	}
}
/**================================================================
 * @Fn				-MCAL_UART_DEInit
 * @brief 			- DEInitializes UART (Supported feature ASYNCH. Only)
 * @param [in] 		- USARTx: where x can be (1..3 depending on device used)
 * @retval 			-none
 * Note				-Reset the Model By RCC
 */
void MCAL_USART_Denit(USART_TypeDef* USARTx)
{
	if(USARTx==USART1)
	{
		USART1_CLK_Reset();
		NVIC_IQR37_USART1_Disable;
	}
	else if(USARTx==USART2)
	{
		USART2_CLK_Reset();
		NVIC_IQR38_USART2_Disable;
	}
	else if(USARTx==USART3)
	{
		USART3_CLK_Reset();
		NVIC_IQR39_USART3_Disable;
	}

}
/*********************************************************************
 * @fn      		  - MCAL_UART_SendData
 *
 * @brief             -Send Buffer on UART
 *
 * @param [in] 		- USARTx: where x can be (1..3 depending on device used)
 * @param[in]         -pTxBuffer Buffer
 * @param[in]         -PollingEn   Enable pooling or dsable it
 *
 * @return            -

 * @Note              - Should initialize UART First
 * 		//			When transmitting with the parity enabled (PCE bit set to 1 in the USART_CR1 register),
			//			the value written in the MSB (bit 7 or bit 8 depending on the data length) has no effect
			//			because it is replaced by the parity.
			//			When receiving with the parity enabled, the value read in the MSB bit is the received parity
			//			bit

 */
void MCAL_USART_SendData(USART_TypeDef* USARTx,uint16_t * pTX,enum Polling_mechism pollingEn)
{
	// check the polling
	if(pollingEn == enable)
		while( ! (USARTx->SR & (1<<7)) );

	if(USARTx==USART1)      index=0;

	else if(USARTx==USART2)	index=1;

	else if(USARTx==USART3)	index=2;

	if(Global_USART_Config[index]->word_lenght == USART_WordLen_9bit)
	{
		USARTx->DR = (*pTX & (uint16_t)(0x01ff));
	}
	else
	{
		USARTx->DR = (*pTX & (uint8_t)(0xff));
	}

}
void MCAL_USART_ReciveData(USART_TypeDef* USARTx,uint16_t * pRX,enum Polling_mechism pollingEn)
{
	// check the polling
	if(pollingEn == enable)
		while( ! (USARTx->SR & (1<<5)) );

	if(USARTx==USART1)      index=0;

	else if(USARTx==USART2)	index=1;

	else if(USARTx==USART3)	index=2;

	if(Global_USART_Config[index]->word_lenght == USART_WordLen_9bit)
	{
		if(Global_USART_Config[index]->parity_bit == USART_Parity_None)
		{
			// all of 9 bits are data
			*((uint16_t*)pRX) = USARTx->DR;
		}
		else
		{
			// 8 bits are data and 1 for parity
			*((uint16_t*)pRX) = (USARTx->DR & (uint8_t)0xff);
		}
	}
	else
	{
		if(Global_USART_Config[index]->parity_bit == USART_Parity_None)
		{
			// all of 8 bits are data
			*((uint16_t*)pRX) = (USARTx->DR & (uint8_t)0xff);
		}
		else
		{
			// 7 bits are data and 1 for parity
			*((uint16_t*)pRX) = (USARTx->DR & (uint8_t)0x7f);
		}
	}


}
void MCAL_USART_Wait_TC(USART_TypeDef* USARTx)
{
	// wait until TC flag equal 1
	while(! (USARTx->SR & (1<<6)));

}
/**================================================================
 * @Fn				-MCAL_UART_GPIO_Set_Pins
 * @brief 			- intialize GPIO Pins
 * @param [in] 		- USARTx: where x can be (1..3 depending on device used)
 * @retval 			-none
 * Note				-Should enable the corresponding ALT  & GPIO  in RCC clock Also called after MCAL_UART_Init()
 */
void MCAL_USART_GPIO_SetPin(USART_TypeDef* USARTx)
{
	if(USARTx==USART1)      index=0;
	else if(USARTx==USART2)	index=1;
	else if(USARTx==USART3)	index=2;
	// for TX -> Alternate function push-pull
	// for RX -> Input floating / Input pull-up
	// for CTS -> Input floating/ Input pull-up
	// for RTS->  Alternate function push-pull
	GPIO_PinConfig_t config_bin ;
	if(USARTx == USART1)
	{
		// TX   PA9
		// RX	PA10
		// CTS	PA11
		// RTS	PA12

		// TX
		config_bin.PinNumber = GPIO_PIN_9;
		config_bin.PinMode = GPIO_MODE_Output_AF_PP;
		config_bin.OutPutSpeed = GPIO_SPEED_10M ;
		MCAL_GPIO_Init(GPIOA, &config_bin);
		// RX
		config_bin.PinNumber = GPIO_PIN_10;
		config_bin.PinMode = GPIO_MODE_Input_AF;
		MCAL_GPIO_Init(GPIOA, &config_bin);
		if((Global_USART_Config[index]->Flow_Ctrl == USART_FlowCtrl_CTS) || (Global_USART_Config[index]->Flow_Ctrl == USART_FlowCtrl_CTS_RTS) )
		{
			// CTS
			config_bin.PinNumber = GPIO_PIN_11;
			config_bin.PinMode = GPIO_MODE_Input_AF;
			MCAL_GPIO_Init(GPIOA, &config_bin);

		}

		if((Global_USART_Config[index]->Flow_Ctrl == USART_FlowCtrl_RTS) || (Global_USART_Config[index]->Flow_Ctrl == USART_FlowCtrl_CTS_RTS) )
		{
			// RTS
			config_bin.PinNumber = GPIO_PIN_12;
			config_bin.PinMode = GPIO_MODE_Output_AF_PP;
			config_bin.OutPutSpeed = GPIO_SPEED_10M ;
			MCAL_GPIO_Init(GPIOA, &config_bin);

		}
	}
	else if (USARTx == USART2)
	{
		// TX   PA2
		// RX	PA3
		// CTS	PA0
		// RTS	PA1

		// TX
		config_bin.PinNumber = GPIO_PIN_2;
		config_bin.PinMode = GPIO_MODE_Output_AF_PP;
		config_bin.OutPutSpeed = GPIO_SPEED_10M ;
		MCAL_GPIO_Init(GPIOA, &config_bin);
		// RX
		config_bin.PinNumber = GPIO_PIN_3;
		config_bin.PinMode = GPIO_MODE_Input_AF;
		MCAL_GPIO_Init(GPIOA, &config_bin);
		if((Global_USART_Config[index]->Flow_Ctrl == USART_FlowCtrl_CTS) || (Global_USART_Config[index]->Flow_Ctrl == USART_FlowCtrl_CTS_RTS) )
		{
			// CTS
			config_bin.PinNumber = GPIO_PIN_0;
			config_bin.PinMode = GPIO_MODE_Input_AF;
			MCAL_GPIO_Init(GPIOA, &config_bin);

		}

		if((Global_USART_Config[index]->Flow_Ctrl == USART_FlowCtrl_RTS) || (Global_USART_Config[index]->Flow_Ctrl == USART_FlowCtrl_CTS_RTS) )
		{
			// RTS
			config_bin.PinNumber = GPIO_PIN_1;
			config_bin.PinMode = GPIO_MODE_Output_AF_PP;
			config_bin.OutPutSpeed = GPIO_SPEED_10M ;
			MCAL_GPIO_Init(GPIOA, &config_bin);

		}
	}
	else if (USARTx == USART3)
	{
		// TX   PB10
		// RX	PB11
		// CTS	PB13
		// RTS	PB14

		// TX
		config_bin.PinNumber = GPIO_PIN_10;
		config_bin.PinMode = GPIO_MODE_Output_AF_PP;
		config_bin.OutPutSpeed = GPIO_SPEED_10M ;
		MCAL_GPIO_Init(GPIOB, &config_bin);
		// RX
		config_bin.PinNumber = GPIO_PIN_11;
		config_bin.PinMode = GPIO_MODE_Input_AF;
		MCAL_GPIO_Init(GPIOB, &config_bin);
		if((Global_USART_Config[index]->Flow_Ctrl == USART_FlowCtrl_CTS) || (Global_USART_Config[index]->Flow_Ctrl == USART_FlowCtrl_CTS_RTS) )
		{
			// CTS
			config_bin.PinNumber = GPIO_PIN_13;
			config_bin.PinMode = GPIO_MODE_Input_AF;
			MCAL_GPIO_Init(GPIOB, &config_bin);

		}

		if((Global_USART_Config[index]->Flow_Ctrl == USART_FlowCtrl_RTS) || (Global_USART_Config[index]->Flow_Ctrl == USART_FlowCtrl_CTS_RTS) )
		{
			// RTS
			config_bin.PinNumber = GPIO_PIN_14;
			config_bin.PinMode = GPIO_MODE_Output_AF_PP;
			config_bin.OutPutSpeed = GPIO_SPEED_10M ;
			MCAL_GPIO_Init(GPIOB, &config_bin);

		}
	}
}

//ISR
void USART1_IRQHandler (void)
{
	Global_USART_Config[0]->P_CallBack () ;
}

void USART2_IRQHandler (void)
{
	Global_USART_Config[1]->P_CallBack () ;

}
void USART3_IRQHandler (void)
{
	Global_USART_Config[2]->P_CallBack () ;
}
