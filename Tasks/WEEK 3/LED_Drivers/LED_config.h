/*
 * LED_config.h
 *
 *  Created on: ??�/??�/????
 *      Author: LENOVO
 */

#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_

typedef struct{
	u8 u8_LedPortID;
	u8 u8_LedPinID;
	u8 u8_LedConnection;
	u8 u8_Ledinital;
}LED;

#define LEDS_NUM 3

#endif /* LED_CONFIG_H_ */
