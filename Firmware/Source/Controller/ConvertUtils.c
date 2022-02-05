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
	float B;
	float Kamp;
}ConvertParams;

// Variables


// Functions prototypes
float CU_ADCtoX(Int16U Data, ConvertParams* Coefficients);

// Functions
//
Int16U CU_UCutoffToExtDAC(float Value)
{
	return (Int16U)(Value * (float)DataTable[REG_EXT_DAC_CUTOFF_K] / 1e6);
}
//-----------------------------

Int16U CU_UNegativeToExtDAC(float Value)
{
	return (Int16U)(Value * (float)DataTable[REG_EXT_DAC_NEGATIVE_K] / 1e6);
}
//-----------------------------

Int16U CU_UToDAC(float Value)
{
	return (Int16U)(Value * (float)DataTable[REG_DAC_U_K] / 1e6);
}
//-----------------------------

Int16U CU_IToDAC(float Value)
{
	return (Int16U)(Value * (float)DataTable[REG_DAC_I_K] / 1e6);
}
//-----------------------------

float CU_UADCUToX(Int16U Data)
{
	return (float)(Data * (float)DataTable[REG_ADC_U_SEN_K] / 1e6);
}
//-----------------------------

float CU_UADCIToX(Int16U Data)
{
	return (float)(Data * (float)DataTable[REG_ADC_I_SEN_K] / 1e6);
}
//-----------------------------

float CU_IADCIToX(Int16U Data)
{
	return (float)(Data * (float)DataTable[REG_ADC_I_GATE_K] / 1e6);
}
//-----------------------------

/*
void CU_LoadConvertParams()
{
	// Параметры преобразования значения АЦП в напряжение
	AdcToVoltageParams.K = (float)DataTable[REG_ADC_VOLTAGE_K] / 1e6;
	AdcToVoltageParams.B = (Int16S)DataTable[REG_ADC_VOLTAGE_B];

	// Параметры преобразования значения АЦП в ток и тока в ЦАП

	AdcToCurrentParams.P2 = (float)((Int16S)DataTable[REG_ADC_I_RANGE0_P2 + i * 6]) / 1e6;
	AdcToCurrentParams.P1 = (float)DataTable[REG_ADC_I_RANGE0_P1 + i * 6] / 1000;
	AdcToCurrentParams.P0 = (float)((Int16S)DataTable[REG_ADC_I_RANGE0_P0 + i * 6]) / 10;
	AdcToCurrentParams.K = (float)DataTable[REG_ADC_I_RANGE0_N + i * 6] / DataTable[REG_ADC_I_RANGE0_D + i * 6];
	AdcToCurrentParams.B = (Int16S)DataTable[REG_ADC_I_RANGE0_B + i * 6];
	AdcToCurrentParams.Kamp = (float)DataTable[REG_K_AMP_RANGE0 + i] / 100;

	CurrentToDacParams[i].K = (float)DataTable[REG_I_TO_DAC_RANGE0_K + i * 2] / 1000;
	CurrentToDacParams[i].B = (Int16S)DataTable[REG_I_TO_DAC_RANGE0_B + i * 2];
}*/
//-----------------------------

