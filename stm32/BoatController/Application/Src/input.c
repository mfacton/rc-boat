#include "input.h"
#include "string.h"
#include "stdint.h"

static volatile uint8_t state[GPIO_INPUTS] = {0};
static volatile uint8_t pressed[GPIO_INPUTS] = {0};

//best to run a timer at 100hz
void Input_Handler(void) {
	for (uint8_t i = 0; i < GPIO_INPUTS; i++) {
		uint8_t new = !GPIO_Read(i);
		if (new && !state[i]) {
			pressed[i] = 1;
		}
		state[i] = new;
	}
}

uint8_t Input_GetState(enum GPIO_Input in) {
	return state[in];
}

uint8_t Input_GetPressed(enum GPIO_Input in) {
	uint8_t state = pressed[in];
	pressed[in] = 0;
	return state;
}
