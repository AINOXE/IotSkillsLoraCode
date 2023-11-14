/************ 交替闪烁灯 START  *************/
#include "led_light.h" //导入led灯库
#include "gpio.h"	   //导入GPIO库
void AlternateBlinkLedExample()
{
	// 开启交替闪烁灯
	startLedBlink();
	while (1)
	{
		// 执行交替闪烁灯服务
		blinkPerHelfSecond();
		// 延时对交替闪烁灯放大50倍 交替时间=(延时+循环一次其他代码执行时间)*50
		DelayMs(2);
	}
}
/************ 交替闪烁灯  END   *************/