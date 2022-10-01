/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f1xx_it.c
  * @brief   Interrupt Service Routines.
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include"../inc/run_main.h"
#include"run_main.h"
#include"motor.h"
#include"../inc/protool.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern I2C_HandleTypeDef hi2c1;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M3 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
  while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F1xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f1xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles TIM1 update interrupt.
  */
void TIM1_UP_IRQHandler(void)
{
  /* USER CODE BEGIN TIM1_UP_IRQn 0 */

  /* USER CODE END TIM1_UP_IRQn 0 */
  HAL_TIM_IRQHandler(&htim1);
  /* USER CODE BEGIN TIM1_UP_IRQn 1 */

  /* USER CODE END TIM1_UP_IRQn 1 */
}

/**
  * @brief This function handles TIM2 global interrupt.
  */
void TIM2_IRQHandler(void)
{
  /* USER CODE BEGIN TIM2_IRQn 0 */

  /* USER CODE END TIM2_IRQn 0 */
  HAL_TIM_IRQHandler(&htim2);
  /* USER CODE BEGIN TIM2_IRQn 1 */

  /* USER CODE END TIM2_IRQn 1 */
}

/**
  * @brief This function handles TIM3 global interrupt.
  */
void TIM3_IRQHandler(void)
{
  /* USER CODE BEGIN TIM3_IRQn 0 */

  /* USER CODE END TIM3_IRQn 0 */
  HAL_TIM_IRQHandler(&htim3);
  /* USER CODE BEGIN TIM3_IRQn 1 */

  /* USER CODE END TIM3_IRQn 1 */
}

/**
  * @brief This function handles I2C1 event interrupt.
  */
void I2C1_EV_IRQHandler(void)
{
  /* USER CODE BEGIN I2C1_EV_IRQn 0 */

  /* USER CODE END I2C1_EV_IRQn 0 */
  HAL_I2C_EV_IRQHandler(&hi2c1);
  /* USER CODE BEGIN I2C1_EV_IRQn 1 */

  /* USER CODE END I2C1_EV_IRQn 1 */
}

/**
  * @brief This function handles USART1 global interrupt.
  */
void USART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART1_IRQn 0 */

  /* USER CODE END USART1_IRQn 0 */
  HAL_UART_IRQHandler(&huart1);
  /* USER CODE BEGIN USART1_IRQn 1 */

  /* USER CODE END USART1_IRQn 1 */
}

/**
  * @brief This function handles USART2 global interrupt.
  */
void USART2_IRQHandler(void)
{
  /* USER CODE BEGIN USART2_IRQn 0 */

  /* USER CODE END USART2_IRQn 0 */
  HAL_UART_IRQHandler(&huart2);
  /* USER CODE BEGIN USART2_IRQn 1 */

  /* USER CODE END USART2_IRQn 1 */
}

/* USER CODE BEGIN 1 */


extern VSTRUCT vl, vr;
extern PIDSTRUCT pidl, pidr;
extern int motor_mode;
__weak void HAL_IncTick(void)
{
	//printf("good\n");
  uwTick += uwTickFreq;
  if(motor_mode == MOTOR_ON && uwTick % 1000 == 0) { //1s测一�????
	  printf("good \n");
	  vl.now_l =__HAL_TIM_GET_COUNTER(&htim_encoder_l);
	  vr.now_l = __HAL_TIM_GET_COUNTER(&htim_encoder_r);
	  //printf("l=%d,%d\n", vl.now_l, vr.now_l);
//	  vl.v = ((vl.now_h - vl.last_h) * 65536 + vl.now_l - vl.last_l);
	  vl.v = ((vl.now_h - vl.last_h) * 65536 + vl.now_l - vl.last_l) / 90.0 / 13 / 4 * TYRE_R;
	  vr.v = ((vr.now_h - vr.last_h) * 65536 + vr.now_l - vr.last_l) / 90.0 / 13 / 4 * TYRE_R;
//	  vr.v = ((vr.now_h - vr.last_h) * 65536 + vr.now_l - vr.last_l);
	  vl.last_l = vl.now_l;
	  vl.last_h = vl.now_h;

	  vr.last_l = vr.now_l;
	  vr.last_h = vr.now_h;

	  PWML = motor_incremental_pi(&pidl, vl.v);
	  PWMR = motor_incremental_pi(&pidr, vr.v);

  }



}



