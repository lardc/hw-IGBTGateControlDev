// Includes
#include "Measurement.h"
#include "Board.h"
#include "LowLevel.h"
#include "DataTable.h"
#include "Global.h"

// Variables


// Functions
//

Int16U MEASURE_UUSen()
{
	Int16U result = ADC_Measure(ADC3, ADC3_U_SEN_CHANNEL);
	return (result > 0) ? result : 0;
}
//-----------------------------------------------

Int16U MEASURE_UISen()
{
	Int16U result = ADC_Measure(ADC1, ADC1_I_SEN_CHANNEL);
	return (result > 0) ? result : 0;
}
//-----------------------------------------------

Int16U MEASURE_IIGate()
{
	Int16U result = ADC_Measure(ADC1, ADC1_I_GATE_CHANNEL);
	return (result > 0) ? result : 0;
}
//-----------------------------------------------

Boolean MEASURE_UParams(volatile RegulatorParamsStruct* Regulator)
{
	float U = CU_UADCUToX(MEASURE_UUSen());
	float I = CU_UADCIToX(MEASURE_UISen());
	Regulator->UMeasured = U;
	Regulator->UFormMeasured[Regulator->RegulatorPulseCounter] = U;
	Regulator->IFormMeasured[Regulator->RegulatorPulseCounter] = I;
	// проверка на достижение током порогового значения
	if ((I >= (float)DataTable[REG_U_I_TRIG]) && (Regulator->ITrigRegulatorPulse == 0))
	{
		Regulator->ITrigRegulatorPulse = Regulator->RegulatorPulseCounter;
		return true;
	}
	else return false;
}
