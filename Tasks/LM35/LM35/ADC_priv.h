/*
 * ADC_priv.h
 *
 *  Created on: Sep 20, 2021
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef MCAL_ADC_ADC_PRIV_H_
#define MCAL_ADC_ADC_PRIV_H_

#define PRES_2			6
#define PRES_4			9
#define PRES_8			11
#define PRES_16			15
#define PRES_32			52
#define PRES_64			96
#define PRES_128		14


#define AVCC_REF		16
#define AREF_REF		18
#define	INTERNAL		93

#define RIGHT_ADJ		9
#define LEFT_ADJ		16


#define ADMUX			*((u8*)0x27)
#define ADCSRA			*((u8*)0x26)
#define ADCH			*((volatile u8*)0x25)
#define ADCL			*((volatile u8*)0x24)

#define SFIOR			*((u8*)0x50)


#define FREE_RUNNING		18
#define EXTI0_TRIG			16


#endif /* MCAL_ADC_ADC_PRIV_H_ */
