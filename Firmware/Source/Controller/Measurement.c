// Includes
#include "Measurement.h"
#include "Board.h"
#include "LowLevel.h"
#include "DataTable.h"
#include "Global.h"

// Variables


// Functions
//

float MEASURE_UUSen()
{
	float result = ((float)ADC_Measure(ADC3, ADC3_U_SEN_CHANNEL));
	return (result > 0) ? result : 0;
}
//-----------------------------------------------

float MEASURE_UISen()
{
	float result = ((float)ADC_Measure(ADC1, ADC1_I_SEN_CHANNEL));
	return (result > 0) ? result : 0;
}
//-----------------------------------------------

float MEASURE_IIGate()
{
	float result = ((float)ADC_Measure(ADC1, ADC1_I_GATE_CHANNEL));
	return (result > 0) ? result : 0;
}
//-----------------------------------------------
