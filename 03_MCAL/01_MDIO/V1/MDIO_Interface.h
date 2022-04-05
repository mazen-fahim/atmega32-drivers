#ifndef _MDIO_INTERFACE_H_
#define _MDIO_INTERFACE_H_

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

#define HIGH  1 
#define LOW   0

#define INPUT 0
#define OUTPUT 1

void MDIO_VoidSetPinDirection(u8 Copy_U8PortNum, u8 Copy_U8PinNum, u8 Copy_U8PinDir);
void MDIO_VoidSetPortDirection(u8 Copy_U8PortNum, u8 Copy_U8PortDir);

void MDIO_VoidActivatePinInternalPullupResistor(u8 Copy_U8PortNum, u8 Copy_U8PinNum);
void MDIO_VoidActivatePortInternalPullupResistor(u8 Copy_U8PortNum);


u8 MDIO_U8GetPinValue(u8 Copy_U8PortNum, u8 Copy_U8PinNum);
u8 MDIO_U8GetPortValue(u8 Copy_U8PortNum);

void MDIO_VoidSetPinValue(u8 Copy_U8PortNum, u8 Copy_U8PinNum, u8 Copy_U8PinValue);
void MDIO_VoidSetPortValue(u8 Copy_U8PortNum, u8 Copy_U8PortValue);

void MDIO_VoidTogglePinValue(u8 Copy_U8PortNum, u8 Copy_U8PinNum);
void MDIO_VoidTogglePortValue(u8 Copy_U8PortNum);

#endif
