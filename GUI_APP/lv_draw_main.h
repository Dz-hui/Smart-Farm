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
    UI_LABEL_X_POS = 10,
    UI_LABEL_Y_POS = 10,
    UI_LABEL_X_OFFEST = 200,
    UI_LABEL_Y_OFFEST = 20,
}UI_LABEL_POS;

typedef enum {
    UI_NONE,                
    UI_HOME,                
    UI_SETTING,             
    UI_CONTROL,             
    UI_ABOUT,               
}UI_LIST;

typedef enum {
    EVENT_TEMP,
    EVENT_HUMI,
    EVENT_ASDASD,
}UI_EVENT;


typedef struct {

    UI_LIST ui_list;
    UI_EVENT event;

    lv_obj_t *main_src;                 
    
    lv_obj_t *home_top_gb_layer;        
    lv_obj_t *home_buttom_gb_layer;     
    lv_obj_t *home_popup;               
    

    lv_style_t main_style;          
    lv_style_t bar_style;           
    lv_style_t bar_label_style;     

    lv_obj_t *bar_label_temp;       
    lv_obj_t *bar_label_humi; 
    lv_obj_t *bar_label_co2;    
    lv_obj_t *bar_label_light;
    lv_obj_t *bar_label_water; 
    lv_obj_t *bar_label_soil; 
    lv_obj_t *bar_label_wifi; 
    lv_obj_t *bar_label_time; 
}MY_UI_T;
extern MY_UI_T my_ui; 

void my_lv_obj_del(lv_obj_t *obj);
void lv_draw_init(void);
void lv_label_main_updata(void);
void lv_get_time_dis(uint8_t year,uint8_t mon, uint8_t day, uint8_t hour, uint8_t min, uint8_t sec) ;

lv_obj_t* lv_btn_set(lv_obj_t* scr, lv_obj_t* btn, lv_coord_t btn_w, lv_coord_t btn_h, lv_coord_t x, lv_coord_t y, lv_event_cb_t event_cb);
lv_obj_t* lv_label_set(lv_obj_t* scr, lv_obj_t* label, lv_coord_t x, lv_coord_t y,const char *txt);
lv_obj_t* lv_static_label_set(lv_obj_t* scr, lv_obj_t* label, lv_coord_t x, lv_coord_t y,const char *txt);
lv_obj_t* lv_label_align_set(lv_obj_t* scr, lv_obj_t* label, const char *txt) ;
lv_obj_t* lv_bar_set(lv_obj_t* scr, lv_obj_t* bar, lv_coord_t bar_w, lv_coord_t bar_h, lv_coord_t x, lv_coord_t y,int16_t bar_min, int16_t bar_max ,lv_event_cb_t event_cb);
lv_obj_t* lv_set_kb(lv_obj_t* scr, lv_obj_t *kb, lv_event_cb_t event_cb);
lv_obj_t* lv_set_ta(lv_obj_t* scr, lv_obj_t *ta, lv_obj_t *kb);
#endif
