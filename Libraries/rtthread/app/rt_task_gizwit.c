/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-02 19:52:24
*@FilePath: ??¾¶·Ö¸ô???Ìæ??Smart-Farm??¾¶·Ö¸ô???Ìæ??Libraries??¾¶·Ö¸ô???Ìæ??rtthread??¾¶·Ö¸ô???Ìæ??app??¾¶·Ö¸ô???Ìæ??rt_task_gizwit.c
*@Drscription: 
***********************************************************************/
#include "rt_task_gizwit.h"

rt_thread_t gizwit_thread = RT_NULL;

void gizwit_thread_init(void) {

	gizwit_thread = rt_thread_create(	"gizwit thread",
										gizwit_init,
										NULL,
										GIZWIT_THREAD_SIZE,
										GIZWIT_THREAD_PRIO,
										20);

	if(gizwit_thread != RT_NULL)
	{
		rt_thread_startup(gizwit_thread);
	}
	else 
		DEBUG_PRINT("gizwit_thread ERR");
}


bool check_gizwitsHandle(void) {

	if(currentDataPoint.valueBH1750 != lastDataPoint.valueBH1750) return true;

	return false;
}

void gizwit_init(void *parg) {

	//³õÊ¼»¯»úÖÇÔÆ
    gizwitsInit();
	//ÅäÖÃ»úÖÇÔÆ
	userInit();

	static bool is_need_to_handle = true;

	while(1) {
     
		// »úÖÇÔÆÉÏÐÐ
		is_need_to_handle = check_gizwitsHandle();
		if(is_need_to_handle) {
			userHandle();
			is_need_to_handle = false;
		}
		gizwitsHandle((dataPoint_t *)&currentDataPoint);
		rt_thread_delay(1000);
	}
}
