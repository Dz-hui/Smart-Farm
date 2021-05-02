/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-02 19:38:41
*@FilePath: ??¾¶·Ö¸ô???Ìæ??Smart-Farm??¾¶·Ö¸ô???Ìæ??Libraries??¾¶·Ö¸ô???Ìæ??rtthread??¾¶·Ö¸ô???Ìæ??app??¾¶·Ö¸ô???Ìæ??rt_task_adc.h
*@Drscription: 
***********************************************************************/
#ifndef _rt_task_adc_h
#define _rt_task_adc_h

#include "main.h"

#define ADC_THREAD_SIZE				1024
#define ADC_THREAD_PRIO              5



extern rt_thread_t adc_thread ;

void adc_init(void *parg);
void adc_thread_init(void);


#endif
