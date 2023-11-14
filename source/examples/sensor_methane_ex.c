/***********  甲烷案例  START  ************/
#include "hal_oled.h"   //导入oled库
#include "adc_reader.h" //导入adc库
void MethaneExample()
{
    // OLED初始化
    OLED_Init();
    // ADC初始化
    ADCS_Init();
    // 甲烷显示字符串
    char showMethaneBuf[20] = {0};
    // 甲烷值
    float methaneBufValue = 0;
    // 通道0电压值
    float voltageValue = 0;
    while (1)
    {
        // 扫描所有ADC通道，并转化为电压值
        AdcScanChannel();
        // 读取通道0电压值
        voltageValue = AdcReadCh0();
        // 计算甲烷值 (当前电压/最大电压)*甲烷最大值
        methaneBufValue = (voltageValue / 3.3) * 1000;
        // 格式甲烷显示字符串
        sprintf(showMethaneBuf, "Methane:%-8.2f", methaneBufValue);
        // OLED屏显示甲烷字符串
        OLED_ShowString(0, 1, showMethaneBuf);
        // 延时1秒
        DelayMs(1000);
    }
}
/***********  甲烷案例   END    ************/