#ifndef MEASUREMENT_H_
#define MEASUREMENT_H_

// Includes
#include "SysConfig.h"
#include "ZwBase.h"
#include "ConvertUtils.h"
#include "Regulator.h"

// Functions
Int16U MEASURE_UUSen();
Int16U MEASURE_UISen();
Int16U MEASURE_IIGate();
Boolean MEASURE_UParams(volatile RegulatorParamsStruct* Regulator);

#endif /* MEASUREMENT_H_ */
