/*************  OLED屏 START **************/
#include "hal_oled.h" //导入OLED屏库
#include "gpio.h"	  //导入GPIO库
#include "hal_key.h"
void OledFontLibExample()
{
	// OLED屏初始化
	OLED_Init();
	// 字库索引
	uint8_t charLibIdx = 0;
	// OLED屏幕更新标识
	char isUpdateOledFlag = 1;
	// 显示字库索引字符串
	char showCharLibIdxBuf[20] = {0};
	// 测试的中文字符
	char testChineseChar[][32]={
		/*--  文字:  单  --*/
		/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
		0x00,0x00,0xF8,0x49,0x4A,0x4C,0x48,0xF8,0x48,0x4C,0x4A,0x49,0xF8,0x00,0x00,0x00,
		0x10,0x10,0x13,0x12,0x12,0x12,0x12,0xFF,0x12,0x12,0x12,0x12,0x13,0x10,0x10,0x00,
		/*--  文字:  片  --*/
		/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
		0x00,0x00,0x00,0xFE,0x20,0x20,0x20,0x20,0x20,0x3F,0x20,0x20,0x20,0x20,0x00,0x00,
		0x00,0x80,0x60,0x1F,0x02,0x02,0x02,0x02,0x02,0x02,0xFE,0x00,0x00,0x00,0x00,0x00,
		/*--  文字:  机  --*/
		/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
		0x10,0x10,0xD0,0xFF,0x90,0x10,0x00,0xFE,0x02,0x02,0x02,0xFE,0x00,0x00,0x00,0x00,
		0x04,0x03,0x00,0xFF,0x00,0x83,0x60,0x1F,0x00,0x00,0x00,0x3F,0x40,0x40,0x78,0x00,
	};
	// 显示第1个测试的中文字符 单
	OLED_ShowCHineseArray(0, 6, testChineseChar[0]);
	// 显示第2个测试的中文字符 片
	OLED_ShowCHineseArray(16, 6, testChineseChar[1]);
	// 显示第3个测试的中文字符 机
	OLED_ShowCHineseArray(32, 6, testChineseChar[2]);

	while (1)
	{
		// OLED屏更新
		if (isUpdateOledFlag)
		{
			// 格式化字库索引显示字符串
			sprintf(showCharLibIdxBuf, "Index:%-10d", charLibIdx);
			// OLED显示字库索引显示字符串
			OLED_ShowString(0, 0, (uint8_t *)showCharLibIdxBuf);
			OLED_ShowString(0, 2, (uint8_t *)"Value:");
			// 根据字库索引显示字符
			OLED_ShowCHinese(48, 2, charLibIdx);
			// 显示数字
			OLED_ShowNum(0, 4, charLibIdx, 2, 16);
		}
		// 字库索引+1
		if (isKey2Pressed())
		{
			if (charLibIdx != 51)
			{
				charLibIdx++;
				isUpdateOledFlag = 1;
			}
			resetKey2();
		}
		// 字库索引-1
		if (isKey3Pressed())
		{
			if (charLibIdx != 0)
			{
				charLibIdx--;
				isUpdateOledFlag = 1;
			}
			resetKey3();
		}
	}
}

/*************  OLED屏  END  **************/