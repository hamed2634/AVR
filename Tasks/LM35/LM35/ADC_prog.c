/*
 * ADC_prog.c
 *
 *  Created on: Sep 20, 2021
 *      Author: Ahmed El-Gaafrawy
 */
#include "stdTypes.h"
#include "errorStates.h"

#include "ADC_config.h"
#include "ADC_priv.h"

#include "interrupt.h"


static void (*ADC_pfunISRFun)(void*) = NULL;
static void * ADC_pvidISRParameter = NULL;


ES ADC_enuInit(void)
{
	ES Local_enuErrorState = ES_NOK;


	//Enable ADEN:
	ADCSRA |= (1<<7);

#if ADC_PRES == PRES_2
	ADCSRA &= ~(1<<0);
	ADCSRA &= ~(1<<1);
	ADCSRA &= ~(1<<2);
#elif ADC_PRES == PRES_4
	ADCSRA &= ~(1<<0);
	ADCSRA |= (1<<1);
	ADCSRA &= ~(1<<2);
#elif ADC_PRES == PRES_8
	ADCSRA |= (1<<0);
	ADCSRA |= (1<<1);
	ADCSRA &= ~(1<<2);
#elif ADC_PRES == PRES_16
	ADCSRA &= ~(1<<0);
	ADCSRA &= ~(1<<1);
	ADCSRA |= (1<<2);
#elif ADC_PRES == PRES_32
	ADCSRA |= (1<<0);
	ADCSRA &= ~(1<<1);
	ADCSRA |= (1<<2);
#elif ADC_PRES == PRES_64
	ADCSRA &= ~(1<<0);
	ADCSRA |= (1<<1);
	ADCSRA |= (1<<2);
#elif ADC_PRES == PRES_128
	ADCSRA |= (1<<0);
	ADCSRA |= (1<<1);
	ADCSRA |= (1<<2);
#else
#error" ADC PRESCALLER is Wrong "
#endif


#if ADC_REF_VOLT == AREF_REF
	ADMUX &= ~(1<<7);
	ADMUX &= ~(1<<6);
#elif ADC_REF_VOLT == INTERNAL
	ADMUX |= (1<<7);
	ADMUX |= (1<<6);
#elif ADC_REF_VOLT == AVCC_REF
	ADMUX &=~(1<<7);
	ADMUX |= (1<<6);
#else
#error" ADC REFRENCE VOLT is Wrong "
#endif


#if ADC_ADJ == LEFT_ADJ
	ADMUX |= (1<<5);
#elif ADC_ADJ == RIGHT_ADJ
	ADMUX &=~(1<<5);
#else
#error" ADC ADJUSTMENT is Wrong "
#endif

	return Local_enuErrorState;
}

ES ADC_enuStartConversion(void)
{
	ES Local_enuErrorState = ES_NOK;

	ADCSRA |= (1<<6);

	return Local_enuErrorState;
}

ES ADC_enuPollingSystem(void)
{
	ES Local_enuErrorState = ES_NOK;

	while (((ADCSRA >> 4)&1) == 0);
	ADCSRA |= (1<<4);

	return Local_enuErrorState;
}

ES ADC_enuReadHighValue(u8 * Copy_pu8Value)
{
	ES Local_enuErrorState = ES_NOK;

#if ADC_ADJ == LEFT_ADJ
	*Copy_pu8Value = ADCH;

#elif ADC_ADJ == RIGHT_ADJ
	*Copy_pu8Value  = (ADCL >> 2);
	*Copy_pu8Value |= (ADCH << 6);
#else
#error" ADC ADJUSTMENT is Wrong "
#endif

	return Local_enuErrorState;
}

ES ADC_enuRead(s16 * Copy_ps16Value)
{
	ES Local_enuErrorState = ES_NOK;

#if ADC_ADJ == LEFT_ADJ
	*Copy_pu16Value  = (ADCL >> 6);
	*Copy_pu16Value |= (ADCH << 2);

#elif ADC_ADJ == RIGHT_ADJ
	*Copy_ps16Value  = ADCL;
	*Copy_ps16Value |= ((s16)ADCH << 8);
#else
#error" ADC ADJUSTMENT is Wrong "
#endif

	return Local_enuErrorState;
}

ES ADC_enuCallBack(void(*Copy_pfunAppFun)(void*) , void * Copy_pvidAppParameter)
{
	ES Local_enuErrorState = ES_NOK;

	if (Copy_pfunAppFun != NULL)
	{
		ADC_pfunISRFun = Copy_pfunAppFun;
		ADC_pvidISRParameter = Copy_pvidAppParameter;
	}

	return Local_enuErrorState;
}

ES ADC_enuSelectChannel(u8 Copy_u8ChannelID)
{
	ES Local_enuErrorState = ES_NOK;

	ADMUX &= ~ 0x1F;
	ADMUX |= Copy_u8ChannelID;

	return Local_enuErrorState;
}

ES ADC_enuEnableTriggeringMode(u8 Copy_u8TriggeringSource)
{
	ES Local_enuErrorState = ES_NOK;

	ADCSRA &=~(1<<5);

	switch(Copy_u8TriggeringSource)
	{
	case FREE_RUNNING:
		SFIOR &=~(1<<5);
		SFIOR &=~(1<<6);
		SFIOR &=~(1<<7);
		break;
	case EXTI0_TRIG:
		SFIOR &=~(1<<5);
		SFIOR |= (1<<6);
		SFIOR &=~(1<<7);
		break;
	}

	ADCSRA |=(1<<5);

	return Local_enuErrorState;
}


ES ADC_enuDisableTriggeringMode(void)
{
	ES Local_enuErrorState = ES_NOK;

	ADCSRA &=~(1<<5);

	return Local_enuErrorState;
}

ES ADC_enuEnableInterruptMode(void)
{
	ES Local_enuErrorState = ES_NOK;

	ADCSRA |= (1<<3);

	return Local_enuErrorState;
}

ISR(VECT_ADC)
{
	if (ADC_pfunISRFun != NULL)
	{
		ADC_pfunISRFun(ADC_pvidISRParameter);
	}
}
