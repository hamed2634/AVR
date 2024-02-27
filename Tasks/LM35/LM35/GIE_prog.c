
#include "stdTypes.h"
#include "errorStates.h"

#include "GIE_priv.h"

ES GIE_enuEnable(void)
{
	ES Local_enuErrorState = ES_NOK;

	SREG |=(1<<7);

	return Local_enuErrorState;
}


ES GIE_enuDisable(void)
{
	ES Local_enuErrorState = ES_NOK;

	SREG &=~(1<<7);

	return Local_enuErrorState;
}
