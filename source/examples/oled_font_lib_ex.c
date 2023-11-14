/*************  OLED�� START **************/
#include "hal_oled.h" //����OLED����
#include "gpio.h"	  //����GPIO��
#include "hal_key.h"
void OledFontLibExample()
{
	// OLED����ʼ��
	OLED_Init();
	// �ֿ�����
	uint8_t charLibIdx = 0;
	// OLED��Ļ���±�ʶ
	char isUpdateOledFlag = 1;
	// ��ʾ�ֿ������ַ���
	char showCharLibIdxBuf[20] = {0};
	// ���Ե������ַ�
	char testChineseChar[][32]={
		/*--  ����:  ��  --*/
		/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=16x16   --*/
		0x00,0x00,0xF8,0x49,0x4A,0x4C,0x48,0xF8,0x48,0x4C,0x4A,0x49,0xF8,0x00,0x00,0x00,
		0x10,0x10,0x13,0x12,0x12,0x12,0x12,0xFF,0x12,0x12,0x12,0x12,0x13,0x10,0x10,0x00,
		/*--  ����:  Ƭ  --*/
		/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=16x16   --*/
		0x00,0x00,0x00,0xFE,0x20,0x20,0x20,0x20,0x20,0x3F,0x20,0x20,0x20,0x20,0x00,0x00,
		0x00,0x80,0x60,0x1F,0x02,0x02,0x02,0x02,0x02,0x02,0xFE,0x00,0x00,0x00,0x00,0x00,
		/*--  ����:  ��  --*/
		/*--  ����12;  �������¶�Ӧ�ĵ���Ϊ����x��=16x16   --*/
		0x10,0x10,0xD0,0xFF,0x90,0x10,0x00,0xFE,0x02,0x02,0x02,0xFE,0x00,0x00,0x00,0x00,
		0x04,0x03,0x00,0xFF,0x00,0x83,0x60,0x1F,0x00,0x00,0x00,0x3F,0x40,0x40,0x78,0x00,
	};
	// ��ʾ��1�����Ե������ַ� ��
	OLED_ShowCHineseArray(0, 6, testChineseChar[0]);
	// ��ʾ��2�����Ե������ַ� Ƭ
	OLED_ShowCHineseArray(16, 6, testChineseChar[1]);
	// ��ʾ��3�����Ե������ַ� ��
	OLED_ShowCHineseArray(32, 6, testChineseChar[2]);

	while (1)
	{
		// OLED������
		if (isUpdateOledFlag)
		{
			// ��ʽ���ֿ�������ʾ�ַ���
			sprintf(showCharLibIdxBuf, "Index:%-10d", charLibIdx);
			// OLED��ʾ�ֿ�������ʾ�ַ���
			OLED_ShowString(0, 0, (uint8_t *)showCharLibIdxBuf);
			OLED_ShowString(0, 2, (uint8_t *)"Value:");
			// �����ֿ�������ʾ�ַ�
			OLED_ShowCHinese(48, 2, charLibIdx);
			// ��ʾ����
			OLED_ShowNum(0, 4, charLibIdx, 2, 16);
		}
		// �ֿ�����+1
		if (isKey2Pressed())
		{
			if (charLibIdx != 51)
			{
				charLibIdx++;
				isUpdateOledFlag = 1;
			}
			resetKey2();
		}
		// �ֿ�����-1
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

/*************  OLED��  END  **************/