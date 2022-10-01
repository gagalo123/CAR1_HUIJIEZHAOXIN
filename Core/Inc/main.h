/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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
#define ENCODER_LA_Pin GPIO_PIN_0
#define ENCODER_LA_GPIO_Port GPIOA
#define ENCODER_LB_Pin GPIO_PIN_1
#define ENCODER_LB_GPIO_Port GPIOA
#define BLE_USART2_TX_Pin GPIO_PIN_2
#define BLE_USART2_TX_GPIO_Port GPIOA
#define BLE_USART2_RX_Pin GPIO_PIN_3
#define BLE_USART2_RX_GPIO_Port GPIOA
#define MPU_SCL_Pin GPIO_PIN_10
#define MPU_SCL_GPIO_Port GPIOB
#define MPU_SDA_Pin GPIO_PIN_11
#define MPU_SDA_GPIO_Port GPIOB
#define INFRA2_Pin GPIO_PIN_12
#define INFRA2_GPIO_Port GPIOB
#define INFRA1_Pin GPIO_PIN_13
#define INFRA1_GPIO_Port GPIOB
#define OBS_ECHO_Pin GPIO_PIN_14
#define OBS_ECHO_GPIO_Port GPIOB
#define OBS_TRIG_Pin GPIO_PIN_15
#define OBS_TRIG_GPIO_Port GPIOB
#define pwm_l_Pin GPIO_PIN_8
#define pwm_l_GPIO_Port GPIOA
#define DEBUG_USART1_TX_Pin GPIO_PIN_9
#define DEBUG_USART1_TX_GPIO_Port GPIOA
#define DEBUG_USART1_RX_Pin GPIO_PIN_10
#define DEBUG_USART1_RX_GPIO_Port GPIOA
#define pwm_r_Pin GPIO_PIN_11
#define pwm_r_GPIO_Port GPIOA
#define BLA_Pin GPIO_PIN_15
#define BLA_GPIO_Port GPIOA
#define BRA_Pin GPIO_PIN_3
#define BRA_GPIO_Port GPIOB
#define ENCODER_RA_Pin GPIO_PIN_4
#define ENCODER_RA_GPIO_Port GPIOB
#define ENCODER_BRB_Pin GPIO_PIN_5
#define ENCODER_BRB_GPIO_Port GPIOB
#define OLED_Pin GPIO_PIN_6
#define OLED_GPIO_Port GPIOB
#define OLEDB7_Pin GPIO_PIN_7
#define OLEDB7_GPIO_Port GPIOB
#define BRB_Pin GPIO_PIN_8
#define BRB_GPIO_Port GPIOB
#define BLB_Pin GPIO_PIN_9
#define BLB_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
