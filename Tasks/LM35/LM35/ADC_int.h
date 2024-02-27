
#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

ES ADC_enuInit(void);

ES ADC_enuStartConversion(void);

ES ADC_enuPollingSystem(void);

ES ADC_enuReadHighValue(u8 * Copy_pu8Value);

ES ADC_enuRead(u16 * Copy_pu16Value);

ES ADC_enuCallBack(void(*Copy_pfunAppFun)(void*) , void * Copy_pvidAppParameter);

ES ADC_enuSelectChannel(u8 Copy_u8ChannelID);

ES ADC_enuEnableTriggeringMode(u8 Copy_u8TriggeringSource);

ES ADC_enuDisableTriggeringMode(void);

ES ADC_enuEnableInterruptMode(void);

#define ADC_FREE_RUNNING		18
#define ADC_EXTI0_TRIG			16

#endif /* MCAL_ADC_ADC_INT_H_ */
