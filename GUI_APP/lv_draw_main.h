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
    
    lv_obj_t *home_top_gb_layer;        // 状态栏
    lv_obj_t *home_buttom_gb_layer;     // 下半屏幕
    lv_obj_t *home_popup;               // 弹窗
    

    lv_style_t main_style;             // 主样式
    lv_style_t bar_style;              // 主样式

    lv_obj_t *bar_label_temp;       
    lv_obj_t *bar_label_pump; 
    lv_obj_t *bar_label_pump1;    
    lv_obj_t *bar_label_pump2;     
         
}MY_UI_T;







void my_lv_obj_del(lv_obj_t *obj);
void lv_draw_init(void);

lv_obj_t* lv_btn_set(lv_obj_t* scr, lv_obj_t* btn, lv_coord_t btn_w, lv_coord_t btn_h, lv_coord_t x, lv_coord_t y, lv_event_cb_t event_cb);
lv_obj_t* lv_label_set(lv_obj_t* scr, lv_obj_t* label, lv_coord_t x, lv_coord_t y,const char *txt);
lv_obj_t* lv_label_align_set(lv_obj_t* scr, lv_obj_t* label, const char *txt) ;
#endif
