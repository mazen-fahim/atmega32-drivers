#include "../../04_LIB/STD_TYPES.h"
#include "../../04_LIB/BIT_MATH.h"
#include "MICU_Private.h"
#include "MICU_Config.h"

u8 icuStatus;
u32 snap1, snap2, snap3;
extern u32 timer1OvCounter;


void MICU_VoidInit(void)
{
    /* wave generation mode -> Normal "the only thing i care about is that TIMER1 fires an ov flag at MAX" */
    CLR_BIT(TCCR1B, WGM13);
    CLR_BIT(TCCR1B, WGM12);
    CLR_BIT(TCCR1A, WGM11);
    CLR_BIT(TCCR1A, WGM10);
    /* compare output mode -> Normal "I don't want to output any wave so i will make the two channels OC1A and OC1B work normally as DIO pins*/
    CLR_BIT(TCCR1A, COM1A1);
    CLR_BIT(TCCR1A, COM1A0);
    CLR_BIT(TCCR1A, COM1B1);
    CLR_BIT(TCCR1A, COM1B0);
    /* disable force output compare  */
    CLR_BIT(TCCR1A, FOC1A); 
    CLR_BIT(TCCR1A, FOC1B); 
    /* make the input capture pin sense the rising edge */
    SET_BIT(TCCR1B, ICES1);
    /* enable the timer/counter1 overflow interrupt*/
    SET_BIT(TIMSK, TOIE1);
    /* set prescalare -> make it 1 to 1 with the cpu "1:1 to avoid the case where we take a capture of the counter and the cpu has already made some clock cycles that wasn't counted */
    CLR_BIT(TCCR1B, CS12);
    CLR_BIT(TCCR1B, CS11);
    SET_BIT(TCCR1B, CS10);
}

void MICU_VoidInterruptEnable(void)
{
    SET_BIT(TIMSK, TICIE);
}

void MICU_VoidInterruptDisable(void)
{
    CLR_BIT(TIMSK, TICIE);
}



void __vector_(void)
{
    if( 0  == icuStatus)
    {
        /* take the first snapshot */
        snap1 = ICR1;
        /* sense falling edge*/
        CLR_BIT(TCCR1B, ICES1);
        icuStatus = 1;
        timer1OvCounter = 0;
    }
    else if( 1 == icuStatus)
    {
        snap2 = ICR1 + (timer1OvCounter * 65564);
        /* sense rising edge*/
        SET_BIT(TCCR1B, ICES1);
        icuStatus = 2;
    }
    else if( 2 == icuStatus)
    {
        snap3 = ICR1 + (timer1OvCounter * 65564);
        icuStatus = 3;
    }

}
