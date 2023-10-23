/*
 * LED_config.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: LENOVO
 */
#include "errorStates.h"
#include "stdTypes.h"

#include "LED_priv.h"
#include "LED_config.h"

#include "DIO_int.h"

LED LED_AStrLEDS[LEDS_NUM] = {
		{DIO_u8PORTA, DIO_u8PIN0, DIO_u8SOURCE},
		{DIO_u8PORTA, DIO_u8PIN1, DIO_u8SOURCE},
		{DIO_u8PORTA, DIO_u8PIN2, DIO_u8SINK}
};
