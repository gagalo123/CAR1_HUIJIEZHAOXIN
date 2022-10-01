#ifndef __MOTOR__H__
#define __MOTOR__H__
#include<stdint.h>
typedef int32_t PID_V;

#define MOTOR_ON 1
#define MOTOR_OFF 0
#define MOTOR_FORWARD 2
#define MOTOR_BACKWARD 3
#define PWML TIM1->CCR1
#define PWMR TIM1->CCR4
//extern VSTRUCT vl, vr;
typedef struct {
    double target_val;
    int pwm;
    double err;
    double err_last;
    double kp,ki, kd;
    double inter;
}PIDSTRUCT;
//void PID_DeInit();
//void PID_Init(PID_V val_l, PID_V val_r );
//PID_V PID_readlize_l(PID_V val);
//void PID_set_pwm_l(PID_V val);
//PID_V PID_readlize_r(PID_V val);
//void PID_set_pwm_r(PID_V val);
//void PID_set_target_l(PID_V val);
//void PID_set_target_r(PID_V val);

void motor_init(double val_l, double val_r);
void motor_power_off(void);

void motor_turn_right(void);
void motor_turn_left(void);
void motor_turn_forward(void);
void motor_turn_backward(void);
void motor_turn_pause(void);
void motor_turn_resume(void);
void motor_turn_tleft(void);
void motor_turn_tright(void);

int motor_incremental_pi(PIDSTRUCT *pid, double now_v);
void motor_set_speed(double v, int id); //rmp  id=0 L   id=1 R


typedef enum {

  enSTOP,
  enRESUME,
  enFORWARD,
  enBACK,
  enLEFT,
  enRIGHT,
  enTLEFT,
  enTRIGHT

}enCarState;
extern enCarState car_state;

#endif
