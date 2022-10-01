#ifndef __OLED__H__
#define __OLED__H__

#include<stdint.h>
#define OLED_COLLUMN_MAX 128
#define OLED_ROW_MAX 8
/*
//OLED的显存
//存放格式如下.
//[0]0 1 2 3 ... 127	
//[1]0 1 2 3 ... 127	
//[2]0 1 2 3 ... 127	
//[3]0 1 2 3 ... 127	
//[4]0 1 2 3 ... 127	
//[5]0 1 2 3 ... 127	
//[6]0 1 2 3 ... 127	
//[7]0 1 2 3 ... 127 			  

每个page  8行
*/
void OLED_Init();
void OLED_ShowString(uint8_t x, uint8_t y, char *chr, uint8_t char_size);
void OLED_ShowNum(uint8_t x, uint8_t y, uint8_t offset, uint32_t num, uint8_t size);
void OLED_ShowChar(uint8_t x, uint8_t y, uint8_t ch, uint8_t char_size);
void OLED_Clear(void);
void OLED_Display_Off(void) ;
#endif