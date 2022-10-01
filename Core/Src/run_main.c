#include"../inc/run_main.h"
/*Base Part1*/


//#include"stm32f1xx_hal.h"
#include"gpio.h"
#include"tim.h"
#include"usart.h"
#include"motor.h"
#include"oled.h"
#include"../inc/protool.h"



void uart_init(void);
int global_mode = 0;
/*
    return: True(have obstacle) False(dont have obstacle)
    PB15: TRIG
    PB14: ECHO
    tim3 as 1 ms
*/
// #define FLA_ON HAL_GPIO_WritePin(FLA_GPIO_Port, FLA_Pin, GPIO_PIN_SET)
// #define FLA_OFF HAL_GPIO_WritePin(FLA_GPIO_Port, FLA_Pin, GPIO_PIN_RESET)
// #define FLB_ON HAL_GPIO_WritePin(FLA_GPIO_Port, FLA_Pin, GPIO_PIN_SET)
// #define FLB_OFF HAL_GPIO_WritePin(FLA_GPIO_Port, FLA_Pin, GPIO_PIN_RESET)
// #define FL_F FLA_ON;FLB_OFF;
// #define FL_B FLA_OFF;FLB_ON;
// #define FL_OFF FLA_OFF;FLB_OFF;

// #define FRA_ON HAL_GPIO_WritePin(FRA_GPIO_Port, FRA_Pin, GPIO_PIN_SET)
// #define FRA_OFF HAL_GPIO_WritePin(FRA_GPIO_Port, FRA_Pin, GPIO_PIN_RESET)
// #define FRB_ON HAL_GPIO_WritePin(FRA_GPIO_Port, FRA_Pin, GPIO_PIN_SET)
// #define FRB_OFF HAL_GPIO_WritePin(FRA_GPIO_Port, FRA_Pin, GPIO_PIN_RESET)
// #define FR_F FRA_ON;FRB_OFF;
// #define FR_B FRA_OFF;FRB_ON;
// #define FR_OFF FRA_OFF;FRB_OFF;



// #define L_OFF FL_OFF;BL_OFF
// #define R_OFF FR_OFF;BR_OFF
// #define L_F FL_F;BL_F
// #define R_F FR_F;BR_F
// #define L_B FL_B;BL_B
// #define R_B FR_B;BR_B






int Detection_Obstacle(void (*fun)(void)) {
    printf("Dectecting obstacle \n");
    uint32_t tl, tr;
    double s;
    char oled_s[60];
    HAL_TIM_Base_Start_IT(&htim4); // 72Mhz / 72
    HAL_GPIO_WritePin(OBS_TRIG_GPIO_Port, OBS_TRIG_Pin, GPIO_PIN_SET);
    HAL_Delay(1);// 
    printf("GPIO_STATE: %d\n",HAL_GPIO_ReadPin(OBS_TRIG_GPIO_Port, OBS_TRIG_Pin) == GPIO_PIN_SET);
    HAL_GPIO_WritePin(OBS_TRIG_GPIO_Port, OBS_TRIG_Pin, GPIO_PIN_RESET);
    while(HAL_GPIO_ReadPin(OBS_ECHO_GPIO_Port, OBS_ECHO_Pin) == GPIO_PIN_RESET);
    htim4.Instance->CNT = 0;
    tl = __HAL_TIM_GET_COUNTER(&htim4);
    while(HAL_GPIO_ReadPin(OBS_ECHO_GPIO_Port, OBS_ECHO_Pin) == GPIO_PIN_SET) {
        if(__HAL_TIM_GET_COUNTER(&htim4) > 50000) {
            HAL_TIM_Base_Stop_IT(&htim4);
            printf("thanks~ no obstacle within 17m\n");
            return 0;
        }
    }
    HAL_TIM_Base_Stop_IT(&htim4);
    tr = __HAL_TIM_GET_COUNTER(&htim4);
    
    s = (tr - tl) * 0.017f; // ms  340*t/10^6*100 / 2
    // if(s < 10) {
    //     (*fun)();
    // }
    printf("%.2lf cm\n", s);
    sprintf(oled_s, "d = %7.2fcm", s);
    printf(oled_s);
    OLED_ShowString(0, 0,oled_s , 16);
    HAL_GPIO_WritePin(OBS_ECHO_GPIO_Port, OBS_ECHO_Pin, GPIO_PIN_RESET);
    return s;
}
/*
无接收到输出1
接收到输出0
*/
#define INFRA1_Read HAL_GPIO_ReadPin(INFRA1_GPIO_Port, INFRA1_Pin)
#define INFRA2_Read HAL_GPIO_ReadPin(INFRA2_GPIO_Port, INFRA2_Pin)
void Line_Follow(void) {
//    int v[2];
//    turn_on(); //开启电机
//    turn_pause();  //电机待机
//
//    while(global_mode == 2) {
//        v[0] = INFRA1_Read;
//        v[1] = INFRA2_Read;
//        if(!v[0] && !v[0]) {
//            /*越界*/
//            turn_pause();
//            global_mode = 0; // stop
//            break;
//        } else if(!v[0] && v[1]){
//            /*左边接收到，右边无接收
//                左白，右黑
//            */
//            turn_right();
//            while(INFRA2_Read == 1);
//            forward();
//        } else if(v[0] && !v[1]) {
//            turn_left();
//            while(INFRA1_Read == 1);
//            forward();
//        }
//    }
    return ;
}
char uart1_buf[255];
int uart1_cnt;
uint8_t uart1_ch;

