/************* UART串口 START  *************/
#include "usart1-board.h" //导入串口1库
#include "hal_oled.h"	  //导入OLED屏库
void UartExample()
{
	// 串口初始化 波特率为115200
	USART1_Init(115200);
	// OLED屏初始化
	OLED_Init();
	// OLED显示测试案例名称
	OLED_ShowString(0, 0, (uint8_t *)"Uart Test");
	while (1)
	{
		if (USART1_RX_BUF[0] != 0)
		{
			// 串口回写接收到的数据
			printf("接收到：%s", (const char *)USART1_RX_BUF);
			// OLED清屏
			OLED_Clear();
			// OLED显示测试案例名称
			OLED_ShowString(0, 0, (uint8_t *)"Uart Test");
			// OLED显示串口接收的数据
			OLED_ShowString(0, 2, USART1_RX_BUF);
			// 清空串口接收缓冲区
			USART1_ReceiveClr();
		}
	}
}
/*************  UART串口  END  *************/