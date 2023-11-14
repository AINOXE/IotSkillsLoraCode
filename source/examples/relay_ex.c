/************ 单联继电器 START **************/
#include "hal_oled.h" //导入oled库
#include "hal_key.h"  //导入按键库
#include "gpio.h"
#include "board.h"
Gpio_t RelayGpio;		   // 继电器GPIO句柄
#define RelayBordPort PB_2 // 继电器GPIO口
void RelayExample()
{
	// OLED初始化
	OLED_Init();
	// 继电器GPIO初始化 (输出,推挽,不上下拉)
	GpioInit(&RelayGpio, RelayBordPort, PIN_OUTPUT, PIN_PUSH_PULL, PIN_NO_PULL, 0);
	// 单联继状态显示字符串
	// char showRelayStateBuf[20] = {0};
	// 显示继电器初始状态
	OLED_ShowString(0, 1, (uint8_t *)"CLOSE");
	while (1)
	{
		// 继电器开
		if (isKey2Pressed())
		{
			// 继电器IO口低电平 继电器开
			GpioWrite(&RelayGpio, 0);
			// 显示继电器状态
			OLED_ShowString(0, 1, (uint8_t *)"OPEN ");
			// 重置按键
			resetKey2();
		}
		// 继电器关
		if (isKey3Pressed())
		{
			// 继电器IO口高电平 继电器关
			GpioWrite(&RelayGpio, 1);
			// 显示继电器状态
			OLED_ShowString(0, 1, (uint8_t *)"CLOSE");
			// 重置按键
			resetKey3();
		}
	}
}

/************ 单联继电器  END  **************/
