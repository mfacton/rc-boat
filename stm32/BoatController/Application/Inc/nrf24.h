#ifndef INC_NRF24_H_
#define INC_NRF24_H_

#include <stddef.h>
#include <stdint.h>

#include "main.h"

extern SPI_HandleTypeDef hspi1;

#define NRF24_CE_PORT RFCE_GPIO_Port
#define NRF24_CE_PIN RFCE_Pin

#define NRF24_CS_PORT RFCS_GPIO_Port
#define NRF24_CS_PIN RFCS_Pin

#define NRF24_SPI &hspi1

#define NRF24_TIMEOUT HAL_MAX_DELAY

/* nRF24L01+ Commands */
#define NRF24_CMD_R_REGISTER                  0b00000000//1-5 bytes
#define NRF24_CMD_W_REGISTER                  0b00100000//1-5 bytes

#define NRF24_CMD_R_RX_PAYLOAD                0b01100001//1-32 bytes
#define NRF24_CMD_W_TX_PAYLOAD                0b10100000//1-32 bytes
#define NRF24_CMD_FLUSH_TX                    0b11100001//0 bytes
#define NRF24_CMD_FLUSH_RX                    0b11100010//0 bytes
#define NRF24_CMD_REUSE_TX_PL                 0b11100011//0 bytes
#define NRF24_CMD_R_RX_PL_WID                 0b01100000//1 byte
#define NRF24_CMD_W_ACK_PAYLOAD               0b10101000//1-32 bytes
#define NRF24_CMD_W_TX_PAYLOAD_NOACK          0b10110000//1-32 bytes
#define NRF24_CMD_NOP                         0b11111111//0 bytes

/* nRF24L01+ Registers */
#define NRF24_REG_CONFIG            0x00
#define NRF24_REG_EN_AA             0x01
#define NRF24_REG_EN_RXADDR         0x02
#define NRF24_REG_SETUP_AW          0x03
#define NRF24_REG_SETUP_RETR        0x04
#define NRF24_REG_RF_CH             0x05
#define NRF24_REG_RF_SETUP          0x06
#define NRF24_REG_STATUS            0x07
#define NRF24_REG_OBSERVE_TX        0x08 // Read-Only
#define NRF24_REG_RPD               0x09 // Read-Only
#define NRF24_REG_RX_ADDR_P0        0x0A
#define NRF24_REG_RX_ADDR_P1        0x0B
#define NRF24_REG_RX_ADDR_P2        0x0C
#define NRF24_REG_RX_ADDR_P3        0x0D
#define NRF24_REG_RX_ADDR_P4        0x0E
#define NRF24_REG_RX_ADDR_P5        0x0F
#define NRF24_REG_TX_ADDR           0x10
#define NRF24_REG_RX_PW_P0          0x11
#define NRF24_REG_RX_PW_P1          0x12
#define NRF24_REG_RX_PW_P2          0x13
#define NRF24_REG_RX_PW_P3          0x14
#define NRF24_REG_RX_PW_P4          0x15
#define NRF24_REG_RX_PW_P5          0x16
#define NRF24_REG_FIFO_STATUS       0x17 //Read-Only
#define NRF24_REG_DYNPD             0x1C
#define NRF24_REG_FEATURE           0x1D

void NRF24_Init_RX(void);
void NRF24_Init_TX(void);

void NRF24_Transmit(uint8_t *buf, size_t len);

void NRF24_Command(uint8_t command);
void NRF24_Command_Read(uint8_t command, uint8_t *buf, size_t len);
void NRF24_Command_Write(uint8_t command, uint8_t *buf, size_t len);

void NRF24_Register_Read_Buffer(uint8_t reg, uint8_t *buf, size_t len);
uint8_t NRF24_Register_Read(uint8_t reg);
void NRF24_Register_Write_Buffer(uint8_t reg, uint8_t *buf, size_t len);
void NRF24_Register_Write(uint8_t reg, uint8_t value);

#endif
