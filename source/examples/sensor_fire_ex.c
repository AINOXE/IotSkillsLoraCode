/************  火焰案例 START **************/
#include "hal_oled.h" //导入oled库
void FireExample()
{
	// OLED初始化
	OLED_Init();
	// 火焰符串
	char showFireBuf[20] = {0};
	// 火焰值
	int fireValue = 0;

	while (1)
	{
		// 读取火焰值
		fireValue = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
		sprintf(showFireBuf, "Fire:%-11d", fireValue);
		// OLED屏显示光照字符串
		OLED_ShowString(0, 1, showFireBuf);
		// 延时1秒
		DelayMs(1000);
	}
}
/************  火焰案例  END  **************/