/*
 * RNG_Driver.h
 *
 *  Created on: Nov 30, 2023
 *      Author: owenallison
 */

#ifndef INC_RNG_DRIVER_H_
#define INC_RNG_DRIVER_H_

#include "stm32f4xx_hal.h"

#include <stdint.h>

void RNG_Init();
uint32_t RNG_GetRandomNumber();

#endif /* INC_RNG_DRIVER_H_ */
