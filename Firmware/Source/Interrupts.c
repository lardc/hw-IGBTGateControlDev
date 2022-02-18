﻿// Include
#include "Interrupts.h"
//
#include "Controller.h"
#include "LowLevel.h"
#include "Board.h"
#include "SysConfig.h"
#include "Global.h"
#include "DataTable.h"
#include "DeviceObjectDictionary.h"

// Functions
//
void USART1_IRQHandler()
{
	if(ZwSCI_RecieveCheck(USART1))
	{
		ZwSCI_RegisterToFIFO(USART1);
		ZwSCI_RecieveFlagClear(USART1);
	}
}
//-----------------------------------------

void USB_LP_CAN_RX0_IRQHandler()
{
	if(NCAN_RecieveCheck())
	{
		NCAN_RecieveData();
		NCAN_RecieveFlagReset();
	}
}
//-----------------------------------------

void EXTI15_10_IRQHandler(void)
{
	EXTI_FlagReset(EXTI_15);
	if (LL_ICompState())
		TIM_Start(TIM6);
	else CONTROL_IHighPriorityProcess(false);
}
//-----------------------------------------------

void TIM15_IRQHandler()
{
	if(TIM_StatusCheck(TIM15))
	{
		CONTROL_UHighPriorityProcess();

		TIM_StatusClear(TIM15);
	}
}
//-----------------------------------------

void TIM6_IRQHandler()
{
	if(TIM_StatusCheck(TIM6))
	{
		CONTROL_IHighPriorityProcess(true);
		TIM_StatusClear(TIM6);
	}
}
//-----------------------------------------

void TIM7_IRQHandler()
{
	static uint16_t LED_BlinkTimeCounter = 0;

	if(TIM_StatusCheck(TIM7))
	{

		CONTROL_TimeCounter++;
		if(++LED_BlinkTimeCounter > TIME_LED_BLINK)
		{
			LL_ToggleBoardLED();
			LED_BlinkTimeCounter = 0;
		}

		TIM_StatusClear(TIM7);
	}
}
//-----------------------------------------
