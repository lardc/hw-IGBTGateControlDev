﻿#ifndef __CONSTRAINTS_H
#define __CONSTRAINTS_H

// Include
#include "stdinc.h"
#include "DataTable.h"
#include "Global.h"

//Definitions
#define NO		0
#define YES		1
//

#define DAC_OUTPUT_LIM_MIN			0
#define DAC_OUTPUT_LIM_MAX			4095
#define DAC_OUTPUT_LIM_DEF			4095
//
#define DAC_OFFSET_MIN				0
#define DAC_OFFSET_MAX				4095
#define DAC_OFFSET_DEF				0
//
#define COEF_P0_MIN					INT16S_MIN
#define COEF_P0_MAX					INT16S_MAX
#define COEF_P0_DEF					0
//
#define COEF_P1_MIN					1
#define COEF_P1_MAX					INT16U_MAX
#define COEF_P1_DEF					1000
//
#define COEF_P2_MIN					INT16S_MIN
#define COEF_P2_MAX					INT16S_MAX
#define COEF_P2_DEF					0
//
#define COEF_K_MIN					1
#define COEF_K_MAX					INT16U_MAX
#define COEF_I_I_GATE_K_DEF			122			// [мА*1000 / код]
#define COEF_U_I_SEN_K_DEF			141			// [мА*1000 / код]
#define COEF_U_U_SEN_K_DEF			7324		// [мВ*1000 / код]
#define COEF_I_I_K_DEF				6827		// [код*1000 / мА]
#define COEF_U_U_K_DEF				204			// [код*1000 / мВ]
#define COEF_I_CUTOFF_K_DEF			162			// [код*1000 / мВ]
#define COEF_I_NEGATIVE_K_DEF		201			// [код*1000 / мВ]
//
#define OFFSET_MIN					0
#define OFFSET_MAX					INT16U_MAX
#define OFFSET_DEF					0
//
#define REGULATOR_KP_MIN			0
#define REGULATOR_KP_MAX			INT16U_MAX
#define REGULATOR_KP_DEF			1000
//
#define REGULATOR_KI_MIN			0
#define REGULATOR_KI_MAX			INT16U_MAX
#define REGULATOR_KI_DEF			0
//

#define CURRENT_TRIG_MIN			1			// [мА]
#define CURRENT_TRIG_MAX			500			// [мА]
//
#define T_UCONSTANT_MIN				1			// [мс]
#define T_UCONSTANT_MAX				20			// [мс]
//
#define T_UFRONT_MIN				1			// [мс]
#define T_UFRONT_MAX				20			// [мс]
//
#define U_DEST_MIN					100			// [мВ]
#define U_DEST_MAX					20000		// [мВ]
//
#define I_U_CUTOFF_MIN				0			// [мВ]
#define I_U_CUTOFF_MAX				20000		// [мВ]
#define I_U_CUTOFF_DEF				15000		// [мВ]
//
#define I_U_NEGATIVE_MIN			0			// [мВ]
#define I_U_NEGATIVE_MAX			20000		// [мВ]
#define I_U_NEGATIVE_DEF			8000		// [мВ]
//
#define I_I_SET_MIN					20			// [мА]
#define I_I_SET_MAX					500			// [мА]
//
#define I_T_CURRENT_MIN				20			// [мс]
#define I_T_CURRENT_MAX				500			// [мс]

// Types
typedef struct __TableItemConstraint
{
	Int16U Min;
	Int16U Max;
	Int16U Default;
} TableItemConstraint;

// Variables
extern const TableItemConstraint NVConstraint[DATA_TABLE_NV_SIZE];
extern const TableItemConstraint VConstraint[DATA_TABLE_WP_START - DATA_TABLE_WR_START];

#endif // __CONSTRAINTS_H
