#include "timing.h"
#include "stm32f4xx_hal.h"
#include "input.h"
#include "encoder.h"

extern TIM_HandleTypeDef htim10;
extern TIM_HandleTypeDef htim11;

void Timing_Start(void) {
	HAL_TIM_Base_Start_IT(&htim10);
	HAL_TIM_Base_Start_IT(&htim11);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
    if (htim == &htim10) {
    	Input_Handler();
    }
    if (htim == &htim11) {
    	Encoder_Handler();
    }
}
