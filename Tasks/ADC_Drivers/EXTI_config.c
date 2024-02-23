
#include "stdTypes.h"
#include "errorStates.h"

#include "EXTI_priv.h"
#include "EXTI_config.h"



EXTI_t EXTI_AstrEXTIConfig [3] =
{
		{ACTIVE, FALLING_EDGE},
		{DEACTIVE},
		{DEACTIVE}
};
