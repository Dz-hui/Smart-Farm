/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-02 19:39:25
*@FilePath: ??���ָ�???��??�½��ļ���??���ָ�???��??Libraries??���ָ�???��??rtthread??���ָ�???��??app??���ָ�???��??rt_task_lvgl.c
*@Drscription: 
***********************************************************************/
#include "rt_task_lvgl.h"

rt_thread_t lv_thread = RT_NULL;
lv_sensor_value_t my_sensor;
lv_ctrl_t my_ctrl;

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
	gui_lvgl_uptada_init();

	my_sensor.co2_value = 26.4;
	my_sensor.distance_value = 0;
	my_sensor.humi_value = 0;
	my_sensor.lighting_value = 0;
	my_sensor.soil_value = 0;
	my_sensor.temp_value = 0;

	my_ctrl.curtain_status = 0;
	my_ctrl.fan_mode = 0;
	my_ctrl.led_value = 0;
	my_ctrl.pump_status = 0; 

	while(1) {
		lv_task_handler();
		rt_thread_delay(5);
	}
}


rt_thread_t lv_thread_updata_task = RT_NULL;

void gui_lvgl_uptada_init(void) {

	lv_thread_updata_task = rt_thread_create("lv thread",
											gui_lvgl_updata_init,
											NULL,
											1024,
											LV_THREAD_PRIO+1,
											20);

	if(lv_thread_updata_task != RT_NULL)
		rt_thread_startup(lv_thread_updata_task);
	else 
		DEBUG_PRINT("lv_thread_updata_task ERR");
}

void gui_lvgl_updata_init(void *parg) {
	while(1) {
		// DEBUG_PRINT("enter updata task");
		if(my_ui.ui_list == UI_NONE) {
			lv_label_main_updata();
		}
		else if(my_ui.ui_list == UI_HOME) {
			lv_label_main_updata();
		}

		rt_thread_delay(100);
	}
}