void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
  //printf("get vl\n");
//
  //printf("good\n");
  if(htim == &htim_encoder_l) {
      vl.now_h++;
      //printf("get vl\n");
  } else if(htim == &htim_encoder_r) {
	  vr.now_h++;
	  //printf("get vr\n");
  }
}


//extern char uart1_buf[255];
//extern int uart1_cnt;
//extern uint8_t uart1_ch;
//
//extern char uart2_buf[255];
//extern int uart2_cnt;
//extern uint8_t uart2_ch;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
  if(huart->Instance == USART1) { //???
      if(uart1_cnt == 255) uart1_cnt = 0;
      if(uart1_ch == '$') {
    	  protool_len = 0;
    	  protool_start = 1;
      }
//      uart1_buf[uart1_cnt++] = uart1_ch;
      if(protool_start == 1) {
    	 protool_s[protool_len++] = uart1_ch;
      }else  {
    	  uart1_buf[uart1_cnt++] = (char)uart1_ch;
      }
      if(protool_start == 1 && uart1_ch == '#') {
    	  protool_s[protool_len] = '\0';
    	  protool_newline = 1;
    	  protool_start = 0;
      }
      if(uart1_cnt > 0 && uart1_buf[uart1_cnt - 1] == 0x0A && uart1_buf[uart1_cnt - 2] == 0x0D){
//        uart1_cnt = 0;
    	  uart1_newline = 1;
      }
      HAL_UART_Receive_IT(&IO_UART1, &uart1_ch, 1);
  }  
  
  if(huart->Instance == USART2) { // ???
    uart2_cnt += 1;
    if(uart2_cnt >= UART2_LEN) uart1_cnt -= UART2_LEN;
      uart2_buf[uart1_cnt++] = (char)uart1_ch;
      if(uart2_cnt > 0 && uart1_buf[uart1_cnt - 1] == 0x0A && uart1_buf[uart1_cnt - 2] == 0x0D){
        uart2_p = uart2_cnt = 0;
      }
      HAL_UART_Receive_IT(&IO_UART2, &uart2_ch, 1);
  }

}
// int obs_capture_cnt;
// int obs_capture_vl, obs_capture_vr;
// void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim){
//     if(TIM3 == htim->Instance){
//       if(HAL_TIM_ACTIVE_CHANNEL_2 == htim->Channel){ //TIM3 CH2   ??�获超声�???????????
//           switch(obs_capture_cnt){
//             case 1:
//                   obs_capture_vl = __HAL_TIM_GET_COMPARE(htim, HAL_TIM_ACTIVE_CHANNEL_2);
//                   __HAL_TIM_SET_CAPTUREPOLARITY(htim, htim->Channel, TIM_INPUTCHANNELPOLARITY_FALLING);
//                   ++obs_capture_cnt;
//                   break;
//             case 2:
//                   obs_capture_vr = __HAL_TIM_GET_COMPARE(htim, htim->Channel);
//                   __HAL_TIM_SET_CAPTUREPOLARITY(htim, htim->Channel, TIM_INPUTCHANNELPOLARITY_RISING);
//                   ++obs_capture_cnt;
//                   break;
//             case 3:
//                   HAL_TIM_IC_Stop_IT(htim, htim->Channel);
//                   obs_capture_cnt++;
//                   break;
//             default:
//                   break;
//           }
//       }
//     }
// }
/* USER CODE END 1 */
