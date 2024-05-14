#ifndef INC_ANALOG_H_
#define INC_ANALOG_H_

#include <stdint.h>

#define ANALOG_CHANNELS 5

enum AnalogChannel {
	JY1Y,
	JY1X,
	JY2X,
	JY2Y,
	BREF,
};

void Analog_Start(void);

uint16_t Analog_GetValue(enum AnalogChannel chan);

#endif
