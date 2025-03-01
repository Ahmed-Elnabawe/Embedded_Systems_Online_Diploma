/*
 * stm32f103c6_I2C_driver.c
 *
 *  Created on: Feb 27, 2025
 *      Author: Lenovo
 */

#include "stm32f103c6_I2C_driver.h"
/*
 * =======================================================================================
 * 							Generic Variables
 * =======================================================================================
 */
I2C_config_t  Global_I2C_Config[2] = {0}  ;
/*
 * =======================================================================================
 * 							Generic Macros
 * =======================================================================================
 */

#define I2C1_INDEX			0
#define I2C2_INDEX			1

/*
 * =======================================================================================
 * 							Generic Functions
 * =======================================================================================
 */
flag_state get_flagState(I2C_TypeDef * I2Cx,I2C_flag flag)
{
	flag_state return_flag ;
	switch (flag) {
	case busy_flag:
	{
		// check on the bus if idle or not
		//  I2C_SR2 .busy flag
		//	0: No communication on the bus
		//	1: Communication ongoing on the bus
		//	– Set by hardware on detection of SDA or SCL low
		//	– cleared by hardware on detection of a Stop condition
		if((I2Cx->SR2 & (I2C_SR2_BUSY)))
			return_flag = set ;
		else
			return_flag = reset ;
		break ;
	}
	case EV5:
	{
		//  Start bit (Master mode)
		//	0: No Start condition
		//	1: Start condition generated
		if(I2Cx->SR1 & (I2C_SR1_SB))
			return_flag = set;
		else
			return_flag =reset;
		break ;
	}
	case EV6:
	{
		if(I2Cx->SR1 & (I2C_SR1_ADDR))
			return_flag = set;
		else
			return_flag =reset;
		break ;
	}
	case EV8_1:
	case EV8:
	{
		if(I2Cx->SR1 & (I2C_SR1_TXE))
			return_flag = set;
		else
			return_flag =reset;
		break ;
	}
	case EV8_2:
	{
		if((I2Cx->SR1 & (I2C_SR1_TXE)) && (I2Cx->SR1 & (I2C_SR1_BTF)))
			return_flag = set;
		else
			return_flag =reset;
		break ;
	}
	case EV7:
	{
		if(I2Cx->SR1 & (I2C_SR1_RXNE))
			return_flag = set;
		else
			return_flag =reset;
		break ;
	}
	}



	return return_flag;
}
void generat_start(I2C_TypeDef * I2Cx,start_state state , Start_condition start)
{

	if(start != repeated_start)
	{
		while(get_flagState(I2Cx, busy_flag));
		// wait until the bus is idle
	}
	if(state != start_disable )
	{
		I2Cx->CR1 |= I2C_CR1_START;
	}
	else
	{
		I2Cx->CR1 &= ~(I2C_CR1_START);
	}

}
void Send_Address (I2C_TypeDef * I2Cx , uint8_t address , direction_state direction )
{
	address = address << 1 ;
	if(direction == Read)
	{
		address |= (1<<0) ;
	}
	else
	{
		address &= ~(1<<0) ;
	}
	I2Cx->DR = address ;
}

void generat_stop(I2C_TypeDef * I2Cx, Stop_condition stop)
{
	if(stop == with_stop )
	{
		I2Cx->CR1 |= I2C_CR1_STOP;
	}
	else
	{
		I2Cx->CR1 &= ~(I2C_CR1_STOP);
	}

}
void ACK_Configuration(I2C_TypeDef * I2Cx ,ACK_state state)
{
	if(state != ack_disable )
	{
		I2Cx->CR1 |= I2C_CR1_ACK;
	}
	else
	{
		I2Cx->CR1 &= ~(I2C_CR1_ACK);
	}
}
//------------------- APIs--------------------//

