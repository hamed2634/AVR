#include "errorStates.h"
#include "stdTypes.h"

#include "Switch_config.h"
#include "Switch_int.h"

#include "DIO_int.h"


extern SW Switch_AStrSwitches[SW_NUMS];
int main(void){

	DIO_enuInit();
	Switch_enuInit(Switch_AStrSwitches);

	u8 Local_u8State = 0;
	while(1){
		Switch_enuGetState(&Switch_AStrSwitches[0], &Local_u8State);

		if(Local_u8State) DIO_enuSetPinValue(DIO_u8PORTA, DIO_u8PIN0,DIO_u8HIGH);
		else DIO_enuSetPinValue(DIO_u8PORTA, DIO_u8PIN0,DIO_u8LOW);
	}
}




