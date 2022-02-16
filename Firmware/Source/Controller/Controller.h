#ifndef __CONTROLLER_H
#define __CONTROLLER_H

// Include
//
#include "stdinc.h"
#include "Global.h"
#include "Regulator.h"

// Types
//
typedef enum __DeviceState
{
	DS_None = 0,
	DS_Fault = 1,
	DS_Disabled = 2,
	DS_Ready = 3,
	DS_InProcess = 4
} DeviceState;

typedef enum __DeviceSubState
{
	SS_None = 0,
	SS_PulsePrepare = 1,
	SS_Pulse = 2,
	SS_WaitAfterPulse = 3
} DeviceSubState;

// Variables
//
extern volatile DeviceState CONTROL_State;
extern volatile Int64U CONTROL_TimeCounter;
extern Int64U CONTROL_LEDTimeout;
extern volatile Int16U CONTROL_Values_Counter;
extern volatile Int16U CONTROL_RegulatorErr_Counter;
extern volatile Int16U CONTROL_UUValues[U_VALUES_x_SIZE];
extern volatile Int16U CONTROL_UUMeasValues[U_VALUES_x_SIZE];
extern volatile Int16U CONTROL_RegulatorOutput[U_VALUES_x_SIZE];
extern volatile Int16U CONTROL_RegulatorErr[U_VALUES_x_SIZE];
extern volatile Int16U CONTROL_DACRawData[U_VALUES_x_SIZE];
extern volatile Int16U CONTROL_UIMeasValues[U_VALUES_x_SIZE];
extern volatile Int16U CONTROL_IIGateValues[I_VALUES_x_SIZE];
//
extern volatile RegulatorParamsStruct RegulatorParams;


// Functions
//
void CONTROL_Init();
void CONTROL_Idle();
void CONTROL_SetDeviceState(DeviceState NewState, DeviceSubState NewSubState);
void CONTROL_DelayMs(uint32_t Delay);
void CONTROL_HighPriorityProcess();
void CONTROL_ExternalInterruptProcess();
void CONTROL_SineConfig(volatile RegulatorParamsStruct* Regulator);
void CONTROL_LinearConfig(volatile RegulatorParamsStruct* Regulator);
void CONTROL_CopyCurrentToEP(volatile RegulatorParamsStruct* Regulator);
void CONTROL_StartProcess();
void CONTROL_HandleFanLogic(bool IsImpulse);
void CONTROL_UAverage();
void CONTROL_UStartProcess();
void CONTROL_UStopProcess();

#endif // __CONTROLLER_H
