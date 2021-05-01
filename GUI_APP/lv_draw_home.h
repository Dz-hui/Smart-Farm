/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-01 16:37:36
*@FilePath: ??¾¶·Ö¸ô???Ìæ??Smart-Farm??¾¶·Ö¸ô???Ìæ??GUI_APP??¾¶·Ö¸ô???Ìæ??lv_draw_home.h
*@Drscription: 
***********************************************************************/
#ifndef __lv_draw_home_h
#define __lv_draw_home_h

#include "main.h"

typedef enum {

    HOME_BTN_X_POS = 50,
    HOME_BTN_Y_POS = 70,
    HOME_BTN_BACK_W = 160,
    HOME_BTN_BACK_H = 160,
    HOME_BTN_OFFEST = 250,

    HOME_BTN_LABEL_X_POS = 80,
    HOME_BTN_LABEL_Y_POS = 130,
    HOME_BTN_LABEL_OFFEST = 250,
  

}HOME_BTN_POS;


typedef struct {
    lv_obj_t *home_btn_setting;
    lv_obj_t *home_btn_ctrl;
    lv_obj_t *home_btn_about;

    lv_obj_t *home_label_setting;
    lv_obj_t *home_label_ctrl;
    lv_obj_t *home_label_about;

    lv_style_t home_label_style;
    
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


void draw_home(void);
void lv_clean_home(void);
void display_home(void);
#endif
