#include "gpio.h"
#include "main.h"

static GPIO_TypeDef *input_ports[GPIO_INPUTS] = {
SW1A_GPIO_Port,
SW1B_GPIO_Port,
SW2A_GPIO_Port,
SW2B_GPIO_Port,
RE1A_GPIO_Port,
RE1B_GPIO_Port,
RE2A_GPIO_Port,
RE2B_GPIO_Port,
RE1SW_GPIO_Port,
RE2SW_GPIO_Port,
BTN1_GPIO_Port,
BTN2_GPIO_Port,
BTN3_GPIO_Port,
BTN4_GPIO_Port,
JY1SW_GPIO_Port,
JY2SW_GPIO_Port,
CHRG_GPIO_Port,
STBY_GPIO_Port, };

static uint16_t input_pins[GPIO_INPUTS] = {
SW1A_Pin,
SW1B_Pin,
SW2A_Pin,
SW2B_Pin,
RE1A_Pin,
RE1B_Pin,
RE2A_Pin,
RE2B_Pin,
RE1SW_Pin,
RE2SW_Pin,
BTN1_Pin,
BTN2_Pin,
BTN3_Pin,
BTN4_Pin,
JY1SW_Pin,
JY2SW_Pin,
CHRG_Pin,
STBY_Pin, };

static GPIO_TypeDef *output_ports[GPIO_OUTPUTS] = {
BTNON_GPIO_Port,
MTR_GPIO_Port,
GCS_GPIO_Port,
PCS_GPIO_Port,
RFCS_GPIO_Port,
RFCE_GPIO_Port, };

static uint16_t output_pins[GPIO_OUTPUTS] = {
BTNON_Pin,
MTR_Pin,
GCS_Pin,
PCS_Pin,
RFCS_Pin,
RFCE_Pin, };

uint8_t GPIO_Read(enum GPIO_Input in) {
	return HAL_GPIO_ReadPin(input_ports[in], input_pins[in]);
}

void GPIO_Write(enum GPIO_Output out, uint8_t state) {
	HAL_GPIO_WritePin(output_ports[out], output_pins[out], state);
}
