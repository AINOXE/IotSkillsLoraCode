/************  ���հ��� START **************/
#include "hal_oled.h"	//����oled��
#include "adc_reader.h" //����adc��
void LightExample()
{
	// OLED��ʼ��
	OLED_Init();
	// ADC��ʼ��
	ADCS_Init();
	// ������ʾ�ַ���
	char showLightBuf[20] = {0};
	// ����ֵ
	int lightValue = 0;
	// ͨ��0��ѹֵ
	float voltageValue = 0;
	while (1)
	{
		// ɨ������ADCͨ������ת��Ϊ��ѹֵ
		AdcScanChannel();
		// ��ȡͨ��0��ѹֵ
		voltageValue = AdcReadCh0();
		// �������ֵ (��ǰ��ѹ/����ѹ)*�������ֵ
		lightValue = (voltageValue / 3.3) * 20000;
		// ��ʽ������ʾ�ַ���
		sprintf(showLightBuf, "Light:%-10d", lightValue);
		// OLED����ʾ�����ַ���
		OLED_ShowString(0, 1, showLightBuf);
		// ��ʱ1��
		DelayMs(1000);
	}
}
/************  ���հ���  END  **************/