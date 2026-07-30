//
// Created by Dolores on 2026/7/31.
//

#ifndef CHASSIS_MOTOR_CONTROL_H
#define CHASSIS_MOTOR_CONTROL_H

#include "bsp_motor.h"
#include "pid.h"

#define MOTOR_CTRL_PERIOD_MS 10U
#define MOTOR_CTRL_DT (MOTOR_CTRL_PERIOD_MS / 1000.0f)
#define MOTOR_KP_DEFAULT 2.5f
#define MOTOR_KI_DEFAULT 0.3f
#define MOTOR_KD_DEFAULT 0.0f
#define MOTOR_OUTPUT_MIN (-(float)MOTOR_PWM_MAX)
#define MOTOR_OUTPUT_MAX ((float)MOTOR_PWM_MAX)
#define MOTOR_ZERO_SPEED_THRESHOLD 2.0f

typedef struct {
    PID_t speed_pid;
    float target_rpm;
    uint8_t target_updated;
    float actual_rpm;
    int32_t raw_encoder;
    uint8_t motor_online;
    float pid_output;
    uint8_t motor_error;
} MotorCtrl_t;

extern MotorCtrl_t g_motor;

void MotorControl_Init(void);
void MotorControl_SetTarget(float rpm);
float MotorControl_GetActualSpeed(void);
uint8_t MotorControl_IsOnline(void);
uint8_t MotorControl_IsError(void);

#endif //CHASSIS_MOTOR_CONTROL_H
