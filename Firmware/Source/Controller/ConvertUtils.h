#ifndef CONVERTUTILS_H_
#define CONVERTUTILS_H_

// Includes
#include "ZwBase.h"

// Functions
Int16U CU_UCutoffToExtDAC(float Value);
Int16U CU_UNegativeToExtDAC(float Value);
Int16U CU_UToDAC(float Value);
Int16U CU_IToDAC(float Value);
float CU_UADCUToX(Int16U Data);
float CU_UADCIToX(Int16U Data);
float CU_IADCIToX(Int16U Data);

#endif /* CONVERTUTILS_H_ */
