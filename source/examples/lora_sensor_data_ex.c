
#include <string.h>
#include "board.h"
#include "hal_key.h"
#include "hal_oled.h"
#include "tim-board.h"
#include "timer_handles.h"
#include "adc_reader.h"
#include "NS_Radio.h"

char buf[50];
float tem, hum, light;
int lampState = 0;


// #define ClearCursor() OLED_ShowChar(100, cursor * 2, ' ');
void ShowMainMenu(int cursor)
{
    OLED_ShowString(32, 0, (uint8_t *)"Menu");
    OLED_ShowString(0, 2, (uint8_t *)"1.Auto Lamp");
    OLED_ShowString(0, 4, (uint8_t *)"2.Mula Lamp");
    OLED_ShowString(0, 6, (uint8_t *)"3.View Freq");
    OLED_ShowChar(100, cursor * 2, '<');
}

void ShowAutoLamp()
{
    OLED_ShowString(32, 0, (uint8_t *)"Auto Lamp");
    sprintf(buf, "Light:%-8.2f", light);
    OLED_ShowString(0, 2, (uint8_t *)buf);
    sprintf(buf, "Temp:%.2f", tem);
    OLED_ShowString(0, 4, (uint8_t *)buf);
    sprintf(buf, "Humi:%.2f", hum);
    OLED_ShowString(0, 6, (uint8_t *)buf);
}

void ShowMulaLamp()
{
    OLED_ShowString(32, 0, (uint8_t *)"Mula Lamp");
    sprintf(buf, "Lamp:%s", lampState ? "Open " : "Close");
    OLED_ShowString(0, 2, (uint8_t *)buf);
}

void ShowFreq(bool isMaster)
{
    OLED_ShowString(32, 0, (uint8_t *)"View Freq");
    OLED_ShowString(0, 2, (uint8_t *)"Freq:433001000");
    if (isMaster)
    {
        OLED_ShowCHinese(0, 4, 44);
    }
}

void ShowSelMenu()
{
    OLED_ShowString(24, 0, (uint8_t *)"Select Menu");
    OLED_ShowCHinese(48, 2, 44);
}

void app_main();
void LoRaSeneorDataExample()
{
    OLED_Init();
    NS_RadioInit(433001000, 20, 2000, 2000);
    app_main();
}

#if 1
#include "sht3x.h"

void app_main()
{
    hal_temHumInit();
    ADCS_Init();
    bool isPageEnter = 0;
    uint8_t pageId = 0;
    uint8_t cursor = 1;
    ShowMainMenu(cursor);
    while (1)
    {
        DelayMs(100);
        /*
            页面0 为主页
            后面的子页面按顺序排
        */
        /* 在这个IF中写页面进入、退出、切换的事件处理 */
        if (isKey4Pressed())
        {
            OLED_Clear();
            isPageEnter = !isPageEnter;
            pageId = isPageEnter ? cursor : 0;
            /* 在这里处理页面切换 */
            if (pageId == 0)
            {
                ShowMainMenu(cursor);
            }
            else if (pageId == 2)
            {
                ShowMulaLamp();
                buf[0] = 2;
                buf[1] = lampState;
                Radio.Send((uint8_t *)buf, 2);
            }
            else if (pageId == 3)
            {
                ShowFreq(true);
                buf[0] = 3;
                Radio.Send((uint8_t *)buf, 50);
            }
            resetKey4();
        }
        /* 下面所有代码只做 页面更新与事件处理 */
        if (pageId == 0)
        {
            if (isKey2Pressed())
            {
                OLED_ShowChar(100, cursor * 2, ' ');
                cursor = cursor == 3 ? 1 : cursor + 1;
                OLED_ShowChar(100, cursor * 2, '<');
                resetKey2();
            }

            if (isKey3Pressed())
            {
                OLED_ShowChar(100, cursor * 2, ' ');
                cursor = cursor == 1 ? 3 : cursor - 1;
                OLED_ShowChar(100, cursor * 2, '<');
                resetKey3();
            }
        }
        else if (pageId == 1)
        {
            call_sht11(&tem, &hum);
            AdcScanChannel();
            float v = AdcReadCh0();
            light = (v / 3.3) * 20000;

            GpioWrite(&Led1, light < 2000 ? 0 : 1);
            GpioWrite(&Led2, light < 2000 ? 0 : 1);
            buf[0] = 1;
            *((float *)(buf + 1)) = tem;
            *((float *)(buf + 5)) = hum;
            *((float *)(buf + 10)) = light;
            Radio.Send((uint8_t *)buf, 50);
            ShowAutoLamp();
        }
        else if (pageId == 2)
        {
            if (isKey2Pressed())
            {
                lampState = 1;
                GpioWrite(&Led1, 0);
                GpioWrite(&Led2, 0);
                resetKey2();

                buf[0] = 2;
                buf[1] = lampState;
                Radio.Send((uint8_t *)buf, 2);
            }

            if (isKey3Pressed())
            {
                lampState = 0;
                GpioWrite(&Led1, 1);
                GpioWrite(&Led2, 1);
                resetKey3();

                buf[0] = 2;
                buf[1] = lampState;
                Radio.Send((uint8_t *)buf, 2);
            }
        }
        else if (pageId == 3)
        {
        }
    }
}

#else
void app_main()
{
    uint8_t pageId = 0;
    int len;
    ShowSelMenu();
    while (1)
    {
        DelayMs(100);
        if ((len = ReadRadioRxBuffer(buf)))
        {
            OLED_Clear();
            if (pageId == 0)
            {
                ShowSelMenu();
            }
            else if (pageId == 1)
            {
                tem = *((float *)(buf + 1));
                hum = *((float *)(buf + 5));
                light = *((float *)(buf + 10));
                GpioWrite(&Led1, light < 2000 ? 0 : 1);
                GpioWrite(&Led2, light < 2000 ? 0 : 1);
                ShowAutoLamp();
            }
            else if (pageId == 2)
            {
                lampState = buf[1];
                ShowMulaLamp();
            }
            else if (pageId == 3)
            {
                ShowFreq(false);
            }
        }
    }
}

#endif
