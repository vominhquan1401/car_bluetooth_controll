#ifndef CAR_H
#define CAR_H
#include "Motor.h"
typedef enum
{
	CAR_STOP_STATE,
	CAR_FORWARD_STATE,
	CAR_BACKWARD_STATE,
	CAR_LEFT_STATE,
	CAR_RIGHT_STATE,
}Car_State;
void car_control(Car_State state,uint8_t speed);
void car_init(TIM_HandleTypeDef *htim);
#endif
