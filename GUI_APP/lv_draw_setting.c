/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-01 19:43:22
*@FilePath: ??¾¶·Ö¸ô???Ìæ??Smart-Farm??¾¶·Ö¸ô???Ìæ??GUI_APP??¾¶·Ö¸ô???Ìæ??lv_draw_setting.c
*@Drscription: 
***********************************************************************/
#include "lv_draw_setting.h"
#include "String.h"

extern MY_UI_T my_ui; 

UI_SETTING_T setting_page;


lv_point_t wifi_line_points[6][2] = {
    {{SETTING_LINE_FIRST_X_POS, SETTING_LINE_FIRST_Y_POS},
    {SETTING_LINE_END_X_POS, SETTING_LINE_END_Y_POS}},

    {{SETTING_LINE_FIRST_X_POS, SETTING_LINE_FIRST_Y_POS+(SETTING_LINE_OFFSET*1)},
    {SETTING_LINE_END_X_POS, SETTING_LINE_END_Y_POS+(SETTING_LINE_OFFSET*1)}},

    {{SETTING_LINE_FIRST_X_POS, SETTING_LINE_FIRST_Y_POS+(SETTING_LINE_OFFSET*2)},
    {SETTING_LINE_END_X_POS, SETTING_LINE_END_Y_POS+(SETTING_LINE_OFFSET*2)}},

    {{SETTING_LINE_FIRST_X_POS, SETTING_LINE_FIRST_Y_POS+(SETTING_LINE_OFFSET*3)},
    {SETTING_LINE_END_X_POS, SETTING_LINE_END_Y_POS+(SETTING_LINE_OFFSET*3)}},

    {{SETTING_LINE_FIRST_X_POS, SETTING_LINE_FIRST_Y_POS+(SETTING_LINE_OFFSET*4)},
    {SETTING_LINE_END_X_POS, SETTING_LINE_END_Y_POS+(SETTING_LINE_OFFSET*4)}},

    {{SETTING_LINE_FIRST_X_POS, SETTING_LINE_FIRST_Y_POS+(SETTING_LINE_OFFSET*5)},
    {SETTING_LINE_END_X_POS, SETTING_LINE_END_Y_POS+(SETTING_LINE_OFFSET*5)}},
};


lv_obj_t* lv_set_line(lv_obj_t* scr, lv_obj_t * line, lv_point_t *line_points) { 

    /*Copy the previous line and apply the new style*/
    line = lv_line_create(scr, NULL);
    lv_line_set_points(line, line_points, 2);     /*Set the points*/
    
    // lv_obj_align(line, NULL, LV_ALIGN_CENTER, 0, 0);

    return line;
}

static void event_handler_wifi_kb_event(lv_obj_t *obj, lv_event_t event) {

   if(obj == setting_page.setting_kb) {

        lv_kb_def_event_cb(obj, event);

        if(event == LV_EVENT_VALUE_CHANGED) {
            
        }else if(event == LV_EVENT_APPLY) {
            

            lv_obj_del(setting_page.setting_kb_src); // É¾³ý¼üÅÌ½çÃæ
        }
    }
}

void draw_wifi_kb(void) {

   setting_page.setting_kb_src = lv_obj_create(my_ui.home_buttom_gb_layer, NULL);
   lv_obj_set_size(setting_page.setting_kb_src, SETTING_KB_SRC_X_SIZE, SETTING_KB_SRC_Y_SIZE);
   lv_obj_set_pos(setting_page.setting_kb_src, SETTING_KB_SRC_X_POS, SETTING_KB_SRC_Y_POS);

   setting_page.setting_kb = lv_set_kb(setting_page.setting_kb_src, setting_page.setting_kb, event_handler_wifi_kb_event);
   setting_page.setting_ta = lv_set_ta(setting_page.setting_kb_src ,setting_page.setting_ta, setting_page.setting_kb);
}


