/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for CAN_Send */
osThreadId_t CAN_SendHandle;
const osThreadAttr_t CAN_Send_attributes = {
  .name = "CAN_Send",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for CAN_Recv */
osThreadId_t CAN_RecvHandle;
const osThreadAttr_t CAN_Recv_attributes = {
  .name = "CAN_Recv",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for CAN_HB */
osThreadId_t CAN_HBHandle;
const osThreadAttr_t CAN_HB_attributes = {
  .name = "CAN_HB",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for Motor */
osThreadId_t MotorHandle;
const osThreadAttr_t Motor_attributes = {
  .name = "Motor",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for OLED */
osThreadId_t OLEDHandle;
const osThreadAttr_t OLED_attributes = {
  .name = "OLED",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for LED */
osThreadId_t LEDHandle;
const osThreadAttr_t LED_attributes = {
  .name = "LED",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartCAN_SendTask(void *argument);
void StartCAN_RecvTask(void *argument);
void StartCAN_HBTask(void *argument);
void StartMotorTask(void *argument);
void StartOLEDTask(void *argument);
void StartLEDTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of CAN_Send */
  CAN_SendHandle = osThreadNew(StartCAN_SendTask, NULL, &CAN_Send_attributes);

  /* creation of CAN_Recv */
  CAN_RecvHandle = osThreadNew(StartCAN_RecvTask, NULL, &CAN_Recv_attributes);

  /* creation of CAN_HB */
  CAN_HBHandle = osThreadNew(StartCAN_HBTask, NULL, &CAN_HB_attributes);

  /* creation of Motor */
  MotorHandle = osThreadNew(StartMotorTask, NULL, &Motor_attributes);

  /* creation of OLED */
  OLEDHandle = osThreadNew(StartOLEDTask, NULL, &OLED_attributes);

  /* creation of LED */
  LEDHandle = osThreadNew(StartLEDTask, NULL, &LED_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartCAN_SendTask */
/**
  * @brief  Function implementing the CAN_Send thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartCAN_SendTask */
void StartCAN_SendTask(void *argument)
{
  /* USER CODE BEGIN StartCAN_SendTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartCAN_SendTask */
}

/* USER CODE BEGIN Header_StartCAN_RecvTask */
/**
* @brief Function implementing the CAN_Recv thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartCAN_RecvTask */
void StartCAN_RecvTask(void *argument)
{
  /* USER CODE BEGIN StartCAN_RecvTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartCAN_RecvTask */
}

/* USER CODE BEGIN Header_StartCAN_HBTask */
/**
* @brief Function implementing the CAN_HB thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartCAN_HBTask */
void StartCAN_HBTask(void *argument)
{
  /* USER CODE BEGIN StartCAN_HBTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartCAN_HBTask */
}

/* USER CODE BEGIN Header_StartMotorTask */
/**
* @brief Function implementing the Motor thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartMotorTask */
void StartMotorTask(void *argument)
{
  /* USER CODE BEGIN StartMotorTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartMotorTask */
}

/* USER CODE BEGIN Header_StartOLEDTask */
/**
* @brief Function implementing the OLED thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartOLEDTask */
void StartOLEDTask(void *argument)
{
  /* USER CODE BEGIN StartOLEDTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartOLEDTask */
}

/* USER CODE BEGIN Header_StartLEDTask */
/**
* @brief Function implementing the LED thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartLEDTask */
void StartLEDTask(void *argument)
{
  /* USER CODE BEGIN StartLEDTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartLEDTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

