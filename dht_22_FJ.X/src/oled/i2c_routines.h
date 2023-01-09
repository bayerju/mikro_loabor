/**
 * @file i2c_routines.h
 * @author Group DHT22
 * @source Jan Haffmueller
 * @brief Providing the I2C functions
 * @version 0.1
 * @date 2023-01-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef I2C_ROUTINES_H
#define	I2C_ROUTINES_H

#define I2C_TIMEOUT 10000       // timeout in �s

#include "../config/global_definitions.h"

// function prototypes
void init_i2c(void);
int8_t I2C_start(uint8_t address);
int8_t I2C_write(uint8_t data);
int8_t I2C_rep_start(uint8_t address);
int8_t I2C_read(uint8_t number , uint8_t *values);
int8_t I2C_stop(void);

    
#endif	// I2C_ROUTINES_H
