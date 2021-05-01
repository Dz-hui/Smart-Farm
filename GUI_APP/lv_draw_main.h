#ifndef __lv_draw_main_h
#define __lv_draw_main_h

#include "main.h"
#include "lvgl/lvgl.h"

typedef enum {
    UI_HOME,                // 主界面
    UI_SETTING,             // 设置界面
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

    lv_obj_t *main_src;         // 主屏幕
    lv_obj_t *bar_status;       // 状态栏
    lv_obj_t *popup_src;        // 弹窗

    lv_style_t main_style;      // 主样式
    lv_style_t bar_style;       // 主样式

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

    lv_obj_t *home_label_temp;
    lv_obj_t *home_label_temp1;
    lv_obj_t *home_label_temp2;

}UI_HOME_T;





#endif
