#ifndef __SYSCONFIG_H
#define __SYSCONFIG_H


// Flash loader options
#define BOOT_LOADER_VARIABLE			(*((volatile uint32_t *)0x20000000))
#define BOOT_LOADER_REQUEST				0x12345678
#define BOOT_LOADER_MAIN_PR_ADDR		0x08008000
//-----------------------------------------------

// System clock
#define SYSCLK							70000000	// Тактовая частота системной шины процессора
#define QUARTZ_FREQUENCY				20000000	// Частота кварца
// ----------------------------------------------

// USART
#define USART_BAUDRATE					115200		// Скорость USART
#define USART_FIFOlen					32			// Длина FIFO USART
// ----------------------------------------------

// Timers
#define TIMER15_uS						50			// в мкс
#define TIMER7_uS						1000		// в мкс
#define TIMER6_uS						10			// в мкс
// ----------------------------------------------

// CAN
#define CAN_BAUDRATE					1000000		// Битрейт CAN
// ----------------------------------------------

// ADC
#define DMA_ADC_CURRENT_CHANNEL			DMA2_Channel5	// Канал DMA для АЦП тока
#define DMA_ADC_V_BAT_CHANNEL			DMA1_Channel1	// Канал DMA для АЦП напряжения батареи
#define ADC1_I_SEN_CHANNEL				1				// АЦП1 номер канала тока (источник V)
#define ADC1_I_GATE_CHANNEL				4				// АЦП1 номер канала тока (источник I)
#define ADC3_U_SEN_CHANNEL				1				// АЦП3 номер канала напряжения (источник V)
// ----------------------------------------------

// SPI
#define SPI1_BAUDRATE_BITS				0x1				// Биты задания битрейта SPI
#define SPI1_LSB_FIRST					false			// Передача младшим битов вперед
// ----------------------------------------------

#endif // __SYSCONFIG_H
