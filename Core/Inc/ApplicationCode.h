/*
 * ApplicationCode.h
 *
 *  Created on: Nov 14, 2023
 *      Author: xcowa
 */

#ifndef INC_APPLICATIONCODE_H_
#define INC_APPLICATIONCODE_H_

#include <math.h>

#include "LCD_Driver.h"
#include "RNG_Driver.h"
#include "Timer_Driver.h"
#include "Button_Driver.h"
#include "Scheduler.h"

void ApplicationInit(void);

void drawSquare(int xPos, int yPos, uint16_t color);
void drawTriangle(int xPos, int yPos, uint16_t color);
void drawCircle(int xPos, int yPos, uint16_t color);

void drawTime(int time);
void drawTimeFinal();

void titleScreen();
void levelOne();
void levelTwo();
void levelThree();


#endif /* INC_APPLICATIONCODE_H_ */
