/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-02 19:38:41
*@FilePath: ??¾¶·Ö¸ô???Ìæ??ÐÂ½¨ÎÄ¼þ¼Ð??¾¶·Ö¸ô???Ìæ??Libraries??¾¶·Ö¸ô???Ìæ??rtthread??¾¶·Ö¸ô???Ìæ??app??¾¶·Ö¸ô???Ìæ??rt_task_adc.h
*@Drscription: 
***********************************************************************/
#ifndef _rt_task_adc_h
#define _rt_task_adc_h

#include "main.h"

#define ADC_THREAD_SIZE     1024
#define ADC_THREAD_PRIO     6

typedef struct {

    float soil_value;
    float distance_value;
    float light_value;
 

}ADC_GET_DEF;
extern ADC_GET_DEF adc_get;


void adc_init(void *parg);
void adc_thread_init(void);
float soil_value_get(void);
float distance_value_get(void);
float light_value_get(void);

uint16_t soil_value_get_int(void);
#endif
