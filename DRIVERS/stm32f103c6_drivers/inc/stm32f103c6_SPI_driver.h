/*
 * stm32f103c6_SPI_driver.h
 *
 *  Created on: Feb 15, 2025
 *      Author: Lenovo
 */

#ifndef INC_STM32F103C6_SPI_DRIVER_H_
#define INC_STM32F103C6_SPI_DRIVER_H_

#include "stm32f103x6.h"
#include "stm32f103c6_gpio_driver.h"

struct S_IRQ_SRC
{
	uint8_t   TXEIE 	:1;
	uint8_t   RXNEIE	:1;
	uint8_t   ERRIE 	:1;
	uint8_t   reserved	:5;
};

// Configuration Structure //
typedef struct
{
	uint8_t		 SPI_Device_Mode			;   // this variable contain the Mode of the SPI Master / Slave
												// set this variable according to  @ref SPI_Device_Mode_define

	uint8_t 	SPI_comunication_Mode 		;	// this variable contain the Mode of SPI 2lines / 1line
												// set this variable according to @ref SPI_comunication_Mode_define

	uint32_t	SPI_Data_Size_Format		;	// this variable is set to choose the data frame format 8bit / 16bit
												// set this variable according to @ref SPI_Data_Size_Format_define

	uint16_t		NSS_Mode					;	// this variable for select mode of NSS pin
												// set this variable according to @ref NSS_Mode_define

	uint8_t		SPI_Fram_Format				;	// this variable for select data frame MSB / LSB
												// set this variable according to @ref SPI_Fram_Format_define

	uint8_t		SPI_Baud_Rate_Prescaller    ;	// this variable for select the clock on the clock bin in master
												// set this variable according to @ref SPI_Baud_Rate_Prescaller_define

	uint8_t		SPI_Clock_Polarity			;	// select the idle state of clock high or low
												// set this variable according to @ref SPI_Clock_Polarity_define

	uint8_t		SPI_Clock_Phase				;	// select the sampling edge first edge or second edge
												// set this variable according to @ref SPI_Clock_phase_define

	uint8_t		SPI_IRQ_Enable				;	// enable or disable SPI IRQ interrupts
												// set this variable according to @ref SPI_IRQ_Enable_define

	void(*P_CallBack)(struct S_IRQ_SRC src)	;    // pointer to function to be set for interrupt handling


}SPI_Config_t;



enum spi_Polling{
	spi_enable,
	spi_disable
};

// references //
// @ref SPI_Device_Mode_define //
//Bit 2 MSTR: Master selection
//0: Slave configuration
//1: Master configuration
#define SPI_Device_Mode_Master						(uint16_t)(1<<2)			// put it in CR1
#define SPI_Device_Mode_Slave						(uint16_t)(0)				// put it in CR1
//==============================================//
//@ref SPI_comunication_Mode_define //
//Bit 15 BIDIMODE: Bidirectional data mode enable
//0: 2-line unidirectional data mode selected
//1: 1-line bidirectional data mode selected

//Bit 14 BIDIOE: Output enable in bidirectional mode
//This bit combined with the BIDImode bit selects the direction of transfer in bidirectional mode
//0: Output disabled (receive-only mode)
//1: Output enabled (transmit-only mode)

