/***************************************************
 * Author : Mazen Fahim                            *
 * Date : 18/10/2021                               *
 * Version : 1                                     *
 * File name : MADC_Config.c                       *
 * Description : user configuration ADC peripheral *
 **************************************************/

#ifndef _MADC_CONFIG_H_
#define _MADC_CONFIG_H_

/* Reference configure */
/* 0 -> AREF
 * 1 -> AVCC
 * 2 -> Reserved
 * 3 -> Internal 2.56v */
#define REF_SELECTION_BITS 1

/* 0 -> one shot mode
 * 1 -> Auto Trigger mode */
#define CONVERSION_MODE 0
/* if CONVERSION_MODE = "free running" choose the soucre of 
 * the auto trigger
 * 0 -> Free running mode
 * 1 -> Analog compartor 
 * 2 -> External interrupt request 0 
 * 3 -> Timer/Counter0 compare match 
 * 4 -> Timer/Counter0 overflow 
 * 5 -> Timer/Counter Compare match B 
 * 6 -> Timer/Counter1 Overflow 
 * 7 -> Timer/Counter1 Capture Event */ 
#define ATS_BITS 0

/* Select the clock freq of the ADC 
 * 0 -> MCU clock / 2
 * 1 -> MCU clock / 2 
 * 2 -> MCU clock / 4 
 * 3 -> MCU clock / 8 
 * 4 -> MCU clock / 16 
 * 5 -> MCU clock / 32 
 * 6 -> MCU clock / 64 
 * 7 -> MCU clock / 128 */
#define PRESCALAR_BITS 7

/* 0 -> to disable the interrupt of the ADC
 * 1 -> to enable the interrupt of the ADC */
#define ADC_INTERRUPT_ENABLE 0

#endif
