/*
 * Seven_Segment_int.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: LENOVO
 */

#ifndef SEVEN_SEGMENT_INT_H_
#define SEVEN_SEGMENT_INT_H_

ES Seven_Segement_enuInit(SEG * Copy_pstrSegConfig);

ES Seven_Segement_enuDisplayNum(u8 Copy_u8SegID,u8 Copy_u8Num);

ES Seven_Segement_enuEnableCommon(u8 Copy_u8SegID);

ES Seven_Segement_enuDisableCommon(u8 Copy_u8SegID);

ES Seven_Segement_enuEnableDot(u8 Copy_u8SegID);

ES Seven_Segement_enuDisableDot(u8 Copy_u8SegID);

ES Seven_Segement_enuClearDisblay(u8 Copy_u8SegID);



#endif /* SEVEN_SEGMENT_INT_H_ */
