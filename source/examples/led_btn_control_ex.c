/***********  �������Ƶ� START  *************/
#include "led_light.h" //����led�ƿ�
#include "gpio.h"	   //����GPIO��
#include "hal_key.h"
void LedBtnControlExample()
{
	while (1)
	{
		// KEY2���������ж� ����
		if (isKey2Pressed())
		{
			GpioWrite(&Led1, 0);
			GpioWrite(&Led2, 0);
			// ������λ
			resetKey2();
		}
		// KEY3���������ж�  �ص�
		if (isKey3Pressed())
		{
			GpioWrite(&Led1, 1);
			GpioWrite(&Led2, 1);
			// ������λ
			resetKey3();
		}
	}
}
/***********  �������Ƶ�  END   *************/