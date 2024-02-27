/*
 * LM35_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: LENOVO
 */
#include "errorStates.h"
#include "stdTypes.h"

#include "ADC_int.h"

#include "LM35_priv.h"
#include "LM35_config.h"

ES LM35_u8GetTemp (s8 * Copy_u8TempValue) {

	ES Local_enuErrorState = ES_OK;

	s16 Local_u16ADCResult, Local_u16AnalogValue;

	s16 Local_u8ADCReference = (s16)ADC_Voltage_Reference * 1000 ;

	// ADC Digital Reading
	ADC_enuRead(&Local_u16ADCResult);




#if ADC_Resolution == ADC_RESOLUTION_10_BIT
	Local_u16AnalogValue = (s16) ( ((s32)Local_u16ADCResult * (s32)Local_u8ADCReference ) / 1024UL) ;
#elif ADC_Resolution == ADC_RESOLUTION_8_BIT
	Local_u16AnalogValue = (s16) ( ((s32)Local_u16ADCResult * (s32)Local_u8ADCReference ) / 256UL) ;
#else
	Local_enuErrorState = ES_OUT_OF_RANGE;
#endif


	* Copy_u8TempValue = Local_u16AnalogValue / 10 ;

	return Local_enuErrorState;
}
