#ifndef _MTIMER_PRIVATE_H_ 
#define _MTIMER_PRIVATE_H_ 

/* time counter control register (0) */
#define TCCR0 *((volatile u8 *) 0x53)

/* time counter control register (0) */
#define TCNT0 *((volatile u8 *) 0x52)

/* we will not use this register as we work with normal mode */
#define OCR0 *((volatile u8 *) 0x5c)

/* */
#define TIMSK *((volatile u8 *) 0x59)

/* */
#define TIFR *((volatile u8 *) 0x58)

/* TCCR0 bits */
#define FOC0  7
#define WGM00 6
#define COM01 5
#define COM00 4
#define WGM01 3
#define CS02  2
#define CS01  1
#define CS00  0

/* TIMSK bits */
#define OCIE0 1
#define TOIE0 0

/* TIFR bits */
#define OCF0 1
#define TOV0 0

void __vector_11(void) __attribute__((signal));


#endif

