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
 *函数：void Init( void )
 *功能：平台初始化
 *输入：无
 *输出：无
 *特殊说明：无
 **********************************************************************************************/
void Init()
{
	// 开发板平台初始化
	BoardInitMcu();
	BoardInitPeriph();
	keys_init(); // 按键初始化
	setTimer2Callback(Time2Handler);
	Tim2McuInit(1); // 定时器初始化，设置定时中断1ms中断一次

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
 *函数：void KeyDownHandler( void )
 *功能：按钮事件监听
 *输入：无
 *输出：无
 *特殊说明：无
 **********************************************************************************************/
void KeyDownHandler(void)
{
}

/**********************************************************************************************
 *函数：void handlerPre10Ms( void )
 *功能：10毫秒循环
 *输入：无
 *输出：无
 *特殊说明：循环处理总时长300ms
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
	Init(); /* 案例代码在Init中 */
	while (1)
	{
	}
}
