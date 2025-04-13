#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

#define HIGH 1
#define LOW 0

#define INPUT 0
#define OUTPUT 1

void DIO_VoidSetPinDirection(u8 Copy_U8PortNum, u8 Copy_U8PinNum,
                             u8 Copy_U8PinDir);
void DIO_VoidSetPortDirection(u8 Copy_U8PortNum, u8 Copy_U8PortDir);

void DIO_VoidActivatePinInternalPullupResistor(u8 Copy_U8PortNum,
                                               u8 Copy_U8PinNum);
void DIO_VoidActivatePortInternalPullupResistor(u8 Copy_U8PortNum);

u8 DIO_U8GetPinValue(u8 Copy_U8PortNum, u8 Copy_U8PinNum);
u8 DIO_U8GetPortValue(u8 Copy_U8PortNum);

void DIO_VoidSetPinValue(u8 Copy_U8PortNum, u8 Copy_U8PinNum,
                         u8 Copy_U8PinValue);
void DIO_VoidSetPortValue(u8 Copy_U8PortNum, u8 Copy_U8PortValue);

void DIO_VoidTogglePinValue(u8 Copy_U8PortNum, u8 Copy_U8PinNum);
void DIO_VoidTogglePortValue(u8 Copy_U8PortNum);

#endif
