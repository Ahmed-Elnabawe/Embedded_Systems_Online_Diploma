/*
 * I2C_Slave_EEPROM.h
 *
 *  Created on: Feb 28, 2025
 *      Author: Lenovo
 */

#ifndef I2C_SLAVE_EEPROM_DRIVER_I2C_SLAVE_EEPROM_H_
#define I2C_SLAVE_EEPROM_DRIVER_I2C_SLAVE_EEPROM_H_
#include "stm32f103c6_I2C_driver.h"
#define EEPROM_ADDRESS  0x2A
void eeprom_init(void);
void eeprom_write(uint32_t Mem_Address,uint8_t *data,uint8_t data_length);
void eeprom_read(uint32_t Mem_Address,uint8_t *data,uint8_t data_length);

#endif /* I2C_SLAVE_EEPROM_DRIVER_I2C_SLAVE_EEPROM_H_ */
