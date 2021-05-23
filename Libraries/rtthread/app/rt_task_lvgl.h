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

// sensor data
typedef struct {

    float soil_value;           
    float distance_value;
    float lighting_value;
    float co2_value;
    float temp_value;
    float humi_value;
    bool wifi_status;
}lv_sensor_value_t;
extern lv_sensor_value_t my_sensor; 

// ctrl define
typedef struct {

    uint8_t curtain_status : 1;     // 窗帘控制                             检测CO2浓度和光照强度配合使用
    uint8_t led_value;              // LED灯控制 value :0-100               检测CO2浓度和光照强度配合使用 
    uint8_t pump_status:1;          // 水泵控制                             检测土壤湿度使用
    uint8_t fan_mode:2;             // 风扇控制模式 0 ，1，2，3             检测温度和湿度配合使用   
    uint8_t heat_value;             // 加热垫或加热棒 value :0-100          检测温度使用
}lv_ctrl_t;
extern lv_ctrl_t my_ctrl;


void gui_lvgl_init(void *parg);
void gui_lvgl_thread_init(void) ;
void gui_lvgl_updata_init(void *parg);
void gui_lvgl_uptada_init(void);
#endif

