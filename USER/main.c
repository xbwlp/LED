#include "stm32f10x.h"
#include "mapping.h"
#include "led.h"
#include "HDL_WS2812B.h"
#include "delay.h"

#define NUMS 100
#define X 24
#define Y 34

int main(void)
{
	int Green[8];
	int Red[8];
	int Blue[8];
	
	SystemInit();
	delay_init();
	PWM_WS2812B_Init(WS2812B_ARR);
	mapp(4,2.0,3.0,60.0);
	u32 pictures[NUMS][X][Y];
	int a[6][8]= {0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,
								0x00ff00,0x00ff00,0x00ff00,0x00ff00,0x00ff00,0x00ff00,0x00ff00,0x00ff00,
								255,255,255,255,255,255,255,255,
								0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,
								0x00ff00,0x00ff00,0x00ff00,0x00ff00,0x00ff00,0x00ff00,0x00ff00,0x00ff00,
								255,255,255,255,255,255,255,255};
	
	
	
	
	while(1)
	{
		WS2812B_Reset();
		for (int j = 0;j<6;j++){
		
		for(int i=0;i<8;i++){
			
			PWM_WS2812B_All(a[j][i]);
			//PWM_WS2812B_Color(g, r, b);
		}
		delay_us(1736);
		
		WS2812B_Reset();
		//delay_us(1736);
		
		
		}
		
		//for(int i=0;i<8;i++){
			
			//PWM_WS2812B_Color(16,16,0);
			////PWM_WS2812B_Color(g, r, b);
		//}
		//delay_us(1736);
		
		
	}

}

