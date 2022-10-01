#include"oled.h"
#include"run_main.h"
#include"oledfont.h"
#define OLED_DEVICE_ADDRESS 0x78
#define OLED_CMD  0
#define OLED_DATA  1
void OLED_Write_Command(unsigned char com) {
    if(HAL_I2C_Mem_Write(&hi2c_oled, OLED_DEVICE_ADDRESS, 0x00, I2C_MEMADD_SIZE_8BIT, &com, 1, 1) != HAL_OK) {
        printf("OLED write command error Timeout");
    }
}
void OLED_Write_Data(uint8_t data) {
    if(HAL_I2C_Mem_Write(&hi2c_oled, OLED_DEVICE_ADDRESS, 0x40, I2C_MEMADD_SIZE_8BIT, &data, 1, 1) != HAL_OK) {
        printf("OLED write command TImeout");
    }
}
void OLED_Write(uint8_t data, int type) {
    switch(type){
        case OLED_CMD:
            OLED_Write_Command(data);
            break;
        case OLED_DATA:
            OLED_Write_Data(data);
            break;
    }
}
void OLED_fill_picture(unsigned fill_data) {
    uint8_t m, n;
    for(m = 0 ; m < 8; ++m) {
        OLED_Write(0xb0 + m, OLED_CMD); //page 0 ~ 8
        OLED_Write(0x00, 0); // lower nibble column start address
        OLED_Write(0x10, 0); // higher nibble column start address
        for(n = 0; n < 128; ++n) {
            OLED_Write(fill_data, OLED_DATA);
        }
    }
}
void OLED_Set_Pos(uint8_t x, uint8_t y) {
    OLED_Write(0xb0 + y, OLED_CMD);
    OLED_Write((x >> 4) | 0x10, OLED_CMD);
    OLED_Write(x & 0xf, OLED_CMD);
}
void OLED_Display_On(void) {
    OLED_Write(0x8D, OLED_CMD); //set dcdc
    OLED_Write(0x14, OLED_CMD); //dcdc on
    OLED_Write(0xAF, OLED_CMD); //display on
}
void OLED_Display_Off(void) {
    OLED_Write(0x8D, OLED_CMD); //set dcdc
    OLED_Write(0x10, OLED_CMD); //dcdc off
    OLED_Write(0xAE, OLED_CMD); //display off
}

