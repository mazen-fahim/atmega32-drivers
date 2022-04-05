/**************************************************
 * Author : Mazen Fahim                           *
 * Date : 18/10/2021                              *
 * Version : 1                                    *
 * File name : MADC_Program.c                     *
 * Description : Implementation of the ADC driver *
 **************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MADC_Config.h"
#include "MADC_Private.h"

void MADC_VoidInit(void)
{
    /* Set ADC enable bit to one */
    SET_BIT(ADCSRA, ADEN);

    /* Select ref voltage */
    SET_ADMUX_RSB(REF_SELECTION_BITS);

#if CONVERSION_MODE==0
    /* Activate single shot mode */
    CLR_BIT(ADCSRA, ADATE);
#elif CONVERSION_MODE==1
    /* Activate Auto Trigger mode */
    SET_BIT(ADCSRA, ADATE);
    SET_SFIOR_ATS_BITS(ATS_BITS);
    SET_BIT(ADCSRA, ADSC);
#endif

#if ADC_INTERRUPT_ENABLE==0
    /* Disable PIE of ADC */
    CLR_BIT(ADCSRA, ADIE);
#elif ADC_INTERRUPT_ENABLE==1
    /* Enable PIE of ADC */
    SET_BIT(ADCSRA, ADIE);
#endif

    /* Set prescalar 3 bits value in ADCSRA register to determin the input clock to the ADC */
    SET_ADCSRA_PRESCALAR_BITS(PRESCALAR_BITS);

    /* the output format of the ADC will be right adjusted */
    CLR_BIT(ADMUX, ADLAR);
}

u16 MADC_U16ReadData(u8 Copy_U8Channel)
{
    u16 LOC_U16RetValue = 0;

    /* we & with 7 to guard against invalid user input (note that channel is between 0:7 if single ended)*/
    Copy_U8Channel &= 0b00000111;

    /* Choose the channel that we will read from */
    SET_ADMUX_CHANNEL_SELECTION_BITS(Copy_U8Channel);
    /* Start conversion only if we are in single shot mode */

#if CONVERSION_MODE==0
    SET_BIT(ADCSRA, ADSC);
#endif

    /* wait for the conversion to finish (note that ADSC returns to zero after conversion finishes) */
    while(1 == GET_BIT(ADCSRA, ADSC));

    /* read data from 2 ADC data registers (high and low) */
    LOC_U16RetValue = ADCDATA;
    return LOC_U16RetValue;
}
