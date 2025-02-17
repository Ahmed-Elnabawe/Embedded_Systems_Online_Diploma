/*
 * stm32f103c6_gpio_driver.c
 *
 *  Created on: Dec 14, 2024
 *      Author: Lenovo
 */

#include "stm32f103c6_gpio_driver.h"
uint8_t GET_CRLH_POSITION(uint16_t pinnumber)
{
	switch (pinnumber)
	{
	case GPIO_PIN_0:
		return 0;
		break;
	case GPIO_PIN_1:
		return 4;
		break;
	case GPIO_PIN_2:
		return 8;
		break;
	case GPIO_PIN_3:
		return 12;
		break;
	case GPIO_PIN_4:
		return 16;
		break;
	case GPIO_PIN_5:
		return 20;
		break;
	case GPIO_PIN_6:
		return 24;
		break;
	case GPIO_PIN_7:
		return 28;
		break;
	case GPIO_PIN_8:
		return 0;
		break;
	case GPIO_PIN_9:
		return 4;
		break;
	case GPIO_PIN_10:
		return 8;
		break;
	case GPIO_PIN_11:
		return 12;
		break;
	case GPIO_PIN_12:
		return 16;
		break;
	case GPIO_PIN_13:
		return 20;
		break;
	case GPIO_PIN_14:
		return 24;
		break;
	case GPIO_PIN_15:
		return 28;
		break;
	}
	return 0;
}
/**================================================================
 * @Fn			-MCAL_GPIO_Init
 * @brief 		-this function initialize GPIO pin according to parameters of pinConfig
 * @param[in] 	-GPIOx :where x can be (A.....E) and is the address of GPIO instant of the pin
 * @param[in] 	-pinConfig: pin configuration informations
 * @retval		-none
 * Note			-none
 */
void MCAL_GPIO_Init(GPIO_TypeDef * GPIOx,GPIO_PinConfig_t*pinConfig)
{
	uint32_t * configReg=(pinConfig->PinNumber<GPIO_PIN_8)? &(GPIOx->CRL):&(GPIOx->CRH);
	uint8_t PIN_config=0;
	// clear CNFx[1:0] MODEx[1:0]
	(*configReg)&=~(0xf<<GET_CRLH_POSITION(pinConfig->PinNumber));
	// if the pin output
	if((pinConfig->PinMode==GPIO_MODE_Output_AF_OD)||(pinConfig->PinMode==GPIO_MODE_Output_AF_PP)||(pinConfig->PinMode==GPIO_MODE_Output_OD)||(pinConfig->PinMode==GPIO_MODE_Output_PP))
	{
		PIN_config=((((pinConfig->PinMode-4)<<2)|(pinConfig->OutPutSpeed))&0x0f);
	}
	else // the pin is input
	{
		if((pinConfig->PinMode==GPIO_MODE_Analog)||(pinConfig->PinMode==GPIO_MODE_Input_FLO))
		{
			PIN_config=((((pinConfig->PinMode)<<2)|(0x0))&0x0f);
		}
		else if (pinConfig->PinMode==GPIO_MODE_Input_AF)// the same of the GPIO_MODE_Input_FLO
		{
			PIN_config=((((GPIO_MODE_Input_FLO)<<2)|(0x0))&0x0f);
		}
		else // the pin is PU or PD
		{
			PIN_config=((((GPIO_MODE_Input_PU)<<2)|(0x0))&0x0f);
			if(pinConfig->PinMode==GPIO_MODE_Input_PU) // according to table 20 if the input is pull up the PxODR register is 1
			{
				GPIOx->ODR|=pinConfig->PinNumber;
			}
			else  // according to table 20 if the input is pull down the PxODR register is 0
			{
				GPIOx->ODR&=~(pinConfig->PinNumber);
			}
		}
	}
	// write on the configuration register (maybe CRL or CRH)
	*(configReg)|=((PIN_config)<<GET_CRLH_POSITION(pinConfig->PinNumber));
}
/**================================================================
 * @Fn			-MCAL_GPIO_DeInit
 * @brief 		-this function reset GPIO port
 * @param[in] 	-GPIOx :where x can be (A.....E) and is the address of GPIO port instant
 * @retval		-none
 * Note			-none
 */