void MCAL_I2C_Init(I2C_TypeDef * I2Cx , I2C_config_t * i2c_confg)
{
	uint32_t fpclk1 , fi2c ;
	uint16_t temp , result ;
	// enable RCC
	if(I2Cx == I2C1)
	{
		I2C1_CLK_EN();
		Global_I2C_Config[I2C1_INDEX]=*i2c_confg;
	}
	else
	{
		I2C2_CLK_EN();
		Global_I2C_Config[I2C2_INDEX]=*i2c_confg;
	}
	//	The following is the required sequence in master mode.
	//	• Program the peripheral input clock in I2C_CR2 Register in order to generate correct
	//	timings
	//	• Configure the clock control registers
	//	• Configure the rise time register
	//	• Program the I2C_CR1 register to enable the peripheral
	//	• Set the START bit in the I2C_CR1 register to generate a Start condition
	//	The peripheral input clock frequency must be at least:

	// timing configuration //
	fpclk1 = MCAL_RCC_GetPCLK1Freq();

	temp = I2Cx->CR2;
	temp &= ~(0b111111<<I2C_CR2_FREQ_Pos); // Reset the value of FREQ bits
	temp |= (uint16_t)(fpclk1/1000000);
	I2Cx->CR2 = temp;
	fi2c = i2c_confg->I2C_clockSpeed;
	result = (uint16_t)(fpclk1/(fi2c << 1));
	temp=0;
	temp |= result;
	I2Cx->CCR = temp;
	temp =0 ;
	result = ((uint16_t)(fpclk1/1000000))+1;
	temp |= result;
	I2Cx->TRISE = temp ;
	//-------------------------//
	temp = I2Cx->CR1;
	// stretching mode
	temp |= (uint16_t)i2c_confg->I2C_stretchMode;
	// Acknowledge mode
	temp |= (uint16_t)i2c_confg->I2C_ACKcontrol;
	// general address call
	temp |= (uint16_t)i2c_confg->I2C_General_call_back_address;
	I2Cx->CR1 = temp ;
	// address set in OAR1
	temp=0;
	temp |= (1<<14); //Bit 14 Should always be kept at 1 by software
	temp |= ((uint16_t)i2c_confg->I2C_slaveAddress)<<1;
	I2Cx->OAR1 = temp ;
	// we support interrupt mechanism only in slave mode so we will enable the interrupt if the call back function not equal null
	if(i2c_confg->P_Slave_Event_CallBack != NULL)
	{
		// you are in slave mode
		I2Cx->CR2 |= (I2C_CR2_ITERREN);
		I2Cx->CR2 |= (I2C_CR2_ITBUFEN);
		I2Cx->CR2 |= (I2C_CR2_ITEVTEN);
		if(I2Cx == I2C1)
		{
			NVIC_IQR31_I2C1_EV_Enable;
			NVIC_IQR32_I2C1_ER_Enable;
		}
		else
		{
			NVIC_IQR33_I2C2_EV_Enable;
			NVIC_IQR34_I2C2_ER_Enable;
		}
	}
	// enable the peripheral
	I2Cx->CR1 |= (I2C_CR1_PE);

}
void MCAL_I2C_DeInit(I2C_TypeDef * I2Cx )
{
	if(I2Cx == I2C1)
	{
		I2C1_CLK_Reset();
		NVIC_IQR31_I2C1_EV_Disable;
		NVIC_IQR32_I2C1_ER_Disable;
	}
	else
	{
		I2C2_CLK_Reset();
		NVIC_IQR33_I2C2_EV_Disable;
		NVIC_IQR34_I2C2_ER_Disable;
	}

}
void MCAL_I2C_GPIO_SET_PINS(I2C_TypeDef * I2Cx )
{
	GPIO_PinConfig_t GPIO_pin ;
	if(I2Cx == I2C1)
	{
		// scl -> PB6 Alternate function open drain
		// SDA -> PB7 Alternate function open drain
		GPIO_pin.PinNumber = GPIO_PIN_6;
		GPIO_pin.PinMode=GPIO_MODE_Output_AF_OD;
		GPIO_pin.OutPutSpeed=GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &GPIO_pin);

		GPIO_pin.PinNumber = GPIO_PIN_7;
		GPIO_pin.PinMode=GPIO_MODE_Output_AF_OD;
		GPIO_pin.OutPutSpeed=GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &GPIO_pin);
	}
	else
	{
		// scl -> PB10 Alternate function open drain
		// SDA -> PB11 Alternate function open drain
		GPIO_pin.PinNumber = GPIO_PIN_10;
		GPIO_pin.PinMode=GPIO_MODE_Output_AF_OD;
		GPIO_pin.OutPutSpeed=GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &GPIO_pin);

		GPIO_pin.PinNumber = GPIO_PIN_11;
		GPIO_pin.PinMode=GPIO_MODE_Output_AF_OD;
		GPIO_pin.OutPutSpeed=GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &GPIO_pin);
	}


}
void MCAL_I2C_Master_TX(I2C_TypeDef * I2Cx ,uint16_t divAddress,uint8_t * data , uint32_t data_length ,Stop_condition stop, Start_condition start )
{
	int i = 0 ; // counter to loop on the data length
	// 1- send start condition on the bus
	generat_start(I2Cx, start_enable, start);
	// check on EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
	while(!get_flagState(I2Cx, EV5));
	// write the address on DR
	Send_Address(I2Cx, divAddress , Write);
	// EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2.
	while(!get_flagState(I2Cx, EV6));
	// EV8_1: TxE=1, shift register empty, data register empty, write Data1 in DR
	while(!get_flagState(I2Cx,EV8_1));
	// send the data
	for(i=0;i<data_length;i++)
	{
		I2Cx->DR = data[i];
		while(!get_flagState(I2Cx,EV8));
	}
	//EV8_2: TxE=1, BTF = 1, Program Stop request. TxE and BTF are cleared by hardware by the Stop condition
	while(!get_flagState(I2Cx,EV8_2));
	// send stop condition
	generat_stop(I2Cx, stop);

}
void MCAL_I2C_Master_RX(I2C_TypeDef * I2Cx ,uint16_t divAddress,uint8_t * data , uint32_t data_length ,Stop_condition stop, Start_condition start )
{
	uint8_t index = (I2Cx == I2C1)? I2C1_INDEX: I2C2_INDEX ;
	int i = 0 ; // loop counter for count the length
	// 1- send start condition on the bus
	generat_start(I2Cx, start_enable, start);
	// check on EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
	while(!get_flagState(I2Cx, EV5));
	// write the address on DR
	Send_Address(I2Cx, divAddress , Read);
	// EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2.
	while(!get_flagState(I2Cx, EV6));
	ACK_Configuration(I2Cx, ack_enable);
	if(data_length)
	{
		for(i = data_length;i > 1; i--)
		{
			// EV7 : RxNE=1 cleared by reading DR register
			while(!get_flagState(I2Cx, EV7));
			*data=I2Cx->DR;
			data++;
		}
		ACK_Configuration(I2Cx, ack_disable);
	}

	generat_stop(I2Cx, stop);
	if(Global_I2C_Config[index].I2C_ACKcontrol == I2C_ACKcontrol_Enable)
		ACK_Configuration(I2Cx, ack_enable);


}
