/************  FLASH  START  **************/
#include "hal_oled.h"							 //����oled��
#include "hal_key.h"							 //���밴����
#include "gpio.h"								 //����gpio��
#include "flash.h"								 //����Flash��
#define FLASH_START_RESERVED_ADDRESS 0x800E000	 // FLASH ��ʼ������ַ
#define FLASH_RESERVED_LENGTH 10				 // FLASH �����ռ��С
#define FLASH_IS_INITED_FLAG_OFFSET_ADDR 0		 // ��ʼ����־ FLASH ƫ�Ƶ�ַ
#define FLASH_NUM_COUNTER_OFFSET_ADDR 1			 // ������ֵ FLASH ƫ�Ƶ�ַ
#define FLASH_IS_INITED 10						 // FLASH �Ѿ���ʼ�ı�ʶֵ
#define FLASH_INIT_NUM_COUNTER_VALUE 213		 // ��������ʼ��ֵ
uint32_t FlashData[FLASH_RESERVED_LENGTH] = {0}; // FLASH ӳ�䵽 RAM �е�����

void FlashExample()
{
	char showCounterValueBuf[20] = {0}; // ��ʾ������ֵ���ַ���
	OLED_Init();						// OLED����ʼ��
	OLED_ShowString(0, 0, (uint8_t *)"Flash Test");

	char isUpdateOledFlag = 1; // �Ƿ����OLED����־
	// ��ȡ������ FLASH �� RAM ��ӳ��������
	STMFLASH_Read(FLASH_START_RESERVED_ADDRESS, FlashData, FLASH_RESERVED_LENGTH);
	// �ж��Ƿ�δ��ʼ�� FLASH
	if (FlashData[FLASH_IS_INITED_FLAG_OFFSET_ADDR] != FLASH_IS_INITED)
	{																			 // ��ʼ�� FLASH
		FlashData[FLASH_IS_INITED_FLAG_OFFSET_ADDR] = FLASH_IS_INITED;			 // ���ó�ʼ����ʶΪ�ѳ�ʼ��
		FlashData[FLASH_NUM_COUNTER_OFFSET_ADDR] = FLASH_INIT_NUM_COUNTER_VALUE; // ���ü�������ʼֵ
		// ͬ���� FLASH ��
		STMFLASH_Write(FLASH_START_RESERVED_ADDRESS, FlashData, FLASH_RESERVED_LENGTH);
	}
	while (1)
	{
		if (isUpdateOledFlag)
		{ // OLED����
			sprintf(showCounterValueBuf, "Counter:%-8d", FlashData[FLASH_NUM_COUNTER_OFFSET_ADDR]);
			OLED_ShowString(0, 2, (uint8_t *)showCounterValueBuf);
			isUpdateOledFlag = 0;
		}
		if (isKey2Pressed())
		{ // ������ֵ��
			FlashData[FLASH_NUM_COUNTER_OFFSET_ADDR]++;
			isUpdateOledFlag = 1;
			resetKey2();
		}
		if (isKey3Pressed())
		{ // ������ֵ��
			FlashData[FLASH_NUM_COUNTER_OFFSET_ADDR]--;
			isUpdateOledFlag = 1;
			resetKey3();
		}
		if (isKey4Pressed())
		{ // ������ֵͬ���� FLASH ��
			STMFLASH_Write(FLASH_START_RESERVED_ADDRESS, FlashData, FLASH_RESERVED_LENGTH);
		}
	}
}
/************  FLASH   END   **************/