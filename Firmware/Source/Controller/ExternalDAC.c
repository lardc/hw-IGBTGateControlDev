// Header
#include "LowLevel.h"
// Include
#include "Board.h"
#include "Delay.h"
#include "Global.h"

// Functions
//
void LL_ToggleBoardLED()
{
	GPIO_Toggle(GPIO_LED);
}
//-----------------------------

void LL_VShortOut(bool State)
{
	GPIO_SetState(GPIO_SHORT_OUT, State);
}
//-----------------------------

void LL_IStart(bool State)
{
	GPIO_SetState(GPIO_I_START, State);
}
//-----------------------------

void LL_ICompState()
{
	GPIO_GetState(GPIO_I_COMP);
}
//-----------------------------

void LL_ISetDAC(Int16U Data)
{
	DAC_SetValueCh1(DAC1, Data);
}
//-----------------------------

void LL_USetDAC(Int16U Data)
{
	DAC_SetValueCh2(DAC1, Data);
}
//-----------------------------

