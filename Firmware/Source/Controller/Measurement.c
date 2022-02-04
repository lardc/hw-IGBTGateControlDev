// Includes
#include "Measurement.h"
#include "Board.h"
#include "LowLevel.h"
#include "DataTable.h"
#include "Global.h"

// Variables
//
Int16U MEASURE_ADC_CurrentRaw[ADC_DMA_BUFF_SIZE];
Int16U MEASURE_ADC_BatteryVoltageRaw[ADC_DMA_BUFF_SIZE];

// Functions prototypes
Int16U MEASURE_DMAExtractX(Int16U* InputArray, Int16U ArraySize);
Int16U MEASURE_DMAExtractCurrent();
Int16U MEASURE_DMAExtractVolatge();
void MEASURE_StartNewSampling();

// Functions
//

float MEASURE_UUSen()
{
	float result = ((float)ADC_Measure(ADC3, 1));
	return (result > 0) ? result : 0;
}
//-----------------------------------------------

float MEASURE_UISen()
{
	float result = ((float)ADC_Measure(ADC1, 1));
	return (result > 0) ? result : 0;
}
//-----------------------------------------------

float MEASURE_IIGate()
{
	float result = ((float)ADC_Measure(ADC1, 4));
	return (result > 0) ? result : 0;
}
//-----------------------------------------------
