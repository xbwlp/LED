#include "stm32f10x.h"
#include "mapping.h"
#include "led.h"
#include "HDL_WS2812B.h"
#include "delay.h"

int main(void)
{
	int Green[8];
	int Red[8];
	int Blue[8];
	
	SystemInit();
	delay_init();
	PWM_WS2812B_Init(WS2812B_ARR);
	mapp(4,2.0,3.0,60.0);
	while(1)
	{
		WS2812B_Reset();
		
		for(int i=0;i<8;i++){
			
			PWM_WS2812B_Color(1,Green[i], Red[i], Blue[i]);
			//PWM_WS2812B_Color(1, g, r, b);
		}
		
		
	}

}

