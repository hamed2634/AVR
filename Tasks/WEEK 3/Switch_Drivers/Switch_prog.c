/*
 * Switch_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: LENOVO
 */

#include "stdTypes.h"
#include "errorStates.h"

#include "Switch_priv.h"
#include "Switch_config.h"

#include "DIO_init.h"


ES Switch_enuInit(SW* copy_AStrSwitches){
	ES Local_enuErrorState = ES_NOK;

	if(copy_AStrSwitches == NULL) Local_enuErrorState = ES_NULL_POINTER;
	else{
		for(u8 Local_u8Iterator = 0;Local_u8Iterator < SW_NUMS; Local_u8Iterator++){
			DIO_enuSetPinDirection(copy_AStrSwitches[Local_u8Iterator].u8_SwitchPortID, copy_AStrSwitches[Local_u8Iterator].u8_SwitchPinID, DIO_u8INPUT);
			DIO_enuSetPinValue(copy_AStrSwitches[Local_u8Iterator].u8_SwitchPortID, copy_AStrSwitches[Local_u8Iterator].u8_SwitchPinID, copy_AStrSwitches[Local_u8Iterator].u8_SwitchState);
		}
	}

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES Switch_enuGetState(SW* copy_AStrSwitches,u8* copy_pu8SwState){
	ES Local_enuErrorState = ES_NOK;

	if(copy_AStrSwitches == NULL || copy_pu8SwState == NULL) Local_enuErrorState = ES_NULL_POINTER;
	else{
		DIO_enuGetpin(copy_AStrSwitches->u8_SwitchPortID, copy_AStrSwitches->u8_SwitchPinID, copy_pu8SwState);
		if(copy_AStrSwitches->u8_SwitchState == DIO_u8PULL_UP){
			*copy_pu8SwState = !(*copy_pu8SwState);
		}
	}

	return Local_enuErrorState;
}
