/*
 * stm32f103c6_gpio_driver.h
 *
 *  Created on: Dec 14, 2024
 *      Author: Ahmed Elnabawe
 */

#ifndef INC_STM32F103C6_GPIO_DRIVER_H_
#define INC_STM32F103C6_GPIO_DRIVER_H_

// Includes //
#include "stm32f103x6.h"
//-----------------------//
// config structure //
typedef struct {
	uint16_t PinNumber ; // Specify the GPIO pin to be configured
						// this parameter can be selected according to @ref GPIO_PIN_define
	uint8_t PinMode ;// Specify the GPIO pin mode to be configured
					// this parameter can be selected according to @ref GPIO_MODE_define
	uint8_t OutPutSpeed ;// Specify the GPIO pin output speed
						// this parameter can be selected according to @ref GPIO_SPEED_define

}GPIO_PinConfig_t;
// References //
//----------------------//
//@ref GPIO_PIN_define//
#define GPIO_PIN_0		((uint16_t)0x0001) // Pin 0 Selected //
#define GPIO_PIN_1		((uint16_t)0x0002) // Pin 1 Selected //
#define GPIO_PIN_2		((uint16_t)0x0004) // Pin 2 Selected //
#define GPIO_PIN_3		((uint16_t)0x0008) // Pin 3 Selected //
#define GPIO_PIN_4		((uint16_t)0x0010) // Pin 4 Selected //
#define GPIO_PIN_5		((uint16_t)0x0020) // Pin 5 Selected //
#define GPIO_PIN_6		((uint16_t)0x0040) // Pin 6 Selected //
#define GPIO_PIN_7		((uint16_t)0x0080) // Pin 7 Selected //
#define GPIO_PIN_8		((uint16_t)0x0100) // Pin 8 Selected //
#define GPIO_PIN_9		((uint16_t)0x0200) // Pin 9 Selected //
#define GPIO_PIN_10		((uint16_t)0x0400) // Pin 10 Selected //
#define GPIO_PIN_11		((uint16_t)0x0800) // Pin 11 Selected //
#define GPIO_PIN_12		((uint16_t)0x1000) // Pin 12 Selected //
#define GPIO_PIN_13		((uint16_t)0x2000) // Pin 13 Selected //
#define GPIO_PIN_14		((uint16_t)0x4000) // Pin 14 Selected //
#define GPIO_PIN_15		((uint16_t)0x8000) // Pin 15 Selected //
#define GPIO_PIN_ALL	((uint16_t)0xFFFF) // All Pins  Selected //
//----------------------//
//----------------------//
//@ref GPIO_MODE_define//
//0: Analog mode
//1: Floating input (reset state)
//2: Input with pull-up
//3: Input with pull-down
//4: General purpose output push-pull
//5: General purpose output Open-drain
//6: Alternate function output Push-pull
//7: Alternate function output Open-drain
//8:Alternate function Input
#define GPIO_MODE_Analog			((uint8_t)0x00U) // analog mode 						//
#define GPIO_MODE_Input_FLO			((uint8_t)0x01U) // input floating 						//
#define GPIO_MODE_Input_PU			((uint8_t)0x02U) // input pull up 						//
#define GPIO_MODE_Input_PD			((uint8_t)0x03U) // input pull down 					//
#define GPIO_MODE_Output_PP			((uint8_t)0x04U) // output push pull 					//
#define GPIO_MODE_Output_OD			((uint8_t)0x05U) // output open drain 					//
#define GPIO_MODE_Output_AF_PP		((uint8_t)0x06U) // alternate function output push pull //
#define GPIO_MODE_Output_AF_OD		((uint8_t)0x07U) // alternate function output open drain//
#define GPIO_MODE_Input_AF			((uint8_t)0x08U) // alternate function input 			//
//----------------------//
//@ref GPIO_SPEED_define//
//1: Output mode, max speed 10 MHz.
//2: Output mode, max speed 2 MHz.
//3: Output mode, max speed 50 MHz.
#define  GPIO_SPEED_10M			((uint8_t)0x01U) // analog mode 						//
#define  GPIO_SPEED_2M			((uint8_t)0x02U) // analog mode 						//
#define  GPIO_SPEED_50M			((uint8_t)0x03U) // analog mode
//----------------------//
//@ref GPIO_PIN_state////
#define  GPIO_PIN_Set			(1) // high //
#define  GPIO_PIN_ReSet			(0) // low //
//----------------------//
//@ref GPIO_RETURN_lock////
#define  GPIO_RETURN_Lock_OK			(1) // lock is done correctly //
#define  GPIO_RETURN_Lock_Error			(0) // lock is failed 		  //


/*
 * ============================================================================
 *					 APIs Supported by "MCAL GPIO DRIVER"
 * ============================================================================
 */

void MCAL_GPIO_Init(GPIO_TypeDef*GPIOx,GPIO_PinConfig_t*pinConfig);
void MCAL_GPIO_DeInit(GPIO_TypeDef*GPIOx);
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef*GPIOx,uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef*GPIOx);
void MCAL_GPIO_WritePin(GPIO_TypeDef*GPIOx,uint16_t PinNumber,uint8_t value);
void MCAL_GPIO_WritePort(GPIO_TypeDef*GPIOx,uint16_t value);
void MCAL_GPIO_TogglePin(GPIO_TypeDef*GPIOx,uint16_t PinNumber);
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef*GPIOx,uint16_t PinNumber);

GPIO_PinConfig_t pinCnfg;


#endif /* INC_STM32F103C6_GPIO_DRIVER_H_ */




