/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-02 19:39:41
*@FilePath: ??¾¶·Ö¸ô???Ìæ??Smart-Farm??¾¶·Ö¸ô???Ìæ??Libraries??¾¶·Ö¸ô???Ìæ??rtthread??¾¶·Ö¸ô???Ìæ??app??¾¶·Ö¸ô???Ìæ??rt_task_lvgl.h
*@Drscription: 
***********************************************************************/
#ifndef _rt_task_lvgl_h
#define _rt_task_lvgl_h

#include "main.h"

#define LV_THREAD_SIZE				1024*50
#define LV_THREAD_PRIO              3

void gui_lvgl_init(void *parg);
void gui_lvgl_thread_init(void) ;

extern rt_thread_t lv_thread ;


#endif

