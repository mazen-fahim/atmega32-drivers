#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MDIO_Private.h"

// Direction
void MDIO_VoidSetPinDirection(u8 Copy_U8PortNum, u8 Copy_U8PinNum, u8 Copy_U8PinDir)
{
    if(Copy_U8PinDir == 0)
    {
        switch(Copy_U8PortNum)
        {
            case 0: CLR_BIT(DDRA_REG, Copy_U8PinNum); break;
            case 1: CLR_BIT(DDRB_REG, Copy_U8PinNum); break;
            case 2: CLR_BIT(DDRC_REG, Copy_U8PinNum); break;
            case 3: CLR_BIT(DDRD_REG, Copy_U8PinNum); break;
        }
    }
    else if(Copy_U8PinDir == 1)
    {
        switch(Copy_U8PortNum)
        {
            case 0: SET_BIT(DDRA_REG, Copy_U8PinNum); break;
            case 1: SET_BIT(DDRB_REG, Copy_U8PinNum); break;
            case 2: SET_BIT(DDRC_REG, Copy_U8PinNum); break;
            case 3: SET_BIT(DDRD_REG, Copy_U8PinNum); break;
        }
    }
}
void MDIO_VoidSetPortDirection(u8 Copy_U8PortNum, u8 Copy_U8PortDir)
{
    switch(Copy_U8PortNum)
    {
        case 0: DDRA_REG = Copy_U8PortDir; break;
        case 1: DDRB_REG = Copy_U8PortDir; break;
        case 2: DDRC_REG = Copy_U8PortDir; break;
        case 3: DDRD_REG = Copy_U8PortDir; break;
    }
}

void MDIO_VoidActivatePinInternalPullupResistor(u8 Copy_U8PortNum, u8 Copy_U8PinNum)
{
    switch(Copy_U8PortNum)
    {
        case 0: SET_BIT(PORTA_REG, Copy_U8PinNum); break;
        case 1: SET_BIT(PORTB_REG, Copy_U8PinNum); break;
        case 2: SET_BIT(PORTC_REG, Copy_U8PinNum); break;
        case 3: SET_BIT(PORTD_REG, Copy_U8PinNum); break;
    }
}

void MDIO_VoidActivatePortInternalPullupResistor(u8 Copy_U8PortNum)
{
    switch(Copy_U8PortNum)
    {
        case 0: PORTA_REG = 0xff; break;
        case 1: PORTB_REG = 0xff; break;
        case 2: PORTC_REG = 0xff; break;
        case 3: PORTD_REG = 0xff; break;
    }
}

// READ
u8 MDIO_U8GetPinValue(u8 Copy_U8PortNum, u8 Copy_U8PinNum)
{
    u8 LOC_U8RetValue;
    switch(Copy_U8PortNum)
    {
        case 0: LOC_U8RetValue = GET_BIT(PINA_REG, Copy_U8PinNum); break;
        case 1: LOC_U8RetValue = GET_BIT(PINB_REG, Copy_U8PinNum); break;
        case 2: LOC_U8RetValue = GET_BIT(PINC_REG, Copy_U8PinNum); break;
        case 3: LOC_U8RetValue = GET_BIT(PIND_REG, Copy_U8PinNum); break;
    }
    return LOC_U8RetValue;
}
u8 MDIO_U8GetPortValue(u8 Copy_U8PortNum)
{
    u8 LOC_U8RetValue;
    switch(Copy_U8PortNum)
    {
        case 0: LOC_U8RetValue = PINA_REG; break;
        case 1: LOC_U8RetValue = PINB_REG; break;
        case 2: LOC_U8RetValue = PINC_REG; break;
        case 3: LOC_U8RetValue = PIND_REG; break;
    }
    return LOC_U8RetValue;
}

// WRITE
void MDIO_VoidSetPinValue(u8 Copy_U8PortNum, u8 Copy_U8PinNum, u8 Copy_U8PinValue)
{
    if(Copy_U8PinValue == 0)
    {
        switch(Copy_U8PortNum)
        {
            case 0: CLR_BIT(PORTA_REG, Copy_U8PinNum); break;
            case 1: CLR_BIT(PORTB_REG, Copy_U8PinNum); break;
            case 2: CLR_BIT(PORTC_REG, Copy_U8PinNum); break;
            case 3: CLR_BIT(PORTD_REG, Copy_U8PinNum); break;
        }
    }
    else if(Copy_U8PinValue == 1)
    {
        switch(Copy_U8PortNum)
        {
            case 0: SET_BIT(PORTA_REG, Copy_U8PinNum); break;
            case 1: SET_BIT(PORTB_REG, Copy_U8PinNum); break;
            case 2: SET_BIT(PORTC_REG, Copy_U8PinNum); break;
            case 3: SET_BIT(PORTD_REG, Copy_U8PinNum); break;
        }
    }
}

void MDIO_VoidSetPortValue(u8 Copy_U8PortNum, u8 Copy_U8PortValue)
{
    switch(Copy_U8PortNum)
    {
        case 0: PORTA_REG = Copy_U8PortValue; break;
        case 1: PORTB_REG = Copy_U8PortValue; break;
        case 2: PORTC_REG = Copy_U8PortValue; break;
        case 3: PORTD_REG = Copy_U8PortValue; break;
    }
}

void MDIO_VoidTogglePinValue(u8 Copy_U8PortNum, u8 Copy_U8PinNum)
{
    switch(Copy_U8PortNum)
    {
        case 0: TOGGLE_BIT(PORTA_REG, Copy_U8PinNum); break;
        case 1: TOGGLE_BIT(PORTB_REG, Copy_U8PinNum); break;
        case 2: TOGGLE_BIT(PORTC_REG, Copy_U8PinNum); break;
        case 3: TOGGLE_BIT(PORTD_REG, Copy_U8PinNum); break;
    }
}

void MDIO_VoidTogglePortValue(u8 Copy_U8PortNum)
{
    switch(Copy_U8PortNum)
    {
        case 0: PORTA_REG = ~PORTA_REG; break;
        case 1: PORTB_REG = ~PORTB_REG; break;
        case 2: PORTC_REG = ~PORTC_REG; break;
        case 3: PORTD_REG = ~PORTD_REG; break;
    }
}