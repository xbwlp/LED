#ifndef _HDL_WS2812B_H
#define _HDL_WS2812B_H

#include "stm32f10x.h"

#define WS2812B_PIN    GPIO_Pin_1
#define WS2812B_PORT   GPIOA
#define WS2812B_HIGH   GPIO_SetBits(WS2812B_PORT,WS2812B_PIN)
#define WS2812B_LOW	   GPIO_ResetBits(WS2812B_PORT,WS2812B_PIN)
/*	����DataSheet����0/1�����Ӧ�ĸߵ�ƽ�Ƚ�ֵ����Ϊ�ߵ�ƽ��ǰ������ߵ�ƽ�ļ���
**	�ߵ͵�ƽ�ı���ԼΪ2:1
*/
#define WS2812B_ARR 90		//TIM2���Զ���װ��ֵ
#define T0H 30						//0����ߵ�ƽʱ��ռ1/3
#define T1H 60						//1����ߵ�ƽʱ��ռ2/3

/* �������ĸ��� */
#define LED_NUM  100		//�ײ�����δ�ã�ΪӦ�÷��㣬�ȼ���
#define DATA_SIZE  24 	    //WS2812Bһ�������bit����3*8

void PWM_WS2812B_Init(uint16_t arr);
void WS2812B_Reset(void);
void PWM_WS2812B_Write_24Bits(uint16_t num,uint32_t GRB_Data);
void PWM_WS2812B_Show(uint16_t num);
void PWM_WS2812B_Red(uint16_t num);
void PWM_WS2812B_Green(uint16_t num);
void PWM_WS2812B_Blue(uint16_t num);

#endif
