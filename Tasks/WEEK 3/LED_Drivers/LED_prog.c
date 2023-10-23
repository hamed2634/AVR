/*
 * LED_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: LENOVO
 */

#include "DIO_int.h"
#include "errorStates.h"
#include "stdTypes.h"

#include "LED_priv.h"
#include "LED_config.h"


ES LED_enuInit(LED* copy_AStrLEDS){
	ES Local_enuErrorState = ES_NOK;

	if(copy_AStrLEDS == NULL) Local_enuErrorState = ES_NULL_POINTER;
	else{
		for(u8 Local_u8Iterator = 0; Local_u8Iterator < LEDS_NUM; Local_u8Iterator++){
			DIO_enuSetPinDirection(copy_AStrLEDS[Local_u8Iterator].u8_LedPortID, copy_AStrLEDS[Local_u8Iterator].u8_LedPinID, DIO_u8OUTPUT);
			DIO_enuSetPinValue(copy_AStrLEDS[Local_u8Iterator].u8_LedPortID, copy_AStrLEDS[Local_u8Iterator].u8_LedPinID, !copy_AStrLEDS[Local_u8Iterator].u8_LedState);
		}
		Local_enuErrorState = ES_OK;
	}


	return Local_enuErrorState;
}

ES LED_enuTurnLedON(LED* copy_AStrLEDS){
	ES Local_enuErrorState = ES_NOK;

	if(copy_AStrLEDS == NULL) Local_enuErrorState = ES_NULL_POINTER;
	else{
		DIO_enuSetPinValue(copy_AStrLEDS->u8_LedPortID, copy_AStrLEDS->u8_LedPinID, copy_AStrLEDS->u8_LedState);
		Local_enuErrorState = ES_OK;
	}


	return Local_enuErrorState;
}

ES LED_enuTurnLedOFF(LED* copy_AStrLEDS){
	ES Local_enuErrorState = ES_NOK;

	if(copy_AStrLEDS == NULL) Local_enuErrorState = ES_NULL_POINTER;
	else{
		DIO_enuSetPinValue(copy_AStrLEDS->u8_LedPortID, copy_AStrLEDS->u8_LedPinID, !copy_AStrLEDS->u8_LedState);
		Local_enuErrorState = ES_OK;
	}

	return Local_enuErrorState;
}

ES LED_enuTogLed(LED* copy_AStrLEDS){
	ES Local_enuErrorState = ES_NOK;

	if(copy_AStrLEDS == NULL) Local_enuErrorState = ES_NULL_POINTER;
	else{
		DIO_enuTogPin(copy_AStrLEDS->u8_LedPortID, copy_AStrLEDS->u8_LedPinID);
		Local_enuErrorState = ES_OK;
	}

	return Local_enuErrorState;
}

