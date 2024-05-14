#include "analog.h"
#include "stm32f4xx_hal.h"
#include "string.h"

extern ADC_HandleTypeDef hadc1;

static volatile uint16_t values[ANALOG_CHANNELS];

static void begin_conversion(void) {
	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)values, ANALOG_CHANNELS);
}

void Analog_Start(void)
{
	begin_conversion();
}

uint16_t Analog_GetValue(enum AnalogChannel chan) {
	return values[chan];
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc) {
	begin_conversion();
}
