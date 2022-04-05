#include "BIT_MATH.h"
#include "MGIE_Private.h"

/* enable global interrupt by setting the GIE bit in SREG*/
void MGIE_VoidEnable(void)
{
    SET_BIT(SREG, SREG_GIE_BIT);
}

/* disable global interrupt by clearing the GIE bit in SREG*/
void MGIE_VoidDisable(void)
{
    CLR_BIT(SREG, SREG_GIE_BIT);
}
