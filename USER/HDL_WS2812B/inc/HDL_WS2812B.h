#ifndef _HDL_WS2812B_H
#define _HDL_WS2812B_H

#include "stm32f10x.h"

#define WS2812B_PIN    GPIO_Pin_1
#define WS2812B_PORT   GPIOA
#define WS2812B_HIGH   GPIO_SetBits(WS2812B_PORT,WS2812B_PIN)
#define WS2812B_LOW	   GPIO_ResetBits(WS2812B_PORT,WS2812B_PIN)
/*	根据DataSheet定义0/1编码对应的高电平比较值，因为高电平在前，定义高电平的即可
**	高低电平的比例约为2:1
*/
#define WS2812B_ARR 90		//TIM2的自动重装载值
#define T0H 30						//0编码高电平时间占1/3
#define T1H 60						//1编码高电平时间占2/3

/* 灯珠亮的个数 */
#define LED_NUM  100		//底层驱动未用，为应用方便，先加上
#define DATA_SIZE  24 	    //WS2812B一个编码的bit数，3*8

void PWM_WS2812B_Init(uint16_t arr);
void WS2812B_Reset(void);
void PWM_WS2812B_Write_24Bits(uint16_t num,uint32_t GRB_Data);
void PWM_WS2812B_Show(uint16_t num);
void PWM_WS2812B_Red(uint16_t num);
void PWM_WS2812B_Green(uint16_t num);
void PWM_WS2812B_Blue(uint16_t num);

#endif
