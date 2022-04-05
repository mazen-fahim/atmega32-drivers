#ifndef _MUART_PRIVATE_H_
#define _MUART_PRIVATE_H_

/** USART I/O Data Register **/
#define UDR *((volatile u8 *)0x2c)
/*==============================================================*/
/** USART Control and status register A **/
#define UCSRA *((volatile u8 *)0x2b)
/* USART Recieve complete (issues an INTERRUPT) */
#define RXC  7
/* USART Transmit complete (issues an INTERRUPT) */
#define TXC  6
/* USART Data register empty (issues an INTERRUPT) */
#define UDRE 5
/* Frame Error (always set to zero when writing to UCSRA) */
#define FE   4
/* Data overrun (always set to zero when writing to UCSRA */
#define DOR  3
/* parity error (always set to zero when writing to UCSRA */
#define PE   2
/* double the USART tranmssion speed */
#define U2X  1
/* multi processor communication mode */
#define MPCM 0
/*==============================================================*/
/** USART Control and status register B **/
#define UCSRB *((volatile u8 *)0x2a)
/* RX complete interrupt enable */
#define RXCIE 7
/* TX complete interrupt enable */
#define TXCIE 6
/* USART Data register empty interrupt enable */
#define UDRIE 5
/* Reciver Enable */
#define RXEN  4
/* Transmitter enable */
#define TXEN  3
/* Character size bit2 */
#define UCSZ2 2
/* receive data bit 8 (when using 9bit char size) */
#define RXB8  1
/* transmit data bit 8 (when using 9bit char size) */
#define TXB8  0
/*==============================================================*/
/** USART Control and status register C **/
#define UCSRC *((volatile u8 *)0x40)
/* register select between UCSRC or UBRRH*/
#define URSEL 7
/* select sync or async mode */
#define UMSEL 6
/* Parity mode */
#define UPM1  5
#define UPM0  4
/* stop bit select (selects the number of stop bits to be inserted by the transmitter) */
#define USBS  3
/* Character size bit1/0 */
#define UCSZ1 2
#define UCSZ0 1
/* clock polarity (in only sync mode, this bit selects whether the transmitter sends bits at rising 
 * edge of the clock or falling edge. And consequently it determines the same for the reciever */
#define UCPOL 0
/*==============================================================*/
/** USART Baud Rate Registers **/
#define UBRRH *((volatile u8 *)0x40)
#define UBRRL *((volatile u8 *)0x29)
/*==============================================================*/



#endif
