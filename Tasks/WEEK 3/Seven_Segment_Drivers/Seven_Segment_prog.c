/*
 * Seven_Segment_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: LENOVO
 */
#include "stdTypes.h"
#include "errorStates.h"

#include "DIO_int.h"

#include "Seven_Segment_priv.h"
#include "Seven_Segment_config.h"

extern SEG Seven_Segment_AstrSegConfig [SEGS_NUM];

ES Seven_Segement_enuInit(SEG * Copy_pstrSegConfig)
{
	ES Local_u8ErrorState = ES_NOK;
	if(Copy_pstrSegConfig == NULL) return ES_NULL_POINTER;

	for(u8 Local_u8it = 0;Local_u8it < SEGS_NUM; Local_u8it++){
		DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8it].SEG_u8APort, Copy_pstrSegConfig[Local_u8it].SEG_u8APin, DIO_u8OUTPUT);
		DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8it].SEG_u8BPort, Copy_pstrSegConfig[Local_u8it].SEG_u8BPin, DIO_u8OUTPUT);
		DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8it].SEG_u8CPort, Copy_pstrSegConfig[Local_u8it].SEG_u8CPin, DIO_u8OUTPUT);
		DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8it].SEG_u8DPort, Copy_pstrSegConfig[Local_u8it].SEG_u8DPin, DIO_u8OUTPUT);
		DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8it].SEG_u8EPort, Copy_pstrSegConfig[Local_u8it].SEG_u8EPin, DIO_u8OUTPUT);
		DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8it].SEG_u8FPort, Copy_pstrSegConfig[Local_u8it].SEG_u8FPin, DIO_u8OUTPUT);
		DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8it].SEG_u8GPort, Copy_pstrSegConfig[Local_u8it].SEG_u8GPin, DIO_u8OUTPUT);

		if(Copy_pstrSegConfig[Local_u8it].SEG_u8Dot_Port != NOT_CONNECTED && Copy_pstrSegConfig[Local_u8it].SEG_u8Dot_Pin != NOT_CONNECTED){
			DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8it].SEG_u8Dot_Port, Copy_pstrSegConfig[Local_u8it].SEG_u8Dot_Pin, DIO_u8OUTPUT);
		}

		if(Copy_pstrSegConfig[Local_u8it].SEG_u8CMN_Port != NOT_CONNECTED && Copy_pstrSegConfig[Local_u8it].SEG_u8CMN_Pin != NOT_CONNECTED){
			DIO_enuSetPinDirection(Copy_pstrSegConfig[Local_u8it].SEG_u8CMN_Port, Copy_pstrSegConfig[Local_u8it].SEG_u8CMN_Pin, DIO_u8OUTPUT);
		}
	}

	Local_u8ErrorState = ES_OK;
	return Local_u8ErrorState;
}

ES Seven_Segement_enuDisplayNum(u8 Copy_u8SegID,u8 Copy_u8Num)
{
	ES Local_u8ErrorState = ES_NOK;
	if(Copy_u8SegID >= SEGS_NUM) return ES_OUT_OF_RANGE;

	if(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
	{
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8APort, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8APin, ((Seg_Au8NumDisplay[Copy_u8Num] >> 0) & 1));
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8BPort, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8BPin, ((Seg_Au8NumDisplay[Copy_u8Num] >> 1) & 1));
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8CPort, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8CPin, ((Seg_Au8NumDisplay[Copy_u8Num] >> 2) & 1));
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8DPort, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8DPin, ((Seg_Au8NumDisplay[Copy_u8Num] >> 3) & 1));
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8EPort, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8EPin, ((Seg_Au8NumDisplay[Copy_u8Num] >> 4) & 1));
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8FPort, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8FPin, ((Seg_Au8NumDisplay[Copy_u8Num] >> 5) & 1));
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8GPort, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8GPin, ((Seg_Au8NumDisplay[Copy_u8Num] >> 6) & 1));
	}
	else if(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
	{
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8APort, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8APin, !((Seg_Au8NumDisplay[Copy_u8Num] >> 0) & 1));
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8BPort, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8BPin, !((Seg_Au8NumDisplay[Copy_u8Num] >> 1) & 1));
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8CPort, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8CPin, !((Seg_Au8NumDisplay[Copy_u8Num] >> 2) & 1));
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8DPort, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8DPin, !((Seg_Au8NumDisplay[Copy_u8Num] >> 3) & 1));
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8EPort, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8EPin, !((Seg_Au8NumDisplay[Copy_u8Num] >> 4) & 1));
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8FPort, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8FPin, !((Seg_Au8NumDisplay[Copy_u8Num] >> 5) & 1));
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8GPort, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8GPin, !((Seg_Au8NumDisplay[Copy_u8Num] >> 6) & 1));
	}
	else return Local_u8ErrorState;




	Local_u8ErrorState = ES_OK;
	return Local_u8ErrorState;
}

