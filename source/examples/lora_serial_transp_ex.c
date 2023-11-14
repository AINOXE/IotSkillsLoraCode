/*******  LoRa��Ե㴮��͸�� START *******/
#include "NS_Radio.h"	  //����LoRa��Ƶ��
#include "hal_oled.h"	  //����OLED����
#include "usart1-board.h" //����Uart1��
void LoRaP2PSerialPortTransparentTransmissionExample()
{
	// ����1��ʼ��
	USART1_Init(115200);
	// OLED����ʼ��
	OLED_Init();
	// ��ʼ��LoRaģ��
	NS_RadioInit(433500000, 14, 1000, 1000);
	// LoRa���ջ���
	uint8_t loRaRxBuf[255] = {0};
	// LoRa�������ݳ���
	uint32_t loRaRxBufReadLen = 0;
	// ��ʾLoRa�������ݳ����ַ���
	char showLoRaRxBufReadLenBuf[20] = {0};
	// ��ʾUart�������ݳ����ַ���
	char showUartRxBufReadLenBuf[20] = {0};
	// OLED����ʾ����͸��
	OLED_ShowCHinese(0, 0, 38);
	OLED_ShowCHinese(16, 0, 39);
	OLED_ShowCHinese(32, 0, 52);
	OLED_ShowCHinese(48, 0, 53);
	while (1)
	{
		// LoRa��Ƶ���� ���ڷ���
		if ((loRaRxBufReadLen = ReadRadioRxBuffer((uint8_t *)loRaRxBuf)))
		{
			// ���ڷ��� LoRa��Ƶ���յ�����
			USART1_SendStr(loRaRxBuf, loRaRxBufReadLen);
			// ��ʽ��LoRa�������ݳ����ַ���
			sprintf(showLoRaRxBufReadLenBuf, "LoRaReadLen:%-6d", loRaRxBufReadLen);
			// OLED����ʾLoRa�������ݳ���
			OLED_ShowString(0, 2, (uint8_t *)showLoRaRxBufReadLenBuf);
			// ��ս��յ�����
			memset(loRaRxBuf, 0, 255);
		}
		DelayMs(50); // �ȴ�LoRa���͡����ڽ���
		// ���ڽ��� LoRa��Ƶ����
		if (USART1_RX_COUNT != 0)
		{
			// LoRa���� ���ڽ��յ�����
			Radio.Send(USART1_RX_BUF, USART1_RX_COUNT);
			// ��ʽ��LoRa�������ݳ����ַ���
			sprintf(showUartRxBufReadLenBuf, "UartReadLen:%-6d", USART1_RX_COUNT);
			// OLED����ʾUart�������ݳ���
			OLED_ShowString(0, 4, (uint8_t *)showUartRxBufReadLenBuf);
			// ��մ��ڽ��ջ�����
			USART1_ReceiveClr();
		}
		DelayMs(50); // �ȴ����ڷ��� LoRa����
	}
}