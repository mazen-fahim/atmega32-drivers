#ifndef _MICU_PRIVATE_H_ 
#define _MICU_PRIVATE_H_ 

/* Timer/Counter1 control register A*/
#define TCCR1A *((volatile u8 *) 0x4f)
#define COM1A1 7
#define COM1A0 6
#define COM1B1 5
#define COM1B0 4
#define FOC1A  3
#define FOC1B  2
#define WGM11  1
#define WGM10  0

/* Timer/Counter1 control register B*/
#define TCCR1B *((volatile u8 *) 0x4e)
#define ICNC1 7
#define ICES1 6
#define WGM13 4
#define WGM12 3
#define CS12  2
#define CS11  1
#define CS10  0

/* Timer/Counter1 register*/
#define TCNT1H *((volatile u8 *) 0x4d)
#define TCNT1L *((volatile u8 *) 0x4c)
#define TCNT1 *((volatile u16 *) 0x4c)

/* Output compare register 1 A*/
#define OCR1AH *((volatile u8 *) 0x4b)
#define OCR1AL *((volatile u8 *) 0x4a)
#define OCR1A *((volatile u16 *) 0x4a)

/* Output compare register 1 B*/
#define OCR1BH *((volatile u8 *) 0x49)
#define OCR1BL *((volatile u8 *) 0x48)
#define OCR1B *((volatile u16 *) 0x48) 
/* Input capture register 1*/
#define ICR1H *((volatile u8 *) 0x47)
#define ICR1L *((volatile u8 *) 0x46)
#define ICR1 *((volatile u16 *) 0x46)

#define TIMSK *((volatile u8 *) 0x59)
#define TICIE 5
#define OCIE1A 4
#define OCIE1B 3
#define TOIE1 2

#define TIFR *((volatile u8 *) 0x58)


void __vector_(void) __attribute__((signal));

#endif

