/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-01 16:37:36
*@FilePath: ??¾¶·Ö¸ô???Ìæ??Smart-Farm??¾¶·Ö¸ô???Ìæ??GUI_APP??¾¶·Ö¸ô???Ìæ??lv_draw_ctrl.c
*@Drscription: 
***********************************************************************/
#include "lv_draw_ctrl.h"

extern MY_UI_T my_ui; 
UI_CTRL_T control_obj;

lv_point_t control_line_points[4][2] = {
    {{CONTROL_LINE_FIRST_X_POS, CONTROL_LINE_FIRST_Y_POS},
    {CONTROL_LINE_END_X_POS, CONTROL_LINE_END_Y_POS}},

    {{CONTROL_LINE_FIRST_X_POS, CONTROL_LINE_FIRST_Y_POS+(CONTROL_LINE_OFFSET*1)},
    {CONTROL_LINE_END_X_POS, CONTROL_LINE_END_Y_POS+(CONTROL_LINE_OFFSET*1)}},

    {{CONTROL_LINE_FIRST_X_POS, CONTROL_LINE_FIRST_Y_POS+(CONTROL_LINE_OFFSET*2)},
    {CONTROL_LINE_END_X_POS, CONTROL_LINE_END_Y_POS+(CONTROL_LINE_OFFSET*2)}},

    {{CONTROL_LINE_FIRST_X_POS, CONTROL_LINE_FIRST_Y_POS+(CONTROL_LINE_OFFSET*3)},
    {CONTROL_LINE_END_X_POS, CONTROL_LINE_END_Y_POS+(CONTROL_LINE_OFFSET*3)}},
};



static void ctrl_back_btn_cb(lv_obj_t *btn, lv_event_t event)
{
   if (event == LV_EVENT_RELEASED)
   {
       my_ui.ui_list = UI_NONE;
       lv_clean_home();
       draw_home();
   }
}

static void ctrl_pump_back_btn_cb(lv_obj_t *btn, lv_event_t event)
{
   if (event == LV_EVENT_RELEASED)
   {
       lv_clean_home();
       draw_ctrl();
   }
}

static void ctrl_led_back_btn_cb(lv_obj_t *btn, lv_event_t event)
{
   if (event == LV_EVENT_RELEASED)
   {
       lv_clean_home();
       draw_ctrl();
   }
}

static void ctrl_fan_back_btn_cb(lv_obj_t *btn, lv_event_t event)
{
   if (event == LV_EVENT_RELEASED)
   {
       lv_clean_home();
       draw_ctrl();
   }
}

static void ctrl_curtain_back_btn_cb(lv_obj_t *btn, lv_event_t event)
{
   if (event == LV_EVENT_RELEASED)
   {
       lv_clean_home();
       draw_ctrl();
   }
}

static void ctrl_pump_btn_cb(lv_obj_t *btn, lv_event_t event)
{
   if (event == LV_EVENT_RELEASED)
   {
        lv_clean_home();
        event_popup_draw(EVENT_PUMP);
   }
}

static void ctrl_led_btn_cb(lv_obj_t *btn, lv_event_t event)
{
   if (event == LV_EVENT_RELEASED)
   {
        lv_clean_home();
        event_popup_draw(EVENT_LED);
   }
}

static void ctrl_fan_btn_cb(lv_obj_t *btn, lv_event_t event)
{
   if (event == LV_EVENT_RELEASED)
   {
        lv_clean_home();
        event_popup_draw(EVENT_FAN);
   }
}

static void ctrl_curtain_btn_cb(lv_obj_t *btn, lv_event_t event)
{
   if (event == LV_EVENT_RELEASED)
   {
        lv_clean_home();
        event_popup_draw(EVENT_CURTAIN);
   }
}


static void ctrl_pump_on_btn_cb(lv_obj_t *btn, lv_event_t event)
{
   if (event == LV_EVENT_RELEASED)
   {
      
   }
}

static void ctrl_pump_off_btn_cb(lv_obj_t *btn, lv_event_t event)
{
   if (event == LV_EVENT_RELEASED)
   {
      
   }
}

