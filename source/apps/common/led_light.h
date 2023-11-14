/* Includes ------------------------------------------------------------------*/

#ifndef __LED_LIGHT_H
#define __LED_LIGHT_H

#include "stm32l1xx_hal.h"
#include "board.h"

#ifdef __cplusplus
extern "C" {
#endif
//设置呼吸灯参数                等级长度            等级改变时间         
void setBreathLedArg(uint8_t levelCnt, uint8_t levelUpDevide);
//PWM等级改变函数
void pwmLevelUp(void);
//PWM实现函数
void pwm(void);
//反转LED1呼吸灯开关
void switchLed1Breath(void);
//反转LED2呼吸灯开关
void switchLed2Breath(void);
//呼吸灯核心函数
void breathLed(void);
//开启呼吸灯
void startLedBreath(void);
//停止呼吸灯
void stopLedBreath(void);

void blinkPerHelfSecond(void);
void startLedBlink(void);
void stopLedBlink(void);

#ifdef __cplusplus
}
#endif

#endif /* __LED_LIGHT_H */


