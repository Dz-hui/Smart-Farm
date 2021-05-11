/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-06 23:24:45
*@FilePath: ??¾¶·Ö¸ô???Ìæ??Smart-Farm??¾¶·Ö¸ô???Ìæ??Libraries??¾¶·Ö¸ô???Ìæ??rtthread??¾¶·Ö¸ô???Ìæ??app??¾¶·Ö¸ô???Ìæ??rt_task_key.c
*@Drscription: 
***********************************************************************/
#include "rt_task_key.h"

static rt_thread_t key_thread=RT_NULL;
void key_thread_entry(void *parameter)
{
	uint8_t key_read = 0;     
    while(1)
    {
        key_read = key_scanf();
		switch(key_read)
		{
			case BSP_KEY1_DOWN: 
                printf("Set WIFI AIRLINK MODE\r\n");
                gizwitsSetMode(WIFI_AIRLINK_MODE); 
            
            break;
			case BSP_KEY2_DOWN: 
                printf("Set WIFI SOFTAP MODEE\r\n");
                gizwitsSetMode(WIFI_SOFTAP_MODE); 
            break;
		}
        rt_thread_delay(20);
    }
}

void key_thread_init(void)
{
    key_thread=rt_thread_create("key thread",
                                key_thread_entry,
                                RT_NULL,
                                KEY_THREAD_SIZE,
                                KEY_THREAD_PRIO,
                                20);
    if(key_thread!=RT_NULL)
    {
        rt_thread_startup(key_thread);
    }
}