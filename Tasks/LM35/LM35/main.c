#include "stdTypes.h"
#include "errorStates.h"

#include "DIO_int.h"

#include "ADC_int.h"

#include "LCD_int.h"

#include "LM35_int.h"

int main(void)
{
	u8 temperature = 0;

	LCD_enuInit();

	DIO_enuSetPortDirection(DIO_u8PORTC, 0xFF);

	//LM35 Channel
	DIO_enuSetPinDirection(DIO_u8PORTA, DIO_u8PIN3, DIO_u8INPUT);
	ADC_enuInit();
	ADC_enuSelectChannel(3);
	ADC_enuDisableTriggeringMode();


	LCD_enuClearDisplay();
	LCD_enuDisplayChar('T');
	LCD_enuDisplayChar('e');
	LCD_enuDisplayChar('m');
	LCD_enuDisplayChar('p');
	LCD_enuDisplayChar('r');
	LCD_enuDisplayChar('a');
	LCD_enuDisplayChar('t');
	LCD_enuDisplayChar('u');
	LCD_enuDisplayChar('r');
	LCD_enuDisplayChar('e');
	LCD_enuDisplayChar(' ');
	LCD_enuDisplayChar('=');
	LCD_enuDisplayChar(' ');
	LCD_enuSendCommand(0x0C);
	while (1)
	{


		ADC_enuStartConversion();
		ADC_enuPollingSystem();
		LM35_u8GetTemp(&temperature);
		//DIO_enuSetPortValue(DIO_u8PORTC , temperature);

		LCD_enuGoto(1,13);

		if(temperature < 0) {
			LCD_enuDisplayChar('-');
			temperature *= -1;
		}

		LCD_enuDisplayChar('0' + (temperature / 10) % 10);
		LCD_enuDisplayChar('0' + temperature % 10);
		LCD_enuDisplayChar('C');

	}
}
