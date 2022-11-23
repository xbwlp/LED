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
	u32 a[1][15][8]= {0,0,0,0,255*256,255*256,0,0,
		0,0,0,255*256,255*256,0,0,0,
		0,0,255*256,255*256,0,0,0,0,
		0,255*256,255*256,255,255,255,255,255,
		255,255,255,255,255,255,255,255,
		0,0,0,0,0,0,0,0,
		0,0,255*256*256,0,0,0,0,0,
		0,255,255,0,0,0,0,0,
		255,0,255,0,0,0,0,0,
		0,0,255,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0
		
		
		
		};
	
	
	
	
	while(1)
	{
		for(int k = 0; k<1;k++){
		WS2812B_Reset();
		for (int j = 0;j<15;j++){
		
		for(int i=0;i<8;i++){
			
			PWM_WS2812B_All(a[k][j][i]);
			//PWM_WS2812B_Color(g, r, b);
		}
		delay_us(500);
		
		WS2812B_Reset();
		
		
		}
		for(int i=0;i<8;i++){
			
			PWM_WS2812B_All(0);
			//PWM_WS2812B_Color(g, r, b);
		}
		WS2812B_Reset();
		//delay_us(1736);
		
		for(int i=0;i<35;i++){
		    delay_us(500);
		}
		}
		
		
		
		
	}

}