ES Seven_Segement_enuEnableCommon(u8 Copy_u8SegID)
{
	ES Local_u8ErrorState = ES_NOK;

	if(Copy_u8SegID >= SEGS_NUM) return ES_OUT_OF_RANGE;
	if(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Port == NOT_CONNECTED || Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Pin == NOT_CONNECTED) return ES_NOK;


	if(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
	{
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Port, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Pin, DIO_u8LOW);
	}
	else if(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
	{
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Port, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Pin, DIO_u8HIGH);
	}
	else return Local_u8ErrorState;

	Local_u8ErrorState = ES_OK;
	return Local_u8ErrorState;
}

ES Seven_Segement_enuDisableCommon(u8 Copy_u8SegID)
{
	ES Local_u8ErrorState = ES_NOK;

	if(Copy_u8SegID >= SEGS_NUM) return ES_OUT_OF_RANGE;
	if(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Port == NOT_CONNECTED || Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Pin == NOT_CONNECTED) return ES_NOK;


	if(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
	{
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Port, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Pin, DIO_u8HIGH);
	}
	else if(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
	{
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Port, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Pin, DIO_u8LOW);
	}
	else return Local_u8ErrorState;

	Local_u8ErrorState = ES_OK;
	return Local_u8ErrorState;
}

ES Seven_Segement_enuEnableDot(u8 Copy_u8SegID)
{
	ES Local_u8ErrorState = ES_NOK;

	if(Copy_u8SegID >= SEGS_NUM) return ES_OUT_OF_RANGE;
	if(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8Dot_Port == NOT_CONNECTED || Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8Dot_Pin == NOT_CONNECTED) return ES_NOK;


	if(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
	{
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8Dot_Port, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8Dot_Pin, DIO_u8HIGH);
	}
	else if(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
	{
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8Dot_Port, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8Dot_Pin, DIO_u8LOW);
	}
	else return Local_u8ErrorState;


	Local_u8ErrorState = ES_OK;
	return Local_u8ErrorState;
}

ES Seven_Segement_enuDisableDot(u8 Copy_u8SegID)
{
	ES Local_u8ErrorState = ES_NOK;

	if(Copy_u8SegID >= SEGS_NUM) return ES_OUT_OF_RANGE;
	if(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8Dot_Port == NOT_CONNECTED || Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8Dot_Pin == NOT_CONNECTED) return ES_NOK;


	if(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
	{
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8Dot_Port, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8Dot_Pin, DIO_u8LOW);
	}
	else if(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
	{
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8Dot_Port, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8Dot_Pin, DIO_u8HIGH);
	}
	else return Local_u8ErrorState;


	Local_u8ErrorState = ES_OK;
	return Local_u8ErrorState;
}

ES Seven_Segement_enuClearDisblay(u8 Copy_u8SegID)
{
	ES Local_u8ErrorState = ES_NOK;
	if(Copy_u8SegID >= SEGS_NUM) return ES_OUT_OF_RANGE;

	if(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
	{
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8APort, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8APin, DIO_u8LOW);
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8BPort, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8BPin, DIO_u8LOW);
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8CPort, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8CPin, DIO_u8LOW);
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8DPort, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8DPin, DIO_u8LOW);
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8EPort, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8EPin, DIO_u8LOW);
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8FPort, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8FPin, DIO_u8LOW);
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8GPort, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8GPin, DIO_u8LOW);
	}
	else if(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
	{
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8APort, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8APin, DIO_u8HIGH);
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8BPort, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8BPin, DIO_u8HIGH);
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8CPort, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8CPin, DIO_u8HIGH);
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8DPort, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8DPin, DIO_u8HIGH);
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8EPort, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8EPin, DIO_u8HIGH);
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8FPort, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8FPin, DIO_u8HIGH);
		DIO_enuSetPinValue(Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8GPort, Seven_Segment_AstrSegConfig[Copy_u8SegID].SEG_u8GPin, DIO_u8HIGH);
	}
	else return Local_u8ErrorState;

	Local_u8ErrorState = ES_OK;
	return Local_u8ErrorState;
}

