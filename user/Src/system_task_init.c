//
// Created by Dolores on 2026/7/31.
//
#include "system_task_init.h"
#include "can_app.h"
#include "bsp_can.h"
#include "LED.h"
#include "motor_control.h"

void System_Periph_Init(void)
{
    BSP_CAN_FilterInit();
    CAN_App_Init();
    LED_Status_Init();
    MotorControl_Init();
}