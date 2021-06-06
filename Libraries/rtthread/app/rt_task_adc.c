/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-02 19:38:27
*@FilePath: ??���ָ�???��??�½��ļ���??���ָ�???��??Libraries??���ָ�???��??rtthread??���ָ�???��??app??���ָ�???��??rt_task_adc.c
*@Drscription: 
***********************************************************************/
#include "rt_task_adc.h"

rt_thread_t adc_thread = RT_NULL;

ADC_GET_DEF adc_get;

void adc_thread_init(void) {

	adc_thread = rt_thread_create(	"adc thread",
										adc_init,
										NULL,
										ADC_THREAD_SIZE,
										ADC_THREAD_PRIO,
										20);

	if(adc_thread != RT_NULL)
	{
		rt_thread_startup(adc_thread);
	}
	else 
		DEBUG_PRINT("adc_thread ERR");
}

void adc_init(void *parg) {

	adc_get.soil_value = 0;
	adc_get.distance_value = 0;
	adc_get.light_value = 0;
	DEBUG_PRINT("creat adc task");

	while(1) {
		
		adc_get.soil_value = soil_value_get();
		//adc_get.distance_value = distance_value_get();
		adc_get.light_value = light_value_get();
		
		my_sensor.soil_value = adc_get.soil_value;
		my_sensor.lighting_value = adc_get.light_value;
		rt_thread_delay(500);
	}
}



