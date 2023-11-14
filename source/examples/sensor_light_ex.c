/************  光照案例 START **************/
#include "hal_oled.h"	//导入oled库
#include "adc_reader.h" //导入adc库
void LightExample()
{
	// OLED初始化
	OLED_Init();
	// ADC初始化
	ADCS_Init();
	// 光照显示字符串
	char showLightBuf[20] = {0};
	// 光照值
	int lightValue = 0;
	// 通道0电压值
	float voltageValue = 0;
	while (1)
	{
		// 扫描所有ADC通道，并转化为电压值
		AdcScanChannel();
		// 读取通道0电压值
		voltageValue = AdcReadCh0();
		// 计算光照值 (当前电压/最大电压)*光照最大值
		lightValue = (voltageValue / 3.3) * 20000;
		// 格式光照显示字符串
		sprintf(showLightBuf, "Light:%-10d", lightValue);
		// OLED屏显示光照字符串
		OLED_ShowString(0, 1, showLightBuf);
		// 延时1秒
		DelayMs(1000);
	}
}
/************  光照案例  END  **************/