#include "stm32f10x.h"
#include "mapping.h"
#include "led.h"
#include "HDL_WS2812B.h"
#include "delay.h"
#include <math.h>

#define NUMS 1
#define ROWS 30
#define COLUMNS 8
#define DELAY 200

int num;
int pic;

u32 a[NUMS][ROWS][COLUMNS]= {0,0,0,0xff0000,0xff0000,0,0,0,
	0,0,0xff0000,0xff0000,0xff0000,0xff0000,0,0,
	0,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0,
	0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,
	0,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0xff0000,0,
	0,0,0xff0000,0xff0000,0xff0000,0xff0000,0,0,
	0,0,0,0xff0000,0xff0000,0,0,0,
	
	0,0,0,0xff00,0xff00,0,0,0,
	0,0,0xff00,0xff00,0xff00,0xff00,0,0,
	0,0xff00,0xff00,0xff00,0xff00,0xff00,0xff00,0,
	0xff00,0xff00,0xff00,0xff00,0xff00,0xff00,0xff00,0xff00,
	0,0xff00,0xff00,0xff00,0xff00,0xff00,0xff00,0,
	0,0,0xff00,0xff00,0xff00,0xff00,0,0,
	0,0,0,0xff00,0xff00,0,0,0,
	
	
	0,0,0,0,0,0,0,0,
	
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 197377, 592388, 592387, 131841, 0, 0, 263426, 3620883, 8492838, 10534189, 10534186, 8361758, 3489548, 263169, 4015893, 12707122, 14220866, 14219859, 14220366, 14155319, 12378662, 3555596, 4806166, 13365549, 13694520, 8031534, 9084978, 13892403, 12839462, 4082445, 592643, 5464594, 6847766, 856068, 1316870, 7637530, 4806671, 461058, 0, 65792, 131841, 0, 0, 197377, 65792, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	 0, 0, 197377, 592388, 592387, 131841, 0, 0, 263426, 3620883, 8492838, 10534189, 10534186, 8361758, 3489548, 263169, 4015893, 12707122, 14220866, 14219859, 14220366, 14155319, 12378662, 3555596, 4806166, 13365549, 13694520, 8031534, 9084978, 13892403, 12839462, 4082445, 592643, 5464594, 6847766, 856068, 1316870, 7637530, 4806671, 461058, 0, 65792, 131841, 0, 0, 197377, 65792, 0, 0, 0, 0, 0, 0, 0, 0, 0
	
	
	
	
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
	 
							
							PWM_WS2812B_All(a[pic][num][0]);
							PWM_WS2812B_All(a[pic][num][1]);
							PWM_WS2812B_All(a[pic][num][2]);
							PWM_WS2812B_All(a[pic][num][3]);
							PWM_WS2812B_All(a[pic][num][4]);
							PWM_WS2812B_All(a[pic][num][5]);
							PWM_WS2812B_All(a[pic][num][6]);
							PWM_WS2812B_All(a[pic][num][7]);
							//PWM_WS2812B_Color(g, r, b);
		
		
			num++;
		 if (num==ROWS){
				num=0;
			 // pic++;
		 }
		 //if (pic = NUMS){
			//	pic=0;
		 //}
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
		
	}
}


