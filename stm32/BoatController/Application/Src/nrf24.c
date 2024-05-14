#include <nrf24.h>

static uint8_t status = 0;

static void set_cs(uint8_t state) {
	HAL_GPIO_WritePin(NRF24_CS_PORT, NRF24_CS_PIN, state);
}

static void set_ce(uint8_t state) {
	HAL_GPIO_WritePin(NRF24_CE_PORT, NRF24_CE_PIN, state);
}

void NRF24_Command(uint8_t command) {
	set_cs(0);
	HAL_SPI_TransmitReceive(NRF24_SPI, &command, &status, 1, NRF24_TIMEOUT);
	set_cs(1);
}
void NRF24_Command_Read(uint8_t command, uint8_t *buf, size_t len) {
	set_cs(0);
	HAL_SPI_TransmitReceive(NRF24_SPI, &command, &status, 1, NRF24_TIMEOUT);
	HAL_SPI_Receive(NRF24_SPI, buf, len, NRF24_TIMEOUT);
	set_cs(1);
}
void NRF24_Command_Write(uint8_t command, uint8_t *buf, size_t len) {
	set_cs(0);
	HAL_SPI_TransmitReceive(NRF24_SPI, &command, &status, 1, NRF24_TIMEOUT);
	HAL_SPI_Transmit(NRF24_SPI, buf, len, NRF24_TIMEOUT);
	set_cs(1);
}

void NRF24_Register_Read_Buffer(uint8_t reg, uint8_t *buf, size_t len) {
	NRF24_Command_Read(NRF24_CMD_R_REGISTER | reg, buf, len);
}

uint8_t NRF24_Register_Read(uint8_t reg) {
	uint8_t value;
	NRF24_Command_Read(NRF24_CMD_R_REGISTER | reg, &value, 1);
	return value;
}

void NRF24_Register_Write_Buffer(uint8_t reg, uint8_t *buf, size_t len) {
	NRF24_Command_Write(NRF24_CMD_W_REGISTER | reg, buf, len);
}

void NRF24_Register_Write(uint8_t reg, uint8_t value) {
	NRF24_Command_Write(NRF24_CMD_W_REGISTER | reg, &value, 1);
}

void NRF24_Init_TX(void) {
	//crc enabled and set to 2 bytes
	//disable retransmits
	//set freq 2476

	//data rate 250kbps
	//set max power

	NRF24_Register_Write(NRF24_REG_CONFIG, 0b01111100);
	NRF24_Register_Write(NRF24_REG_EN_AA, 0b00000000);
	NRF24_Register_Write(NRF24_REG_EN_RXADDR, 0b00000000);
	NRF24_Register_Write(NRF24_REG_SETUP_RETR , 0b00000000);
	NRF24_Register_Write(NRF24_REG_RF_CH , 0x7F & (2524 - 2400));
	NRF24_Register_Write(NRF24_REG_RF_SETUP , 0b00100110);
	uint8_t address[5] = "00001";
	NRF24_Register_Write_Buffer(NRF24_REG_TX_ADDR, address, 5);

	NRF24_Register_Write(NRF24_REG_CONFIG, 0b01111110);
	NRF24_Command(NRF24_CMD_FLUSH_TX);
	NRF24_Command(NRF24_CMD_FLUSH_RX);
	set_ce(1);
}

void NRF24_Transmit(uint8_t *buf, size_t len) {
	NRF24_Command_Write(NRF24_CMD_W_TX_PAYLOAD, buf, len);
}
