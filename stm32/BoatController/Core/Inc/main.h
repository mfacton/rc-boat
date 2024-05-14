/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define RE2SW_Pin GPIO_PIN_14
#define RE2SW_GPIO_Port GPIOC
#define MTR_Pin GPIO_PIN_15
#define MTR_GPIO_Port GPIOC
#define JY1Y_Pin GPIO_PIN_0
#define JY1Y_GPIO_Port GPIOC
#define JY1X_Pin GPIO_PIN_1
#define JY1X_GPIO_Port GPIOC
#define JY2X_Pin GPIO_PIN_2
#define JY2X_GPIO_Port GPIOC
#define JY2Y_Pin GPIO_PIN_3
#define JY2Y_GPIO_Port GPIOC
#define BTN4_Pin GPIO_PIN_3
#define BTN4_GPIO_Port GPIOA
#define BREF_Pin GPIO_PIN_4
#define BREF_GPIO_Port GPIOC
#define SW2B_Pin GPIO_PIN_5
#define SW2B_GPIO_Port GPIOC
#define BTN3_Pin GPIO_PIN_0
#define BTN3_GPIO_Port GPIOB
#define BTNON_Pin GPIO_PIN_1
#define BTNON_GPIO_Port GPIOB
#define JY2SW_Pin GPIO_PIN_2
#define JY2SW_GPIO_Port GPIOB
#define RE2B_Pin GPIO_PIN_10
#define RE2B_GPIO_Port GPIOB
#define RFCE_Pin GPIO_PIN_12
#define RFCE_GPIO_Port GPIOB
#define RFCS_Pin GPIO_PIN_14
#define RFCS_GPIO_Port GPIOB
#define GCS_Pin GPIO_PIN_15
#define GCS_GPIO_Port GPIOB
#define SW2A_Pin GPIO_PIN_6
#define SW2A_GPIO_Port GPIOC
#define CHRG_Pin GPIO_PIN_7
#define CHRG_GPIO_Port GPIOC
#define STBY_Pin GPIO_PIN_8
#define STBY_GPIO_Port GPIOC
#define RE2A_Pin GPIO_PIN_10
#define RE2A_GPIO_Port GPIOA
#define SW1B_Pin GPIO_PIN_15
#define SW1B_GPIO_Port GPIOA
#define SW1A_Pin GPIO_PIN_10
#define SW1A_GPIO_Port GPIOC
#define RE1A_Pin GPIO_PIN_11
#define RE1A_GPIO_Port GPIOC
#define RE1B_Pin GPIO_PIN_12
#define RE1B_GPIO_Port GPIOC
#define JY1SW_Pin GPIO_PIN_2
#define JY1SW_GPIO_Port GPIOD
#define RE1SW_Pin GPIO_PIN_3
#define RE1SW_GPIO_Port GPIOB
#define BTN1_Pin GPIO_PIN_4
#define BTN1_GPIO_Port GPIOB
#define BTN2_Pin GPIO_PIN_5
#define BTN2_GPIO_Port GPIOB
#define PCS_Pin GPIO_PIN_9
#define PCS_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
