/*
 * Switch_config.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: LENOVO
 */

#include "stdTypes.h"
#include "errorStates.h"

#include "Switch_priv.h"
#include "Switch_config.h"

#include "DIO_int.h"


SW Switch_AStrSwitches [SW_NUMS] = {
		{DIO_u8PORTC, DIO_u8PIN2, DIO_u8FLOAT},
		{DIO_u8PORTB, DIO_u8PIN3, DIO_u8PULL_UP},
		{DIO_u8PORTC, DIO_u8PIN3, DIO_u8PULL_UP}
};

