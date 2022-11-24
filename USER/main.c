#include "stm32f10x.h"
#include "mapping.h"
#include "led.h"
#include "HDL_WS2812B.h"
#include "delay.h"
#include <math.h>

#define NUMS 1
#define ROWS 15
#define COLUMNS 8
#define DELAY 200

int num;

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



int main(void)
{
	int Green[8];
	int Red[8];
	int Blue[8];
	
	SystemInit();
	delay_init();
	PWM_WS2812B_Init(WS2812B_ARR);
	//mapp(4,2.0,3.0,60.0);
	
	//图像的像素点，绿红蓝分别是255*256*256, 255*256， 255
	//a[图像数][行][每列]
	
	
	
	
	delay_color();
	while(1){
		
	}
		
		
		
		
}



void TIM3_IRQHandler(void)
{
 if (TIM_GetITStatus(TIM3, TIM_IT_Update) == SET)
 {	

			WS2812B_Reset();
	 
							
							PWM_WS2812B_All(a[0][num][0]);
							PWM_WS2812B_All(a[0][num][1]);
							PWM_WS2812B_All(a[0][num][2]);
							PWM_WS2812B_All(a[0][num][3]);
							PWM_WS2812B_All(a[0][num][4]);
							PWM_WS2812B_All(a[0][num][5]);
							PWM_WS2812B_All(a[0][num][6]);
							PWM_WS2812B_All(a[0][num][7]);
							//PWM_WS2812B_Color(g, r, b);
		
		
			num++;
		 if (num==15){
				num=0;
		 }
		 
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
		
	}
}


