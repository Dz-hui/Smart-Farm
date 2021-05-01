/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-01 16:37:36
*@FilePath: ??径分隔???替??Smart-Farm??径分隔???替??GUI_APP??径分隔???替??lv_draw_main.h
*@Drscription: 
***********************************************************************/
#ifndef __lv_draw_main_h
#define __lv_draw_main_h

#include "main.h"


typedef enum {
    UI_HOME,                // 主界面
    UI_SETTING,             // 设置界面
    UI_control,             // 控制界面
    UI_ABOUT,               // 介绍信息界面 
}UI_LIST;

typedef enum {
    EVENT_TEMP,
    EVENT_HUMI,
    EVENT_ASDASD,
}UI_EVENT;


typedef struct {

    UI_LIST ui_list;
    UI_EVENT event;

    lv_obj_t *main_src;                 // 主屏幕
    lv_obj_t *home_top_gb_layer;       // 状态栏
    lv_obj_t *home_buttom_gb_layer;    // 弹窗

    lv_style_t main_style;             // 主样式
    lv_style_t bar_style;              // 主样式

    lv_obj_t *bar_label_temp;       
    lv_obj_t *bar_label_pump; 
    lv_obj_t *bar_label_pump1;    
    lv_obj_t *bar_label_pump2;     
         
}MY_UI_T;




typedef struct {


    lv_obj_t *home_btn_setting;
    lv_obj_t *home_btn_ctrl;
    lv_obj_t *home_btn_about;

    lv_obj_t *home_label_setting;
    lv_obj_t *home_label_ctrl;
    lv_obj_t *home_label_about;

    lv_obj_t *home_temp_text;
    lv_obj_t *home_co2_text;
    lv_obj_t *home_lighting_text;
    lv_obj_t *home_humi_text;
    lv_obj_t *home_water_text;
    lv_obj_t *home_soil_text;

    lv_obj_t *home_fan_text;
    lv_obj_t *home_curtain_text;
    lv_obj_t *home_led_text;
    lv_obj_t *home_pump_text;
    lv_obj_t *device_text;

    lv_obj_t *back_btn;


    
}UI_HOME_T;



void my_lv_obj_del(lv_obj_t *obj);
void lv_draw_init(void);



#endif
