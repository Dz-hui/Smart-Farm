/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-02 19:52:24
*@FilePath: ??���ָ�???��??Smart-Farm??���ָ�???��??Libraries??���ָ�???��??rtthread??���ָ�???��??app??���ָ�???��??rt_task_gizwit.c
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

	//if(currentDataPoint.valueBH1750 != lastDataPoint.valueBH1750) return true;
	return false;
}

void gizwit_init(void *parg) {

    gizwitsInit();
    userInit();
	while(1) {
		DEBUG_PRINT("enter gizwits task");
		rt_enter_critical();
		gizwitsHandle((dataPoint_t *)&currentDataPoint);
		userHandle();
		rt_exit_critical();
		rt_thread_delay(100);
	}
}
