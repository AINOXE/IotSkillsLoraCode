/* Includes ------------------------------------------------------------------*/
#include "led_light.h"

#define LED_ILLUMINATION_LEVEL 8
#define LED_LEVEL_TIMER				LED_ILLUMINATION_LEVEL/2
#define DEVIDE_VALUE 16

uint8_t levelCount = LED_ILLUMINATION_LEVEL;    //等级长度
uint8_t led_levet_timer = LED_LEVEL_TIMER;      //等级最大存活时间
uint8_t devideCount = DEVIDE_VALUE;             //PWM等级改变计数器最大值
uint8_t level = 1;                              //PWM等级
uint8_t timeTic = 0;                            //PWM周期计数器
bool isUprise = true;                           //PWM等级改变方向 true提升，false降低
bool isLed1BreathEnable = false;                //LED1呼吸灯开关
bool isLed2BreathEnable = false;                //LED2呼吸灯开关
//设置呼吸灯参数                等级长度        等级改变时间         
void setBreathLedArg(uint8_t levelCnt, uint8_t levelUpDevide){
	levelCount = levelCnt;
	led_levet_timer = levelCount/2;
	devideCount = levelUpDevide;
}
//一个周期已结束，PWM周期复位
void resetLedPwm() {
    timeTic = 0;
    if (isLed1BreathEnable)
        GpioWrite( &Led1, 0 );
    if (isLed2BreathEnable)
        GpioWrite( &Led2, 0 );
}
//PWM等级改变函数
void pwmLevelUp() {
    //Led PWM的每个等级的存活计时间数器
    static unsigned long led_level_tick = 0; 
    //存活计时间数器+1
    led_level_tick++;
    //存活计时间数器>最大存活时间次数   (默认最大存活时间次数=PWM等级量/2)
    if (led_level_tick > led_levet_timer) {     //到了最大存活时间
        led_level_tick = 0;                     //存活时间计数器复位
        if (isUprise)                           //是否是提升PWM等级
            level++;                            //提升PWM等级
        else
            level--;                            //降低PWM等级
        if (level > levelCount) {               //PWM等级达到最高
            level = levelCount;                 //等级设置成最大值
            isUprise = false;                   //设置为降低等级方向
        } else if (level == 0) {                //PWM等级达到最小
            isUprise = true;                    //设置为提升等级方向
        }
    }
}
//PWM实现函数
void pwm() {
    timeTic++;                          //PWM等级改变计数器+1
    if (timeTic > level) {              //等级计数器值大于设置值
        if (isLed1BreathEnable)         //判断LED1是否开启PWM
            GpioWrite( &Led1, 1 );      //LED1开
        if (isLed2BreathEnable)         //判断LED1是否开启PWM
            GpioWrite( &Led2, 1 );      //LED2开
    }
    if (timeTic > levelCount) {         //PWM等级改变计数器>最大等级
        resetLedPwm();                  //一个PWM周期结束执行，LED、PWM等级改变计数器复位
    }
}

uint8_t timeDevice = 0;
//呼吸灯核心函数
void breathLed() {
    timeDevice++;                       //呼吸灯亮度切换计数器1
    if (timeDevice >= devideCount) {    //计数器值大于设置值
        timeDevice = 0;                 //计数器复位
        pwmLevelUp();                   //改变亮度
    }
    pwm();                              //PWM周期
}
//反转LED1呼吸灯开关
void switchLed1Breath() {
    isLed1BreathEnable = !isLed1BreathEnable;
}
//反转LED2呼吸灯开光
void switchLed2Breath() {
    isLed2BreathEnable = !isLed2BreathEnable;
}
//开启呼吸灯
void startLedBreath() {
    isLed1BreathEnable = true;
    isLed2BreathEnable = true;
    GpioWrite( &Led1, 1 );
    GpioWrite( &Led2, 1 );
}
//停止呼吸灯
void stopLedBreath() {
    isLed1BreathEnable = false;
    isLed2BreathEnable = false;
    GpioWrite( &Led1, 1 );
    GpioWrite( &Led2, 1 );
}

#define HELF_SECOND 50
uint16_t helfSecondCnt = 0;
bool isLed1Lighted = true;
bool isHelfSecondLedBlinkEnable = false;
void blinkPerHelfSecond() {
    if (!isHelfSecondLedBlinkEnable)
        return;

    helfSecondCnt ++;
    if (helfSecondCnt > HELF_SECOND) {
        helfSecondCnt = 0;
        isLed1Lighted = !isLed1Lighted;
    }

    if (isLed1Lighted) {
        GpioWrite( &Led1, 0 );
        GpioWrite( &Led2, 1 );
    }
    else {
        GpioWrite( &Led1, 1 );
        GpioWrite( &Led2, 0 );
    }
}

void startLedBlink() {
    isHelfSecondLedBlinkEnable = true;
    GpioWrite( &Led1, 1 );
    GpioWrite( &Led2, 1 );
}

void stopLedBlink() {
    isHelfSecondLedBlinkEnable = false;
    GpioWrite( &Led1, 1 );
    GpioWrite( &Led2, 1 );
}
