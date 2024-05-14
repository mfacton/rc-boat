#ifndef INC_ENCODER_H_
#define INC_ENCODER_H_

#include <stdint.h>

#define ENCODERS 2

enum Encoder {
	ENCODER1,
	ENCODER2,
};

void Encoder_Handler(void);

void Encoder_Init(void);

int32_t Encoder_GetRotation(enum Encoder encoder);
void Encoder_Reset(enum Encoder encoder);

#endif
