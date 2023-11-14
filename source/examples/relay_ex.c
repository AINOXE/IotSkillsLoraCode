/************ �����̵��� START **************/
#include "hal_oled.h" //����oled��
#include "hal_key.h"  //���밴����
#include "gpio.h"
#include "board.h"
Gpio_t RelayGpio;		   // �̵���GPIO���
#define RelayBordPort PB_2 // �̵���GPIO��
void RelayExample()
{
	// OLED��ʼ��
	OLED_Init();
	// �̵���GPIO��ʼ�� (���,����,��������)
	GpioInit(&RelayGpio, RelayBordPort, PIN_OUTPUT, PIN_PUSH_PULL, PIN_NO_PULL, 0);
	// ������״̬��ʾ�ַ���
	// char showRelayStateBuf[20] = {0};
	// ��ʾ�̵�����ʼ״̬
	OLED_ShowString(0, 1, (uint8_t *)"CLOSE");
	while (1)
	{
		// �̵�����
		if (isKey2Pressed())
		{
			// �̵���IO�ڵ͵�ƽ �̵�����
			GpioWrite(&RelayGpio, 0);
			// ��ʾ�̵���״̬
			OLED_ShowString(0, 1, (uint8_t *)"OPEN ");
			// ���ð���
			resetKey2();
		}
		// �̵�����
		if (isKey3Pressed())
		{
			// �̵���IO�ڸߵ�ƽ �̵�����
			GpioWrite(&RelayGpio, 1);
			// ��ʾ�̵���״̬
			OLED_ShowString(0, 1, (uint8_t *)"CLOSE");
			// ���ð���
			resetKey3();
		}
	}
}

/************ �����̵���  END  **************/
