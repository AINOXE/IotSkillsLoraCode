/***********  ���鰸��  START  ************/
#include "hal_oled.h"   //����oled��
#include "adc_reader.h" //����adc��
void MethaneExample()
{
    // OLED��ʼ��
    OLED_Init();
    // ADC��ʼ��
    ADCS_Init();
    // ������ʾ�ַ���
    char showMethaneBuf[20] = {0};
    // ����ֵ
    float methaneBufValue = 0;
    // ͨ��0��ѹֵ
    float voltageValue = 0;
    while (1)
    {
        // ɨ������ADCͨ������ת��Ϊ��ѹֵ
        AdcScanChannel();
        // ��ȡͨ��0��ѹֵ
        voltageValue = AdcReadCh0();
        // �������ֵ (��ǰ��ѹ/����ѹ)*�������ֵ
        methaneBufValue = (voltageValue / 3.3) * 1000;
        // ��ʽ������ʾ�ַ���
        sprintf(showMethaneBuf, "Methane:%-8.2f", methaneBufValue);
        // OLED����ʾ�����ַ���
        OLED_ShowString(0, 1, showMethaneBuf);
        // ��ʱ1��
        DelayMs(1000);
    }
}
/***********  ���鰸��   END    ************/