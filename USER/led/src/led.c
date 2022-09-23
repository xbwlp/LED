#include "led.h"

void led_init(){
	 GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC , ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_SetBits(GPIOC, GPIO_Pin_14);
	for(int i=0;i<=10000000;i++){
		GPIO_ResetBits(GPIOC, GPIO_Pin_14);
	}
	GPIO_SetBits(GPIOC, GPIO_Pin_14);
}
	
