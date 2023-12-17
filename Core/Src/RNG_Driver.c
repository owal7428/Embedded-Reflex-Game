/*
 * RNG_Driver.c
 *
 *  Created on: Nov 30, 2023
 *      Author: owenallison
 */

#include "RNG_Driver.h"

static HAL_StatusTypeDef status;
static RNG_HandleTypeDef rng;

static uint32_t randomNumber;

void RNG_Init()
{
    rng.Instance = RNG;
    HAL_RNG_Init(&rng);
}

uint32_t RNG_GetRandomNumber()
{
    int status = HAL_RNG_GenerateRandomNumber(&rng, &randomNumber);
    return randomNumber;
}
