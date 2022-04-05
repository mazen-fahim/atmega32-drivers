#ifndef _MUART_CONFIG_H_
#define _MUART_CONFIG_H_


/*
 * 0 -> 5bit
 * 1 -> 6bit
 * 2 -> 7bit
 * 3 -> 8bit
 * 7 -> 9bit
 * */
#define CHAR_SIZE 3


/*
 * 0 -> sync comms
 * 1 -> async comms */
#define SYNC 0

/*
 * 0 -> disabled 
 * 2 -> even parity
 * 3 -> odd parity
 * */
#define PARITY_MODE 0


/*
 * 0 -> disable
 * 1 -> enable
 * */
#define RECIEVER 1

/*
 * 0 -> disable
 * 1 -> enable
 * */
#define TRANSMITTER 1




#endif
