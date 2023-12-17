/*
 * Timer_Driver.h
 *
 *  Created on: Nov 30, 2023
 *      Author: owenallison
 */

#ifndef INC_TIMER_DRIVER_H_
#define INC_TIMER_DRIVER_H_

#include "stm32f4xx_hal.h"

int Timer_GetCurrentTime();

void Timer_Pause();
void Timer_Resume();

#endif /* INC_TIMER_DRIVER_H_ */
