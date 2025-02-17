/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define MCU_Act_as_Master
//#define MCU_Act_as_slave

#include "stm32f103x6.h"
#include "stm32f103c6_gpio_driver.h"
#include "stm32f103c6_EXTI_driver.h"
#include "stm32f103c6_UART_driver.h"
#include "stm32f103c6_SPI_driver.h"

uint16_t ch ;
void my_wait(int x)
{
	int i , j ;
	for (i = 0; i < x; ++i) {
		for (j = 0; j < 255; ++j);
	}
}
void USART_CallBack (void)
{
#ifdef MCU_Act_as_Master
	MCAL_USART_ReciveData(USART1, &ch, disable);
	MCAL_USART_SendData(USART1, &ch, enable);
	// send to SPI
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_ReSet);
	MCAL_SPI_Transmit_Receive(SPI1,  &ch, spi_enable);
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_Set);

#endif
}
int main(void)
{
	// enable clock
	GPIOA_CLK_EN();
	GPIOB_CLK_EN();
	AFIO_CLK_EN();

	USART_Config_t USART_CFG ;

	USART_CFG.BuadRate      = USART_BaudRate_115200bps;
	USART_CFG.Flow_Ctrl     = USART_FlowCtrl_None;
	USART_CFG.IRQ_Enable	= USART_IRQ_Enable_RXNEIE;
	USART_CFG.P_CallBack	= USART_CallBack;
	USART_CFG.USART_Mode	= USART_Mode_TX_RX;
	USART_CFG.parity_bit	= USART_Parity_None;
	USART_CFG.stop_bit		= USART_StopBit_1bit;
	USART_CFG.word_lenght	= USART_WordLen_8bit;
	MCAL_USART_Init(USART1, &USART_CFG);
	MCAL_USART_GPIO_SetPin(USART1);

	SPI_Config_t Spi1_config;
	// common configuration
	Spi1_config.SPI_Clock_Phase = SPI_Clock_Phase_2ndEdge;
	Spi1_config.SPI_Clock_Polarity= SPI_Clock_Polarity_High;
	Spi1_config.SPI_Data_Size_Format = SPI_Data_Size_Format_8Bit;
	Spi1_config.SPI_Fram_Format=SPI_Fram_Format_MsbFirst;
	Spi1_config.SPI_Baud_Rate_Prescaller = SPI_Baud_Rate_Prescaller_8;
#ifdef MCU_Act_as_Master
	Spi1_config.SPI_Device_Mode = SPI_Device_Mode_Master;
	Spi1_config.SPI_IRQ_Enable =SPI_IRQ_Enable_None;
	Spi1_config.NSS_Mode = NSS_Mode_Soft_Set;
	Spi1_config.P_CallBack= NULL;
#endif
	MCAL_SPI_Init(SPI1, &Spi1_config);
	MCAL_SPI_GPIO_Set_Pin(SPI1);
	// use GPIO to control NSS
	GPIO_PinConfig_t gpio_nss_config;
	gpio_nss_config.PinNumber = GPIO_PIN_4;
	gpio_nss_config.PinMode= GPIO_MODE_Output_PP;
	gpio_nss_config.OutPutSpeed= GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOA, &gpio_nss_config);
	// write one on the nss pin
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_Set);
	while(1)
	{

	}
}
