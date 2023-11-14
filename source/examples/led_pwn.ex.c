/*************  PWM��  START  **************/
#include "led_light.h" //����led�ƿ�
#include "gpio.h"	   //����GPIO��
#include "hal_oled.h"  //����OLED����
#include "hal_key.h"
void LedPwmExample()
{
	// OLED����ʼ��
	OLED_Init();
	// PWM�ȼ�
	char pwmLevel = 0;
	// OLED�����±�ʶ
	char isUpdateOledFlag = 1;
	// pwm�ȼ���ʾ�ַ���
	char showPwmLevelBuf[20] = {0};
	// OLED��ʾ���԰�������
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

		// KEY3 ���� PWM�ȼ�+1
		if (isKey2Pressed())
		{
			if (pwmLevel != 10)
			{
				pwmLevel++;
				isUpdateOledFlag = 1;
			}
			resetKey2();
		}
		// KEY3 ���� PWM�ȼ�-1
		if (isKey3Pressed())
		{
			if (pwmLevel != 0)
			{
				pwmLevel--;
				isUpdateOledFlag = 1;
			}
			resetKey3();
		}
		// OLED����
		if (isUpdateOledFlag)
		{
			sprintf(showPwmLevelBuf, "Pwm Level:%-7d", pwmLevel);
			OLED_ShowString(0, 2, (uint8_t *)showPwmLevelBuf);
			isUpdateOledFlag = 0;
		}
	}
}

/*************  PWM��  END   **************/