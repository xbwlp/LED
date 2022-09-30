#include "stm32f10x.h"                  // Device header
#include "PWM.h"

#define ENABLE_GPIO_1 GPIO_Pin_4
#define ENABLE_GPIO_2 GPIO_Pin_5

void Motor_Init(void)
{
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = ENABLE_GPIO_1 | ENABLE_GPIO_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	PWM_Init();
}

void Motor_SetSpeed(int8_t Speed)
{
	if (Speed >= 0)
	{
		GPIO_SetBits(GPIOA, ENABLE_GPIO_2);
		GPIO_ResetBits(GPIOA, ENABLE_GPIO_1);
		PWM_SetCompare3(Speed);
	}
	else
	{
		GPIO_ResetBits(GPIOA, ENABLE_GPIO_1);
		GPIO_SetBits(GPIOA, ENABLE_GPIO_2);
		PWM_SetCompare2(Speed);
	}
}
