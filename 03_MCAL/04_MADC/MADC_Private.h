/***********************************************************
 * Author : Mazen Fahim                                    *
 * Date : 18/10/2021                                       *
 * Version : 1                                             *
 * File name : MADC_Private.c                              *
 * Description : Private header to ease the implementation *
 * of the ADC Driver and make it more readable. note:      *
 * user must NOT alter this file                           *
 **********************************************************/
#ifndef _MADC_PRIVATE_H_
#define _MADC_PRIVATE_H_

/* ADC Registers addresses */
#define ADMUX * ((volatile u8 *) 0x27)
#define ADCSRA * ((volatile u8 *) 0x26)
#define ADCH * ((volatile u8 *) 0x25)
#define ADCL * ((volatile u8 *) 0x24)
#define ADCDATA *((volatile u16 *) 0x24)
#define SFIOR * ((volatile u8 *) 0x50)

/*==========================================================================*/
/** ADMUX bits (Multiplexer selection register) **/
/* ADC voltage reference selection bits */
#define REFS1 7
#define REFS0 6
#define SET_ADMUX_RSB(value) ADMUX = ((ADMUX & 0b00111111) | (value << 6))

/* Left adjust bit (0 -> Rigt-adjust, 1 -> Left-adjust) */
#define ADLAR 5

/* (this macro is for readability purpose) */
#define SET_ADMUX_CHANNEL_SELECTION_BITS(value) ADMUX = ((ADMUX & 0b11100000) | value)

/*==========================================================================*/
/** ADCSRA bits (control and status register A) **/
/* ADC enable bit 
 * 0 -> Disable ADC 
 * 1 -> Enable ADC */
#define ADEN 7

/* ADC start conversion bit 
 * 1 -> start conversion */
#define ADSC 6

/* ADC auto trigger enable bit
 * 0 -> single mode
 * 1 -> auto mode */
#define ADATE 5

/* ADC interrupt flag 
 * 0 -> busy
 * 1 -> finished conversion */
#define ADIF 4

/* ADC interrupt enable 
 * 0 -> Disable PIE 
 * 1 -> Enable PIE */
#define ADIE 3

/* ADC 3 prescalar bits (this is for readability purpose) */
#define SET_ADCSRA_PRESCALAR_BITS(value) ADCSRA = ((ADCSRA & 0b11111000) | value)

/*==========================================================================*/
/** SFIOR bits (Special function IO register) **/

/* ADC 3 auto trigger source bits (this is for readability purpose) */
#define SET_SFIOR_ATS_BITS(value) SFIOR = ((SFIOR & 0b00011111) | (value << 5))

#endif
