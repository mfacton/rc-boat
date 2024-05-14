#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "stdint.h"

#define GPIO_INPUTS 18
#define GPIO_OUTPUTS 6

enum GPIO_Input {
	SW1A,
	SW1B,
	SW2A,
	SW2B,
	RE1A,
	RE1B,
	RE2A,
	RE2B,
	RE1SW,
	RE2SW,
	BTN1,
	BTN2,
	BTN3,
	BTN4,
	JY1SW,
	JY2SW,
	CHRG,
	STDBY,
};

enum GPIO_Output {
	BON, MTR, GCS, PCS, RFCS, RFCE,
};

uint8_t GPIO_Read(enum GPIO_Input in);
void GPIO_Write(enum GPIO_Output out, uint8_t state);

#endif
