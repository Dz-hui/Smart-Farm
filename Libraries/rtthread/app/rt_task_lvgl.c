/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-02 19:39:25
*@FilePath: ??¾¶·Ö¸ô???Ìæ??Smart-Farm??¾¶·Ö¸ô???Ìæ??Libraries??¾¶·Ö¸ô???Ìæ??rtthread??¾¶·Ö¸ô???Ìæ??app??¾¶·Ö¸ô???Ìæ??rt_task_lvgl.c
*@Drscription: 
***********************************************************************/
#include "rt_task_lvgl.h"

rt_thread_t lv_thread = RT_NULL;

void gui_lvgl_thread_init(void) {

	lv_thread = rt_thread_create(	"lv thread",
									gui_lvgl_init,
									NULL,
									LV_THREAD_SIZE,
									LV_THREAD_PRIO,
									20);

	if(lv_thread != RT_NULL)
		rt_thread_startup(lv_thread);
	else 
		DEBUG_PRINT("lv_thread ERR");
}

void gui_lvgl_init(void *parg) {

    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();

	lv_draw_init();

	while(1) {
		
		lv_task_handler();
		rt_thread_delay(5);
	}
}