/***********************************************************************
*@Author: Dz_hui
*@Date: 2020-11-19 20:34:50
*@FilePath: ??���ָ�???��??Smart-Farm??���ָ�???��??Libraries??���ָ�???��??hardware??���ָ�???��??gpt.c
*@Drscription: 
***********************************************************************/
#include "exit.h"
#include "gpt.h"
#include "gizwits_product.h"
#include "main.h"

uint16_t i=0;
// void GPT_Config(void)
// {
//   gpt_config_t gptConfig;
  
//   /*����GPTʹ�õ����ⲿʱ��*/
//   CLOCK_SetMux(kCLOCK_PerclkMux, EXAMPLE_GPT_CLOCK_SOURCE_SELECT);
//   CLOCK_SetDiv(kCLOCK_PerclkDiv, EXAMPLE_GPT_CLOCK_DIVIDER_SELECT);
  
//   /*��ʼ��GPT*/
//   GPT_GetDefaultConfig(&gptConfig);
//   gptConfig.enableFreeRun = false;
//   GPT_Init(EXAMPLE_GPT, &gptConfig);
  
//   /* ����ʱ�ӷ�Ƶ */
//   GPT_SetClockDivider(EXAMPLE_GPT, GPT_DIVIDER);
  
//   /* ����GPT��ʱ���ļ���ֵ*/
//   GPT_SetOutputCompareValue(EXAMPLE_GPT, kGPT_OutputCompare_Channel1, (uint32_t)COUNGER_NUMBER);

//   /* ����GPT2��ʱ���Ƚ�ͨ��1���ж� */
//   GPT_EnableInterrupts(EXAMPLE_GPT, kGPT_OutputCompare1InterruptEnable);

//    /*�����ж����ȼ�,*/
//   IRQN_priority(4,6,0,GPT_IRQ_ID);
//   /*ʹ���ж�*/
//   EnableIRQ(GPT_IRQ_ID);

//   /* ������ʱ�� */
//   GPT_StartTimer(EXAMPLE_GPT);
// }



// /*�����жϷ�����*/
// void EXAMPLE_GPT_IRQHandler(void)
// {

// 	/* ����жϱ�־λ.*/
// 	GPT_ClearStatusFlags(EXAMPLE_GPT, kGPT_OutputCompare1Flag);
//   if(i==5000)
//   {
//     i=0;
//     printf("hello\n");
//   }
//   else
//   {
//     i++;
//   }
// 	//gizTimerMs();

  
// }


void GPT_Config(void)
{
  gpt_config_t gptConfig;
  
  CLOCK_SetMux(kCLOCK_PerclkMux, EXAMPLE_GPT_CLOCK_SOURCE_SELECT);
  CLOCK_SetDiv(kCLOCK_PerclkDiv, EXAMPLE_GPT_CLOCK_DIVIDER_SELECT);
  
  GPT_GetDefaultConfig(&gptConfig);

  gptConfig.enableFreeRun = false;
  
  GPT_Init(EXAMPLE_GPT, &gptConfig);
  
  GPT_SetClockDivider(EXAMPLE_GPT, GPT_DIVIDER);
  
  GPT_SetOutputCompareValue(EXAMPLE_GPT, kGPT_OutputCompare_Channel1, (uint32_t)COUNGER_NUMBER);

  GPT_EnableInterrupts(EXAMPLE_GPT, kGPT_OutputCompare1InterruptEnable);

  //set_IRQn_Priority(GPT_IRQ_ID,Group4_PreemptPriority_6, Group4_SubPriority_0);
  IRQN_priority(4,6,0,GPT_IRQ_ID);

  EnableIRQ(GPT_IRQ_ID);

  GPT_StartTimer(EXAMPLE_GPT);
}



/*�����жϷ�����*/
void EXAMPLE_GPT_IRQHandler(void)
{
  /* ����жϱ�־λ.*/
  rt_interrupt_enter();
  GPT_ClearStatusFlags(EXAMPLE_GPT, kGPT_OutputCompare1Flag);
  gizTimerMs();
  rt_interrupt_leave();
}

