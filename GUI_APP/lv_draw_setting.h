/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-01 19:43:52
*@FilePath: ??¾¶·Ö¸ô???Ìæ??Smart-Farm??¾¶·Ö¸ô???Ìæ??GUI_APP??¾¶·Ö¸ô???Ìæ??lv_draw_setting.h
*@Drscription: 
***********************************************************************/
#ifndef __lv_draw_setting_h
#define __lv_draw_setting_h

#include "main.h"

typedef enum {

    SETTING_LINE_FIRST_X_POS = 1,
    SETTING_LINE_FIRST_Y_POS = 47,
    SETTING_LINE_END_X_POS = 799,
    SETTING_LINE_END_Y_POS = 47,
    SETTING_LINE_OFFSET = 55,

    SETTING_BTN_X_POS = 650,
    SETTING_BTN_Y_POS = 2,
    SETTING_BTN_BACK_W = 100,
    SETTING_BTN_BACK_H = 40,
    SETTING_BTN_OFFEST = 55,

    SETTING_BTN_back_X_POS = 690,
    SETTING_BTN_back_Y_POS = 350,

    SETTING_label_back_X_POS = 705,
    SETTING_label_back_Y_POS = 355,

    SETTING_LABEL_TEMP_X_POS = 20,
    SETTING_LABEL_TEMP_Y_POS = 2,
    SETTING_LABEL_HUMI_X_POS = 20,
    SETTING_LABEL_HUMI_Y_POS = 57,
    SETTING_LABEL_CO2_X_POS = 20,
    SETTING_LABEL_CO2_Y_POS = 112,
    SETTING_LABEL_LIGHT_X_POS = 20,
    SETTING_LABEL_LIGHT_Y_POS = 167,
    SETTING_LABEL_WATER_X_POS = 20,
    SETTING_LABEL_WATER_Y_POS = 222,
    SETTING_LABEL_SOIL_X_POS = 20,
    SETTING_LABEL_SOIL_Y_POS = 277,

    SETTING_LABEL_TEMP_STATUS_X_POS = 680,
    SETTING_LABEL_TEMP_STATUS_Y_POS = 7,
    SETTING_LABEL_STATUS_OFFSET = 55,
    
    SETTING_KB_SRC_X_SIZE = 800,
    SETTING_KB_SRC_Y_SIZE = 400,
    SETTING_KB_SRC_X_POS = 0,
    SETTING_KB_SRC_Y_POS = 0,
}SETTING_LINE_POS;


typedef struct {

    lv_obj_t *setting_label_temp;
    lv_obj_t *setting_label_humi;
    lv_obj_t *setting_label_co2;
    lv_obj_t *setting_label_light;
    lv_obj_t *setting_label_water;
    lv_obj_t *setting_label_soil;

    lv_obj_t *setting_btn_temp_status;
    lv_obj_t *setting_btn_humi_status;
    lv_obj_t *setting_btn_co2_status;
    lv_obj_t *setting_btn_light_status;
    lv_obj_t *setting_btn_water_status;
    lv_obj_t *setting_btn_soil_status;

    lv_obj_t *setting_label_temp_status;
    lv_obj_t *setting_label_humi_status;
    lv_obj_t *setting_label_co2_status;
    lv_obj_t *setting_label_light_status;
    lv_obj_t *setting_label_water_status;
    lv_obj_t *setting_label_soil_status;
    
    lv_style_t setting_line_style;
    lv_style_t setting_label_style;

    lv_obj_t *setting_line1;
    lv_obj_t *setting_line2;
    lv_obj_t *setting_line3;
    lv_obj_t *setting_line4;
    lv_obj_t *setting_line5;
    lv_obj_t *setting_line6;

    lv_obj_t *back_btn;
    lv_obj_t *setting_label_back;

    lv_obj_t *setting_kb_src;
    lv_obj_t *setting_kb;
    lv_obj_t *setting_ta;
    
}UI_SETTING_T;



void draw_setting(void);
lv_obj_t* lv_set_line(lv_obj_t* scr, lv_obj_t * line, lv_point_t *line_points);
void draw_wifi_kb(void);
#endif