void MCAL_GPIO_DeInit(GPIO_TypeDef*GPIOx)
{
	//	Bit y IOPARST: I/O port x reset
	//	Set and cleared by software.
	//	0: No effect
	//	1: Reset I/O port x
	if(GPIOx==GPIOA)
	{
		RCC->APB2RSTR|=(1<<2);
		RCC->APB2RSTR&=~(1<<2);
	}
	else if(GPIOx==GPIOB)
	{
		RCC->APB2RSTR|=(1<<3);
		RCC->APB2RSTR&=~(1<<3);
	}
	else if(GPIOx==GPIOC)
	{
		RCC->APB2RSTR|=(1<<4);
		RCC->APB2RSTR&=~(1<<4);
	}
	else if(GPIOx==GPIOD)
	{
		RCC->APB2RSTR|=(1<<5);
		RCC->APB2RSTR&=~(1<<5);
	}
	else if(GPIOx==GPIOE)
	{
		RCC->APB2RSTR|=(1<<6);
		RCC->APB2RSTR&=~(1<<6);
	}
}
/**================================================================
 * @Fn			-MCAL_GPIO_ReadPin
 * @brief 		-Read Specific input pin value
 * @param[in] 	-GPIOx :where x can be (A.....E) and is the address of GPIO port instant
 * @param[in] 	-PinNumber : pin number according to @ref GPIO_PIN_define
 * @retval		-value of the input pin (two values according to @ref GPIO_PIN_state )
 * Note			-none
 */
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef*GPIOx,uint16_t PinNumber)
{
	uint8_t bitStates ;
	if (((GPIOx->IDR)&PinNumber)!=GPIO_PIN_ReSet)
	{
		bitStates=(uint8_t)GPIO_PIN_Set;
	}
	else
	{
		bitStates=(uint8_t)GPIO_PIN_ReSet;
	}
	return bitStates;
}
/**================================================================
 * @Fn			-MCAL_GPIO_ReadPort
 * @brief 		-Read Specific Port value
 * @param[in] 	-GPIOx :where x can be (A.....E) and is the address of GPIO port instant
 * @retval		-value of the port
 * Note			-none
 */
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef*GPIOx)
{
	uint16_t PortStates ;
	PortStates=(uint16_t)GPIOx->IDR;
	return PortStates;
}
/**================================================================
 * @Fn			-MCAL_GPIO_WritePin
 * @brief 		-write on Specific pin
 * @param[in] 	-GPIOx :where x can be (A.....E) and is the address of GPIO port instant
 * @param[in] 	-PinNumber : pin number according to @ref GPIO_PIN_define
 * @param[in] 	-value : value that you need to write it on the pin according to @ref GPIO_PIN_state
 * @retval		-none
 * Note			-none
 */
void MCAL_GPIO_WritePin(GPIO_TypeDef*GPIOx,uint16_t PinNumber,uint8_t value)
{
	if (value != GPIO_PIN_ReSet)
	{
		//GPIOx->ODR |= PinNumber;
		//	BSy: Port x Set bit y (y= 0 .. 15)
		//	These bits are write-only and can be accessed in Word mode only.
		//	0: No action on the corresponding ODRx bit
		//	1: Set the corresponding ODRx bit
		GPIOx->BSRR=(uint32_t)PinNumber;
	}
	else
	{
		//	BRy: Port x Reset bit y (y= 0 .. 15)
		//	These bits are write-only and can be accessed in Word mode only.
		//	0: No action on the corresponding ODRx bit
		//	1: Reset the corresponding ODRx bit
		GPIOx->BRR=(uint32_t)PinNumber;

	}
}
/**================================================================
 * @Fn			-MCAL_GPIO_WritePort
 * @brief 		-write on Specific port
 * @param[in] 	-GPIOx :where x can be (A.....E) and is the address of GPIO port instant
 * @param[in] 	-value : value that you need to write it on the Port
 * @retval		-none
 * Note			-none
 */
void MCAL_GPIO_WritePort(GPIO_TypeDef*GPIOx,uint16_t value)
{
	GPIOx->ODR=(uint32_t)value;
}



/**================================================================
 * @Fn			-MCAL_GPIO_ToggelPin
 * @brief 		-toggle Specific pin
 * @param[in] 	-GPIOx :where x can be (A.....E) and is the address of GPIO port instant
 * @param[in] 	-PinNumber : pin number according to @ref GPIO_PIN_define
 * @retval		-none
 * Note			-none
 */
void MCAL_GPIO_TogglePin(GPIO_TypeDef*GPIOx,uint16_t PinNumber)
{
	GPIOx->ODR ^=PinNumber;
}
/**================================================================
 * @Fn			-MCAL_GPIO_ToggelPin
 * @brief 		-toggle Specific pin
 * @param[in] 	-GPIOx :where x can be (A.....E) and is the address of GPIO port instant
 * @param[in] 	-PinNumber : pin number according to @ref GPIO_PIN_define
 * @retval		-lock information according to @ref GPIO_RETURN_lock
 * Note			-none
 */
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef*GPIOx,uint16_t PinNumber)
{
	//	Bit 16 LCKK[16]: Lock key
	//	This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
	//	0: Port configuration lock key not active
	//	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
	//	LOCK key writing sequence:
	//	Write 1
	//	Write 0
	//	Write 1
	//	Read 0
	//	Read 1 (this read is optional but confirms that the lock is active)
	//	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	//	Any error in the lock sequence will abort the lock.
	//	Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
	//	These bits are read write but can only be written when the LCKK bit is 0.
	//	0: Port configuration not locked
	//	1: Port configuration locked.
	volatile temp = 1<<16;
	temp|=PinNumber;
	//	LOCK key writing sequence:
	//	Write 1
	GPIOx->LCKR=temp;
	//	Write 0
	GPIOx->LCKR=PinNumber;
	//	Write 1
	GPIOx->LCKR=temp;
	//	Read 0
	temp=GPIOx->LCKR;
	//	Read 1 (this read is optional but confirms that the lock is active)
	if((uint32_t)(GPIOx->LCKR & 1<<16) )
	{
		return GPIO_RETURN_Lock_OK;
	}
	else
	{
		return GPIO_RETURN_Lock_Error;
	}
}





















