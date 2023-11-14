/************  FLASH  START  **************/
#include "hal_oled.h"							 //导入oled库
#include "hal_key.h"							 //导入按键库
#include "gpio.h"								 //导入gpio库
#include "flash.h"								 //导入Flash库
#define FLASH_START_RESERVED_ADDRESS 0x800E000	 // FLASH 起始保留地址
#define FLASH_RESERVED_LENGTH 10				 // FLASH 保留空间大小
#define FLASH_IS_INITED_FLAG_OFFSET_ADDR 0		 // 初始化标志 FLASH 偏移地址
#define FLASH_NUM_COUNTER_OFFSET_ADDR 1			 // 计数器值 FLASH 偏移地址
#define FLASH_IS_INITED 10						 // FLASH 已经初始的标识值
#define FLASH_INIT_NUM_COUNTER_VALUE 213		 // 计数器初始化值
uint32_t FlashData[FLASH_RESERVED_LENGTH] = {0}; // FLASH 映射到 RAM 中的数组

void FlashExample()
{
	char showCounterValueBuf[20] = {0}; // 显示计数器值的字符串
	OLED_Init();						// OLED屏初始化
	OLED_ShowString(0, 0, (uint8_t *)"Flash Test");

	char isUpdateOledFlag = 1; // 是否更新OLED屏标志
	// 读取保留区 FLASH 到 RAM 的映射数组中
	STMFLASH_Read(FLASH_START_RESERVED_ADDRESS, FlashData, FLASH_RESERVED_LENGTH);
	// 判断是否未初始化 FLASH
	if (FlashData[FLASH_IS_INITED_FLAG_OFFSET_ADDR] != FLASH_IS_INITED)
	{																			 // 初始化 FLASH
		FlashData[FLASH_IS_INITED_FLAG_OFFSET_ADDR] = FLASH_IS_INITED;			 // 设置初始化标识为已初始化
		FlashData[FLASH_NUM_COUNTER_OFFSET_ADDR] = FLASH_INIT_NUM_COUNTER_VALUE; // 设置计数器初始值
		// 同步到 FLASH 中
		STMFLASH_Write(FLASH_START_RESERVED_ADDRESS, FlashData, FLASH_RESERVED_LENGTH);
	}
	while (1)
	{
		if (isUpdateOledFlag)
		{ // OLED更新
			sprintf(showCounterValueBuf, "Counter:%-8d", FlashData[FLASH_NUM_COUNTER_OFFSET_ADDR]);
			OLED_ShowString(0, 2, (uint8_t *)showCounterValueBuf);
			isUpdateOledFlag = 0;
		}
		if (isKey2Pressed())
		{ // 计数器值加
			FlashData[FLASH_NUM_COUNTER_OFFSET_ADDR]++;
			isUpdateOledFlag = 1;
			resetKey2();
		}
		if (isKey3Pressed())
		{ // 计数器值减
			FlashData[FLASH_NUM_COUNTER_OFFSET_ADDR]--;
			isUpdateOledFlag = 1;
			resetKey3();
		}
		if (isKey4Pressed())
		{ // 计数器值同步到 FLASH 中
			STMFLASH_Write(FLASH_START_RESERVED_ADDRESS, FlashData, FLASH_RESERVED_LENGTH);
		}
	}
}
/************  FLASH   END   **************/