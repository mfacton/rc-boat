#include "encoder.h"
#include "gpio.h"
#include "input.h"

static enum GPIO_Input apins[ENCODERS] = {RE1A, RE2A};
static enum GPIO_Input bpins[ENCODERS] = {RE1B, RE2B};

static volatile int32_t rotation[ENCODERS];

static volatile uint8_t astate[ENCODERS] = {0};
static volatile uint8_t bstate[ENCODERS] = {0};

void Encoder_Init(void) {
	for (int e = 0; e < ENCODERS; e++) {
		astate[e] = GPIO_Read(apins[e]);
		bstate[e] = GPIO_Read(bpins[e]);
	}
}

//best to run timer at 10khz for no skipping
void Encoder_Handler(void) {
	for (int e = 0; e < ENCODERS; e++) {
		const uint8_t anew = GPIO_Read(apins[e]);
		const uint8_t bnew = GPIO_Read(bpins[e]);

		//only one state changed
		const uint8_t achanged = anew^astate[e];
		if (achanged^(bnew^bstate[e])) {
			if (achanged) {
				if (bnew^anew) {
					rotation[e]++;
				}else{
					rotation[e]--;
				}
			}else{
				if (bnew^anew) {
					rotation[e]--;
				}else{
					rotation[e]++;
				}
			}
		}
		astate[e] = anew;
		bstate[e] = bnew;
	}
}

int32_t Encoder_GetRotation(enum Encoder encoder) {
	return rotation[encoder];
}
void Encoder_Reset(enum Encoder encoder) {
	rotation[encoder] = 0;
}
