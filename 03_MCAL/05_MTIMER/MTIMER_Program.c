#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MTIMER_Config.h"
#include "MTIMER_Private.h"
#include "MDIO_Interface.h"

static u8 counter = 0;
void MTIMER0_VoidInit(void)
{
    /* select normal mode */
    CLR_BIT(TCCR0, WGM01);
    CLR_BIT(TCCR0, WGM00);
    /* Normal port operation disconnect OC0 */
    CLR_BIT(TCCR0, COM01);
    CLR_BIT(TCCR0, COM00);
    /* Set prescalar (/256) */
    SET_BIT(TCCR0, CS02);
    CLR_BIT(TCCR0, CS01);
    CLR_BIT(TCCR0, CS00);
    /* TCNT0 preload value */
    TCNT0 = 238;
}
void MTIMER0_VoidEnableOVInterrupt(void)
{
    /*(PIE) enable overflow interrupt and disable compare interrupt */
    CLR_BIT(TIMSK, OCIE0);
    SET_BIT(TIMSK, TOIE0);
}

void __vector_11(void)
{
    counter++;
    if(counter == 123)
    {
        TCNT0 = 238;
        MDIO_VoidTogglePinValue(PORTA, 0);
        counter = 0;
    }
}
