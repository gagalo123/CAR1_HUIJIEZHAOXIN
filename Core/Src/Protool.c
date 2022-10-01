/*
 * Protool.c
 *
 *  Created on: Sep 8, 2022
 *      Author: bamia
 */

#include"run_main.h"
#include"../Inc/motor.h"
#include<string.h>


char protool_s[255];
int protool_len;
int protool_start;
int protool_newline;

int StringFind(char *s, char *t, int start_pos) {
	int i;
	for(i = start_pos; s[i] != '\0'; ++i) {
		int fg = 1;
		int j = 0;
		for(; t[j] !='\0'; ++j) {
			if(s[i + j] != t[j]) {
				fg = 0;
				break;
			}
		}
		if(fg) return i;
	}
	return -1;
}
/*
 * $0,0#  停止
 * $1,0#  恢复
 * $2,0#  前进
 * $3,0#  后退
 * $4,0#  左转
 * $5,0#  右转
 * $0,1#  左旋
 * $0,2#  右旋
 *
 * $MODE,0# 手动模式
 * */
void protool_deal(){

	if(StringFind(protool_s, "MODE", 0)>=0	) {
		switch(protool_s[5]){
			case'0':
				motor_init(0.5, 0.5);
				break;
		}
		printf("MODE changed\n");
		//printf("GOOD\n");
	} else {
		switch(protool_s[1]){
			case '0':
				car_state = enSTOP;
				break;
			case '1':
				car_state = enRESUME;
				break;
			case '2':
				car_state = enFORWARD;
				break;
			case '3':
				car_state = enBACK;
				break;
			case '4':
				car_state = enLEFT;
				break;
			case '5':
				car_state = enRIGHT;
				break;
		}
		switch(protool_s[3]){
			case '1':
				car_state = enTLEFT;
			case '2':
				car_state = enTRIGHT;
		}


		switch(car_state){
			case enSTOP:
				motor_turn_pause();
				break;
			case enRESUME:
				motor_turn_resume();
				break;
			case enFORWARD:
				motor_turn_forward();
				break;
			case enBACK:
				motor_turn_backward();
				break;
			case enLEFT:
				motor_turn_left();
				break;
			case enRIGHT:
				motor_turn_right();
				break;
			case enTLEFT:
				motor_turn_tleft();
				break;
			case enTRIGHT:
				motor_turn_tright();
				break;
		}
		printf("state changed\n");
	}



	protool_newline = 0;



}





