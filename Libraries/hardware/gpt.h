/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-01 16:37:37
*@FilePath: ??���ָ�???��??Smart-Farm??���ָ�???��??Libraries??���ָ�???��??hardware??���ָ�???��??gpt.h
*@Drscription: 
***********************************************************************/
#ifndef __BSP_GPT_H
#define __BSP_GPT_H

#include "fsl_common.h"
#include "fsl_gpt.h"


// /* ѡ���ⲿʱ��Դ */
// #define EXAMPLE_GPT_CLOCK_SOURCE_SELECT (0U)
// /* ʱ��Դ��ʱ�ӷ�Ƶ */
// #define EXAMPLE_GPT_CLOCK_DIVIDER_SELECT (0U)

// /*GPT ʱ�ӷ�Ƶ(1-4096)*/
// #define GPT_DIVIDER 100

// /* �õ�GPT��ʱ���ļ���Ƶ��*/
// #define EXAMPLE_GPT_CLK_FREQ ( (CLOCK_GetFreq(kCLOCK_IpgClk) / (EXAMPLE_GPT_CLOCK_DIVIDER_SELECT + 1U))/GPT_DIVIDER )
// #define COUNGER_NUMBER  ((TIME_ms/1000.0)*EXAMPLE_GPT_CLK_FREQ)
// #define TIME_ms 1

// /*����ʹ�õ�GPT*/
// #define EXAMPLE_GPT GPT2

// /*�жϺź��жϷ������궨��*/
// #define GPT_IRQ_ID GPT2_IRQn
// #define EXAMPLE_GPT_IRQHandler GPT2_IRQHandler

// void GPT_Config(void);

/* ѡ���ⲿʱ��Դ */
#define EXAMPLE_GPT_CLOCK_SOURCE_SELECT (0U)
/* ʱ��Դ��ʱ�ӷ�Ƶ */
#define EXAMPLE_GPT_CLOCK_DIVIDER_SELECT (0U)

/*GPT ʱ�ӷ�Ƶ(1-4096)*/
#define GPT_DIVIDER 100

/* �õ�GPT��ʱ���ļ���Ƶ��*/
#define EXAMPLE_GPT_CLK_FREQ ( (CLOCK_GetFreq(kCLOCK_IpgClk) / (EXAMPLE_GPT_CLOCK_DIVIDER_SELECT + 1U))/GPT_DIVIDER )
#define COUNGER_NUMBER  ((TIME_ms/1000.0)*EXAMPLE_GPT_CLK_FREQ)
#define TIME_ms 1

/*����ʹ�õ�GPT*/
#define EXAMPLE_GPT GPT2

/*�жϺź��жϷ������궨��*/
#define GPT_IRQ_ID GPT2_IRQn
#define EXAMPLE_GPT_IRQHandler GPT2_IRQHandler

void GPT_Config(void);



#endif /* __BSP_GPT_H */
