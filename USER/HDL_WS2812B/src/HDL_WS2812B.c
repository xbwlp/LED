#include "HDL_WS2812B.h"
#include "delay.h"	//��ʱ�������Լ���Ӧ��ͷ�ļ����ڸ�λ��ʹ��

/* ��������ı����Ӧ�ıȽ�ֵ���� */
uint16_t Single_LED_Buffer[DATA_SIZE*LED_NUM];

/*
*���ã�ͨ�ö�ʱ��2 TIM2_CH2 PWM���+DMA��ʼ�� 
*������arr���Զ���װֵ
*˵������ʱ�����ʱ����㷽��:Tout=((arr+1)*(psc+1))/Ft us.
*      Ft=��ʱ������Ƶ��,��λ:Mhz
*/
void PWM_WS2812B_Init(uint16_t arr)
{
	//�ṹ�����
	GPIO_InitTypeDef  GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	DMA_InitTypeDef DMA_InitStructure;
	
	//ʹ��RCCʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);		//ʹ��PORTAʱ��	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);			//ʹ��TIM2ʱ��    
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);				//ʹ��DMA1ʱ��    
	
	//��ʼ��GPIO��
	GPIO_InitStructure.GPIO_Pin = WS2812B_PIN;					//GPIO��
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		//�ٶ�50MHz
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;			//�����������                               
	GPIO_Init(WS2812B_PORT,&GPIO_InitStructure);				//����ָ���Ĳ�����ʼ��GPIO��
	
	//��ʼ��TIM2
	TIM_TimeBaseStructure.TIM_Prescaler=0;											//��ʱ����Ƶ��(0+1)=1,����Ƶ
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;		//���ϼ���ģʽ
	TIM_TimeBaseStructure.TIM_Period=arr;												//�Զ���װ��ֵ
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;				//ʱ�ӷָ�
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseStructure);							//����ָ���Ĳ�����ʼ��TIM2
	
	//��ʼ��TIM2 Channel2 PWMģʽ
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 						//ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	//TIM_OCInitStructure.TIM_Pulse = 0;													//��װ�벶��ȽϼĴ���������ֵ(�˳����üӳ�ֵ)
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 		//�������:TIM����Ƚϼ��Ը�
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);  										//����ָ���Ĳ�����ʼ������TIM2 Channel2
	/* �˴�Ϊ֪ʶ�����������Ķ�Ӧ���룬һ��Ҫ�С���ֲʱע��0C2����ʱ��ͨ��2*/
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);  						//ʹ��TIM2��CCR2�ϵ�Ԥװ�ؼĴ���
	
	TIM_Cmd(TIM2, DISABLE);  									//ʧ��TIM2����ֹ��һ�������쳣
	
	TIM_DMACmd(TIM2, TIM_DMA_CC2, ENABLE);		//ʹ��TIM2_CH2��DMA����(CC2��Ӧͨ��2)
	
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&(TIM2->CCR2); 				//����DMAĿ�ĵ�ַ
  	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)Single_LED_Buffer;					//����DMAԴ��ַ
 	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;													//���򣺴��ڴ�SendBuff���ڴ�ReceiveBuff  
 	DMA_InitStructure.DMA_BufferSize = DATA_SIZE; 															//һ�δ����СDMA_BufferSize=SendBuffSize   
  	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable; 						//ReceiveBuff��ַ����
  	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;											//SendBuff��ַ����
  	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;	//ReceiveBuff���ݵ�λ,16bit
  	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;					//SENDBUFF_SIZE���ݵ�λ,16bit
  	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;																//DMAģʽ������ģʽ(����һ��)
  	DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;												//���ȼ����� 
  	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable; 																//�ڴ浽�ڴ�Ĵ���
  	DMA_Init(DMA1_Channel7, &DMA_InitStructure);																//����DMA1��7ͨ��(��ͬ��ʱ����ͨ����һ��)
    
  	DMA_Cmd(DMA1_Channel7, DISABLE);					//ʧ��DMA1��7ͨ������Ϊһ��ʹ�ܾͿ�ʼ����
}
//��λ�ƴ�
void WS2812B_Reset(void)
{
	TIM_Cmd(TIM2, DISABLE);
	WS2812B_LOW;
	delay_ms(1);	//�˴���ʱʱ����Сֵ����50us����
}
//д���ݱ���
void PWM_WS2812B_Write_24Bits(uint16_t num,uint32_t GRB_Data)
{
  uint8_t i,j;
  for(j = 0; j < num; j++)
  {
  	for(i = 0; i < DATA_SIZE; i++)
	{
		/*��Ϊ���ݷ��͵�˳����GRB����λ�ȷ������ԴӸ�λ��ʼ�жϣ��жϺ�Ƚ�ֵ�ȷ��뻺������*/
		Single_LED_Buffer[i] = ((GRB_Data << i) & 0x800000) ? T1H : T0H;
	}
  }
}

//��������
void PWM_WS2812B_Show(uint16_t num)
{
	/* ��ֲʱ�˴���Ӧ��ͨ�����жϱ�־����Ҫ���� */
  	DMA_SetCurrDataCounter(DMA1_Channel7, num*DATA_SIZE);
  	DMA_Cmd(DMA1_Channel7, ENABLE);
  	TIM_Cmd(TIM2, ENABLE);
  	while(DMA_GetFlagStatus(DMA1_FLAG_TC7) != SET);
  	DMA_Cmd(DMA1_Channel7, DISABLE);
  	DMA_ClearFlag(DMA1_FLAG_TC7);
  	TIM_Cmd(TIM2, DISABLE);
}

//N�����鷢���
void PWM_WS2812B_Red(uint16_t num)
{
	PWM_WS2812B_Write_24Bits(num,0x00ff00);
	PWM_WS2812B_Show(num);
}
//N�����鷢�̹�
void PWM_WS2812B_Green(uint16_t num)
{
	PWM_WS2812B_Write_24Bits(num,0xff0000);
	PWM_WS2812B_Show(num);
}
//N�����鷢����
void PWM_WS2812B_Blue(uint16_t num)
{
	PWM_WS2812B_Write_24Bits(num,0x0000ff);
	PWM_WS2812B_Show(num);
}

void PWM_WS2812B_Color(uint32_t Green, uint32_t Red, uint32_t Blue)
{
	PWM_WS2812B_Write_24Bits(1,Green*256*256+Red*256+Blue);
	PWM_WS2812B_Show(1);
}

void PWM_WS2812B_All(uint32_t color)
{
	PWM_WS2812B_Write_24Bits(1,color);
	PWM_WS2812B_Show(1);
}