/*
 * ApplicationCode.c
 *
 *  Created on: Nov 14, 2023
 *      Author: xcowa
 */

#include "ApplicationCode.h"

static int oldTime;
static int newTime;

static bool button_enabled = false;

static float level = 1;

static float time1;
static float time2;
static float time3;

static int level3_numWins;

static const int centerX = LCD_PIXEL_WIDTH / 2;
static const int centerY = LCD_PIXEL_HEIGHT / 2;

void ApplicationInit(void)
{
	LTCD__Init();
    LTCD_Layer_Init(0);
    LCD_Clear(0,LCD_COLOR_WHITE);

    LCD_SetTextColor(LCD_COLOR_BLACK);
	LCD_SetFont(&Font16x24);

    RNG_Init();

    Button_InitInterruptMode();
}

void drawSquare(int xPos, int yPos, uint16_t color)
{
    LCD_Draw_Rectangle_Fill(xPos, yPos, 40, 40, color);
}

void drawTriangle(int xPos, int yPos, uint16_t color)
{
    LCD_Draw_Triangle_Fill(xPos, yPos, 80, 40, color);
}

void drawCircle(int xPos, int yPos, uint16_t color)
{
    LCD_Draw_Circle_Fill(xPos, yPos, 20, color);
}

void drawTime(int time)
{
    int fourthNum   =   ((time / 1) % 10) + 48;
    int thirdNum    =   ((time / 10) % 10) + 48;
    int secondNum   =   ((time / 100) % 10) + 48;
    int firstNum    =   ((time / 1000) % 10) + 48;

    LCD_Clear(0,LCD_COLOR_BLUE2);

    LCD_SetTextColor(LCD_COLOR_WHITE);

    // Display time header

    LCD_DisplayChar(centerX - 80, centerY - 50, 84);
    LCD_DisplayChar(centerX - 65, centerY - 50, 105);
    LCD_DisplayChar(centerX - 50, centerY - 50, 109);
    LCD_DisplayChar(centerX - 35, centerY - 50, 101);
    LCD_DisplayChar(centerX - 25, centerY - 50, 58);

    LCD_Draw_Horizontal_Line(centerX - 80, centerY - 30, 70, 2, LCD_COLOR_WHITE);

    LCD_SetTextColor(LCD_COLOR_BLACK);

    // Display the time in milliseconds

    LCD_DisplayChar(centerX - 40, centerY, firstNum);
    LCD_DisplayChar(centerX - 25, centerY, secondNum);
    LCD_DisplayChar(centerX - 10, centerY, thirdNum);
    LCD_DisplayChar(centerX + 5, centerY, fourthNum);
    LCD_DisplayChar(centerX + 30, centerY, 109);
    LCD_DisplayChar(centerX + 45, centerY, 115);
}

void drawTimeFinal()
{
    LCD_Clear(0,LCD_COLOR_BLUE2);

    LCD_SetTextColor(LCD_COLOR_WHITE);

    // Display time header

    LCD_DisplayChar(centerX - 80, 40, 84);
    LCD_DisplayChar(centerX - 65, 40, 105);
    LCD_DisplayChar(centerX - 50, 40, 109);
    LCD_DisplayChar(centerX - 35, 40, 101);
    LCD_DisplayChar(centerX - 20, 40, 115);
    LCD_DisplayChar(centerX - 10, 40, 58);

    LCD_Draw_Horizontal_Line(centerX - 80, 70, 85, 2, LCD_COLOR_WHITE);

    LCD_SetTextColor(LCD_COLOR_BLACK);

    for (int i = 0; i < 3; i++)
    {
        int time;

        if (i == 0) 
            time = time1;  
        else if (i == 1) 
            time = time2;  
        else 
            time = time3;

        int fourthNum   =   ((time / 1) % 10) + 48;
        int thirdNum    =   ((time / 10) % 10) + 48;
        int secondNum   =   ((time / 100) % 10) + 48;
        int firstNum    =   ((time / 1000) % 10) + 48;

        // Display the time in milliseconds

        LCD_DisplayChar(centerX - 40, 100 + (25 * i), firstNum);
        LCD_DisplayChar(centerX - 25, 100 + (25 * i), secondNum);
        LCD_DisplayChar(centerX - 10, 100 + (25 * i), thirdNum);
        LCD_DisplayChar(centerX + 5, 100 + (25 * i), fourthNum);
        LCD_DisplayChar(centerX + 30, 100 + (25 * i), 109);
        LCD_DisplayChar(centerX + 45, 100 + (25 * i), 115);
    }

    LCD_SetTextColor(LCD_COLOR_WHITE);

    // Display time header

    LCD_DisplayChar(centerX - 80, 200, 65);
    LCD_DisplayChar(centerX - 65, 200, 118);
    LCD_DisplayChar(centerX - 50, 200, 101);
    LCD_DisplayChar(centerX - 35, 200, 114);
    LCD_DisplayChar(centerX - 20, 200, 97);
    LCD_DisplayChar(centerX - 5, 200, 103);
    LCD_DisplayChar(centerX + 10, 200, 101);
    LCD_DisplayChar(centerX + 20, 200, 58);

    LCD_Draw_Horizontal_Line(centerX - 80, 230, 115, 2, LCD_COLOR_WHITE);

    LCD_SetTextColor(LCD_COLOR_BLACK);

    int average = (time1 + time2 + time3) / 3;

    int fourthNum   =   ((average / 1) % 10) + 48;
    int thirdNum    =   ((average / 10) % 10) + 48;
    int secondNum   =   ((average / 100) % 10) + 48;
    int firstNum    =   ((average / 1000) % 10) + 48;

    // Display the average time in milliseconds

    LCD_DisplayChar(centerX - 40, 260, firstNum);
    LCD_DisplayChar(centerX - 25, 260, secondNum);
    LCD_DisplayChar(centerX - 10, 260, thirdNum);
    LCD_DisplayChar(centerX + 5, 260, fourthNum);
    LCD_DisplayChar(centerX + 30, 260, 109);
    LCD_DisplayChar(centerX + 45, 260, 115);
}

