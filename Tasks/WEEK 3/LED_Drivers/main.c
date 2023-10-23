#include <util/delay.h>

#include "stdTypes.h"
#include "errorStates.h"

#include "LED_config.h"
#include "LED_int.h"

#include "DIO_int.h"

extern LED LED_AStrLEDS[LEDS_NUM];
int main(void){

	//DIO_enuInit();
	LED_enuInit(LED_AStrLEDS);
	while(1){
		for(u8 i = 0; i < LEDS_NUM; i++){
			LED_enuTurnLedON(&LED_AStrLEDS[i]);
			_delay_ms(500);
		}
		for(u8 i = 0; i < LEDS_NUM; i++){
			LED_enuTurnLedOFF(&LED_AStrLEDS[i]);
			_delay_ms(500);
		}
	}
}




