/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-01 16:37:36
*@FilePath: ??¾¶·Ö¸ô???Ìæ??Smart-Farm??¾¶·Ö¸ô???Ìæ??GUI_APP??¾¶·Ö¸ô???Ìæ??lv_draw_home.c
*@Drscription: 
***********************************************************************/
#include "lv_draw_home.h"
extern MY_UI_T my_ui; 
UI_HOME_T home_obj;


static void event_handler_temp(lv_obj_t* obj, lv_event_t event) {
    
}

static void event_handler_humi(lv_obj_t* obj, lv_event_t event) {

}

static void event_handler_co2(lv_obj_t* obj, lv_event_t event) {

}

static void event_handler_soil(lv_obj_t* obj, lv_event_t event) {


}

static void event_handler_lighting(lv_obj_t* obj, lv_event_t event) {

}

static void event_handler_water(lv_obj_t* obj, lv_event_t event) {


}

static void event_handler_btn_setting(lv_obj_t* obj, lv_event_t event) {

    if (event == LV_EVENT_RELEASED) {
        lv_clean_home();
        draw_setting();
        
	}
}

static void event_handler_btn_ctrl(lv_obj_t* obj, lv_event_t event) {

    if (event == LV_EVENT_RELEASED) {
        lv_clean_home();
        draw_ctrl();
	}
}

static void event_handler_btn_about(lv_obj_t* obj, lv_event_t event) {

    if (event == LV_EVENT_RELEASED) {
        lv_clean_home();
        draw_about();
        
	}
}

void draw_home(void) {
    lv_style_copy(&home_obj.home_label_style, &lv_style_plain);
    home_obj.home_label_style.text.color = LV_COLOR_WHITE;
    home_obj.home_label_style.text.font = &lv_font_roboto_28;
    
    lv_btn_set(my_ui.home_buttom_gb_layer, 
                home_obj.home_btn_setting,
                HOME_BTN_BACK_W, 
                HOME_BTN_BACK_H,
                HOME_BTN_X_POS,
                HOME_BTN_Y_POS,
                event_handler_btn_setting);
    lv_btn_set(my_ui.home_buttom_gb_layer, 
                home_obj.home_btn_ctrl,
                HOME_BTN_BACK_W, 
                HOME_BTN_BACK_H,
                (HOME_BTN_X_POS+(HOME_BTN_OFFEST*1)),
                HOME_BTN_Y_POS,
                event_handler_btn_ctrl);

    lv_btn_set(my_ui.home_buttom_gb_layer, 
                home_obj.home_btn_about,
                HOME_BTN_BACK_W, 
                HOME_BTN_BACK_W,
                HOME_BTN_X_POS+(HOME_BTN_OFFEST*2),
                HOME_BTN_Y_POS,
                event_handler_btn_about);

    home_obj.home_label_setting=lv_label_set(my_ui.home_buttom_gb_layer,
                home_obj.home_label_setting,
                HOME_BTN_LABEL_X_POS,
                HOME_BTN_LABEL_Y_POS,
                "SETTING");
    home_obj.home_label_ctrl = lv_label_set(my_ui.home_buttom_gb_layer,
                home_obj.home_label_ctrl,
                HOME_BTN_LABEL_X_POS+(HOME_BTN_LABEL_OFFEST-10),
                HOME_BTN_LABEL_Y_POS,
                "CONTROL");
    home_obj.home_label_about = lv_label_set(my_ui.home_buttom_gb_layer,
                home_obj.home_label_about,
                HOME_BTN_LABEL_X_POS+(HOME_BTN_LABEL_OFFEST*2),
                HOME_BTN_LABEL_Y_POS,
                "ABOUT");

    lv_label_set_style(home_obj.home_label_setting, LV_LABEL_STYLE_MAIN, &home_obj.home_label_style);
    lv_label_set_style(home_obj.home_label_ctrl, LV_LABEL_STYLE_MAIN, &home_obj.home_label_style);
    lv_label_set_style(home_obj.home_label_about, LV_LABEL_STYLE_MAIN, &home_obj.home_label_style);

    
    home_obj.home_device_label_status=lv_label_set(my_ui.home_buttom_gb_layer,
                home_obj.home_device_label_status,
                HOME_LABEL_device_status_X_POS,
                HOME_LABEL_device_status_Y_POS,
                "DEVICE\nSTATUS");

                home_obj.home_label_fan_status=lv_label_set(my_ui.home_buttom_gb_layer,
                home_obj.home_label_fan_status,
                HOME_LABEL_status_X_POS,
                HOME_LABEL_status_Y_POS,
                "Wind Speed : 0 %");
                    home_obj.home_label_curtain_status=lv_label_set(my_ui.home_buttom_gb_layer,
                home_obj.home_label_curtain_status,
                HOME_LABEL_status_X_POS+HOME_LABEL_status_X_OFFEST,
                HOME_LABEL_status_Y_POS+HOME_LABEL_status_Y_OFFEST,
                "Curtain Status  : OFF");
                    home_obj.home_label_led_status=lv_label_set(my_ui.home_buttom_gb_layer,
                home_obj.home_label_led_status,
                HOME_LABEL_status_X_POS+HOME_LABEL_status_X_OFFEST,
                HOME_LABEL_status_Y_POS,
                "Light Brightness : 0 %");
                    home_obj.home_label_pump_status=lv_label_set(my_ui.home_buttom_gb_layer,
                home_obj.home_label_pump_status,
                HOME_LABEL_status_X_POS,
                HOME_LABEL_status_Y_POS+HOME_LABEL_status_Y_OFFEST,
                "Pump Status : OFF");

    lv_label_set_style(home_obj.home_label_fan_status, LV_LABEL_STYLE_MAIN, &home_obj.home_label_style);
    lv_label_set_style(home_obj.home_label_curtain_status, LV_LABEL_STYLE_MAIN, &home_obj.home_label_style);
    lv_label_set_style(home_obj.home_label_led_status, LV_LABEL_STYLE_MAIN, &home_obj.home_label_style);
    lv_label_set_style(home_obj.home_label_pump_status, LV_LABEL_STYLE_MAIN, &home_obj.home_label_style);
    lv_label_set_style(home_obj.home_device_label_status, LV_LABEL_STYLE_MAIN, &home_obj.home_label_style);      
    my_ui.ui_list = UI_HOME;
}


char str_label_fan_status[20];
char str_label_curtain_statusp[20];
// char str_label_humi[20];
// char str_label_soil[20];
// char str_label_light[20];
// char str_label_water[20];

void lv_label_home_updata(void) {


    // if() sprintf(str_label_fan_status, "ON");
    // else sprintf(str_label_fan_status, "OFF");
    //lv_label_set_text(home_obj.home_label_fan_status, str_label_fan_status);

    // if() sprintf(str_label_curtain_statusp, "ON");
    // else sprintf(str_label_curtain_statusp, "OFF");
    //lv_label_set_text(home_obj.home_label_fan_status, str_label_curtain_statusp);
}



void lv_clean_home(void) {
	lv_obj_clean(my_ui.home_buttom_gb_layer);
}
