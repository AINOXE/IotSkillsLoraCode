/************ Timer��ʱ�� START  ***********/
#include "tim-board.h"	   //���뿪���嶨ʱ����
#include "timer_handles.h" //���붨ʱ���жϴ�����
#include "board.h"		   //���뿪�����

void MyTimer3Handler()
{
	// ��תLED1
	GpioToggle(&Led1);
	// ��תLED2
	GpioToggle(&Led2);
}
void TimerExample()
{
	// Time2Handle ��timer_handles.cʵ�� Ĭ������ʵ�ְ���ɨ��
	// ��ͨ����Ŀ��main.c Init��������Ĭ���������д����
	setTimer2Callback(Time2Handler); // ���ö�ʱ��2�Ĵ�����
	Tim2McuInit(1);					 // ��ʼ����ʱ��2  1�����ж�1��
	// ���ö�ʱ��3�Ĵ�����
	// setTimer3Callback(Time3Handler);
	setTimer3Callback(MyTimer3Handler);
	// ��ʼ����ʱ��3  500�����ж�1��
	Tim3McuInit(1000);
}
/*  timer_handles.c �ļ��е�Ĭ�ϴ���

	#include "timer_handles.h"
	#include "key_scaner.h"

	void Time2Handler(){
		keyScanner();
	}

	void Time3Handler(){
	}
*/
/************ Timer��ʱ��  END  ************/