
#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

ES EXTI_enuInit (EXTI_t * Copy_pstrEXTIConfig);

ES EXTI_enuSetSenceMode(u8 Copy_u8EXTI_ID , u8 Copy_u8SenseLevel);

ES EXTI_enuEnableINT(u8 Copy_u8EXTI_ID);

ES EXTI_enuDisableINT(u8 Copy_u8EXTI_ID);

ES EXTI_enuCallBack(void (*Copy_pfunAppFun)(void*), void * Copy_pvidParameter , u8 Copy_u8EXTI_ID);

#define RISING_EDGE			5
#define FALLING_EDGE		9
#define ANY_LOGIC			19
#define LOW_LEVEL			93

#endif /* MCAL_EXTI_EXTI_INT_H_ */
