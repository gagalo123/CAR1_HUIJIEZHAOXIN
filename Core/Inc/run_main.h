#ifndef __RUN__MAIN__H__
#define __RUN__MAIN__H__
#define GNU_TO_UART

#ifdef GNU_TO_UART
#include  <sys/unistd.h>
#include  <sys/stat.h>
#include  <errno.h>
#include<stdio.h>
#endif

/*Base part1*/
#include"tim.h"
#include"i2c.h"
#define obs_htim htim4
#define htim_pwm_l htim1
#define htim_pwm_r htim1
#define htim_encoder_l htim2
#define htim_encoder_r htim3
#define hi2c_oled hi2c1
#define TYRE_R 1
// typedef uint8_t u8;
typedef struct {
    int last_h, last_l;
    int now_h, now_l;
    double v;
}VSTRUCT;
extern VSTRUCT vl, vr;

extern int global_mode;

extern char uart1_buf[255];
extern int uart1_cnt;
extern uint8_t uart1_ch;
#define UART2_LEN 255
extern char uart2_buf[UART2_LEN];
extern int uart2_cnt, uart2_p;
extern uint8_t uart2_ch;
extern int uart1_newline;
//extern int uart1_start;


int run_main(void);
int Detection_Obstacle();












/*Base part2*/
#ifdef GNU_TO_UART
#define IO_UART1 huart1
#define IO_UART2 huart2
int _read(int file, char *data, int len);
int _write(int file, char *data, int len);
#endif
#endif
