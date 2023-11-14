/*********** ������������ START ************/
#include "hal_oled.h"   //����oled��
#include "adc_reader.h" //����adc��
void AirQualityExample()
{
    // OLED��ʼ��
    OLED_Init();
    // ADC��ʼ��
    ADCS_Init();
    // ����������ʾ�ַ���
    char showAirQualityBuf[20] = {0};
    // ��������ֵ
    float airQualityValue = 0;
    // ͨ��0��ѹֵ
    float voltageValue = 0;
    while (1)
    {
        // ɨ������ADCͨ������ת��Ϊ��ѹֵ
        AdcScanChannel();
        // ��ȡͨ��0��ѹֵ
        voltageValue = AdcReadCh0();
        // �����������ֵ (��ǰ��ѹ/����ѹ)*�����������ֵ
        airQualityValue = (voltageValue / 3.3) * 443;
        // ��ʽ����������ʾ�ַ���
        sprintf(showAirQualityBuf, "AirQuailty:%-5f", airQualityValue);
        // OLED����ʾ���������ַ���
        OLED_ShowString(0, 1, (uint8_t *)showAirQualityBuf);
        // ��ʱ1��
        DelayMs(1000);
    }
}
/*********** ������������  END  ************/