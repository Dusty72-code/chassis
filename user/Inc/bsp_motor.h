//
// Created by Dolores on 2026/7/31.
//

#ifndef CHASSIS_BSP_MOTOR_H
#define CHASSIS_BSP_MOTOR_H

#include "main.h"
#include "tim.h"

#define MOTOR_PWM_MAX 7199U
#define MOTOR_ENCODER_PPR 11U
#define MOTOR_GEAR_RATIO 30U
#define MOTOR_ENCODER_CPR (MOTOR_ENCODER_PPR * MOTOR_GEAR_RATIO * 4U)

typedef enum {
    MOTOR_DIR_STOP = 0,
    MOTOR_DIR_CW = 1,
    MOTOR_DIR_CCW = 2,
    MOTOR_DIR_BRAKE = 3,
} MotorDir_t;

void BSP_Motor_Init(void);
void BSP_Motor_SetSpeed(uint16_t duty, MotorDir_t dir);
void BSP_Motor_Stop(void);
void BSP_Motor_Brake(void);
int32_t BSP_Motor_GetEncoderAndClear(void);
int32_t BSP_Motor_GetEncoder(void);
void BSP_Motor_Enable(void);
void BSP_Motor_Disable(void);

#endif //CHASSIS_BSP_MOTOR_H
