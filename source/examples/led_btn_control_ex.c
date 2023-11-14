/***********  按键控制灯 START  *************/
#include "led_light.h" //导入led灯库
#include "gpio.h"	   //导入GPIO库
#include "hal_key.h"
void LedBtnControlExample()
{
	while (1)
	{
		// KEY2按键按下判断 开灯
		if (isKey2Pressed())
		{
			GpioWrite(&Led1, 0);
			GpioWrite(&Led2, 0);
			// 按键复位
			resetKey2();
		}
		// KEY3按键按下判断  关灯
		if (isKey3Pressed())
		{
			GpioWrite(&Led1, 1);
			GpioWrite(&Led2, 1);
			// 按键复位
			resetKey3();
		}
	}
}
/***********  按键控制灯  END   *************/