static void setting_back_btn_cb(lv_obj_t *btn, lv_event_t event)
{
   if (event == LV_EVENT_RELEASED)
   {
      lv_clean_home();
      draw_home();
   }
}

static void setting_temp_btn_cb(lv_obj_t *btn, lv_event_t event)
{
   if (event == LV_EVENT_RELEASED)
   {
      draw_wifi_kb();
   }
}

static void setting_humi_btn_cb(lv_obj_t *btn, lv_event_t event)
{
   if (event == LV_EVENT_RELEASED)
   {
      draw_wifi_kb();
   }
}

static void setting_co2_btn_cb(lv_obj_t *btn, lv_event_t event)
{
   if (event == LV_EVENT_RELEASED)
   {
     draw_wifi_kb();
   }
}

static void setting_light_btn_cb(lv_obj_t *btn, lv_event_t event)
{
   if (event == LV_EVENT_RELEASED)
   {
      draw_wifi_kb();
   }
}

static void setting_water_btn_cb(lv_obj_t *btn, lv_event_t event)
{
   if (event == LV_EVENT_RELEASED)
   {
      draw_wifi_kb();
   }
}

static void setting_soil_btn_cb(lv_obj_t *btn, lv_event_t event)
{
   if (event == LV_EVENT_RELEASED)
   {
      draw_wifi_kb();
   }
}
void draw_setting(void)
{
    lv_style_copy(&setting_page.setting_line_style, &lv_style_plain);
    setting_page.setting_line_style.line.color = LV_COLOR_BLACK;
    setting_page.setting_line_style.line.width = 5;
    setting_page.setting_line_style.line.rounded = 0;
    
    lv_style_copy(&setting_page.setting_label_style, &lv_style_plain);
    setting_page.setting_label_style.text.color = LV_COLOR_WHITE;
    setting_page.setting_label_style.text.font = &lv_font_roboto_28;
    

    setting_page.setting_label_temp = lv_label_set(my_ui.home_buttom_gb_layer,
                setting_page.setting_label_temp,
                SETTING_LABEL_TEMP_X_POS,
                SETTING_LABEL_TEMP_Y_POS,
                "TEMP");
    setting_page.setting_label_humi = lv_label_set(my_ui.home_buttom_gb_layer,
                setting_page.setting_label_humi,
                SETTING_LABEL_HUMI_X_POS,
                SETTING_LABEL_HUMI_Y_POS,
                "HUMI");
    setting_page.setting_label_co2 = lv_label_set(my_ui.home_buttom_gb_layer,
                setting_page.setting_label_co2,
                SETTING_LABEL_CO2_X_POS,
                SETTING_LABEL_CO2_Y_POS,
                "CO2");
    setting_page.setting_label_light = lv_label_set(my_ui.home_buttom_gb_layer,
                setting_page.setting_label_light,
                SETTING_LABEL_LIGHT_X_POS,
                SETTING_LABEL_LIGHT_Y_POS,
                "LIGHT");
    setting_page.setting_label_water = lv_label_set(my_ui.home_buttom_gb_layer,
                setting_page.setting_label_water,
                SETTING_LABEL_WATER_X_POS,
                SETTING_LABEL_WATER_Y_POS,
                "WATER");
    setting_page.setting_label_soil = lv_label_set(my_ui.home_buttom_gb_layer,
                setting_page.setting_label_soil,
                SETTING_LABEL_SOIL_X_POS,
                SETTING_LABEL_SOIL_Y_POS,
                "SOIL");

   lv_label_set_style(setting_page.setting_label_temp, LV_LABEL_STYLE_MAIN, &setting_page.setting_label_style);           
   lv_label_set_style(setting_page.setting_label_humi, LV_LABEL_STYLE_MAIN, &setting_page.setting_label_style);           
   lv_label_set_style(setting_page.setting_label_co2, LV_LABEL_STYLE_MAIN, &setting_page.setting_label_style);           
   lv_label_set_style(setting_page.setting_label_light, LV_LABEL_STYLE_MAIN, &setting_page.setting_label_style);           
   lv_label_set_style(setting_page.setting_label_water, LV_LABEL_STYLE_MAIN, &setting_page.setting_label_style);           
   lv_label_set_style(setting_page.setting_label_soil, LV_LABEL_STYLE_MAIN, &setting_page.setting_label_style);           

    lv_btn_set(my_ui.home_buttom_gb_layer, 
                setting_page.setting_btn_temp_status,
                SETTING_BTN_BACK_W, 
                SETTING_BTN_BACK_H,
                SETTING_BTN_X_POS,
                SETTING_BTN_Y_POS,
                setting_temp_btn_cb);
                
    lv_btn_set(my_ui.home_buttom_gb_layer, 
                setting_page.setting_btn_humi_status,
                SETTING_BTN_BACK_W, 
                SETTING_BTN_BACK_H,
                SETTING_BTN_X_POS,
                SETTING_BTN_Y_POS+(SETTING_BTN_OFFEST*1),
                setting_humi_btn_cb);
    lv_btn_set(my_ui.home_buttom_gb_layer, 
                setting_page.setting_btn_co2_status,
                SETTING_BTN_BACK_W, 
                SETTING_BTN_BACK_H,
                SETTING_BTN_X_POS,
                SETTING_BTN_Y_POS+(SETTING_BTN_OFFEST*2),
                setting_co2_btn_cb);
    lv_btn_set(my_ui.home_buttom_gb_layer, 
                setting_page.setting_btn_light_status,
                SETTING_BTN_BACK_W, 
                SETTING_BTN_BACK_H,
                SETTING_BTN_X_POS,
                SETTING_BTN_Y_POS+(SETTING_BTN_OFFEST*3),
                setting_light_btn_cb);
    lv_btn_set(my_ui.home_buttom_gb_layer, 
                setting_page.setting_btn_water_status,
                SETTING_BTN_BACK_W, 
                SETTING_BTN_BACK_H,
                SETTING_BTN_X_POS,
                SETTING_BTN_Y_POS+(SETTING_BTN_OFFEST*4),
                setting_water_btn_cb);
    lv_btn_set(my_ui.home_buttom_gb_layer, 
                setting_page.setting_btn_soil_status,
                SETTING_BTN_BACK_W, 
                SETTING_BTN_BACK_H,
                SETTING_BTN_X_POS,
                SETTING_BTN_Y_POS+(SETTING_BTN_OFFEST*5),
                setting_soil_btn_cb);
    
    setting_page.setting_label_temp_status = lv_label_set(my_ui.home_buttom_gb_layer,
                setting_page.setting_label_temp_status,
                SETTING_LABEL_TEMP_STATUS_X_POS,
                SETTING_LABEL_TEMP_STATUS_Y_POS,
                "33");
    setting_page.setting_label_humi_status = lv_label_set(my_ui.home_buttom_gb_layer,
                setting_page.setting_label_humi_status,
                SETTING_LABEL_TEMP_STATUS_X_POS,
                SETTING_LABEL_TEMP_STATUS_Y_POS+(SETTING_LABEL_STATUS_OFFSET*1),
                "33");
    setting_page.setting_label_co2_status = lv_label_set(my_ui.home_buttom_gb_layer,
                setting_page.setting_label_co2_status,
                SETTING_LABEL_TEMP_STATUS_X_POS,
                SETTING_LABEL_TEMP_STATUS_Y_POS+(SETTING_LABEL_STATUS_OFFSET*2),
                "66");
    setting_page.setting_label_light_status = lv_label_set(my_ui.home_buttom_gb_layer,
                setting_page.setting_label_light_status,
                SETTING_LABEL_TEMP_STATUS_X_POS,
                SETTING_LABEL_TEMP_STATUS_Y_POS+(SETTING_LABEL_STATUS_OFFSET*3),
                "58");
    setting_page.setting_label_water_status = lv_label_set(my_ui.home_buttom_gb_layer,
                setting_page.setting_label_water_status,
                SETTING_LABEL_TEMP_STATUS_X_POS,
                SETTING_LABEL_TEMP_STATUS_Y_POS+(SETTING_LABEL_STATUS_OFFSET*4),
                "36");
    setting_page.setting_label_soil_status = lv_label_set(my_ui.home_buttom_gb_layer,
                setting_page.setting_label_soil_status,
                SETTING_LABEL_TEMP_STATUS_X_POS,
                SETTING_LABEL_TEMP_STATUS_Y_POS+(SETTING_LABEL_STATUS_OFFSET*5),
                "66");
   lv_label_set_style(setting_page.setting_label_temp_status, LV_LABEL_STYLE_MAIN, &setting_page.setting_label_style);           
   lv_label_set_style(setting_page.setting_label_humi_status, LV_LABEL_STYLE_MAIN, &setting_page.setting_label_style);           
   lv_label_set_style(setting_page.setting_label_co2_status, LV_LABEL_STYLE_MAIN, &setting_page.setting_label_style);           
   lv_label_set_style(setting_page.setting_label_light_status, LV_LABEL_STYLE_MAIN, &setting_page.setting_label_style);           
   lv_label_set_style(setting_page.setting_label_water_status, LV_LABEL_STYLE_MAIN, &setting_page.setting_label_style);           
   lv_label_set_style(setting_page.setting_label_soil_status, LV_LABEL_STYLE_MAIN, &setting_page.setting_label_style);           
 
    setting_page.setting_line1 = lv_set_line(my_ui.home_buttom_gb_layer, setting_page.setting_line1, wifi_line_points[0]);
    setting_page.setting_line2 = lv_set_line(my_ui.home_buttom_gb_layer, setting_page.setting_line2, wifi_line_points[1]);
    setting_page.setting_line3 = lv_set_line(my_ui.home_buttom_gb_layer, setting_page.setting_line3, wifi_line_points[2]);
    setting_page.setting_line4 = lv_set_line(my_ui.home_buttom_gb_layer, setting_page.setting_line4, wifi_line_points[3]);
    setting_page.setting_line5 = lv_set_line(my_ui.home_buttom_gb_layer, setting_page.setting_line5, wifi_line_points[4]);
    setting_page.setting_line6 = lv_set_line(my_ui.home_buttom_gb_layer, setting_page.setting_line6, wifi_line_points[5]);
    
    lv_line_set_style(setting_page.setting_line1, LV_LINE_STYLE_MAIN, &setting_page.setting_line_style);
    lv_line_set_style(setting_page.setting_line2, LV_LINE_STYLE_MAIN, &setting_page.setting_line_style);
    lv_line_set_style(setting_page.setting_line3, LV_LINE_STYLE_MAIN, &setting_page.setting_line_style);
    lv_line_set_style(setting_page.setting_line4, LV_LINE_STYLE_MAIN, &setting_page.setting_line_style);
    lv_line_set_style(setting_page.setting_line5, LV_LINE_STYLE_MAIN, &setting_page.setting_line_style);
    lv_line_set_style(setting_page.setting_line6, LV_LINE_STYLE_MAIN, &setting_page.setting_line_style);
    
   lv_btn_set(my_ui.home_buttom_gb_layer, 
               setting_page.back_btn,
               SETTING_BTN_BACK_W, 
               SETTING_BTN_BACK_H,
               SETTING_BTN_back_X_POS,
               SETTING_BTN_back_Y_POS,
               setting_back_btn_cb);
   setting_page.setting_label_back = lv_label_set(my_ui.home_buttom_gb_layer,
                setting_page.setting_label_back,
                SETTING_label_back_X_POS,
                SETTING_label_back_Y_POS,
                "BACK");
   lv_label_set_style(setting_page.setting_label_back, LV_LABEL_STYLE_MAIN, &setting_page.setting_label_style);           

   my_ui.ui_list = UI_SETTING;
}


