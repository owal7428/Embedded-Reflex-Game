/*
 * InterruptControl.h
 *
 *  Created on: Sep 26, 2023
 *      Author: owenallison
 */

#ifndef INTERRUPTCONTROL_H_
#define INTERRUPTCONTROL_H_

#include "stm32f4xx_hal.h"
#include <stdint.h>

#define EXTI0_IRQ_NUMBER 6

void InterruptIRQ_enable(IRQn_Type IRQn);
void InterruptIRQ_disable(IRQn_Type IRQn);
void InterruptIRQ_clear_pending(IRQn_Type IRQn);
void InterruptIRQ_set_pending(IRQn_Type IRQn);

void EXTI_clear_pending(uint8_t pin_num);

#endif