static void ctrl_curtain_on_btn_cb(lv_obj_t *btn, lv_event_t event)
{
   if (event == LV_EVENT_RELEASED)
   {    
       if(user_step.curtain_status == CURTAIN_OFF) {
           curtain_up();
           user_step.curtain_status = CURTAIN_ON;
       }
   }
}

static void ctrl_curtain_off_btn_cb(lv_obj_t *btn, lv_event_t event)
{
   if (event == LV_EVENT_RELEASED)
   {
       if(user_step.curtain_status == CURTAIN_ON) {
           curtain_down();
           user_step.curtain_status = CURTAIN_OFF;
       }
   }
}

static void ctrl_fan_0_btn_cb(lv_obj_t *btn, lv_event_t event)
{
   if (event == LV_EVENT_RELEASED)
   {
      
   }
}


static void ctrl_fan_1_btn_cb(lv_obj_t *btn, lv_event_t event)
{
   if (event == LV_EVENT_RELEASED)
   {
      
   }
}

static void ctrl_fan_2_btn_cb(lv_obj_t *btn, lv_event_t event)
{
   if (event == LV_EVENT_RELEASED)
   {
      
   }
}

static void ctrl_fan_3_btn_cb(lv_obj_t *btn, lv_event_t event)
{
   if (event == LV_EVENT_RELEASED)
   {
      
   }
}

static void ctrl_bar_cb(lv_obj_t* slider, lv_event_t event)
{
    if (event == LV_EVENT_VALUE_CHANGED) {
        
    }
}

