#ifndef INC_INPUT_H_
#define INC_INPUT_H_

#include "stdint.h"
#include "gpio.h"

void Input_Handler(void);

uint8_t Input_GetState(enum GPIO_Input in);

uint8_t Input_GetPressed(enum GPIO_Input in);

#endif
