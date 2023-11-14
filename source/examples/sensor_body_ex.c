/************  人体    START **************/
#include "hal_oled.h" //导入oled库
void BodyExample()
{
    // OLED初始化
    OLED_Init();
    // 人体显示字符串
    char showBodyBuf[20] = {0};
    // 人体值
    int bodyValue = 0;
    while (1)
    {
        // 读取人体值
        bodyValue = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2);
        // 格式人体显示字符串
        sprintf(showBodyBuf, "Body:%-11d", bodyValue);
        // OLED屏显示人体字符串
        OLED_ShowString(0, 1, showBodyBuf);
        // 延时1秒
        DelayMs(1000);
    }
}
/************  人体    END   **************/