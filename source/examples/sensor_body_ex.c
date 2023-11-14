/************  ����    START **************/
#include "hal_oled.h" //����oled��
void BodyExample()
{
    // OLED��ʼ��
    OLED_Init();
    // ������ʾ�ַ���
    char showBodyBuf[20] = {0};
    // ����ֵ
    int bodyValue = 0;
    while (1)
    {
        // ��ȡ����ֵ
        bodyValue = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2);
        // ��ʽ������ʾ�ַ���
        sprintf(showBodyBuf, "Body:%-11d", bodyValue);
        // OLED����ʾ�����ַ���
        OLED_ShowString(0, 1, showBodyBuf);
        // ��ʱ1��
        DelayMs(1000);
    }
}
/************  ����    END   **************/