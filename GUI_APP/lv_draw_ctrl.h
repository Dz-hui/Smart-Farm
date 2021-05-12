/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-01 16:37:36
*@FilePath: ??���ָ�???��??Smart-Farm??���ָ�???��??GUI_APP??���ָ�???��??lv_draw_ctrl.h
*@Drscription: 
***********************************************************************/
#ifndef __lv_draw_ctrlt_h
#define __lv_draw_ctrlt_h

#include "main.h"

typedef enum {

    CONTROL_LINE_FIRST_X_POS = 1,
    CONTROL_LINE_FIRST_Y_POS = 50,
    CONTROL_LINE_END_X_POS = 799,
    CONTROL_LINE_END_Y_POS = 50,
    CONTROL_LINE_OFFSET = 60,

    CONTROL_BTN_X_POS = 650,
    CONTROL_BTN_Y_POS = 5,
    CONTROL_BTN_BACK_W = 150,
    CONTROL_BTN_BACK_H = 40,
    CONTROL_BTN_OFFEST = 60,

    CONTROL_BTN_back_X_POS = 690,
    CONTROL_BTN_back_Y_POS = 350,


    CONTROL_label_back_X_POS = 705,
    CONTROL_label_back_Y_POS = 355,

    CONTROL_LABEL_pump_X_POS = 20,
    CONTROL_LABEL_pump_Y_POS = 5,
    CONTROL_LABEL_led_X_POS = 20,
    CONTROL_LABEL_led_Y_POS = 60,
    CONTROL_LABEL_fan_X_POS = 20,
    CONTROL_LABEL_fan_Y_POS = 115,
    CONTROL_LABEL_curtain_X_POS = 20,
    CONTROL_LABEL_curtain_Y_POS = 170,


    CONTROL_LABEL_pump_STATUS_X_POS = 670,
    CONTROL_LABEL_pump_STATUS_Y_POS = 7,
    CONTROL_LABEL_STATUS_OFFSET = 60,


    CONTROL_label_status_choose_X_POS = 300,
    CONTROL_label_status_choose_Y_POS = 20,
    
    CONTROL_label_pump_on_X_POS = 240,
    CONTROL_label_pump_on_Y_POS = 185,
    ONTROL_label_pump_on_OFFEST = 250,

    CONTROL_label_curtain_on_X_POS = 240,
    CONTROL_label_curtain_on_Y_POS = 185,
    CONTROL_label_curtain_on_OFFES = 250,

    CONTROL_label_fan_1_X_POS = 90,
    CONTROL_label_fan_1_Y_POS = 185,
    CONTROL_label_fan_1_OFFEST = 200,

    CONTROL_LABEL_BAR_X_POS = 350,
    CONTROL_LABEL_BAR_Y_POS = 280,

    CONTROL_BTN_status_W = 160,
    CONTROL_BTN_status_H = 160,
    CONTROL_BTN_STATUS_X_POS = 180,
    CONTROL_BTN_STATUS_Y_POS = 120,
    CONTROL_BTN_STATUS_OFFEST = 250,

    CONTROL_BTN_FAN_X_POS = 20,
    CONTROL_BTN_FAN_Y_POS = 120,
    CONTROL_BTN_FAN_BACK_W = 150,
    CONTROL_BTN_FAN_BACK_H = 150,
    CONTROL_BTN_FAN_OFFEST = 200,

    CONTROL_BAR_STATUS_W = 400,
    CONTROL_BAR_STATUS_H = 60,
    CONTROL_BAR_X_POS = 250,
    CONTROL_BAR_Y_POS = 150,
    CONTROL_BAR_MIN_POS = 0,
    CONTROL_BAR_MAX_POS = 100,

    

}CTRL_LABEL_POS;


typedef enum {
    EVENT_PUMP,
    EVENT_FAN,
    EVENT_LED,
    EVENT_CURTAIN,
}CTRL_EVENT;


typedef struct {

    CTRL_EVENT evnet;
    lv_obj_t *control_label_pump;
    lv_obj_t *control_label_led;
    lv_obj_t *control_label_fan;
    lv_obj_t *control_label_curtain;

    lv_obj_t *control_btn_pump_status;
    lv_obj_t *control_btn_led_status;
    lv_obj_t *control_btn_fan_status;
    lv_obj_t *control_btn_curtain_status;

    lv_obj_t *control_label_pump_status;
    lv_obj_t *control_label_led_status;
    lv_obj_t *control_label_fan_status;
    lv_obj_t *control_label_curtain_status;

    lv_style_t control_line_style;
    lv_style_t control_label_style;
    lv_style_t control_indic_style;
    lv_style_t control_knob_style;
    lv_style_t control_style_bg;

    lv_obj_t *control_line1;
    lv_obj_t *control_line2;
    lv_obj_t *control_line3;
    lv_obj_t *control_line4;


    lv_obj_t *control_back_btn;
    lv_obj_t *control_pump_back_btn;
    lv_obj_t *control_led_back_btn;
    lv_obj_t *control_fan_back_btn;
    lv_obj_t *control_curtain_back_btn;
    lv_obj_t *control_label_back;


    lv_obj_t *control_btn_pump_on;
    lv_obj_t *control_btn_pump_off;
    lv_obj_t *control_btn_curtain_on;
    lv_obj_t *control_btn_curtain_off;
    lv_obj_t *control_btn_fan_0;
    lv_obj_t *control_btn_fan_1;
    lv_obj_t *control_btn_fan_2;
    lv_obj_t *control_btn_fan_3;

    lv_obj_t *control_bar_led;

    lv_obj_t *control_label_pump_on;
    lv_obj_t *control_label_pump_off;
    lv_obj_t *control_label_fan_0;
    lv_obj_t *control_label_fan_1;
    lv_obj_t *control_label_fan_2;
    lv_obj_t *control_label_fan_3;
    lv_obj_t *control_label_curtain_on;
    lv_obj_t *control_label_curtain_off;
    lv_obj_t *control_label_led_val;
    lv_obj_t *control_label_status_choose;
    
}UI_CTRL_T;


static void event_popup_draw(CTRL_EVENT event) ;
void draw_ctrl(void);

#endif
