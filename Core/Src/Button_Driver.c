#include "Button_Driver.h"

static GPIO_InitTypeDef button;

void Button_Init() {
    button.Mode = GPIO_MODE_IT_RISING;
    button.Pin = BUTTON_PIN_NUM;
    button.Pull = GPIO_NOPULL;
    button.Speed = GPIO_SPEED_MEDIUM;
    Button_EnableClock();
    HAL_GPIO_Init(GPIOA, &button);
}

void Button_InitInterruptMode() {
    button.Mode = GPIO_MODE_IT_RISING;
    button.Pin = BUTTON_PIN_NUM;
    button.Pull = GPIO_NOPULL;
    button.Speed = GPIO_SPEED_MEDIUM;
    Button_EnableClock();
    HAL_GPIO_Init(GPIOA, &button);
}

void Button_EnableClock() {
    __HAL_RCC_GPIOA_CLK_ENABLE();
}

void Button_EnableInterrupt() {
    EXTI_clear_pending(0);
    InterruptIRQ_clear_pending(EXTI0_IRQn);
    InterruptIRQ_enable(EXTI0_IRQn);
}

void Button_DisableInterrupt() {
    InterruptIRQ_disable(EXTI0_IRQn);
}

bool Button_IsPressed() {
    uint8_t val = (uint8_t) HAL_GPIO_ReadPin(GPIOA, BUTTON_PIN_NUM);

    if (val == BUTTON_PRESSED)
        return true;
    else if (val == BUTTON_NOT_PRESSED)
        return false;
    return false;
}
