/*******  LoRa点对点串口透传 START *******/
#include "NS_Radio.h"	  //导入LoRa射频库
#include "hal_oled.h"	  //导入OLED屏库
#include "usart1-board.h" //导入Uart1库
void LoRaP2PSerialPortTransparentTransmissionExample()
{
	// 串口1初始化
	USART1_Init(115200);
	// OLED屏初始化
	OLED_Init();
	// 初始化LoRa模块
	NS_RadioInit(433500000, 14, 1000, 1000);
	// LoRa接收缓存
	uint8_t loRaRxBuf[255] = {0};
	// LoRa接收数据长度
	uint32_t loRaRxBufReadLen = 0;
	// 显示LoRa接收数据长度字符串
	char showLoRaRxBufReadLenBuf[20] = {0};
	// 显示Uart接收数据长度字符串
	char showUartRxBufReadLenBuf[20] = {0};
	// OLED屏显示串口透传
	OLED_ShowCHinese(0, 0, 38);
	OLED_ShowCHinese(16, 0, 39);
	OLED_ShowCHinese(32, 0, 52);
	OLED_ShowCHinese(48, 0, 53);
	while (1)
	{
		// LoRa射频接收 串口发送
		if ((loRaRxBufReadLen = ReadRadioRxBuffer((uint8_t *)loRaRxBuf)))
		{
			// 串口发送 LoRa射频接收的内容
			USART1_SendStr(loRaRxBuf, loRaRxBufReadLen);
			// 格式化LoRa接收数据长度字符串
			sprintf(showLoRaRxBufReadLenBuf, "LoRaReadLen:%-6d", loRaRxBufReadLen);
			// OLED屏显示LoRa接收数据长度
			OLED_ShowString(0, 2, (uint8_t *)showLoRaRxBufReadLenBuf);
			// 清空接收的数据
			memset(loRaRxBuf, 0, 255);
		}
		DelayMs(50); // 等待LoRa发送、串口接收
		// 串口接收 LoRa射频发送
		if (USART1_RX_COUNT != 0)
		{
			// LoRa发送 串口接收的内容
			Radio.Send(USART1_RX_BUF, USART1_RX_COUNT);
			// 格式化LoRa接收数据长度字符串
			sprintf(showUartRxBufReadLenBuf, "UartReadLen:%-6d", USART1_RX_COUNT);
			// OLED屏显示Uart接收数据长度
			OLED_ShowString(0, 4, (uint8_t *)showUartRxBufReadLenBuf);
			// 清空串口接收缓冲区
			USART1_ReceiveClr();
		}
		DelayMs(50); // 等待串口发送 LoRa接收
	}
}