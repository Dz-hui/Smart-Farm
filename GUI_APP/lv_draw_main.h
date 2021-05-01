#ifndef __lv_draw_main_h
#define __lv_draw_main_h

#include "main.h"
#include "lvgl/lvgl.h"

typedef enum {
    UI_HOME,                // ������
    UI_SETTING,             // ���ý���
    UI_ABOUT,               // ������Ϣ���� 
}UI_LIST;

typedef enum {
    EVENT_TEMP,
    EVENT_HUMI,
    EVENT_ASDASD,
}UI_EVENT;


typedef struct {

    UI_LIST ui_list;
    UI_EVENT event;

    lv_obj_t *main_src;         // ����Ļ
    lv_obj_t *bar_status;       // ״̬��
    lv_obj_t *popup_src;        // ����

    lv_style_t main_style;      // ����ʽ
    lv_style_t bar_style;       // ����ʽ

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
