#ifndef PWM_H
#define PWM_H
#include "main.h"

void pwm_set_duty(TIM_HandleTypeDef *tim,uint16_t chanel,uint8_t duty);

#endif
