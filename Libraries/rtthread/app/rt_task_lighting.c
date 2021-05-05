/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-02 20:43:07
*@FilePath: ??¾¶·Ö¸ô???Ìæ??Smart-Farm??¾¶·Ö¸ô???Ìæ??Libraries??¾¶·Ö¸ô???Ìæ??rtthread??¾¶·Ö¸ô???Ìæ??app??¾¶·Ö¸ô???Ìæ??rt_task_lighting.c
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

void bh1750_init(void *parg) {

	while(1) {

		bh1750_measure();
		rt_thread_mdelay(500);
		
	}
}

