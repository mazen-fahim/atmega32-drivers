#ifndef PORT_CONFIG_H
#define PORT_CONFIG_H

/* choose input or output*/
#define PORTA_PIN0_DIR OUTPUT
#define PORTA_PIN1_DIR OUTPUT
#define PORTA_PIN2_DIR OUTPUT
#define PORTA_PIN3_DIR OUTPUT
#define PORTA_PIN4_DIR OUTPUT
#define PORTA_PIN5_DIR OUTPUT
#define PORTA_PIN6_DIR OUTPUT
#define PORTA_PIN7_DIR OUTPUT

#define PORTB_PIN0_DIR OUTPUT
#define PORTB_PIN1_DIR OUTPUT
#define PORTB_PIN2_DIR OUTPUT
#define PORTB_PIN3_DIR OUTPUT
#define PORTB_PIN4_DIR OUTPUT
#define PORTB_PIN5_DIR OUTPUT
#define PORTB_PIN6_DIR OUTPUT
#define PORTB_PIN7_DIR OUTPUT

#define PORTC_PIN0_DIR OUTPUT
#define PORTC_PIN1_DIR OUTPUT
#define PORTC_PIN2_DIR OUTPUT
#define PORTC_PIN3_DIR OUTPUT
#define PORTC_PIN4_DIR OUTPUT
#define PORTC_PIN5_DIR OUTPUT
#define PORTC_PIN6_DIR OUTPUT
#define PORTC_PIN7_DIR OUTPUT

#define PORTD_PIN0_DIR OUTPUT
#define PORTD_PIN1_DIR OUTPUT
#define PORTD_PIN2_DIR OUTPUT
#define PORTD_PIN3_DIR OUTPUT
#define PORTD_PIN4_DIR OUTPUT
#define PORTD_PIN5_DIR OUTPUT
#define PORTD_PIN6_DIR OUTPUT
#define PORTD_PIN7_DIR OUTPUT

#define PORTA_DIR                                                              \
  CONC(PORTA_PIN7_DIR, PORTA_PIN6_DIR, PORTA_PIN5_DIR, PORTA_PIN4_DIR,         \
       PORTA_PIN3_DIR, PORTA_PIN2_DIR, PORTA_PIN1_DIR, PORTA_PIN0_DIR)
#define PORTB_DIR                                                              \
  CONC(PORTB_PIN7_DIR, PORTB_PIN6_DIR, PORTB_PIN5_DIR, PORTB_PIN4_DIR,         \
       PORTB_PIN3_DIR, PORTB_PIN2_DIR, PORTB_PIN1_DIR, PORTB_PIN0_DIR)
#define PORTC_DIR                                                              \
  CONC(PORTC_PIN7_DIR, PORTC_PIN6_DIR, PORTC_PIN5_DIR, PORTC_PIN4_DIR,         \
       PORTC_PIN3_DIR, PORTC_PIN2_DIR, PORTC_PIN1_DIR, PORTC_PIN0_DIR)
#define PORTD_DIR                                                              \
  CONC(PORTD_PIN7_DIR, PORTD_PIN6_DIR, PORTD_PIN5_DIR, PORTD_PIN4_DIR,         \
       PORTD_PIN3_DIR, PORTD_PIN2_DIR, PORTD_PIN1_DIR, PORTD_PIN0_DIR)

#define CONC(A, B, C, D, E, F, G, H) CONC_HELPER(A, B, C, D, E, F, G, H)
#define CONC_HELPER(A, B, C, D, E, F, G, H) 0b##A##B##C##D##E##F##G##H

#endif
