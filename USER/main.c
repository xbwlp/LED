#include "stm32f10x.h"
#include "mapping.h"
#include "led.h"
#include "HDL_WS2812B.h"
#include "delay.h"

int main(void)
{
	SystemInit();
	delay_init();
	PWM_WS2812B_Init(WS2812B_ARR);
	while(1)
	{
		WS2812B_Reset();
		PWM_WS2812B_Red(1);		//灯珠个数可修改
		PWM_WS2812B_Green(1);
		PWM_WS2812B_Blue(1);
	}

}

