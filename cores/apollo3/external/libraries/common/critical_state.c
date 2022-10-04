#include "stdbool.h"
#include "critical_state.h"
#include "apollo3.h"


static bool state = true;
void critical_state_enter(void)
{
	if(state == true)
	{
            __disable_irq();
            state = false;
	}	
}

void critical_state_exit(void)
{
	if (state == false)
	{
            __enable_irq();
            state = true;
	}
}
