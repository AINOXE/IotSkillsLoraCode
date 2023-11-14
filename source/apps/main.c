/**
 ******************************************************************************
 * File Name          : main.c
 * Description        : Main program body
 ******************************************************************************
 */
#include <string.h>
#include "board.h"
#include "hal_key.h"
#include "tim-board.h"
#include "timer_handles.h"
#include "lzyx_examples.h"

/**********************************************************************************************
 *������void Init( void )
 *���ܣ�ƽ̨��ʼ��
 *���룺��
 *�������
 *����˵������
 **********************************************************************************************/
void Init()
{
	// ������ƽ̨��ʼ��
	BoardInitMcu();
	BoardInitPeriph();
	keys_init(); // ������ʼ��
	setTimer2Callback(Time2Handler);
	Tim2McuInit(1); // ��ʱ����ʼ�������ö�ʱ�ж�1ms�ж�һ��

	// TemplateHumidtyExample();
	// LightExample();
	// FireExample();
	// BodyExample();
	// AirQualityExample();
	// MethaneExample();
	// RelayExample();
	// FlashExample();
	// UartExample();
	// TimerExample();
	// LedAlternateBlinkExample();
	// LedBtnControlExample();
	// LedBreathExample();
	// LedPwmExample();
	// OledFontLibExample();
	OledDateExample();
	// LoRaLedExample();
	// LoRaP2PSerialPortTransparentTransmissionExample();
}

/**********************************************************************************************
 *������void KeyDownHandler( void )
 *���ܣ���ť�¼�����
 *���룺��
 *�������
 *����˵������
 **********************************************************************************************/
void KeyDownHandler(void)
{
}

/**********************************************************************************************
 *������void handlerPre10Ms( void )
 *���ܣ�10����ѭ��
 *���룺��
 *�������
 *����˵����ѭ��������ʱ��300ms
 **********************************************************************************************/
void handlerPre10Ms(void)
{
	for (int delay = 0; delay < 30; delay++)
	{
		HAL_Delay(10);
	}
}

/**
 * Main application entry point.
 */
int main(void)
{
	Init(); /* ����������Init�� */
	while (1)
	{
	}
}
