/************  ���永�� START **************/
#include "hal_oled.h" //����oled��
void FireExample()
{
	// OLED��ʼ��
	OLED_Init();
	// �������
	char showFireBuf[20] = {0};
	// ����ֵ
	int fireValue = 0;

	while (1)
	{
		// ��ȡ����ֵ
		fireValue = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
		sprintf(showFireBuf, "Fire:%-11d", fireValue);
		// OLED����ʾ�����ַ���
		OLED_ShowString(0, 1, showFireBuf);
		// ��ʱ1��
		DelayMs(1000);
	}
}
/************  ���永��  END  **************/