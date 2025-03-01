/*
 * stm32f103c6_I2C_driver.h
 *
 *  Created on: Feb 27, 2025
 *      Author: Lenovo
 */

#ifndef INC_STM32F103C6_I2C_DRIVER_H_
#define INC_STM32F103C6_I2C_DRIVER_H_
#include "stm32f103x6.h"
#include "stm32f103c6_gpio_driver.h"
#include "stm32f103c6_RCC_Partial_driver.h"

typedef enum
{
	I2C_EV_STOP,
	I2C_ERROR_AF,
	I2C_EV_ADDRESS_MATCH,
	I2C_EV_DATA_REQ,
	I2C_EV_DATA_RECIEVE
}Slave_State;

typedef enum
{
	with_stop,
	without_stop
}Stop_condition;
typedef enum
{
	normal_start,
	repeated_start
}Start_condition;

typedef enum
{
	start_enable ,
	start_disable
} start_state ;

typedef enum
{
	ack_enable ,
	ack_disable
}ACK_state ;
typedef enum
{
	reset,
	set
}flag_state;
typedef enum
{
	busy_flag,
	EV5,
	EV6,
	EV8_1,
	EV8,
	EV8_2,
	EV7

}I2C_flag;
typedef enum
{
	Read,
	Write
}direction_state;
typedef struct {

	   uint32_t			 I2C_clockSpeed						;   // this variable contain the I2C clock speed
																// set this variable according to  @ref I2C_clockSpeed_define

	   uint32_t 		 I2C_stretchMode 					;	// this variable contain the Mode stretch Enable/Disable
																// set this variable according to @ref I2C_stretchMode_define

	   uint32_t		     I2C_slaveAddress				   	;	// this variable contain the slave address
																// is set by the user

	   uint32_t		     I2C_ACKcontrol					    ;	// this variable for select ACk state  Enable/Disable
																// set this variable according to @ref I2C_ACKcontrol_define

	   uint32_t		     I2C_General_call_back_address	   	;	// this variable for Enable/Disable general address call
																// set this variable according to @ref I2C_General_call_back_address_define

	   void(*P_Slave_Event_CallBack)(Slave_State state)	    ;   // pointer to function to be set for interrupt handling note:supported in slave mode only


}I2C_config_t;


// references //
//@ref I2C_clockSpeed_define note: we support standard mode only
#define I2C_clockSpeed_SM_50k					(50000U)
#define I2C_clockSpeed_SM_100k					(100000U)
//==============================================//
//@ref I2C_stretchMode_define
//This bit is used to disable clock stretching in slave mode when ADDR or BTF flag is set, until
//it is reset by software.
//0: Clock stretching enabled
//1: Clock stretching disabled
#define I2C_stretchMode_Enable					(0U)
#define I2C_stretchMode_Disable					(I2C_CR1_NOSTRETCH)
//==============================================//
//@ref I2C_ACKcontrol_define
//This bit is set and cleared by software and cleared by hardware when PE=0.
//0: No acknowledge returned
//1: Acknowledge returned after a byte is received (matched address or data)
#define I2C_ACKcontrol_Enable					(I2C_CR1_ACK)
#define I2C_ACKcontrol_Disable					(0U)
//==============================================//
//@ref I2C_General_call_back_address_define
//0: General call disabled. Address 00h is NACKed.
//1: General call enabled. Address 00h is ACKed.

//------------------------ APIs--------------------//
void MCAL_I2C_Init(I2C_TypeDef * I2Cx , I2C_config_t * i2c_confg);
void MCAL_I2C_DeInit(I2C_TypeDef * I2Cx );
void MCAL_I2C_GPIO_SET_PINS(I2C_TypeDef * I2Cx );
// we support master only in polling mechanism
void MCAL_I2C_Master_TX(I2C_TypeDef * I2Cx ,uint16_t divAddress,uint8_t * data , uint32_t data_length ,Stop_condition stop, Start_condition start );
void MCAL_I2C_Master_RX(I2C_TypeDef * I2Cx ,uint16_t divAddress,uint8_t * data , uint32_t data_length ,Stop_condition stop, Start_condition start );

// we support slave only in interrupt mechanism


#define I2C_General_call_back_address_Enable	(I2C_CR1_ENGC)
#define I2C_General_call_back_address_Disable	(0U)

#endif /* INC_STM32F103C6_I2C_DRIVER_H_ */