void titleScreen()
{
    LCD_Clear(0,LCD_COLOR_BLUE2);

    LCD_SetTextColor(LCD_COLOR_WHITE);

    // Display time header

    LCD_DisplayChar(centerX - 100, 40, 82);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 85, 40, 101);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 70, 40, 102);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 55, 40, 108);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 40, 40, 101);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 25, 40, 120);
    HAL_Delay(50);

    LCD_DisplayChar(centerX, 40, 71);
    HAL_Delay(50);
    LCD_DisplayChar(centerX + 15, 40, 97);
    HAL_Delay(50);
    LCD_DisplayChar(centerX + 30, 40, 109);
    HAL_Delay(50);
    LCD_DisplayChar(centerX + 45, 40, 101);
    HAL_Delay(50);

    // Colon character
    LCD_DisplayChar(centerX + 55, 40, 58);
    HAL_Delay(50);

    LCD_Draw_Horizontal_Line(centerX - 100, 70, 155, 2, LCD_COLOR_WHITE);
    HAL_Delay(500);

    LCD_DisplayChar(centerX - 100, 100, 80);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 88, 100, 114);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 76, 100, 101);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 64, 100, 115);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 52, 100, 115);
    HAL_Delay(50);

    LCD_DisplayChar(centerX - 28, 100, 98);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 16, 100, 117);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 4, 100, 116);
    HAL_Delay(50);
    LCD_DisplayChar(centerX + 8, 100, 116);
    HAL_Delay(50);
    LCD_DisplayChar(centerX + 20, 100, 111);
    HAL_Delay(50);
    LCD_DisplayChar(centerX + 32, 100, 110);
    HAL_Delay(50);

    LCD_DisplayChar(centerX - 100, 130, 119);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 88, 130, 104);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 76, 130, 101);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 64, 130, 110);
    HAL_Delay(50);

    LCD_DisplayChar(centerX - 40, 130, 115);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 28, 130, 104);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 16, 130, 97);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 4, 130, 112);
    HAL_Delay(50);
    LCD_DisplayChar(centerX + 8, 130, 101);
    HAL_Delay(50);

    LCD_DisplayChar(centerX - 100, 160, 97);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 88, 160, 112);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 76, 160, 112);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 64, 160, 101);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 52, 160, 97);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 40, 160, 114);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 28, 160, 115);
    HAL_Delay(50);

    LCD_DisplayChar(centerX - 4, 160, 116);
    HAL_Delay(50);
    LCD_DisplayChar(centerX + 8, 160, 111);
    HAL_Delay(50);

    LCD_DisplayChar(centerX + 32, 160, 116);
    HAL_Delay(50);
    LCD_DisplayChar(centerX + 44, 160, 101);
    HAL_Delay(50);
    LCD_DisplayChar(centerX + 56, 160, 115);
    HAL_Delay(50);
    LCD_DisplayChar(centerX + 68, 160, 116);
    HAL_Delay(50);

    LCD_DisplayChar(centerX - 100, 190, 121);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 88, 190, 111);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 76, 190, 117);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 64, 190, 114);
    HAL_Delay(50);

    LCD_DisplayChar(centerX - 40, 190, 114);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 28, 190, 101);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 16, 190, 102);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 4, 190, 108);
    HAL_Delay(50);
    LCD_DisplayChar(centerX + 8, 190, 101);
    HAL_Delay(50);
    LCD_DisplayChar(centerX + 20, 190, 120);
    HAL_Delay(50);

    LCD_DisplayChar(centerX - 100, 220, 116);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 88, 220, 105);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 76, 220, 109);
    HAL_Delay(50);
    LCD_DisplayChar(centerX - 64, 220, 101);
    HAL_Delay(50);

    LCD_DisplayChar(centerX - 52, 220, 46);

    removeSchedulerEvent(START_EVENT);
    addSchedulerEvent(LEVEL_1_EVENT);

    HAL_Delay(1000);
}

