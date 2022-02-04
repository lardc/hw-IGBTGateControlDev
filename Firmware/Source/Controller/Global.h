﻿#ifndef __GLOBAL_H
#define __GLOBAL_H

#include "SysConfig.h"

// Definitions
// 
#define	SCCI_TIMEOUT_TICKS						1000	// Таймаут интерфейса SCCI (в мс)
#define EP_WRITE_COUNT							0		// Количество массивов для записи

#define EP_COUNT								3		// Количество массивов для чтения
#define ENABLE_LOCKING							FALSE	// Защита NV регистров паролем
#define CURRENT_PULSE_WIDTH						300		// Макс длительность импульса тока (мкс)
#define VOLTAGE_PULSE_WIDTH						20000	// Макс длительность импульса напряжения (мкс)

#define PI										3.1416f	// Значение числа Пи
#define DAC_MAX_VAL								0x0FFF	// Максимальное значение ЦАП

// Размер массивов EP
#define VALUES_x_SIZE	((CURRENT_PULSE_WIDTH + CURRENT_PULSE_TAIL) / TIMER15_uS)

// Временные параметры
#define TIME_LED_BLINK							500		// Мигание светодиодом (в мс)

#endif //  __GLOBAL_H
