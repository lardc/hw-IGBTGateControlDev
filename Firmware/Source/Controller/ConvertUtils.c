// Includes
//
#include "ConvertUtils.h"
#include "LowLevel.h"
#include "DataTable.h"
#include "Global.h"

// Structs
typedef struct __ConvertParams
{
	float P2;
	float P1;
	float P0;
	float K;
}ConvertParams;

// Variables
ConvertParams AdcToUUSenParams;
ConvertParams AdcToUISenParams;
ConvertParams AdcToIIGateParams;
ConvertParams UUToDACParams;
ConvertParams IIToDACParams;
ConvertParams UCutoffToExtDACParams;
ConvertParams UNegativeToExtDACParams;

// Functions
//
Int16U CU_UCutoffToExtDAC(float Value)
{
	return (Int16U)(((Value - UCutoffToExtDACParams.P0) / UCutoffToExtDACParams.P1) * UCutoffToExtDACParams.K);
}
//-----------------------------

Int16U CU_UNegativeToExtDAC(float Value)
{
	return (Int16U)(((Value - UNegativeToExtDACParams.P0) / UNegativeToExtDACParams.P1) * UNegativeToExtDACParams.K);
}
//-----------------------------

Int16U CU_UUToDAC(float Value)
{
	return (Int16U)(((Value - UUToDACParams.P0) / UUToDACParams.P1) * UUToDACParams.K);
}
//-----------------------------

Int16U CU_IIToDAC(float Value)
{
	return (Int16U)(((Value - IIToDACParams.P0) / IIToDACParams.P1) * IIToDACParams.K);
}
//-----------------------------

float CU_UADCUToX(Int16U Data)
{
	float Value = Data * AdcToUUSenParams.K;
	return (float)(Value * Value * AdcToUUSenParams.P2 + Value * AdcToUUSenParams.P1 + AdcToUUSenParams.P0);
}
//-----------------------------

float CU_UADCIToX(Int16U Data)
{
	float Value = Data * AdcToUISenParams.K;
	return (float)(Value * Value * AdcToUISenParams.P2 + Value * AdcToUISenParams.P1 + AdcToUISenParams.P0);
}
//-----------------------------

float CU_IADCIToX(Int16U Data)
{
	float Value = Data * AdcToIIGateParams.K;
	return (float)(Value * Value * AdcToIIGateParams.P2 + Value * AdcToIIGateParams.P1 + AdcToIIGateParams.P0);
}
//-----------------------------


void CU_LoadConvertParams()
{
	AdcToUUSenParams.K = (float)DataTable[REG_ADC_U_U_SEN_K];
	AdcToUUSenParams.P0 = (float)((Int16S)DataTable[REG_ADC_U_U_SEN_P0]);
	AdcToUUSenParams.P1 = (float)DataTable[REG_ADC_U_U_SEN_P1] / 1000;
	AdcToUUSenParams.P2 = (float)((Int16S)DataTable[REG_ADC_U_U_SEN_P2]) / 1e6;

	AdcToUISenParams.K = (float)DataTable[REG_ADC_U_I_SEN_K];
	AdcToUISenParams.P0 = (float)((Int16S)DataTable[REG_ADC_U_I_SEN_P0]);
	AdcToUISenParams.P1 = (float)DataTable[REG_ADC_U_I_SEN_P1] / 1000;
	AdcToUISenParams.P2 = (float)((Int16S)DataTable[REG_ADC_U_I_SEN_P2]) / 1e6;

	AdcToIIGateParams.K = (float)DataTable[REG_ADC_I_I_GATE_K];
	AdcToIIGateParams.P0 = (float)((Int16S)DataTable[REG_ADC_I_I_GATE_P0]);
	AdcToIIGateParams.P1 = (float)DataTable[REG_ADC_I_I_GATE_P1] / 1000;
	AdcToIIGateParams.P2 = (float)((Int16S)DataTable[REG_ADC_I_I_GATE_P2]) / 1e6;

	UUToDACParams.K = (float)DataTable[REG_DAC_U_U_K] / 1000;
	UUToDACParams.P1 = (float)DataTable[REG_DAC_U_U_P1] / 1000;
	UUToDACParams.P0 = (float)(Int16S)DataTable[REG_DAC_U_U_P0];

	IIToDACParams.K = (float)DataTable[REG_DAC_I_I_K] / 1000;
	IIToDACParams.P1 = (float)DataTable[REG_DAC_I_I_P1] / 1000;
	IIToDACParams.P0 = (float)(Int16S)DataTable[REG_DAC_I_I_P0];

	UCutoffToExtDACParams.K = (float)DataTable[REG_EXT_DAC_I_CUTOFF_K] / 1000;
	UCutoffToExtDACParams.P1 = (float)DataTable[REG_EXT_DAC_I_CUTOFF_P1] / 1000;
	UCutoffToExtDACParams.P0 = (float)(Int16S)DataTable[REG_EXT_DAC_I_CUTOFF_P0];

	UNegativeToExtDACParams.K = (float)DataTable[REG_EXT_DAC_I_NEGATIVE_K] / 1000;
	UNegativeToExtDACParams.P1 = (float)DataTable[REG_EXT_DAC_I_NEGATIVE_P1] / 1000;
	UNegativeToExtDACParams.P0 = (float)(Int16S)DataTable[REG_EXT_DAC_I_NEGATIVE_P0];
}
//-----------------------------

