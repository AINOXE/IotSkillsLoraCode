/***********************************************************************************************************
*
*
*
*
*
*
***********************************************************************************************************/
#ifndef _HAL_OLED_H_
#define _HAL_OLED_H_

#include "board.h"
#include "user_define.h"


//OLED模式设置
//0:4线串行模式
//1:并行8080模式
#define OLED_MODE 0

#define SIZE 16
#define XLevelL		0x00
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF 
#define X_WIDTH 	128
#define Y_WIDTH 	64	    						  
//-----------------OLED端口定义----------------  

#define OLED_CS 		PB_12
#if (USE_OLED_RST == true)
#define OLED_RST 		PB_13
#endif //(USE_OLED_RST == true)
#define OLED_DC			PB_14
#define OLED_SCLK 	PB_13
#define OLED_SDIN 	PB_15

//外部变量声明
extern Gpio_t OLED_CS_PIN;
#if (USE_OLED_RST == true)
extern Gpio_t OLED_RST_PIN;
#endif //(USE_OLED_RST == true)
extern Gpio_t OLED_DC_PIN;
extern Gpio_t OLED_SCLK_PIN;
extern Gpio_t OLED_SDIN_PIN;


#define OLED_CS_Clr()  GpioWrite( &OLED_CS_PIN, 0 )//CS
#define OLED_CS_Set()  GpioWrite( &OLED_CS_PIN, 1 )

#if (USE_OLED_RST == true)
#define OLED_RST_Clr() GpioWrite( &OLED_RST_PIN, 0 )//RES
#define OLED_RST_Set() GpioWrite( &OLED_RST_PIN, 1 )
#endif //(USE_OLED_RST == true)

#define OLED_DC_Clr() GpioWrite( &OLED_DC_PIN, 0 )//DC
#define OLED_DC_Set() GpioWrite( &OLED_DC_PIN, 1 )

#define OLED_SCLK_Clr() GpioWrite( &OLED_SCLK_PIN, 0 )//CLK
#define OLED_SCLK_Set() GpioWrite( &OLED_SCLK_PIN, 1 )

#define OLED_SDIN_Clr() GpioWrite( &OLED_SDIN_PIN, 0 )//DIN
#define OLED_SDIN_Set() GpioWrite( &OLED_SDIN_PIN, 1 )
 		     
#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据


//OLED控制用函数
void OLED_WR_Byte(uint8_t dat,uint8_t cmd);
//开启OLED显示   	    
void OLED_Display_On(void);
//关闭OLED显示   
void OLED_Display_Off(void);
void OLED_Init(void);   							   		    
void OLED_Init_Inverse(void);
//清屏函数,清完屏,整个屏幕是黑色的!和没点亮一样!!!	 
void OLED_Clear(void);
//单次擦除两页，即一行，从当页开始算
void OLED_Clear_Page(uint8_t page);
void OLED_DrawPoint(uint8_t x,uint8_t y,uint8_t t);
void OLED_Fill(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t dot);

//显示一个字符
//x,y: 起点坐标：x:0~127  y:0~7
//chr: 显示的字符
void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr);

//显示数字 
//x,y: 起点坐标：x:0~127  y:0~7
//len: 数字的位数   size:字体大小
//num: 数值(0~4294967295);	
void OLED_ShowNum(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t size);

//显示16进制数字 
//x,y: 起点坐标：x:0~127  y:0~7
//len :数字的位数   size:字体大小
//num:数值(0~4294967295);	
void OLED_ShowHex(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t size);

//显示一个字符号串
//x,y: 起点坐标：x:0~127  y:0~7
//p:   要显示的字符串
void OLED_ShowString(uint8_t x,uint8_t y, uint8_t *p);

void OLED_Set_Pos(unsigned char x, unsigned char y);

//根据字库索引显示汉字
//x,y: 起点坐标：x:0~127  y:0~7
//no:  字库索引
void OLED_ShowCHinese(uint8_t x,uint8_t y,uint8_t no);
//显示汉字
//x,y: 起点坐标：x:0~127  y:0~7
//arr: 取模后的数组
void OLED_ShowCHineseArray(uint8_t x,uint8_t y,char arr[32]);
//显示点阵图
//x,y: 起点坐标：x:0~127  y:0~7
//width,hight: 图像宽高
//BMP: 图像取模后的数组
void OLED_DrawBMP(unsigned char x, unsigned char y,unsigned char width, unsigned char hight,unsigned char BMP[]);
void OLED_DrawPoint_tim(uint8_t x,uint8_t y,uint8_t *no, uint8_t size) ;
#endif  //_OLED_H_
	 



