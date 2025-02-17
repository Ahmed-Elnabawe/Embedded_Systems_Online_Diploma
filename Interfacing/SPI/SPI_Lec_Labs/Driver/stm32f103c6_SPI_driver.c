/*
 * stm32f103c6_SPI_driver.c
 *
 *  Created on: Feb 15, 2025
 *      Author: Lenovo
 */
#include "stm32f103x6.h"
#include "stm32f103c6_SPI_driver.h"
#include "stm32f103c6_gpio_driver.h"

/*
 * =======================================================================================
 * 							Generic Variables
 * =======================================================================================
 */
SPI_Config_t * Global_SPI_Config[2]  = {NULL,NULL} ;
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


//------------------- APIs--------------------//

void MCAL_SPI_Init(SPI_TypeDef * SPIx , SPI_Config_t * SPI_config )
{
	// two registers for safty
	uint16_t CR1 = 0;
	uint16_t CR2 = 0;
	//enable spi
	CR1 |= (1<<6);
	// check on the instance
	if(SPIx == SPI1)
	{
		index =0;
		Global_SPI_Config[index] = SPI_config;
		// enable clock
		SPI1_CLK_EN();
	}
	else if(SPIx == SPI2)
	{
		index =1;
		Global_SPI_Config[index] = SPI_config;
		// enable clock
		SPI2_CLK_EN();
	}
	// set device mode
	CR1 |= SPI_config->SPI_Device_Mode;
	// set communication mode
	CR1 |= SPI_config->SPI_comunication_Mode;
	// set data size
	CR1 |= SPI_config->SPI_Data_Size_Format;
	// set frame format mode
	CR1 |= SPI_config->SPI_Fram_Format;
	// set baud rate prescaller
	CR1 |= SPI_config->SPI_Baud_Rate_Prescaller;
	// set clock polarity
	CR1 |= SPI_config->SPI_Clock_Polarity;
	// set clock phase
	CR1 |= SPI_config->SPI_Clock_Phase;
	// set NSS pin mode
	if((SPI_config->NSS_Mode == NSS_Mode_Hard_Slave) || (SPI_config->NSS_Mode == NSS_Mode_Soft_Reset) || (SPI_config->NSS_Mode == NSS_Mode_Soft_Set))
	{
		CR1 |= SPI_config->NSS_Mode;
	}
	else if ((SPI_config->NSS_Mode == NSS_Mode_Hard_Master_Input) || (SPI_config->NSS_Mode == NSS_Mode_Hard_Master_OutPut))
	{
		CR2 |= SPI_config->NSS_Mode;
	}
	// set interrupt
	if(SPI_config->SPI_IRQ_Enable != SPI_IRQ_Enable_None)
	{
		CR2 = SPI_config->SPI_IRQ_Enable;
		// enable nvic
		if(SPIx == SPI1)
		{
			NVIC_IQR35_SPI1_Enable;
		}
		else if (SPIx == SPI2)
		{
			NVIC_IQR36_SPI2_Enable;
		}
	}

	SPIx->CR1 = CR1;
	SPIx->CR2 = CR2;
}
void MCAL_SPI_Deinit(SPI_TypeDef * SPIx )
{
	if(SPIx == SPI1)
	{
		SPI1_CLK_Reset();
		NVIC_IQR35_SPI1_Disable;
	}
	else if (SPIx == SPI2)
	{
		SPI2_CLK_Reset();
		NVIC_IQR36_SPI2_Disable;
	}
}
void MCAL_SPI_Transmit(SPI_TypeDef * SPIx ,uint16_t* buffer ,enum spi_Polling polling_En)
{
	if(polling_En == spi_enable )
		while (!((SPIx->SR) & (1<<1)));

	SPIx->DR = *buffer;
}
void MCAL_SPI_Receive(SPI_TypeDef * SPIx ,uint16_t* buffer ,enum spi_Polling polling_En)
{
	if(polling_En == spi_enable )
		while (!((SPIx->SR) & (1<<0)));

	*buffer = SPIx->DR ;
}
void MCAL_SPI_Transmit_Receive(SPI_TypeDef * SPIx ,uint16_t *buffer ,enum spi_Polling polling_En)
{
	if(polling_En == spi_enable )
		while (!((SPIx->SR) & (1<<1)));
	SPIx->DR = *buffer;
	if(polling_En == spi_enable )
		while (!((SPIx->SR) & (1<<0)));
	*buffer = SPIx->DR ;
}
void MCAL_SPI_GPIO_Set_Pin(SPI_TypeDef * SPIx )
{
	GPIO_PinConfig_t GPIO_config;
	if(SPIx == SPI1)
	{
		// PA4 NSS
		// PA5 sck
		// PA6 MISO
		// PA7 MOSI
		if(Global_SPI_Config[0]->SPI_Device_Mode == SPI_Device_Mode_Master)
		{
			// if Master
			// PA4 NSS  --> input if nss output disable and Alternate function push-pull if nss output enable and not used if software
			switch (Global_SPI_Config[0]->NSS_Mode)
			{
			case NSS_Mode_Hard_Master_Input:
				// hardware master input or hardware slave
				// PA4 --> input floating
				GPIO_config.PinNumber = GPIO_PIN_4;
				GPIO_config.PinMode	  = GPIO_MODE_Input_FLO;
				MCAL_GPIO_Init(GPIOA, &GPIO_config);
				break;
			case NSS_Mode_Hard_Master_OutPut:
				// PA4 --> Alternate function push-pull
				GPIO_config.PinNumber  = GPIO_PIN_4;
				GPIO_config.PinMode    = GPIO_MODE_Output_PP;
				GPIO_config.OutPutSpeed= GPIO_SPEED_10M;
				MCAL_GPIO_Init(GPIOA, &GPIO_config);
				break;
			}
			// PA5 sck --> Alternate function push-pull
			GPIO_config.PinNumber = GPIO_PIN_5;
			GPIO_config.PinMode	= GPIO_MODE_Output_AF_PP;
			GPIO_config.OutPutSpeed =GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &GPIO_config);
			// PA6 MISO --> Input floating (support full duplex only )
			GPIO_config.PinNumber = GPIO_PIN_6;
			GPIO_config.PinMode	= GPIO_MODE_Input_FLO;
			MCAL_GPIO_Init(GPIOA, &GPIO_config);
			// PA7 MOSI --> Alternate function push-pull (support full duplex only )
			GPIO_config.PinNumber = GPIO_PIN_7;
			GPIO_config.PinMode	= GPIO_MODE_Output_AF_PP;
			GPIO_config.OutPutSpeed =GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &GPIO_config);
		}
		else // if slave
		{
			// PA4 --> input floating
			if(Global_SPI_Config[0]->NSS_Mode == NSS_Mode_Hard_Slave)
			{
				// PA4 --> input floating
				GPIO_config.PinNumber = GPIO_PIN_4;
				GPIO_config.PinMode	  = GPIO_MODE_Input_FLO;
				MCAL_GPIO_Init(GPIOA, &GPIO_config);
			}
			// PA5 sck --> Input floating
			GPIO_config.PinNumber = GPIO_PIN_5;
			GPIO_config.PinMode	  = GPIO_MODE_Input_FLO;
			MCAL_GPIO_Init(GPIOA, &GPIO_config);
			// PA6 MISO --> Alternate function push-pull note: we support only (Full duplex (point to point) )
			// to do (Full duplex / slave (multi-slave))
			GPIO_config.PinNumber = GPIO_PIN_6;
			GPIO_config.PinMode	= GPIO_MODE_Output_AF_PP;
			GPIO_config.OutPutSpeed =GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &GPIO_config);
			// PA7 MOSI --> Input floating
			GPIO_config.PinNumber = GPIO_PIN_7;
			GPIO_config.PinMode	  = GPIO_MODE_Input_FLO;
			MCAL_GPIO_Init(GPIOA, &GPIO_config);
		}
	}
	else if (SPIx == SPI2)
	{
		// PB12 NSS
		// PB13 sck
		// PB14 MISO
		// PB15 MOSI

		if(Global_SPI_Config[1]->SPI_Device_Mode == SPI_Device_Mode_Master)
		{
			// if Master
			// PB12 NSS  --> input if nss output disable and Alternate function push-pull if nss output enable and not used if software
			switch (Global_SPI_Config[1]->NSS_Mode)
			{
			case NSS_Mode_Hard_Master_Input:
				// hardware master input or hardware slave
				// PB12 --> input floating
				GPIO_config.PinNumber = GPIO_PIN_12;
				GPIO_config.PinMode	  = GPIO_MODE_Input_FLO;
				MCAL_GPIO_Init(GPIOB, &GPIO_config);
				break;
			case NSS_Mode_Hard_Master_OutPut:
				// PB12 --> Alternate function push-pull
				GPIO_config.PinNumber  = GPIO_PIN_12;
				GPIO_config.PinMode    = GPIO_MODE_Output_PP;
				GPIO_config.OutPutSpeed= GPIO_SPEED_10M;
				MCAL_GPIO_Init(GPIOB, &GPIO_config);
				break;
			}
			// PB13 sck --> Alternate function push-pull
			GPIO_config.PinNumber = GPIO_PIN_13;
			GPIO_config.PinMode	= GPIO_MODE_Output_AF_PP;
			GPIO_config.OutPutSpeed =GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &GPIO_config);
			// PB14 MISO --> Input floating (support full duplex only )
			GPIO_config.PinNumber = GPIO_PIN_14;
			GPIO_config.PinMode	= GPIO_MODE_Input_FLO;
			MCAL_GPIO_Init(GPIOB, &GPIO_config);
			// PB15 MOSI --> Alternate function push-pull (support full duplex only )
			GPIO_config.PinNumber = GPIO_PIN_15;
			GPIO_config.PinMode	= GPIO_MODE_Output_AF_PP;
			GPIO_config.OutPutSpeed =GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &GPIO_config);
		}
		else // if slave
		{
			// PB12 --> input floating
			if(Global_SPI_Config[1]->NSS_Mode == NSS_Mode_Hard_Slave)
			{
				// PB12 --> input floating
				GPIO_config.PinNumber = GPIO_PIN_12;
				GPIO_config.PinMode	  = GPIO_MODE_Input_FLO;
				MCAL_GPIO_Init(GPIOB, &GPIO_config);
			}
			// PB13 sck --> Input floating
			GPIO_config.PinNumber = GPIO_PIN_13;
			GPIO_config.PinMode	  = GPIO_MODE_Input_FLO;
			MCAL_GPIO_Init(GPIOB, &GPIO_config);
			// PB14 MISO --> Alternate function push-pull note: we support only (Full duplex (point to point) )
			// to do (Full duplex / slave (multi-slave))
			GPIO_config.PinNumber = GPIO_PIN_14;
			GPIO_config.PinMode	= GPIO_MODE_Output_AF_PP;
			GPIO_config.OutPutSpeed =GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &GPIO_config);
			// PB15 MOSI --> Input floating
			GPIO_config.PinNumber = GPIO_PIN_15;
			GPIO_config.PinMode	  = GPIO_MODE_Input_FLO;
			MCAL_GPIO_Init(GPIOB, &GPIO_config);
		}

	}
}



//------------------- ISR --------------------//

void SPI1_IRQHandler (void)
{
	struct S_IRQ_SRC	interrupt_src ;
	interrupt_src.TXEIE =((SPI1->SR & (1<<1))>>1);
	interrupt_src.RXNEIE =((SPI1->SR & (1<<0))>>0);
	interrupt_src.ERRIE =((SPI1->SR & (1<<4))>>4);
	Global_SPI_Config[0]->P_CallBack(interrupt_src);

}

void SPI2_IRQHandler (void)
{
	struct S_IRQ_SRC	interrupt_src ;
	interrupt_src.TXEIE =((SPI2->SR & (1<<1))>>1);
	interrupt_src.RXNEIE =((SPI2->SR & (1<<0))>>0);
	interrupt_src.ERRIE =((SPI2->SR & (1<<4))>>4);
	Global_SPI_Config[1]->P_CallBack(interrupt_src);
}




















