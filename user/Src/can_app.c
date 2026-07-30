//
// Created by Dolores on 2026/7/31.
//
#include "can_app.h"
#include "cmsis_os.h"
#include <string.h>

CAN_AppState_t g_can_state;

void CAN_App_Init(void)
{
    memset(&g_can_state, 0, sizeof(g_can_state));
    g_can_state.can_comm_ok = 0U;
    uint32_t now = HAL_GetTick();
    g_can_state.last_gimbal_rx_time = now;
    g_can_state.chassis_feedback.status_flags = STATUS_SYSTEM_OK;
}

void CAN_App_SetChassisFeedback(int16_t actual_speed, int16_t encoder_raw)
{
    taskENTER_CRITICAL();
    g_can_state.chassis_feedback.motor_actual_speed = actual_speed;
    g_can_state.chassis_feedback.motor_encoder_raw  = encoder_raw;
    g_can_state.chassis_feedback.motor_online = 1U;
    taskEXIT_CRITICAL();
}

GimbalCtrlMsg_t CAN_App_GetGimbalCtrl(void)
{
    GimbalCtrlMsg_t ctrl;
    taskENTER_CRITICAL();
    ctrl = g_can_state.gimbal_ctrl_rx;
    g_can_state.gimbal_ctrl_updated = 0U;
    taskEXIT_CRITICAL();
    return ctrl;
}

uint8_t CAN_App_IsGimbalCtrlUpdated(void)
{
    return g_can_state.gimbal_ctrl_updated;
}

uint8_t CAN_App_IsCommOK(void)
{
    return g_can_state.can_comm_ok;
}
