#include <nrf24.h>
#include "control.h"
#include "main.h"
#include "ssd1306.h"
#include "stdio.h"
#include "input.h"
#include "gpio.h"
#include "timing.h"
#include "analog.h"
#include "encoder.h"

static uint8_t count = 0;

void Control_Init(void) {
	Analog_Start();
	Timing_Start();
	ssd1306_Init();
	NRF24_Init_TX();

	HAL_Delay(100);
}

static int32_t clamp(int32_t val) {
	if (val < 0) {
		return 0;
	}
	if (val > 180) {
		return 180;
	}
	return val;
}

static void update_screen(uint8_t *vals) {
	char buf[20];
	sprintf(buf, "%3d,%3d,%3d,%3d", vals[0], vals[1], vals[2], vals[3]);
	ssd1306_SetCursor(10, 2);
	ssd1306_WriteString(buf, Font_7x10, 1);
	ssd1306_UpdateScreen();
}

void Control_Loop(void) {
	GPIO_Write(MTR, !Input_GetState(BTN2));

	uint8_t data[4];

	int32_t scale = Input_GetState(SW1A);

	int32_t enc1 = Encoder_GetRotation(ENCODER1);
	int32_t enc2 = Encoder_GetRotation(ENCODER2);

	uint16_t jy1 = Analog_GetValue(JY2X);
	uint16_t jy2 = Analog_GetValue(JY1X);

	if (scale) {
		jy1 = (jy1-2048)/4+2048;
		jy2 = (jy2-2048)/4+2048;
	}else{
		jy1 = (jy1-2048)/2+2048;
		jy2 = (jy2-2048)/2+2048;
	}

	data[0] = jy1/23;
	data[1] = 180 - jy2/23;
	data[2] = 173 - clamp(-enc1);
	data[3] = 3 + clamp(enc2);

	if (!count) {
		update_screen(data);
	}
	count++;

	NRF24_Transmit(data, 4);
	HAL_Delay(1);
}
