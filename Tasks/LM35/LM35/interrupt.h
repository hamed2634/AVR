/*
 * intrrupt.h
 *
 *  Created on: Sep 16, 2021
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef MCAL_INTERRUPT_H_
#define MCAL_INTERRUPT_H_



#define ISR(VECT_NUM)		void VECT_NUM (void) __attribute__ ((signal));\
							void VECT_NUM (void)

#define VECT_INT0			__vector_1
#define VECT_INT1			__vector_2
#define VECT_INT2			__vector_3
#define VECT_TIMER2_CTC		__vector_4

#define VECT_ADC			__vector_16

#endif /* MCAL_INTERRUPT_H_ */
