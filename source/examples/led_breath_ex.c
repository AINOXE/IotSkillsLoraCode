/*************  呼吸灯 START  **************/
#include "led_light.h" //导入led灯库
#include "gpio.h"	   //导入GPIO库
void LedBreathExample()
{
	// 设置呼吸灯参数
	setBreathLedArg(54, 250);
	// 第一次调用反转 就是开
	switchLed1Breath();
	switchLed2Breath();
	// 打开呼吸灯
	startLedBreath();
	while (1)
	{
		// 呼吸灯服务函数
		breathLed();
	}
}

/*************  呼吸灯  END   **************/