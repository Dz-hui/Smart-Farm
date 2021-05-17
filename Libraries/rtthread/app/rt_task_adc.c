/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-02 19:38:27
*@FilePath: ??¾¶·Ö¸ô???Ìæ??ÐÂ½¨ÎÄ¼þ¼Ð??¾¶·Ö¸ô???Ìæ??Libraries??¾¶·Ö¸ô???Ìæ??rtthread??¾¶·Ö¸ô???Ìæ??app??¾¶·Ö¸ô???Ìæ??rt_task_adc.c
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
		// DEBUG_PRINT("enter adc task");

		// adc_get.soil_value = (((float)4095-(float)adc_measure(ADC,SOIL_ADC_CHANNLE_GROUP,SOIL_ADC_CHANNLE))/4095)*100;
		// adc_get.distance_value = -(((((float)adc_measure(ADC,DISTANCE_ADC_CHANNLE_GROUP,DISTANCE_ADC_CHANNLE)/(float)4095)*(float)3.3)-(float)2.35)/(float)0.035);

		adc_get.soil_value = soil_value_get();
		//adc_get.distance_value = distance_value_get();
		adc_get.light_value = light_value_get();
		
		my_sensor.soil_value = adc_get.soil_value;
		my_sensor.lighting_value = adc_get.light_value;
		rt_thread_delay(500);
	}
}

float soil_value_get(void) {
	return (((float)4095-(float)adc_measure(ADC ,SOIL_ADC_CHANNLE_GROUP, SOIL_ADC_CHANNLE))/4095)*100;
}

uint16_t soil_value_get_int(void) {
	return ((4095-adc_measure(ADC ,SOIL_ADC_CHANNLE_GROUP, SOIL_ADC_CHANNLE)));
}

// float distance_value_get(void) {
	
// 	return -(((((float)adc_measure(ADC,DISTANCE_ADC_CHANNLE_GROUP,DISTANCE_ADC_CHANNLE)/(float)4095)*(float)3.3)-(float)2.35)/(float)0.035);
// }

float light_value_get(void) {
	return ((float)adc_measure(ADC,LIGHT_ADC_CHANNLE_GROUP,LIGHT_ADC_CHANNLE)/(float)4095*100);
}



