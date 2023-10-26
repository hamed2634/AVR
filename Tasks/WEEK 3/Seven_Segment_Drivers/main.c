/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: LENOVO
 */
#include "stdTypes.h"
#include "errorStates.h"

#include "DIO_int.h"

#include "Seven_segment_config.h"
#include "Seven_Segment_int.h"

#include <util\delay.h>

extern SEG Seven_Segment_AstrSegConfig [SEGS_NUM];
int main(void){
	DIO_enuInit();
	Seven_Segement_enuInit(Seven_Segment_AstrSegConfig);
	while(1){
		for(u8 i = 0;i < 10; i++){
			Seven_Segement_enuDisplayNum(0,i);
			for(u8 j = 0;j < 10; j++){
				Seven_Segement_enuDisplayNum(1,j);
				_delay_ms(100);
			}
		}
	}

	return 0;
}
