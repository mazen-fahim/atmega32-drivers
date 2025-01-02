#include "bit_math.h"
#include "gie_private.h"

/* enable global interrupt by setting the GIE bit in SREG*/
void GIE_VoidEnable(void)
{
    SET_BIT(SREG, SREG_GIE_BIT);
}

/* disable global interrupt by clearing the GIE bit in SREG*/
void GIE_VoidDisable(void)
{
    CLR_BIT(SREG, SREG_GIE_BIT);
}
