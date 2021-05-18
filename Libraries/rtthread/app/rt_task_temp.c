/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-01 16:37:37
*@FilePath: ??���ָ�???��??Smart-Farm??���ָ�???��??Libraries??���ָ�???��??rtthread??���ָ�???��??app??���ָ�???��??rt_task_temp.c
*@Drscription: 
***********************************************************************/
#include "rt_task_temp.h"

rt_thread_t dht11_thread = RT_NULL;

void dht11_init(void *parg);

void dht11_thread_init(void) {

	dht11_thread = rt_thread_create(	"dht11 thread",
										dht11_init,
										NULL,
										DHT11_THREAD_SIZE,
										DHT11_THREAD_PRIO,
										20);

	if(dht11_thread != RT_NULL)
	{
		rt_thread_startup(dht11_thread);
		DEBUG_PRINT("dht11_thread succeed\n");
	}
	else 
		DEBUG_PRINT("dht11_thread ERR");
}

void dht11_init(void *parg) {

	while(1) {
		rt_enter_critical();
		if(Read_DHT11(&dht11_data) == 1) {
			my_sensor.temp_value = (float)dht11_data.temp_int + (float)dht11_data.temp_deci/100;
			my_sensor.humi_value = (float)dht11_data.humi_int + (float)dht11_data.humi_deci/100;
		}
		rt_exit_critical();
		rt_thread_delay(2000);
	}
}