void draw_ctrl(void)
{
    lv_style_copy(&control_obj.control_line_style, &lv_style_plain);
    control_obj.control_line_style.line.color = LV_COLOR_BLACK;
    control_obj.control_line_style.line.width = 5;
    control_obj.control_line_style.line.rounded = 0;
    
    lv_style_copy(&control_obj.control_label_style, &lv_style_plain);
    control_obj.control_label_style.text.color = LV_COLOR_WHITE;
    control_obj.control_label_style.text.font = &lv_font_roboto_28;

    control_obj.control_label_pump = lv_label_set(my_ui.home_buttom_gb_layer,
                                                 control_obj.control_label_pump,
                                                 CONTROL_LABEL_pump_X_POS,
                                                 CONTROL_LABEL_pump_Y_POS,
                                                 "PUMP STATUS");   
    control_obj.control_label_led = lv_label_set(my_ui.home_buttom_gb_layer,
                                                 control_obj.control_label_led,
                                                 CONTROL_LABEL_pump_X_POS,
                                                 CONTROL_LABEL_pump_Y_POS+(CONTROL_LABEL_STATUS_OFFSET*1),
                                                 "LED STATUS");   
    control_obj.control_label_fan = lv_label_set(my_ui.home_buttom_gb_layer,
                                                 control_obj.control_label_fan,
                                                 CONTROL_LABEL_pump_X_POS,
                                                 CONTROL_LABEL_pump_Y_POS+(CONTROL_LABEL_STATUS_OFFSET*2),
                                                 "FAN STATUS");   
    control_obj.control_label_curtain = lv_label_set(my_ui.home_buttom_gb_layer,
                                                 control_obj.control_label_curtain,
                                                 CONTROL_LABEL_pump_X_POS,
                                                 CONTROL_LABEL_pump_Y_POS+(CONTROL_LABEL_STATUS_OFFSET*3),
                                                 "CURTAIN STATUS"); 

    lv_label_set_style(control_obj.control_label_pump, LV_LABEL_STYLE_MAIN, &control_obj.control_label_style);           
    lv_label_set_style(control_obj.control_label_led, LV_LABEL_STYLE_MAIN, &control_obj.control_label_style);           
    lv_label_set_style(control_obj.control_label_fan, LV_LABEL_STYLE_MAIN, &control_obj.control_label_style);           
    lv_label_set_style(control_obj.control_label_curtain, LV_LABEL_STYLE_MAIN, &control_obj.control_label_style);           
    
    lv_btn_set(my_ui.home_buttom_gb_layer, 
                control_obj.control_btn_pump_status,
                CONTROL_BTN_BACK_W, 
                CONTROL_BTN_BACK_H,
                CONTROL_BTN_X_POS,
                CONTROL_BTN_Y_POS,
                ctrl_pump_btn_cb);   

    lv_btn_set(my_ui.home_buttom_gb_layer, 
                control_obj.control_btn_led_status,
                CONTROL_BTN_BACK_W, 
                CONTROL_BTN_BACK_H,
                CONTROL_BTN_X_POS,
                CONTROL_BTN_Y_POS+(CONTROL_BTN_OFFEST*1),
                ctrl_led_btn_cb);  

    lv_btn_set(my_ui.home_buttom_gb_layer, 
                control_obj.control_btn_fan_status,
                CONTROL_BTN_BACK_W, 
                CONTROL_BTN_BACK_H,
                CONTROL_BTN_X_POS,
                CONTROL_BTN_Y_POS+(CONTROL_BTN_OFFEST*2),
                ctrl_fan_btn_cb);  

    lv_btn_set(my_ui.home_buttom_gb_layer, 
                control_obj.control_btn_curtain_status,
                CONTROL_BTN_BACK_W, 
                CONTROL_BTN_BACK_H,
                CONTROL_BTN_X_POS,
                CONTROL_BTN_Y_POS+(CONTROL_BTN_OFFEST*3),
                ctrl_curtain_btn_cb);  


    control_obj.control_label_pump_status = lv_label_set(my_ui.home_buttom_gb_layer,
                control_obj.control_label_pump_status,
                SETTING_LABEL_TEMP_STATUS_X_POS,
                SETTING_LABEL_TEMP_STATUS_Y_POS,
                "click me");
    control_obj.control_label_led_status = lv_label_set(my_ui.home_buttom_gb_layer,
                control_obj.control_label_led_status,
                SETTING_LABEL_TEMP_STATUS_X_POS,
                SETTING_LABEL_TEMP_STATUS_Y_POS+(CONTROL_LABEL_STATUS_OFFSET*1),
                "click me");

    control_obj.control_label_fan_status = lv_label_set(my_ui.home_buttom_gb_layer,
                control_obj.control_label_fan_status,
                SETTING_LABEL_TEMP_STATUS_X_POS,
                SETTING_LABEL_TEMP_STATUS_Y_POS+(CONTROL_LABEL_STATUS_OFFSET*2),
                "click me");

    control_obj.control_label_curtain_status = lv_label_set(my_ui.home_buttom_gb_layer,
                control_obj.control_label_curtain_status,
                SETTING_LABEL_TEMP_STATUS_X_POS,
                SETTING_LABEL_TEMP_STATUS_Y_POS+(CONTROL_LABEL_STATUS_OFFSET*3),
                "click me");
    
    lv_label_set_style(control_obj.control_label_pump_status, LV_LABEL_STYLE_MAIN, &control_obj.control_label_style);           
    lv_label_set_style(control_obj.control_label_led_status, LV_LABEL_STYLE_MAIN, &control_obj.control_label_style);           
    lv_label_set_style(control_obj.control_label_fan_status, LV_LABEL_STYLE_MAIN, &control_obj.control_label_style);           
    lv_label_set_style(control_obj.control_label_curtain_status, LV_LABEL_STYLE_MAIN, &control_obj.control_label_style);           

    control_obj.control_line1 = lv_set_line(my_ui.home_buttom_gb_layer, control_obj.control_line1, control_line_points[0]);
    control_obj.control_line2 = lv_set_line(my_ui.home_buttom_gb_layer, control_obj.control_line2, control_line_points[1]);
    control_obj.control_line3 = lv_set_line(my_ui.home_buttom_gb_layer, control_obj.control_line3, control_line_points[2]);
    control_obj.control_line4 = lv_set_line(my_ui.home_buttom_gb_layer, control_obj.control_line4, control_line_points[3]);

    lv_line_set_style(control_obj.control_line1, LV_LINE_STYLE_MAIN, &control_obj.control_line_style);
    lv_line_set_style(control_obj.control_line2, LV_LINE_STYLE_MAIN, &control_obj.control_line_style);
    lv_line_set_style(control_obj.control_line3, LV_LINE_STYLE_MAIN, &control_obj.control_line_style);
    lv_line_set_style(control_obj.control_line4, LV_LINE_STYLE_MAIN, &control_obj.control_line_style);

    lv_btn_set(my_ui.home_buttom_gb_layer, 
               control_obj.control_back_btn,
               CONTROL_BTN_BACK_W, 
               CONTROL_BTN_BACK_H,
               CONTROL_BTN_back_X_POS,
               CONTROL_BTN_back_Y_POS,
               ctrl_back_btn_cb);
   control_obj.control_label_back = lv_label_set(my_ui.home_buttom_gb_layer,
                control_obj.control_label_back,
                CONTROL_label_back_X_POS,
                CONTROL_label_back_Y_POS,
                "BACK");
   lv_label_set_style(control_obj.control_label_back, LV_LABEL_STYLE_MAIN, &control_obj.control_label_style);           

    my_ui.ui_list = UI_CONTROL;
}


