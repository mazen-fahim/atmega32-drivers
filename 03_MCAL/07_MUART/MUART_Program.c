#include "../../04_LIB/STD_TYPES.h"
#include "../../04_LIB/BIT_MATH.h"
#include "MUART_Config.h"
#include "MUART_Private.h"

/** Initialization **/
void MUART_VoidInit(void)
{
    u8 help_UCSRC = 0b10000000;
    /* chose normal transmission speed */
    CLR_BIT(UCSRA, U2X);

    /* Disable Multi-processor communication mode */
    CLR_BIT(UCSRA, MPCM);

    /* set character size */
    UCSRB = (UCSRB & 0b11111011) | (CHAR_SIZE & 0b00000100);
    help_UCSRC = (help_UCSRC & 0b11111001) | ((CHAR_SIZE & 0b00000011) << 1);

    /* select sync or async mode */
#if SYNC == 1
    SET_BIT(help_UCSRC, UMSEL);
#elif SYNC == 0
    CLR_BIT(help_UCSRC, UMSEL);
#endif
    
    /* set parity mode */
    help_UCSRC = (help_UCSRC & 0b11001111) | (PARITY_MODE & 0b00000011 << 4);

    /* select the number of stop bits -> 1 bit*/
    CLR_BIT(help_UCSRC, USBS);

    /* assign the actual UCSRC */
    UCSRC = help_UCSRC;

    /* Set the baud rate -> 9600 (cpu at 8Mhz)*/
    UBRRH = 0;
    UBRRL = 51;

    /* disable all interrupts when initializing */
    CLR_BIT(UCSRB, RXCIE);
    CLR_BIT(UCSRB, TXCIE);
    CLR_BIT(UCSRB, UDRIE);

    /* enable or disable the reciever */
#if RECIVER == 1
    SET_BIT(UCSRB, RXEN);
#elif RECIEVER == 0
    CLR_BIT(UCSRB, RXEN);
#endif
    /* enable or disable the transmitter */
#if TRANSMITTER == 1
    SET_BIT(UCSRB, TXEN);
#elif TRANSMITTER == 0
    CLR_BIT(UCSRB, TXEN);
#endif
}

/** Interrupts **/
void MUART_VoidRXCompleteIE(void)
{
    SET_BIT(UCSRB, RXCIE);
}
void MUART_VoidRXCompleteID(void)
{
    CLR_BIT(UCSRB, RXCIE);
}
void MUART_VoidTXCompleteIE(void)
{
    SET_BIT(UCSRB, TXCIE);
}
void MUART_VoidTXCompleteID(void)
{
    CLR_BIT(UCSRB, TXCIE);
}
void MUART_VoidDataRegEmptyIE(void)
{
    SET_BIT(UCSRB, UDRIE);
}
void MUART_VoidDataRegEmptyID(void)
{
    CLR_BIT(UCSRB, UDRIE);
}

#if CHAR_SIZE == 7
void MUART_VoidSend(u16 Copy_U16Data)
{
    /* busy wait till the transmitter buffer is ready */
    while (0 == GET_BIT(UCSRA, UDRE));
    UCSRB = (UCSRB & 0b11111110) | GET_BIT(Copy_U16Data, 8);
    UDR = (u8) Copy_U16Data;
}

u16 MUART_U16Recieve(void)
{
    LOC_U16RetValue;
    /* busy wait till the reciever buffer is ready */
    while( 0 == GET_BIT(UCSRA, RXC));
    UCSRB ........................
}
#else
void MUART_VoidSend(u8 Copy_U8Data)
{
    /* busy wait till the transmitter buffer is ready */
    while (0 == GET_BIT(UCSRA, UDRE));
    UDR = Copy_U8Data;
}

u8 MUART_U8Recieve(void)
{
    /* busy wait till the reciever buffer is ready */
    while( 0 == GET_BIT(UCSRA, RXC));
    return UDR;
}
#endif
