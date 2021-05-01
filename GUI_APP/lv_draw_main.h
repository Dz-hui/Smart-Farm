/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-01 16:37:36
*@FilePath: ??���ָ�???��??Smart-Farm??���ָ�???��??GUI_APP??���ָ�???��??lv_draw_main.h
*@Drscription: 
***********************************************************************/
#ifndef __lv_draw_main_h
#define __lv_draw_main_h

#include "main.h"


typedef enum {
    UI_HOME,                // ������
    UI_SETTING,             // ���ý���
    UI_control,             // ���ƽ���
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

    lv_obj_t *main_src;                 // ����Ļ
    
    lv_obj_t *home_top_gb_layer;        // ״̬��
    lv_obj_t *home_buttom_gb_layer;     // �°���Ļ
    lv_obj_t *home_popup;               // ����
    

    lv_style_t main_style;             // ����ʽ
    lv_style_t bar_style;              // ����ʽ

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