void levelOne()
{
    uint8_t randShape = RNG_GetRandomNumber();
    randShape %= 3;
    
    uint32_t randDelay = RNG_GetRandomNumber();
    randDelay %= 4;

    LCD_Clear(0,LCD_COLOR_WHITE);

    // Ensure delay is not zero
    if (randDelay < 1) randDelay = 1;

    HAL_Delay(randDelay * 1000);

    if (randShape == 0)
    {
        drawSquare(centerX - 25, centerY + 20, LCD_COLOR_BLACK);
    }
    else if (randShape == 1)
    {
        drawTriangle(centerX - 45, centerY + 20, LCD_COLOR_BLACK);
    }
    else
    {
        drawCircle(centerX - 5, centerY, LCD_COLOR_BLACK);
    }

    oldTime = Timer_GetCurrentTime();
    newTime = oldTime;

    Button_EnableInterrupt();

    while (level == 1)
        ;
    
    drawTime(time1);
}

void levelTwo()
{
    LCD_Clear(0,LCD_COLOR_WHITE);
    LCD_Draw_Vertical_Line(centerX, 0, LCD_PIXEL_HEIGHT, LCD_COLOR_BLACK);
    LCD_Draw_Horizontal_Line(0, centerY, LCD_PIXEL_WIDTH, 1, LCD_COLOR_BLACK);

    uint8_t randShape = RNG_GetRandomNumber();
    randShape %= 3;

    uint8_t randX = RNG_GetRandomNumber();
    randX %= 2;

    uint8_t randY = RNG_GetRandomNumber();
    randY %= 2;

    uint32_t xPos;
    uint32_t yPos;

    if (randX == 0)
    {
        xPos = centerX - 80;
    }
    else
    {
        xPos = centerX + 40;
    }

    if (randY == 0)
    {
        yPos = centerY - 70;
    }
    else
    {
        yPos = centerY + 60;
    }

    uint32_t randDelay = RNG_GetRandomNumber();
    randDelay %= 4;

    // Ensure delay is not zero
    if (randDelay < 1) randDelay = 1;

    HAL_Delay(randDelay * 1000);

    if (randShape == 0)
    {
        drawSquare(xPos, yPos, LCD_COLOR_BLACK);
    }
    else if (randShape == 1)
    {
        drawTriangle(xPos, yPos, LCD_COLOR_BLACK);
    }
    else
    {
        drawCircle(xPos, yPos, LCD_COLOR_BLACK);
    }

    oldTime = Timer_GetCurrentTime();
    newTime = oldTime;

    Button_EnableInterrupt();

    while (level == 2)
        ;
    
    drawTime(time2);
}

void levelThree()
{
    oldTime = Timer_GetCurrentTime();

    int tempOldTime = oldTime;

    time3 = INT16_MAX;

    while (level3_numWins < 3)
    {
        newTime = Timer_GetCurrentTime();
        int deltaTime = newTime - tempOldTime;

        // Only update every 15ms to avoid flickering
        if (deltaTime >= 15)
        {
            tempOldTime = newTime;

            int xOffset = (int) (sin(((double) newTime / 150.0f)) * (20 + centerX / 2));

            if (xOffset >= 20)
            {
                LCD_Clear(0, LCD_COLOR_GREEN);
                
                if (button_enabled == false)
                {
                    oldTime = newTime;
                    Button_EnableInterrupt();
                    button_enabled = true;
                }
            }
            else
            {
                LCD_Clear(0,LCD_COLOR_RED);
                Button_DisableInterrupt();
                button_enabled = false;
            }
            
            LCD_Draw_Vertical_Line(centerX, 0, LCD_PIXEL_HEIGHT, LCD_COLOR_BLACK);
            drawCircle(centerX + xOffset, centerY, LCD_COLOR_BLACK);
        }
    }

    drawTime(time3);
}

void stageWinScreen()
{
    if (level == 0)
    {
        
    }

    else if (level == 1)
    {
        newTime = Timer_GetCurrentTime();
        time1 = newTime - oldTime;

        level++;
        removeSchedulerEvent(LEVEL_1_EVENT);
        addSchedulerEvent(LEVEL_2_EVENT);
    }

    else if (level == 2)
    {
        newTime = Timer_GetCurrentTime();
        time2 = newTime - oldTime;

        level++;
        removeSchedulerEvent(LEVEL_2_EVENT);
        addSchedulerEvent(LEVEL_3_EVENT);
    }

    else if (level == 3)
    {
        newTime = Timer_GetCurrentTime();
        int temp = newTime - oldTime;

        if (temp < time3)
            time3 = temp;

        level3_numWins++;

        if (level3_numWins == 3)
        {
            removeSchedulerEvent(LEVEL_3_EVENT);
            addSchedulerEvent(END_EVENT);
        }
    }
}

void EXTI0_IRQHandler(void) 
{
    Button_DisableInterrupt();
    
    stageWinScreen();
}
