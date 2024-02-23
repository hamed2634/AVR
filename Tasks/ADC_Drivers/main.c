#include "stdTypes.h"
#include "errorStates.h"

#include "DIO_int.h"

#include "EXTI_config.h"
#include "EXTI_int.h"

#include "ADC_int.h"
#include "GIE_int.h"

extern EXTI_t EXTI_AstrEXTIConfig [3] ;


void read (void *p)
{
	ADC_enuRead((u16*)p);
}



int main(void)
{
	u16 adcRead=0;

	DIO_enuSetPortDirection(DIO_u8PORTC, 0xff);
	DIO_enuSetPinDirection(DIO_u8PORTA, DIO_u8PIN3, DIO_u8INPUT);
	DIO_enuSetPinDirection(DIO_u8PORTD, DIO_u8PIN2, DIO_u8INPUT);

	EXTI_enuInit(EXTI_AstrEXTIConfig);
	EXTI_enuSetSenceMode(0,FALLING_EDGE);
	EXTI_enuEnableINT(0);

	ADC_enuInit();
	ADC_enuSelectChannel(3);
	ADC_enuEnableTriggeringMode(ADC_EXTI0_TRIG);
	ADC_enuEnableInterruptMode();

	ADC_enuCallBack(read , &adcRead);

	ADC_enuStartConversion();

	GIE_enuEnable();

	while (1)
	{

		DIO_enuSetPortValue(DIO_u8PORTC , adcRead);

	}
}
