/*
 * I2C_Slave_EEPROM.c
 *
 *  Created on: Feb 28, 2025
 *      Author: Lenovo
 */
#include "I2C_Slave_EEPROM.h"

void eeprom_init(void)
{
	I2C_config_t eeprom_config ;
	eeprom_config.I2C_ACKcontrol = I2C_ACKcontrol_Enable;
	eeprom_config.I2C_General_call_back_address=I2C_General_call_back_address_Enable;
	eeprom_config.I2C_clockSpeed=I2C_clockSpeed_SM_100k;
	eeprom_config.I2C_stretchMode=I2C_stretchMode_Enable;
	MCAL_I2C_Init(I2C1, &eeprom_config);
	MCAL_I2C_GPIO_SET_PINS(I2C1);
}
void eeprom_write(uint32_t Mem_Address,uint8_t *data,uint8_t data_length)
{
	int i = 0; // counter
	// define buffer
	uint8_t buffer[256];
	buffer[0]=Mem_Address>>8;
	buffer[1]=Mem_Address;
	for(i=2 ; i<(data_length+2) ; i++)
	{
		buffer[i]=data[i-2];
	}
	MCAL_I2C_Master_TX(I2C1, EEPROM_ADDRESS, buffer, (data_length+2), with_stop, normal_start);
}
void eeprom_read(uint32_t Mem_Address,uint8_t *data,uint8_t data_length)
{
	uint8_t buffer[2];
	buffer[0]=Mem_Address>>8;
	buffer[1]=Mem_Address;
	MCAL_I2C_Master_TX(I2C1, EEPROM_ADDRESS, buffer, 2, without_stop, normal_start);
	MCAL_I2C_Master_RX(I2C1, EEPROM_ADDRESS, data, data_length, with_stop, repeated_start);

}
