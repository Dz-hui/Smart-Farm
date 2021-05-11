/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-02 19:39:41
*@FilePath: ??���ָ�???��??Smart-Farm??���ָ�???��??Libraries??���ָ�???��??rtthread??���ָ�???��??app??���ָ�???��??rt_task_lvgl.h
*@Drscription: 
***********************************************************************/
#ifndef _rt_task_lvgl_h
#define _rt_task_lvgl_h

#include "main.h"

#define LV_THREAD_SIZE				1024*50
#define LV_THREAD_PRIO              4

typedef struct {

    float soil_value;
    float distance_value;
    float lighting_value;
    float co2_value;
    float temp_value;
    float humi_value;
}lv_sensor_value_t;
extern lv_sensor_value_t my_sensor;



void gui_lvgl_init(void *parg);
void gui_lvgl_thread_init(void) ;

void gui_lvgl_updata_init(void *parg);
void gui_lvgl_uptada_init(void);
#endif

