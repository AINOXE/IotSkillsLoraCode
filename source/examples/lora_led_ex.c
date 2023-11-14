/*********  LoRa��Ե��� START  **********/
#include "NS_Radio.h" //����LoRa��Ƶ��
#include "hal_oled.h" //����OLED����
#include "hal_key.h"
void LoRaLedExample()
{
	// OLED����ʼ��
	OLED_Init();
	// ��ʼ��LoRaģ��
	NS_RadioInit(433500000, 14, 1000, 1000);
	// LoRa���ջ���
	uint8_t loRaRxBuf[255] = {0};
	while (1)
	{
		// ��KEY2 ���Ϳ�������
		if (isKey2Pressed())
		{
			// LoRa��Ƶ����
			Radio.Send((uint8_t *)"1", 1);
			GpioWrite(&Led1, 0);
			resetKey2();
		}
		// ��KEY3 ���͹ص�����
		if (isKey3Pressed())
		{
			// LoRa��Ƶ����
			Radio.Send((uint8_t *)"0", 1);
			GpioWrite(&Led1, 1);
			resetKey3();
		}
		// LoRa��Ƶ����
		if (ReadRadioRxBuffer((uint8_t *)loRaRxBuf))
		{
			// OLED����ʾ���յ�����
			OLED_ShowString(0, 0, loRaRxBuf);
			// ���յ���1������
			if (loRaRxBuf[0] == '1')
			{
				GpioWrite(&Led1, 0);
			}
			// ���յ���0���ص�
			if (loRaRxBuf[0] == '0')
			{
				GpioWrite(&Led1, 1);
			}
			// ��ս��յ�����
			memset(loRaRxBuf, 0, 255);
		}
	}
}
/*********  LoRa��Ե��� END  **********/