#include "car.h"
Motor_Typedef motor_front_left;
Motor_Typedef motor_front_right;
Motor_Typedef motor_back_left;
Motor_Typedef motor_back_right;

void car_control(Car_State state,uint8_t speed){
	switch(state){
		case CAR_STOP_STATE:
			motor_control(&motor_front_left,MOTOR_STOP,100);
			motor_control(&motor_front_right,MOTOR_STOP,100);
			motor_control(&motor_back_left,MOTOR_STOP,100);
			motor_control(&motor_back_right,MOTOR_STOP,100);
			break;
		case CAR_FORWARD_STATE:
			motor_control(&motor_front_left,MOTOR_CW,speed);
			motor_control(&motor_front_right,MOTOR_CCW,100-speed);
			motor_control(&motor_back_left,MOTOR_CW,speed);
			motor_control(&motor_back_right,MOTOR_CCW,100-speed);
			break;
		case CAR_BACKWARD_STATE:
			motor_control(&motor_front_left,MOTOR_CCW,100-speed);
			motor_control(&motor_front_right,MOTOR_CW,speed);
			motor_control(&motor_back_left,MOTOR_CCW,100-speed);
			motor_control(&motor_back_right,MOTOR_CW,speed);
			break;
		case CAR_LEFT_STATE:
			motor_control(&motor_front_left,MOTOR_STOP,100);
			motor_control(&motor_front_right,MOTOR_CCW,100-speed);
			motor_control(&motor_back_left,MOTOR_STOP,100);
			motor_control(&motor_back_right,MOTOR_CCW,100-speed);
			break;
		case CAR_RIGHT_STATE:
			motor_control(&motor_front_left,MOTOR_CW,speed);
			motor_control(&motor_front_right,MOTOR_STOP,100);
			motor_control(&motor_back_left,MOTOR_CW,speed);
			motor_control(&motor_back_right,MOTOR_STOP,100);
			break;
	}
}

void car_init(TIM_HandleTypeDef *htim){
	motor_init(&motor_front_left,GPIOB,GPIO_PIN_12,htim,TIM_CHANNEL_1);
	motor_init(&motor_front_right,GPIOB,GPIO_PIN_13,htim,TIM_CHANNEL_2);
	motor_init(&motor_back_left,GPIOB,GPIO_PIN_14,htim,TIM_CHANNEL_3);
	motor_init(&motor_back_right,GPIOB,GPIO_PIN_15,htim,TIM_CHANNEL_4);
	car_control(CAR_STOP_STATE,0);
}
