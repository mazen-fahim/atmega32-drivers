#ifndef _MEXTI_INTERFACE_H_
#define _MEXTI_INTERFACE_H_

/* Interrupt sense control register */
#define MCUCR *((volatile char *) 0x55)
/* Interrupt sense control 1 */
#define ISC11 3
#define ISC10 2
/* Interrupt sense control 0 */
#define ISC01 1
#define ISC00 0


#define MCUCSR *((volatile char *) 0x54)

#define GICR *((volatile char *) 0x5B)
#define INT2_PIE_BIT 5
#define INT0_PIE_BIT 6
#define INT1_PIE_BIT 7

#define GIFR *((volatile char *) 0x5A)

void __vector_1(void) __attribute__((signal));



#endif
