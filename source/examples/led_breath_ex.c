/*************  ������ START  **************/
#include "led_light.h" //����led�ƿ�
#include "gpio.h"	   //����GPIO��
void LedBreathExample()
{
	// ���ú����Ʋ���
	setBreathLedArg(54, 250);
	// ��һ�ε��÷�ת ���ǿ�
	switchLed1Breath();
	switchLed2Breath();
	// �򿪺�����
	startLedBreath();
	while (1)
	{
		// �����Ʒ�����
		breathLed();
	}
}

/*************  ������  END   **************/