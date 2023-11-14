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


//OLEDģʽ����
//0:4�ߴ���ģʽ
//1:����8080ģʽ
#define OLED_MODE 0

#define SIZE 16
#define XLevelL		0x00
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF 
#define X_WIDTH 	128
#define Y_WIDTH 	64	    						  
//-----------------OLED�˿ڶ���----------------  

#define OLED_CS 		PB_12
#if (USE_OLED_RST == true)
#define OLED_RST 		PB_13
#endif //(USE_OLED_RST == true)
#define OLED_DC			PB_14
#define OLED_SCLK 	PB_13
#define OLED_SDIN 	PB_15

//�ⲿ��������
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
 		     
#define OLED_CMD  0	//д����
#define OLED_DATA 1	//д����


//OLED�����ú���
void OLED_WR_Byte(uint8_t dat,uint8_t cmd);
//����OLED��ʾ   	    
void OLED_Display_On(void);
//�ر�OLED��ʾ   
void OLED_Display_Off(void);
void OLED_Init(void);   							   		    
void OLED_Init_Inverse(void);
//��������,������,������Ļ�Ǻ�ɫ��!��û����һ��!!!	 
void OLED_Clear(void);
//���β�����ҳ����һ�У��ӵ�ҳ��ʼ��
void OLED_Clear_Page(uint8_t page);
void OLED_DrawPoint(uint8_t x,uint8_t y,uint8_t t);
void OLED_Fill(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,uint8_t dot);

//��ʾһ���ַ�
//x,y: ������꣺x:0~127  y:0~7
//chr: ��ʾ���ַ�
void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr);

//��ʾ���� 
//x,y: ������꣺x:0~127  y:0~7
//len: ���ֵ�λ��   size:�����С
//num: ��ֵ(0~4294967295);	
void OLED_ShowNum(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t size);

//��ʾ16�������� 
//x,y: ������꣺x:0~127  y:0~7
//len :���ֵ�λ��   size:�����С
//num:��ֵ(0~4294967295);	
void OLED_ShowHex(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t size);

//��ʾһ���ַ��Ŵ�
//x,y: ������꣺x:0~127  y:0~7
//p:   Ҫ��ʾ���ַ���
void OLED_ShowString(uint8_t x,uint8_t y, uint8_t *p);

void OLED_Set_Pos(unsigned char x, unsigned char y);

//�����ֿ�������ʾ����
//x,y: ������꣺x:0~127  y:0~7
//no:  �ֿ�����
void OLED_ShowCHinese(uint8_t x,uint8_t y,uint8_t no);
//��ʾ����
//x,y: ������꣺x:0~127  y:0~7
//arr: ȡģ�������
void OLED_ShowCHineseArray(uint8_t x,uint8_t y,char arr[32]);
//��ʾ����ͼ
//x,y: ������꣺x:0~127  y:0~7
//width,hight: ͼ����
//BMP: ͼ��ȡģ�������
void OLED_DrawBMP(unsigned char x, unsigned char y,unsigned char width, unsigned char hight,unsigned char BMP[]);
void OLED_DrawPoint_tim(uint8_t x,uint8_t y,uint8_t *no, uint8_t size) ;
#endif  //_OLED_H_
	 



