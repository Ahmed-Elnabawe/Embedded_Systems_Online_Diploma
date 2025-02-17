/*
 * stm32f103c6_UART_driver.h
 *
 *  Created on: Feb 5, 2025
 *      Author: Lenovo
 */

#ifndef INC_STM32F103C6_UART_DRIVER_H_
#define INC_STM32F103C6_UART_DRIVER_H_
#include "stm32f103x6.h"
#include "stm32f103c6_gpio_driver.h"

typedef struct
{
	uint8_t		 USART_Mode	;   // this variable contain the Mode of the USART Enable / Disable
								// set this variable according to @ref USART_Mode_define

	uint8_t 	word_lenght ;	// this variable contain the length of the date will be send
								// set this variable according to @ref USART_WordLen_define

	uint32_t	BuadRate	;	// this variable should have the baud rate which will be used in USART
								// set this variable according to @ref USART_BaudRate_define

	uint8_t		stop_bit	;	// this variable for select how many stop bit you want
								// set this variable according to @ref USART_StopBit_define

	uint8_t		parity_bit	;	// this variable for select the parity mode
								// set this variable according to @ref USART_Parity_define

	uint8_t		Flow_Ctrl	;	// this variable for select if you need to use flow control or not
								// set this variable according to @ref USART_FlowCtrl_define

	uint8_t		IRQ_Enable	;	// enable or disable USART IRQ TX/RX
								// set this variable according to @ref USART_IRQ_Enable_define

	void(*P_CallBack)(void);    // pointer to function to be set for interrupt handling

}USART_Config_t;

enum Polling_mechism{
	enable,
	disable
};
// References //
//----------------------//
//@ref USART_Mode_define
#define USART_Mode_TX					(uint32_t)(1<<3)
#define USART_Mode_RX 					(uint32_t)(1<<2)
#define USART_Mode_TX_RX 				(uint32_t)(1<<3 | 1<<2)

//@ref USART_WordLen_define
#define USART_WordLen_8bit				(uint32_t)(0)
#define USART_WordLen_9bit				(uint32_t)(1<<12)

//@ref USART_BaudRate_define
#define USART_BaudRate_2400bps			2400
#define USART_BaudRate_9600bps			9600
#define USART_BaudRate_19200bps			19200
#define USART_BaudRate_57600bps			57600
#define USART_BaudRate_115200bps		115200
#define USART_BaudRate_230400bps		230400
#define USART_BaudRate_460800bps		460800
#define USART_BaudRate_921600bps		921600
#define USART_BaudRate_2250000bps		2250000
#define USART_BaudRate_4500000bps		4500000

//@ref USART_StopBit_define
#define USART_StopBit_1bit				(uint32_t)((0 & 0x3)<<12)
#define USART_StopBit_halfBit	 		(uint32_t)((1 & 0x3)<<12)
#define USART_StopBit_2bit				(uint32_t)((2 & 0x3)<<12)
#define USART_StopBit_1Halfbit 		    (uint32_t)((3 & 0x3)<<12)

//@ref USART_Parity_define
#define USART_Parity_None				(uint32_t)(0)
#define USART_Parity_Even				(uint32_t)(1<<10)
#define USART_Parity_Odd				(uint32_t)(1<<10 | 1<<9)

//@ref USART_FlowCtrl_define
#define USART_FlowCtrl_None				(uint32_t)(0)
#define USART_FlowCtrl_CTS				(uint32_t)(1<<9)
#define USART_FlowCtrl_RTS				(uint32_t)(1<<8)
#define USART_FlowCtrl_CTS_RTS			(uint32_t)(1<<9 | 1<<8)

//@ref USART_IRQ_Enable_define
#define USART_IRQ_Enable_NONE           (uint32_t)(0)
#define USART_IRQ_Enable_TXE            (uint32_t) (1<<7) //Transmit data register empty
#define USART_IRQ_Enable_TC             (uint32_t)(1<<6)  //Transmission complete
#define USART_IRQ_Enable_RXNEIE         (uint32_t) (1<<5) //Received data ready to be read & Overrun error detected
#define USART_IRQ_Enable_PE         																					    (uint32_t) (1<<8) //Parity error

//BaudRate Calculation
//USARTDIV = fclk / (16 * Baudrate)
//USARTDIV_MUL100 =
// uint32((100 *fclk ) / (16 * Baudrate) == (25 *fclk ) / (4* Baudrate) )
//DIV_Mantissa_MUL100 = Integer Part (USARTDIV  )  * 100
//DIV_Mantissa = Integer Part (USARTDIV  )
//DIV_Fraction = (( USARTDIV_MUL100  - DIV_Mantissa_MUL100  ) * 16 ) / 100

#define USARTDIV(_PCLK_, _BAUD_)							(uint32_t) (_PCLK_/(16 * _BAUD_ ))
#define USARTDIV_MUL100(_PCLK_, _BAUD_)						(uint32_t) ( (25 * _PCLK_ ) / (4  * _BAUD_ ))
#define Mantissa_MUL100(_PCLK_, _BAUD_)						(uint32_t) (USARTDIV(_PCLK_, _BAUD_) * 100)
#define Mantissa(_PCLK_, _BAUD_)							(uint32_t) (USARTDIV(_PCLK_, _BAUD_) )
#define DIV_Fraction(_PCLK_, _BAUD_)						(uint32_t) (((USARTDIV_MUL100(_PCLK_, _BAUD_) -  Mantissa_MUL100(_PCLK_, _BAUD_) ) * 16 ) / 100 )
#define UART_BRR_Register(_PCLK_, _BAUD_)					(( Mantissa (_PCLK_, _BAUD_) ) <<4 )|( (DIV_Fraction(_PCLK_, _BAUD_)) & 0xF )



//------------------------ APIs--------------------//

void MCAL_USART_Init(USART_TypeDef* USARTx,USART_Config_t* USART_Cnfg);
void MCAL_USART_Denit(USART_TypeDef* USARTx);
void MCAL_USART_SendData(USART_TypeDef* USARTx,uint16_t * pTX,enum Polling_mechism pollingEn);
void MCAL_USART_ReciveData(USART_TypeDef* USARTx,uint16_t * pTX,enum Polling_mechism pollingEn);
void MCAL_USART_Wait_TC(USART_TypeDef* USARTx);
void MCAL_USART_GPIO_SetPin(USART_TypeDef* USARTx);




#endif /* INC_STM32F103C6_UART_DRIVER_H_ */
