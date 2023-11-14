/************  温湿度案例  START **************/
#include "hal_oled.h" //导入oled库
#include "sht3x.h"	  //导入温湿度库
void TemplateHumidtyExample()
{
	// 温湿度初始化
	SHTXX_Init();
	// OLED初始化
	OLED_Init();
	// 温度字符串
	char showTempBuf[20] = {0};
	// 湿度字符串
	char showHumBuf[20] = {0};
	// 温度值，湿度值
	float tempValue = 0, humValue = 0;
	while (1)
	{
		// 获取温湿度值
		call_sht11(&tempValue, &humValue);
		// 格式化温度显示字符串
		sprintf(showTempBuf, "Temperature:%-4.2f", tempValue);
		// 格式化湿度显示字符串
		sprintf(showHumBuf, "Humidty:%-8.2f", humValue);
		// OLED屏显示温度字符串
		OLED_ShowString(0, 0, (uint8_t *)showTempBuf);
		// OLED屏显示湿度字符串
		OLED_ShowString(0, 2, (uint8_t *)showHumBuf);
		// 延时1秒
		DelayMs(1000);
	}
}
