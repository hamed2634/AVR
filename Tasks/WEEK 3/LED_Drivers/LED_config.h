/*
 * LED_config.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: LENOVO
 */

#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_

typedef struct{
	u8 u8_LedPortID;
	u8 u8_LedPinID;
	u8 u8_LedState;
}LED;

#define LEDS_NUM 3

#endif /* LED_CONFIG_H_ */
