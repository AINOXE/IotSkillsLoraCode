/************ ������˸�� START  *************/
#include "led_light.h" //����led�ƿ�
#include "gpio.h"	   //����GPIO��
void AlternateBlinkLedExample()
{
	// ����������˸��
	startLedBlink();
	while (1)
	{
		// ִ�н�����˸�Ʒ���
		blinkPerHelfSecond();
		// ��ʱ�Խ�����˸�ƷŴ�50�� ����ʱ��=(��ʱ+ѭ��һ����������ִ��ʱ��)*50
		DelayMs(2);
	}
}
/************ ������˸��  END   *************/