/*********  LoRa点对点点灯 START  **********/
#include "NS_Radio.h" //导入LoRa射频库
#include "hal_oled.h" //导入OLED屏库
#include "hal_key.h"
void LoRaLedExample()
{
	// OLED屏初始化
	OLED_Init();
	// 初始化LoRa模块
	NS_RadioInit(433500000, 14, 1000, 1000);
	// LoRa接收缓存
	uint8_t loRaRxBuf[255] = {0};
	while (1)
	{
		// 按KEY2 发送开灯命令
		if (isKey2Pressed())
		{
			// LoRa射频发送
			Radio.Send((uint8_t *)"1", 1);
			GpioWrite(&Led1, 0);
			resetKey2();
		}
		// 按KEY3 发送关灯命令
		if (isKey3Pressed())
		{
			// LoRa射频发送
			Radio.Send((uint8_t *)"0", 1);
			GpioWrite(&Led1, 1);
			resetKey3();
		}
		// LoRa射频接收
		if (ReadRadioRxBuffer((uint8_t *)loRaRxBuf))
		{
			// OLED屏显示接收的内容
			OLED_ShowString(0, 0, loRaRxBuf);
			// 接收到‘1’开灯
			if (loRaRxBuf[0] == '1')
			{
				GpioWrite(&Led1, 0);
			}
			// 接收到‘0’关灯
			if (loRaRxBuf[0] == '0')
			{
				GpioWrite(&Led1, 1);
			}
			// 清空接收的数据
			memset(loRaRxBuf, 0, 255);
		}
	}
}
/*********  LoRa点对点点灯 END  **********/