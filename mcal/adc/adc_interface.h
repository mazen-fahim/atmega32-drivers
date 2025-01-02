/**************************************************
 * Author : Mazen Fahim                           *
 * Date : 18/10/2021                              *
 * Version : 1                                    *
 * File name : adc_interface.c                     *
 * Description : Interface of the ADC driver      *
 **************************************************/
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

void ADC_VoidInit(void);
u16 ADC_U16ReadData(u8 Copy_U8Channel);

#endif
