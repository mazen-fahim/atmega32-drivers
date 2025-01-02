#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

void UART_VoidInit(void);
void UART_VoidRXCompleteIE(void);
void UART_VoidRXCompleteID(void);
void UART_VoidTXCompleteIE(void);
void UART_VoidTXCompleteID(void);
void UART_VoidDataRegEmptyIE(void);
void UART_VoidDataRegEmptyID(void);
void UART_VoidSend(u16 Copy_U16Data);
u16 UART_U16Recieve(void);
void UART_VoidSend(u8 Copy_U8Data);
u8 UART_U8Recieve(void);

#endif