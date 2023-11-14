/************ Timer定时器 START  ***********/
#include "tim-board.h"	   //导入开发板定时器库
#include "timer_handles.h" //导入定时器中断处理函数
#include "board.h"		   //导入开发板库

void MyTimer3Handler()
{
	// 反转LED1
	GpioToggle(&Led1);
	// 反转LED2
	GpioToggle(&Led2);
}
void TimerExample()
{
	// Time2Handle 在timer_handles.c实现 默认用来实现按键扫描
	// 在通用项目中main.c Init函数中是默认下面两行代码的
	setTimer2Callback(Time2Handler); // 设置定时器2的处理器
	Tim2McuInit(1);					 // 初始化定时器2  1毫秒中断1次
	// 设置定时器3的处理器
	// setTimer3Callback(Time3Handler);
	setTimer3Callback(MyTimer3Handler);
	// 初始化定时器3  500毫秒中断1次
	Tim3McuInit(1000);
}
/*  timer_handles.c 文件中的默认代码

	#include "timer_handles.h"
	#include "key_scaner.h"

	void Time2Handler(){
		keyScanner();
	}

	void Time3Handler(){
	}
*/
/************ Timer定时器  END  ************/