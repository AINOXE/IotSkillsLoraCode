/************  ��ʪ�Ȱ���  START **************/
#include "hal_oled.h" //����oled��
#include "sht3x.h"	  //������ʪ�ȿ�
void TemplateHumidtyExample()
{
	// ��ʪ�ȳ�ʼ��
	SHTXX_Init();
	// OLED��ʼ��
	OLED_Init();
	// �¶��ַ���
	char showTempBuf[20] = {0};
	// ʪ���ַ���
	char showHumBuf[20] = {0};
	// �¶�ֵ��ʪ��ֵ
	float tempValue = 0, humValue = 0;
	while (1)
	{
		// ��ȡ��ʪ��ֵ
		call_sht11(&tempValue, &humValue);
		// ��ʽ���¶���ʾ�ַ���
		sprintf(showTempBuf, "Temperature:%-4.2f", tempValue);
		// ��ʽ��ʪ����ʾ�ַ���
		sprintf(showHumBuf, "Humidty:%-8.2f", humValue);
		// OLED����ʾ�¶��ַ���
		OLED_ShowString(0, 0, (uint8_t *)showTempBuf);
		// OLED����ʾʪ���ַ���
		OLED_ShowString(0, 2, (uint8_t *)showHumBuf);
		// ��ʱ1��
		DelayMs(1000);
	}
}