//Bit 10 RXONLY: Receive only
//This bit combined with the BIDImode bit selects the direction of transfer in 2-line
//unidirectional mode. This bit is also useful in a multislave system in which this particular
//slave is not accessed, the output from the accessed slave is not corrupted.
//0: Full duplex (Transmit and receive)
//1: Output disabled (Receive-only mode)
#define SPI_comunication_Mode_2lines				(uint16_t)(0)					// put it in CR1
#define SPI_comunication_Mode_2lines_RXONLY			(uint16_t)(1<<10)				// put it in CR1
#define SPI_comunication_Mode_1line_RXONLY			(uint16_t)(1<<15)				// put it in CR1
#define SPI_comunication_Mode_1line_TXONLY			(uint16_t)((1<<15) | (1<<14))	// put it in CR1
//==============================================//
// @ref SPI_Data_Size_Format_define //
//Bit 11 DFF: Data frame format
//0: 8-bit data frame format is selected for transmission/reception
//1: 16-bit data frame format is selected for transmission/reception
#define SPI_Data_Size_Format_8Bit					(uint16_t)(0)					// put it in CR1
#define SPI_Data_Size_Format_16Bit					(uint16_t)(1<<11)				// put it in CR1
//==============================================//
// @ref NSS_Mode_define //
//Bit 9 SSM: Software slave management
//When the SSM bit is set, the NSS pin input is replaced with the value from the SSI bit.
//0: Software slave management disabled
//1: Software slave management enabled
//Bit 2 SSOE: SS output enable (in CR2 )
//0: SS output is disabled in master mode and the cell can work in multimaster configuration
//1: SS output is enabled in master mode
//        hardware      //
#define NSS_Mode_Hard_Slave							(uint16_t)(0) 				// put it in CR1
#define NSS_Mode_Hard_Master_OutPut					(uint16_t)(1<<2) 			// put it in CR2
#define NSS_Mode_Hard_Master_Input					(uint16_t)(0)    			// put it in CR2
//        software      //
// master or slave
#define NSS_Mode_Soft_Set							(uint16_t)((1<<9) | (1<<8)) // put it in CR1
#define NSS_Mode_Soft_Reset							(uint16_t)(1<<9) 			// put it in CR1
//==============================================//
// @ref SPI_Fram_Format_define //
//Bit 7 LSBFIRST: Frame format
//0: MSB transmitted first
//1: LSB transmitted first
#define SPI_Fram_Format_LsbFirst					(uint16_t)(1<<7) 			// put it in CR1
#define SPI_Fram_Format_MsbFirst					(uint16_t)(0)   	 		// put it in CR1
//==============================================//
//  @ref SPI_Baud_Rate_Prescaller_define
//Bits 5:3 BR[2:0]: Baud rate control
//000: fPCLK/2
//001: fPCLK/4
//010: fPCLK/8
//011: fPCLK/16
//100: fPCLK/32
//101: fPCLK/64
//110: fPCLK/128
//111: fPCLK/256
#define SPI_Baud_Rate_Prescaller_2				(uint16_t)(0b000 << 3)		// put it in CR1
#define SPI_Baud_Rate_Prescaller_4				(uint16_t)(0b001 << 3)		// put it in CR1
#define SPI_Baud_Rate_Prescaller_8				(uint16_t)(0b010 << 3)		// put it in CR1
#define SPI_Baud_Rate_Prescaller_16				(uint16_t)(0b011 << 3)		// put it in CR1
#define SPI_Baud_Rate_Prescaller_32				(uint16_t)(0b100 << 3)		// put it in CR1
#define SPI_Baud_Rate_Prescaller_64				(uint16_t)(0b101 << 3)		// put it in CR1
#define SPI_Baud_Rate_Prescaller_128			(uint16_t)(0b110 << 3)		// put it in CR1
#define SPI_Baud_Rate_Prescaller_256			(uint16_t)(0b111 << 3)		// put it in CR1
//==============================================//
// @ref SPI_Clock_Polarity_define //
//Bit1 CPOL: Clock polarity
//0: CK to 0 when idle
//1: CK to 1 when idle
#define SPI_Clock_Polarity_High						(uint16_t)(1<<1)			// put it in CR1
#define SPI_Clock_Polarity_Low						(uint16_t)(0)				// put it in CR1
//==============================================//
// @ref SPI_Clock_phase_define //
//Bit 0 CPHA: Clock phase
//0: The first clock transition is the first data capture edge
//1: The second clock transition is the first data capture edge
#define SPI_Clock_Phase_1stEdge						(uint16_t)(0)				// put it in CR1
#define SPI_Clock_Phase_2ndEdge						(uint16_t)(1<<0)			// put it in CR1
//==============================================//
// @ref SPI_IRQ_Enable_define //
//Bit 7 TXEIE: Tx buffer empty interrupt enable
//0: TXE interrupt masked
//1: TXE interrupt not masked. Used to generate an interrupt request when the TXE flag is set.
//Bit 6 RXNEIE: RX buffer not empty interrupt enable
//0: RXNE interrupt masked
//1: RXNE interrupt not masked. Used to generate an interrupt request when the RXNE flag is
//set.
//Bit 5 ERRIE: Error interrupt enable
//This bit controls the generation of an interrupt when an error condition occurs (CRCERR,
//OVR, MODF in SPI mode and UDR, OVR in I2S mode).
//0: Error interrupt is masked
//1: Error interrupt is enabled
#define SPI_IRQ_Enable_TXEIE						(uint16_t)(1<<7)			// put it in CR2
#define SPI_IRQ_Enable_RXNEIE						(uint16_t)(1<<6)			// put it in CR2
#define SPI_IRQ_Enable_ERRIE						(uint16_t)(1<<5)			// put it in CR2
#define SPI_IRQ_Enable_None							(uint16_t)(0)			// put it in CR2


//------------------------ APIs--------------------//
void MCAL_SPI_Init(SPI_TypeDef * SPIx , SPI_Config_t * SPI_config );
void MCAL_SPI_Deinit(SPI_TypeDef * SPIx );
void MCAL_SPI_Transmit(SPI_TypeDef * SPIx ,uint16_t* buffer ,enum spi_Polling polling_En);
void MCAL_SPI_Receive(SPI_TypeDef * SPIx ,uint16_t* buffer ,enum spi_Polling polling_En);
void MCAL_SPI_Transmit_Receive(SPI_TypeDef * SPIx ,uint16_t* buffer ,enum spi_Polling polling_En);
void MCAL_SPI_GPIO_Set_Pin(SPI_TypeDef * SPIx );


#endif /* INC_STM32F103C6_SPI_DRIVER_H_ */
