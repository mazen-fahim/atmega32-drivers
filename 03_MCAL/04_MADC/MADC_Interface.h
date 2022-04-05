/**************************************************
 * Author : Mazen Fahim                           *
 * Date : 18/10/2021                              *
 * Version : 1                                    *
 * File name : MADC_Interface.c                     *
 * Description : Interface of the ADC driver      *
 **************************************************/
#ifndef _MADC_INTERFACE_H_
#define _MADC_INTERFACE_H_

void MADC_VoidInit(void);
u16 MADC_U16ReadData(u8 Copy_U8Channel);


#endif
