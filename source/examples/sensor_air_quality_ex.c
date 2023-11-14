/*********** 空气质量案例 START ************/
#include "hal_oled.h"   //导入oled库
#include "adc_reader.h" //导入adc库
void AirQualityExample()
{
    // OLED初始化
    OLED_Init();
    // ADC初始化
    ADCS_Init();
    // 空气质量显示字符串
    char showAirQualityBuf[20] = {0};
    // 空气质量值
    float airQualityValue = 0;
    // 通道0电压值
    float voltageValue = 0;
    while (1)
    {
        // 扫描所有ADC通道，并转化为电压值
        AdcScanChannel();
        // 读取通道0电压值
        voltageValue = AdcReadCh0();
        // 计算空气质量值 (当前电压/最大电压)*空气质量最大值
        airQualityValue = (voltageValue / 3.3) * 443;
        // 格式空气质量显示字符串
        sprintf(showAirQualityBuf, "AirQuailty:%-5f", airQualityValue);
        // OLED屏显示空气质量字符串
        OLED_ShowString(0, 1, (uint8_t *)showAirQualityBuf);
        // 延时1秒
        DelayMs(1000);
    }
}
/*********** 空气质量案例  END  ************/