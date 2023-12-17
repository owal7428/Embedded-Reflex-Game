#include "InterruptControl.h"

void InterruptIRQ_enable(IRQn_Type IRQn)
{
    NVIC_EnableIRQ(IRQn);
}

void InterruptIRQ_disable(IRQn_Type IRQn)
{
    NVIC_DisableIRQ(IRQn);
}

void InterruptIRQ_clear_pending(IRQn_Type IRQn)
{
	NVIC_ClearPendingIRQ(IRQn);
}

void InterruptIRQ_set_pending(IRQn_Type IRQn)
{
    NVIC_SetPendingIRQ(IRQn);
}

void EXTI_clear_pending(uint8_t pin_num)
{
    EXTI -> PR |= (1 << pin_num);
}
