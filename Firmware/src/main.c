#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

GPIO_InitTypeDef GPIOSetup;
EXTI_InitTypeDef EXTISetup;
NVIC_InitTypeDef NVICSetup;

void GPIO_Configuration(){
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	GPIOSetup.GPIO_Mode = 0x01;
	GPIOSetup.GPIO_OType = 0x00;
	GPIOSetup.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11 |GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIOSetup.GPIO_PuPd = 0x00;
	GPIOSetup.GPIO_Speed = 0x00;
	GPIO_Init(GPIOD, &GPIOSetup);
	GPIOSetup.GPIO_Mode = 0x00;
	GPIOSetup.GPIO_OType = 0x00;
	GPIOSetup.GPIO_Pin = 0x0001;
	GPIOSetup.GPIO_PuPd = 0x02;
	GPIOSetup.GPIO_Speed = 0x03;
	GPIO_Init(GPIOA, &GPIOSetup);
	GPIOSetup.GPIO_Mode = 0x00;
	GPIOSetup.GPIO_OType = 0x00;
	GPIOSetup.GPIO_Pin = 0x0001;
	GPIOSetup.GPIO_PuPd = 0x02;
	GPIOSetup.GPIO_Speed = 0x03;
	GPIO_Init(GPIOE, &GPIOSetup);
}

void EXTI_Configuration(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);
	EXTISetup.EXTI_Line = EXTI_Line0;
	EXTISetup.EXTI_LineCmd = ENABLE;
	EXTISetup.EXTI_Mode = 0x00;
	EXTISetup.EXTI_Trigger = 0x08;
	EXTI_Init(&EXTISetup);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource1);
	EXTISetup.EXTI_Line = EXTI_Line1;
	EXTISetup.EXTI_LineCmd = ENABLE;
	EXTISetup.EXTI_Mode = 0x00;
	EXTISetup.EXTI_Trigger = 0x08;
	EXTI_Init(&EXTISetup);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVICSetup.NVIC_IRQChannel = EXTI0_IRQn;
	NVICSetup.NVIC_IRQChannelCmd = ENABLE;
	NVICSetup.NVIC_IRQChannelPreemptionPriority = 0;
	NVICSetup.NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(&NVICSetup);
	NVICSetup.NVIC_IRQChannel = EXTI1_IRQn;
	NVICSetup.NVIC_IRQChannelCmd = ENABLE;
	NVICSetup.NVIC_IRQChannelPreemptionPriority = 1;
	NVICSetup.NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(&NVICSetup);
	}

void delay(uint32_t t){
	while(t--);
}

void EXTI0_IRQHandler(){
	if(EXTI_GetITStatus(EXTI_Line0) != RESET){
		GPIO_ResetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
		delay(16800000);
		GPIO_SetBits(GPIOD, GPIO_Pin_11);
		delay(16800000);
		GPIO_ResetBits(GPIOD,GPIO_Pin_11);
		delay(16800000);
		GPIO_SetBits(GPIOD, GPIO_Pin_11);
		delay(16800000);
		GPIO_ResetBits(GPIOD,GPIO_Pin_11);
		delay(16800000);
		EXTI_ClearITPendingBit(EXTI_Line0);
	}
}

void EXTI1_IRQHandler(){
	if(EXTI_GetITStatus(EXTI_Line1) != RESET){
		GPIO_ResetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
		delay(16800000);
		GPIO_SetBits(GPIOD, GPIO_Pin_10);
		delay(16800000);
		GPIO_ResetBits(GPIOD,GPIO_Pin_10);
		delay(16800000);
		GPIO_SetBits(GPIOD, GPIO_Pin_10);
		delay(16800000);
		GPIO_ResetBits(GPIOD,GPIO_Pin_10);
		delay(16800000);
		EXTI_ClearITPendingBit(EXTI_Line1);
	}
}

int main(void)
{
	GPIO_Configuration();
	EXTI_Configuration();
  while (1)
  {
	  GPIO_SetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
	  delay(16800000);
	  GPIO_ResetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
	  delay(16800000);
  }
}


void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
