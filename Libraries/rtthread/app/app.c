#include "app.h"
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "lv_apps\demo\demo.h"
#include "lv_tests\lv_test_theme\lv_test_theme_1.h"
#include "lv_tests\lv_test_theme\lv_test_theme_2.h"

rt_thread_t lv_thread = RT_NULL;
#define LV_THREAD_SIZE				4096
void gui_lvgl_init(void *parg);

void gui_lvgl_thread_init(void) {

	lv_thread = rt_thread_create(	"lv thread",
									gui_lvgl_init,
									NULL,
									LV_THREAD_SIZE,
									3,
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


    draw_home();
    //lv_test_theme_1(lv_theme_night_init(210, NULL));
	while(1) {
		lv_task_handler();
		rt_thread_delay(5);
	}
}


rt_thread_t gizwit_thread = RT_NULL;
#define GIZWIT_THREAD_SIZE				4096
void gizwit_init(void *parg);


void gizwit_thread_init(void) {

	gizwit_thread = rt_thread_create(	"gizwit thread",
										gui_lvgl_init,
										NULL,
										GIZWIT_THREAD_SIZE,
										4,
										20);

	if(lv_thread != RT_NULL)
		rt_thread_startup(gizwit_thread);
	else 
		DEBUG_PRINT("gizwit_thread ERR");
}

void gizwit_init(void *parg) {

	//初始化机智云

	//配置机智云


	while(1) {

		// 机智云上行
		

		// 机智云下行


		rt_thread_delay(1000);
	}
}




