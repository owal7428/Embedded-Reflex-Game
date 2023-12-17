/*
 * Timer_Driver.c
 *
 *  Created on: Nov 30, 2023
 *      Author: owenallison
 */

#include "Timer_Driver.h"

int Timer_GetCurrentTime()
{
    HAL_GetTick();
}

void Timer_Pause()
{
    HAL_SuspendTick();
}

void Timer_Resume()
{
    HAL_ResumeTick();
}
