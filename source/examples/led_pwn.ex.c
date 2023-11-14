/*************  PWM灯  START  **************/
#include "led_light.h" //导入led灯库
#include "gpio.h"	   //导入GPIO库
#include "hal_oled.h"  //导入OLED屏库
#include "hal_key.h"
void LedPwmExample()
{
	// OLED屏初始化
	OLED_Init();
	// PWM等级
	char pwmLevel = 0;
	// OLED屏更新标识
	char isUpdateOledFlag = 1;
	// pwm等级显示字符串
	char showPwmLevelBuf[20] = {0};
	// OLED显示测试案例名称
	OLED_ShowString(0, 0, (uint8_t *)"Pwm Led Test");
	while (1)
	{
		/*******     PWM   START     *******/
		for (size_t i = 0; i < 10; i++)
		{
			if (i < pwmLevel)
			{
				GpioWrite(&Led1, 0);
			}
			else
			{
				GpioWrite(&Led1, 1);
			}
		}
		/*******     PWM    END      *******/

		// KEY3 按下 PWM等级+1
		if (isKey2Pressed())
		{
			if (pwmLevel != 10)
			{
				pwmLevel++;
				isUpdateOledFlag = 1;
			}
			resetKey2();
		}
		// KEY3 按下 PWM等级-1
		if (isKey3Pressed())
		{
			if (pwmLevel != 0)
			{
				pwmLevel--;
				isUpdateOledFlag = 1;
			}
			resetKey3();
		}
		// OLED更新
		if (isUpdateOledFlag)
		{
			sprintf(showPwmLevelBuf, "Pwm Level:%-7d", pwmLevel);
			OLED_ShowString(0, 2, (uint8_t *)showPwmLevelBuf);
			isUpdateOledFlag = 0;
		}
	}
}

/*************  PWM灯  END   **************/