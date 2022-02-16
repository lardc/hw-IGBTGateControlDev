#ifndef CONVERTUTILS_H_
#define CONVERTUTILS_H_

// Includes
#include "ZwBase.h"

// Functions
Int16U CU_UCutoffToExtDAC(float Value);
Int16U CU_UNegativeToExtDAC(float Value);
Int16U CU_UUToDAC(float Value);
Int16U CU_IIToDAC(float Value);
float CU_UADCUToX(Int16U Data);
float CU_UADCIToX(Int16U Data);
float CU_IADCIToX(Int16U Data);
void CU_LoadConvertParams();

#endif /* CONVERTUTILS_H_ */