void OLED_Clear(void) {
    uint8_t i, n;
    for(i = 0; i < 8; ++i) {
        OLED_Write(0xb0 + i, OLED_CMD); //set page
        OLED_Write(0x00, OLED_CMD);  //lower nibble column address
        OLED_Write(0x10, OLED_CMD); // higher nibble column address
        for(n = 0; n< 128; ++n) {
            OLED_Write(0, OLED_DATA);
        }
    }
}
/*
    x:行
    y:列
*/
void OLED_ShowChar(uint8_t x, uint8_t y, uint8_t ch, uint8_t char_size){
    uint8_t c = 0, i = 0;
    c = ch - ' ';
    if(x >= OLED_COLLUMN_MAX){
        x = 0;        y += 2;
    }

    if(char_size == 16) {
        OLED_Set_Pos(x, y);
        for(i = 0; i < 8; ++i) {
            OLED_Write(F8X16[c * 16 + i], OLED_DATA);
        }
        OLED_Set_Pos(x, y + 1);
        for(i = 0;i < 8; ++i) {
            OLED_Write(F8X16[c * 16 + i + 8], OLED_DATA);
        }
    } else if(char_size == 8){
        OLED_Set_Pos(x, y);
        for(i = 0;i < 6; ++i) {
            OLED_Write(F6x8[c][i], OLED_DATA);
        }
    }
}
/*
    x, y 行、列
    offset 输出格式长度  offset=-1 output len of num
    num  输出数字
    size  字体大小
*/
void OLED_ShowNum(uint8_t x, uint8_t y, uint8_t offset, uint32_t num, uint8_t size) {
    uint8_t t;
    uint8_t st[11];
    st[0] = 0;
    do {
        st[++st[0]] = num % 10;
    }while(num /= 10);
    for(t = offset == -1 ? st[0] : offset; t > 0; --t) {
        if(t > st[0]) OLED_ShowChar(x + (size / 2) * (st[0] - t), y, '0', size);
        else OLED_ShowChar(x + (size / 2) * (st[0] - t), y, st[t] + '0', size);
    }
}
/*
x, y  row,col
*/
void OLED_ShowString(uint8_t x, uint8_t y, char *chr, uint8_t char_size) {
    uint8_t j = 0;
    while(chr[j] != '\0') {
        OLED_ShowChar(x, y, chr[j], char_size);
        x += 8;
        if(x > 120){
            x = 0;
            y += 2;
        }
        ++j;
    }
}
/*
16 rows
16 cols
x rwo
y col
*/
void OLED_ShowChinese(uint8_t x, uint8_t y, uint8_t no) {
    uint8_t t, adder = 0;
    OLED_Set_Pos(x, y);
    for(t = 0;t < 16; ++t) {
        OLED_Write(Hzk[2 * no][t], OLED_DATA);
        adder += 1;
    }
    OLED_Set_Pos(x, y + 1);
    for(t = 0; t < 16; ++t) {
        OLED_Write(Hzk[2 * no + 1][t], OLED_DATA);
        adder += 1;
    }
}
void OLED_ShowBMP(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, char * src) {
    uint8_t j = 0, x, y;

    for(x = x0; x < x1; ++x) {
        OLED_Set_Pos(x, y0);
        for(y = y0; y < y1; ++y) {
            OLED_Write(src[j++], OLED_DATA);
        }
    }
}
void OLED_Init() {
    HAL_Delay(800);
    HAL_I2C_Init(&hi2c_oled);
    OLED_Write(0xAE,OLED_CMD);//--display off
	OLED_Write(0x00,OLED_CMD);//---set low column address
	OLED_Write(0x10,OLED_CMD);//---set high column address
	OLED_Write(0x40,OLED_CMD);//--set start line address  
	OLED_Write(0xB0,OLED_CMD);//--set page address
	OLED_Write(0x81,OLED_CMD); // contract control
	OLED_Write(0xFF,OLED_CMD);//--128   
	OLED_Write(0xA1,OLED_CMD);//set segment remap 
	OLED_Write(0xA6,OLED_CMD);//--normal / reverse
	OLED_Write(0xA8,OLED_CMD);//--set multiplex ratio(1 to 64)
	OLED_Write(0x3F,OLED_CMD);//--1/32 duty
	OLED_Write(0xC8,OLED_CMD);//Com scan direction
	OLED_Write(0xD3,OLED_CMD);//-set display offset
	OLED_Write(0x00,OLED_CMD);//
	
	OLED_Write(0xD5,OLED_CMD);//set osc division
	OLED_Write(0x80,OLED_CMD);//
	
	OLED_Write(0xD8,OLED_CMD);//set area color mode off
	OLED_Write(0x05,OLED_CMD);//
	
	OLED_Write(0xD9,OLED_CMD);//Set Pre-Charge Period
	OLED_Write(0xF1,OLED_CMD);//
	
	OLED_Write(0xDA,OLED_CMD);//set com pin configuartion
	OLED_Write(0x12,OLED_CMD);//
	
	OLED_Write(0xDB,OLED_CMD);//set Vcomh
	OLED_Write(0x30,OLED_CMD);//
	
	OLED_Write(0x8D,OLED_CMD);//set charge pump enable
	OLED_Write(0x14,OLED_CMD);//
	
	OLED_Write(0xAF,OLED_CMD);//--turn on oled panel
    // int i, j;
    // for(i=0;i<8;++i)
    //     for(j=0;j<128;++j)
    //         OLED_Write_Data(0);
}