/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-02 20:43:07
*@FilePath: ??径分隔???替??Smart-Farm??径分隔???替??Libraries??径分隔???替??rtthread??径分隔???替??app??径分隔???替??rt_task_lighting.c
*@Drscription: 
***********************************************************************/
#include "rt_task_lighting.h"

rt_thread_t bh1750_thread = RT_NULL;

void bh1750_thread_init(void) {

	bh1750_thread = rt_thread_create(	"bh1750 thread",
										bh1750_init,
										NULL,
										BH1750_THREAD_SIZE,
										BH1750_THREAD_PRIO,
										20);

	if(bh1750_thread != RT_NULL)
	{
		rt_thread_startup(bh1750_thread);
	}
	else 
		DEBUG_PRINT("bh1750_thread ERR");
}

#define BH1750_DIV				5
void bh1750_init(void *parg) {

	float lighting_value = 0;
	while(1) {

		lighting_value = bh1750_measure();
		
		if(lighting_value >= BH1750_DIV) {
			my_sensor.lighting_value = lighting_value;
		}
		else {
			// 不更新你的值
		}
		rt_thread_mdelay(1000);
	}
}

