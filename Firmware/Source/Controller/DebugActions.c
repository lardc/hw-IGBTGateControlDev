﻿// Header
#include "DebugActions.h"

// Include
//
#include "LowLevel.h"
#include "Board.h"
#include "Delay.h"
#include "Controller.h"
#include "DataTable.h"
#include "Controller.h"
#include "Delay.h"
#include "ConvertUtils.h"
#include "Measurement.h"
#include "ExternalDAC.h"

// Functions
//
// Источник напряжения
//
void DBGACT_UUSet()
{
	LL_UUSetDAC(CU_UToDAC((float)DataTable[REG_DBG]));
}
//-----------------------------

void DBGACT_UShortOut()
{
	DataTable[REG_DBG] == 0 ? LL_UShortOut(false) : LL_UShortOut(true);
}
//-----------------------------

void DBGACT_UUSen()
{
	DataTable[REG_DBG] = (Int16U)CU_UADCUToX(MEASURE_UUSen());
}
//-----------------------------

void DBGACT_UISen()
{
	DataTable[REG_DBG] = (Int16U)CU_UADCIToX(MEASURE_UISen());
}
//-----------------------------

// Источник тока
//
void DBGACT_IISet()
{
	LL_IISetDAC(CU_UToDAC((float)DataTable[REG_DBG]));
}
//-----------------------------

void DBGACT_IStart()
{
	DataTable[REG_DBG] == 0 ? LL_IStart(false) : LL_IStart(true);
}
//-----------------------------

void DBGACT_IIGate()
{
	DataTable[REG_DBG] = (Int16U)CU_IADCIToX(MEASURE_IIGate());
}
//-----------------------------

void DBGACT_UUCutoffSet()
{
	ExDAC_IUCutoff(DataTable[REG_DBG]);
}
//-----------------------------

void DBGACT_UUNegativeSet()
{
	ExDAC_IUNegative(DataTable[REG_DBG]);
}
//-----------------------------
