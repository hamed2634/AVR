/*
 * Switch_config.c
 *
 *  Created on: ??�/??�/????
 *      Author: LENOVO
 */

#include "stdTypes.h"
#include "errorStates.h"

#include "Switch_priv.h"
#include "Switch_config.h"

#include "DIO_init.h"


SW Switch_AStrSwitches [SW_NUMS] = {
		{DIO_u8PORTA, DIO_u8PIN3, DIO_u8FLOAT},
		{DIO_u8PORTB, DIO_u8PIN3, DIO_u8PULL_UP},
		{DIO_u8PORTC, DIO_u8PIN3, DIO_u8PULL_UP}
};