char uart2_buf[UART2_LEN];
int uart2_cnt, uart2_p;
uint8_t uart2_ch;

int uart1_newline;

//int uart1_start;
void Manual_Control(void) {
	while(1) {

	}
//    while(1) {
//        if(uart2_cnt != uart2_p) {
//            switch(uart2_buf[uart2_p]) {
//                case '1':
//                    forward();
//                    HAL_Delay(100);
//                    turn_pause();
//                    break;
//                case '2':
//                    turn_left();
//                    HAL_Delay(100);
//                    turn_pause();
//                    break;
//                case '3':
//                    backward();
//                    HAL_Delay(100);
//                    turn_pause();
//                    break;
//                case '4':
//                    turn_right();
//                    HAL_Delay(100);
//                    turn_pause();
//                    break;
//                case '5':
//                    turn_pause();
//                    break;
//                case '6':
//                    turn_off();
//                    break;
//                case '7':
//                    turn_on();
//                    break;
//            }
//            uart2_p++;
//            if(uart2_p >= UART2_LEN) uart2_p -= UART2_LEN;
//        }
//    }
}
char *mode_name[3] = {
    "stop",
    "Manual",
    "LineFollow"
};
void Show_Oled() {
   /*
   一个英文8*16 or 6*8
   一个中文16*16
   一共64*128
   */ 
  OLED_ShowString(0, 0, "PWML:", 8);//5*8=40
  OLED_ShowNum(40, 0, -1, vl.v, 8);
  OLED_ShowString(0, 8, "PWMR:", 8);
  OLED_ShowNum(40, 8, -1, vr.v, 8);
  OLED_ShowString(0, 16, "MODE:", 8);//5*8=40
  OLED_ShowString(40, 16, mode_name[global_mode], 8);


}

double get_speed(char *s, int len) {
	int i = 0;
	double ans = 0, base = 0.1;
//	s[len] = '\0';
	printf("gets = %s", s);
	printf("i=%d len=%d s[0]=%c\n", i, len, s[i]);
	while(i < len && s[i] >= '0' && s[i] <= '9') {
		ans = ans * 10 + s[i] - '0';
		++i;
	}
	if(s[i] == '.') {
		++i;

		while(i < len && s[i] >= '0' && s[i] <= '9') {
			ans += (s[i] - '0') * base;
			++i;
		}
		base *= 0.1;
	}
	printf("ans=%f\n", ans);
	return ans;
}
/*
 * mode
 * 0:stop
 * 1:manual control
 * 2:line follower
 * 3:obstacle dodge
 *
 * */
int run_main(void) {
	uart_init();
    OLED_Init();
    OLED_Clear();
    while(1) {
    	if(protool_newline == 1) {
    		protool_deal();
    	}
    	switch(global_mode) {
			case 0:
				break;

    	}
    }

//    double v;
//    while(1) {
//    	//printf("hello Wolrd\n");
//    	printf("v: vl=%.2f, vr = %.2f\n", vl.v, vr.v);
//    	printf("pwml = %d, pwmr = %d\n", PWML, PWMR);
//
//      if(uart1_cnt > 0 && uart1_buf[uart1_cnt - 1] == 0x0A && uart1_buf[uart1_cnt - 2] == 0x0D){
//    	  if(uart1_buf[0] == 'v') {
//    		  double v = get_speed(uart1_buf + 3, uart1_cnt);
//    		  if(uart1_buf[1] == 'l') {
//    			  motor_set_speed(v, 0);
//    		  } else {
//    			  motor_set_speed(v, 1);
//    		  }
//    		  printf("receive v = %f\n", v);
//    	  }
//    	  uart1_cnt = 0;
//
//      }
//    	HAL_Delay(1000);
//    }
//    while(1) {
//        printf("hello Wolrd\n");
//
//        HAL_Delay(3000);
//    }

    return 0;
}



/* Base part2 */
extern uint8_t uart1_ch;
void uart_init(void) {
	HAL_UART_Receive_IT(&IO_UART1, &uart1_ch, 1);
}
#ifdef GNU_TO_UART
#undef errno
extern int errno;
int _read(int file, char *data, int len)
{
    int bytes_read;

    if (file != STDIN_FILENO)
    {
        errno = EBADF;
        return -1;
    }

    for (bytes_read = 0; bytes_read < len; bytes_read++)
    {
        //*data = (char) UART_RxBlocking();
        data++;
	      HAL_UART_Receive(&IO_UART1, (uint8_t *)data, 1, 1000);	
        //data++;
    }

    return bytes_read;
}
int _write(int file, char *data, int len)
{
    int bytes_written;

    if ((file != STDOUT_FILENO) && (file != STDERR_FILENO))
    {
        errno = EBADF;
        return -1;
    }

    for (bytes_written = 0; bytes_written < len; bytes_written++)
    {
        //UART_TxBlocking(*data);
        HAL_UART_Transmit(&IO_UART1, (uint8_t *)data, 1, 1000);	
        data++;
    }

    return bytes_written;
}
#endif
