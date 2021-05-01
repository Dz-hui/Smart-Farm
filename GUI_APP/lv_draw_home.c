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
    char buff[20];


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
        
        
	}
}

static void event_handler_btn_ctrl(lv_obj_t* obj, lv_event_t event) {

    if (event == LV_EVENT_RELEASED) {
        lv_clean_home();
        
	}
}

static void event_handler_btn_about(lv_obj_t* obj, lv_event_t event) {

    if (event == LV_EVENT_RELEASED) {
        lv_clean_home();
        draw_about();

        
	}
}




void draw_home(void) {

    home_display_val(my_ui.home_top_gb_layer, home_obj.home_temp_text, event_handler_temp, 10, 42, "Temperature: 35 C");
    home_display_val(my_ui.home_top_gb_layer, home_obj.home_humi_text, event_handler_humi, 10, 2, "Humidity: 70%");
    home_display_val(my_ui.home_top_gb_layer, home_obj.home_co2_text, event_handler_co2, 270, 2, "CO2 Content: 70%");
    home_display_val(my_ui.home_top_gb_layer, home_obj.home_lighting_text , event_handler_lighting, 520, 42, "Light Intensity: 50%");
    home_display_val(my_ui.home_top_gb_layer, home_obj.home_soil_text, event_handler_soil, 270, 42, "Soil Moisture: 50%");
    home_display_val(my_ui.home_top_gb_layer, home_obj.home_water_text, event_handler_water, 520, 2, "Water Remaining: 50%");

    page_btn(my_ui.home_buttom_gb_layer, home_obj.home_btn_setting, event_handler_btn_setting, 50, 75, "Setting");
    page_btn(my_ui.home_buttom_gb_layer, home_obj.home_btn_ctrl, event_handler_btn_ctrl, 320, 75, "Control");
    page_btn(my_ui.home_buttom_gb_layer, home_obj.home_btn_about, event_handler_btn_about, 590, 75, "About");

    fan_dispaly(my_ui.home_buttom_gb_layer);
    curtain_dispaly(my_ui.home_buttom_gb_layer);
    pump_dispaly(my_ui.home_buttom_gb_layer);
    device_text_dispaly(my_ui.home_buttom_gb_layer);
    led_dispaly(my_ui.home_buttom_gb_layer);
     
}

void display_home(void)
{
    page_btn(my_ui.home_buttom_gb_layer, home_obj.home_btn_setting, event_handler_btn_setting, 50, 75, "Setting");
    page_btn(my_ui.home_buttom_gb_layer, home_obj.home_btn_ctrl, event_handler_btn_ctrl, 320, 75, "Control");
    page_btn(my_ui.home_buttom_gb_layer, home_obj.home_btn_about, event_handler_btn_about, 590, 75, "About");

    fan_dispaly(my_ui.home_buttom_gb_layer);
    curtain_dispaly(my_ui.home_buttom_gb_layer);
    pump_dispaly(my_ui.home_buttom_gb_layer);
    device_text_dispaly(my_ui.home_buttom_gb_layer);
    led_dispaly(my_ui.home_buttom_gb_layer);  
     
}

void lv_clean_home(void) {
	lv_obj_clean(my_ui.home_buttom_gb_layer);
}
