/************* UART���� START  *************/
#include "usart1-board.h" //���봮��1��
#include "hal_oled.h"	  //����OLED����
void UartExample()
{
	// ���ڳ�ʼ�� ������Ϊ115200
	USART1_Init(115200);
	// OLED����ʼ��
	OLED_Init();
	// OLED��ʾ���԰�������
	OLED_ShowString(0, 0, (uint8_t *)"Uart Test");
	while (1)
	{
		if (USART1_RX_BUF[0] != 0)
		{
			// ���ڻ�д���յ�������
			printf("���յ���%s", (const char *)USART1_RX_BUF);
			// OLED����
			OLED_Clear();
			// OLED��ʾ���԰�������
			OLED_ShowString(0, 0, (uint8_t *)"Uart Test");
			// OLED��ʾ���ڽ��յ�����
			OLED_ShowString(0, 2, USART1_RX_BUF);
			// ��մ��ڽ��ջ�����
			USART1_ReceiveClr();
		}
	}
}
/*************  UART����  END  *************/