static void event_popup_draw(CTRL_EVENT event) {

    switch(event) {

        case EVENT_PUMP:
            lv_clean_home();
            control_obj.control_label_status_choose = lv_label_set(my_ui.home_buttom_gb_layer,
                                                 control_obj.control_label_status_choose,
                                                 CONTROL_label_status_choose_X_POS,
                                                 CONTROL_label_status_choose_Y_POS,
                                                 "Please select status");   
            lv_label_set_style(control_obj.control_label_status_choose, LV_LABEL_STYLE_MAIN, &control_obj.control_label_style);           

            lv_btn_set(my_ui.home_buttom_gb_layer, 
                control_obj.control_label_pump_on,
                CONTROL_BTN_status_W, 
                CONTROL_BTN_status_H,
                CONTROL_BTN_STATUS_X_POS,
                CONTROL_BTN_STATUS_Y_POS,
                ctrl_pump_on_btn_cb);   

            lv_btn_set(my_ui.home_buttom_gb_layer, 
                control_obj.control_label_pump_off,
                CONTROL_BTN_status_W, 
                CONTROL_BTN_status_H,
                CONTROL_BTN_STATUS_X_POS+CONTROL_BTN_STATUS_OFFEST,
                CONTROL_BTN_STATUS_Y_POS,
                ctrl_pump_off_btn_cb);   

            lv_btn_set(my_ui.home_buttom_gb_layer, 
               control_obj.control_pump_back_btn,
               CONTROL_BTN_BACK_W, 
               CONTROL_BTN_BACK_H,
               CONTROL_BTN_back_X_POS,
               CONTROL_BTN_back_Y_POS,
               ctrl_pump_back_btn_cb);

            control_obj.control_label_back = lv_label_set(my_ui.home_buttom_gb_layer,
                control_obj.control_label_back,
                CONTROL_label_back_X_POS,
                CONTROL_label_back_Y_POS,
                "BACK");
            lv_label_set_style(control_obj.control_label_back, LV_LABEL_STYLE_MAIN, &control_obj.control_label_style);           

            control_obj.control_label_pump_on = lv_label_set(my_ui.home_buttom_gb_layer,
                control_obj.control_label_pump_on,
                CONTROL_label_pump_on_X_POS,
                CONTROL_label_pump_on_Y_POS,
                "ON");
            lv_label_set_style(control_obj.control_label_pump_on, LV_LABEL_STYLE_MAIN, &control_obj.control_label_style);           

              
            control_obj.control_label_pump_off = lv_label_set(my_ui.home_buttom_gb_layer,
                control_obj.control_label_pump_off,
                CONTROL_label_pump_on_X_POS+ONTROL_label_pump_on_OFFEST,
                CONTROL_label_pump_on_Y_POS,
                "OFF");
            lv_label_set_style(control_obj.control_label_pump_off, LV_LABEL_STYLE_MAIN, &control_obj.control_label_style);           


        break;
        
        case EVENT_CURTAIN:
            lv_clean_home();
            control_obj.control_label_status_choose = lv_label_set(my_ui.home_buttom_gb_layer,
                                                 control_obj.control_label_status_choose,
                                                 CONTROL_label_status_choose_X_POS,
                                                 CONTROL_label_status_choose_Y_POS,
                                                 "Please select status");   
            lv_label_set_style(control_obj.control_label_status_choose, LV_LABEL_STYLE_MAIN, &control_obj.control_label_style);           

            lv_btn_set(my_ui.home_buttom_gb_layer, 
                control_obj.control_btn_curtain_on,
                CONTROL_BTN_status_W, 
                CONTROL_BTN_status_H,
                CONTROL_BTN_STATUS_X_POS,
                CONTROL_BTN_STATUS_Y_POS,
                ctrl_curtain_on_btn_cb);   
            
            lv_btn_set(my_ui.home_buttom_gb_layer, 
                control_obj.control_btn_curtain_off,
                CONTROL_BTN_status_W, 
                CONTROL_BTN_status_H,
                CONTROL_BTN_STATUS_X_POS+CONTROL_BTN_STATUS_OFFEST,
                CONTROL_BTN_STATUS_Y_POS,
                ctrl_curtain_off_btn_cb);  

            lv_btn_set(my_ui.home_buttom_gb_layer, 
               control_obj.control_curtain_back_btn,
               CONTROL_BTN_BACK_W, 
               CONTROL_BTN_BACK_H,
               CONTROL_BTN_back_X_POS,
               CONTROL_BTN_back_Y_POS,
               ctrl_curtain_back_btn_cb);

            control_obj.control_label_back = lv_label_set(my_ui.home_buttom_gb_layer,
                control_obj.control_label_back,
                CONTROL_label_back_X_POS,
                CONTROL_label_back_Y_POS,
                "BACK");
            lv_label_set_style(control_obj.control_label_back, LV_LABEL_STYLE_MAIN, &control_obj.control_label_style);           

            control_obj.control_label_curtain_on = lv_label_set(my_ui.home_buttom_gb_layer,
                control_obj.control_label_curtain_on,
                CONTROL_label_curtain_on_X_POS,
                CONTROL_label_curtain_on_Y_POS,
                "ON");
            lv_label_set_style(control_obj.control_label_pump_on, LV_LABEL_STYLE_MAIN, &control_obj.control_label_style);           

              
            control_obj.control_label_curtain_off = lv_label_set(my_ui.home_buttom_gb_layer,
                control_obj.control_label_curtain_off,
                CONTROL_label_curtain_on_X_POS+CONTROL_label_curtain_on_OFFES,
                CONTROL_label_curtain_on_Y_POS,
                "OFF");
            lv_label_set_style(control_obj.control_label_curtain_off, LV_LABEL_STYLE_MAIN, &control_obj.control_label_style);  

        break;
    
        case EVENT_LED:
            lv_clean_home();

            lv_style_copy(&control_obj.control_style_bg, &lv_style_pretty);
                          control_obj.control_style_bg.body.main_color = LV_COLOR_BLACK;
                          control_obj.control_style_bg.body.grad_color = LV_COLOR_GRAY;
                          control_obj.control_style_bg.body.radius = LV_RADIUS_CIRCLE;
                          control_obj.control_style_bg.body.border.color = LV_COLOR_WHITE;
            
            lv_style_copy(&control_obj.control_indic_style, &lv_style_pretty_color);
                          control_obj.control_indic_style.body.radius = LV_RADIUS_CIRCLE;
                          control_obj.control_indic_style.body.shadow.width = 8;
                          control_obj.control_indic_style.body.shadow.color = control_obj.control_indic_style.body.main_color;
                          control_obj.control_indic_style.body.padding.left = 3;
                          control_obj.control_indic_style.body.padding.right = 3;
                          control_obj.control_indic_style.body.padding.top = 3;
                          control_obj.control_indic_style.body.padding.bottom = 3;

            lv_style_copy(&control_obj.control_knob_style, &lv_style_pretty);
                          control_obj.control_knob_style.body.radius = LV_RADIUS_CIRCLE;
                          control_obj.control_knob_style.body.opa = LV_OPA_70;
                          control_obj.control_knob_style.body.padding.top = 10;
                          control_obj.control_knob_style.body.padding.bottom = 10;

            control_obj.control_label_status_choose = lv_label_set(my_ui.home_buttom_gb_layer,
                                                 control_obj.control_label_status_choose,
                                                 CONTROL_label_status_choose_X_POS,
                                                 CONTROL_label_status_choose_Y_POS,
                                                 "Please select status");   
            lv_label_set_style(control_obj.control_label_status_choose, LV_LABEL_STYLE_MAIN, &control_obj.control_label_style);           
           
           control_obj.control_bar_led = lv_bar_set(my_ui.home_buttom_gb_layer,
                                                    control_obj.control_bar_led,
                                                    CONTROL_BAR_STATUS_W,
                                                    CONTROL_BAR_STATUS_H,
                                                    CONTROL_BAR_X_POS,
                                                    CONTROL_BAR_Y_POS,
                                                    CONTROL_BAR_MIN_POS,
                                                    CONTROL_BAR_MAX_POS,
                                                    ctrl_bar_cb);

            lv_slider_set_style(control_obj.control_bar_led, LV_SLIDER_STYLE_BG, &control_obj.control_style_bg);
            lv_slider_set_style(control_obj.control_bar_led, LV_SLIDER_STYLE_INDIC, &control_obj.control_indic_style);
            lv_slider_set_style(control_obj.control_bar_led, LV_SLIDER_STYLE_KNOB, &control_obj.control_knob_style);
            
            control_obj.control_label_led_val = lv_label_set(my_ui.home_buttom_gb_layer,
                                                             control_obj.control_label_led_val,
                                                             CONTROL_LABEL_BAR_X_POS,
                                                             CONTROL_LABEL_BAR_Y_POS,
                                                 "lighting : 000");   
            lv_label_set_style(control_obj.control_label_led_val, LV_LABEL_STYLE_MAIN, &control_obj.control_label_style);           

            
            lv_btn_set(my_ui.home_buttom_gb_layer, 
               control_obj.control_led_back_btn,
               CONTROL_BTN_BACK_W, 
               CONTROL_BTN_BACK_H,
               CONTROL_BTN_back_X_POS,
               CONTROL_BTN_back_Y_POS,
               ctrl_led_back_btn_cb);
            control_obj.control_label_back = lv_label_set(my_ui.home_buttom_gb_layer,
                control_obj.control_label_back,
                CONTROL_label_back_X_POS,
                CONTROL_label_back_Y_POS,
                "BACK");
            lv_label_set_style(control_obj.control_label_back, LV_LABEL_STYLE_MAIN, &control_obj.control_label_style);           
            

        break;
        case EVENT_FAN:
            lv_clean_home();
            control_obj.control_label_status_choose = lv_label_set(my_ui.home_buttom_gb_layer,
                                                                   control_obj.control_label_status_choose,
                                                                   CONTROL_label_status_choose_X_POS,
                                                                   CONTROL_label_status_choose_Y_POS,
                                                 "Please select status");   
            lv_label_set_style(control_obj.control_label_status_choose, LV_LABEL_STYLE_MAIN, &control_obj.control_label_style);           

            lv_btn_set(my_ui.home_buttom_gb_layer, 
                       control_obj.control_fan_back_btn,
                       CONTROL_BTN_BACK_W, 
                       CONTROL_BTN_BACK_H,
                       CONTROL_BTN_back_X_POS,
                       CONTROL_BTN_back_Y_POS,
                       ctrl_fan_back_btn_cb);

            lv_btn_set(my_ui.home_buttom_gb_layer, 
                       control_obj.control_btn_fan_0,
                       CONTROL_BTN_FAN_BACK_W, 
                       CONTROL_BTN_FAN_BACK_H,
                       CONTROL_BTN_FAN_X_POS,
                       CONTROL_BTN_FAN_Y_POS,
                       ctrl_fan_0_btn_cb);

            lv_btn_set(my_ui.home_buttom_gb_layer, 
                       control_obj.control_btn_fan_1,
                       CONTROL_BTN_FAN_BACK_W, 
                       CONTROL_BTN_FAN_BACK_H,
                       CONTROL_BTN_FAN_X_POS+(CONTROL_BTN_FAN_OFFEST*1),
                       CONTROL_BTN_FAN_Y_POS,
                       ctrl_fan_1_btn_cb);

            lv_btn_set(my_ui.home_buttom_gb_layer, 
                       control_obj.control_btn_fan_2,
                       CONTROL_BTN_FAN_BACK_H, 
                       CONTROL_BTN_FAN_BACK_H,
                       CONTROL_BTN_FAN_X_POS+(CONTROL_BTN_FAN_OFFEST*2),
                       CONTROL_BTN_FAN_Y_POS,
                       ctrl_fan_2_btn_cb);

            lv_btn_set(my_ui.home_buttom_gb_layer, 
                       control_obj.control_btn_fan_3,
                       CONTROL_BTN_FAN_BACK_W, 
                       CONTROL_BTN_FAN_BACK_H,
                       CONTROL_BTN_FAN_X_POS+(CONTROL_BTN_FAN_OFFEST*3),
                       CONTROL_BTN_FAN_Y_POS,
                       ctrl_fan_3_btn_cb);

            control_obj.control_label_back = lv_label_set(my_ui.home_buttom_gb_layer,
                                                          control_obj.control_label_back,
                                                          CONTROL_label_back_X_POS,
                                                          CONTROL_label_back_Y_POS,
                                                          "BACK");
            lv_label_set_style(control_obj.control_label_back, LV_LABEL_STYLE_MAIN, &control_obj.control_label_style);
            
            control_obj.control_label_fan_0 = lv_label_set(my_ui.home_buttom_gb_layer,
                                                          control_obj.control_label_fan_0,
                                                          CONTROL_label_fan_1_X_POS,
                                                          CONTROL_label_fan_1_Y_POS,
                                                          "0");
            lv_label_set_style(control_obj.control_label_fan_0, LV_LABEL_STYLE_MAIN, &control_obj.control_label_style);
            
            control_obj.control_label_fan_1 = lv_label_set(my_ui.home_buttom_gb_layer,
                                                          control_obj.control_label_fan_1,
                                                          CONTROL_label_fan_1_X_POS+(CONTROL_label_fan_1_OFFEST*1),
                                                          CONTROL_label_fan_1_Y_POS,
                                                          "1");
            lv_label_set_style(control_obj.control_label_fan_1, LV_LABEL_STYLE_MAIN, &control_obj.control_label_style);
            control_obj.control_label_fan_2 = lv_label_set(my_ui.home_buttom_gb_layer,
                                                          control_obj.control_label_fan_2,
                                                          CONTROL_label_fan_1_X_POS+(CONTROL_label_fan_1_OFFEST*2),
                                                          CONTROL_label_fan_1_Y_POS,
                                                          "2");
            lv_label_set_style(control_obj.control_label_fan_2, LV_LABEL_STYLE_MAIN, &control_obj.control_label_style);
            control_obj.control_label_fan_3 = lv_label_set(my_ui.home_buttom_gb_layer,
                                                          control_obj.control_label_fan_3,
                                                          CONTROL_label_fan_1_X_POS+(CONTROL_label_fan_1_OFFEST*3),
                                                          CONTROL_label_fan_1_Y_POS,
                                                          "3");
            lv_label_set_style(control_obj.control_label_fan_3, LV_LABEL_STYLE_MAIN, &control_obj.control_label_style);           


        break;
            
        // ....
    }
}


