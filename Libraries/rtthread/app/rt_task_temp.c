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
        dht11_lvgl_display(&dht11_data);
		rt_exit_critical();

		rt_thread_mdelay(200);
	}
}
