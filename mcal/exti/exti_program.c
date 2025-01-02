#include "std_types.h"
#include "bit_math.h"
#include "exti_private.h"
#include "dio_interface.h"

static void (*exti0CallBackPtr)(void) = 0;
/* configure sense control in MCUCR register to choose
 * sensing falling edge on INT0 pin */
void EXTI0_VoidInit(void)
{
    SET_BIT(MCUCR, ISC01);
    CLR_BIT(MCUCR, ISC00);
}

/* enable INT0 by setting the peripheral interrupt enable of
 * the corresponding bit in the GICR register */
void EXTI0_VoidIntEnable(void)
{
    SET_BIT(GICR, INT0_PIE_BIT);
}

/* disable INT0 by clearing the peripheral interrupt enable of
 * the corresponding bit in the GICR register */
void EXTI0_VoidIntDisable(void)
{
    CLR_BIT(GICR, INT0_PIE_BIT);
}

void EXTI0_VoidSetCallBack(void (*Copy_VoidCallBackFun)(void))
{
    exti0CallBackPtr = Copy_VoidCallBackFun;
}

/* ISR for INT0 */
void __vector_1(void)
{
    exti0CallBackPtr();
}
