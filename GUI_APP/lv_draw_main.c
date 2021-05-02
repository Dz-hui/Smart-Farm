/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-01 16:37:36
*@FilePath: ??¾¶·Ö¸ô???Ìæ??Smart-Farm??¾¶·Ö¸ô???Ìæ??GUI_APP??¾¶·Ö¸ô???Ìæ??lv_draw_main.c
*@Drscription: 
***********************************************************************/
#include "lv_draw_main.h" 

MY_UI_T my_ui; 


void lv_draw_init(void) {

    lv_style_copy(&my_ui.bar_label_style, &lv_style_plain);
    my_ui.bar_label_style.text.color = LV_COLOR_BLACK;
    my_ui.bar_label_style.text.font = &lv_font_roboto_28;

    my_ui.main_src = lv_scr_act();
    my_ui.home_top_gb_layer = lv_obj_create(my_ui.main_src, NULL);
    lv_obj_set_pos(my_ui.home_top_gb_layer, 0, 0);
    lv_obj_set_size(my_ui.home_top_gb_layer, 800, 80);
    static lv_style_t home_top_gb_style;
    lv_style_copy(&home_top_gb_style, &lv_style_plain_color);

    home_top_gb_style.body.main_color = LV_COLOR_MAKE(0x77, 0x88, 0x99);
    home_top_gb_style.body.grad_color = LV_COLOR_MAKE(0x77, 0x88, 0x99);
    lv_obj_set_style(my_ui.home_top_gb_layer, &home_top_gb_style);

    my_ui.home_buttom_gb_layer = lv_obj_create(my_ui.main_src, NULL);
    lv_obj_set_pos(my_ui.home_buttom_gb_layer, 0, 80);
    lv_obj_set_size(my_ui.home_buttom_gb_layer, 800, 430);
    static lv_style_t home_buttom_gb_style;
    lv_style_copy(&home_buttom_gb_style, &lv_style_plain_color);
    home_buttom_gb_style.body.main_color = LV_COLOR_MAKE(0x13, 0x35, 0x55);
    home_buttom_gb_style.body.grad_color = LV_COLOR_MAKE(0x13, 0x35, 0x55);
    lv_obj_set_style(my_ui.home_buttom_gb_layer, &home_buttom_gb_style);

    my_ui.bar_label_temp = lv_label_set(my_ui.home_top_gb_layer,
                my_ui.bar_label_temp,
                UI_LABEL_X_POS+(UI_LABEL_X_OFFEST*1),
                UI_LABEL_Y_POS,
                "Temperature: 35 C");
                
    my_ui.bar_label_humi = lv_label_set(my_ui.home_top_gb_layer,
                my_ui.bar_label_humi,
                UI_LABEL_X_POS,
                UI_LABEL_Y_POS,
                "Humidity: 70%");
    my_ui.bar_label_co2 = lv_label_set(my_ui.home_top_gb_layer,
                my_ui.bar_label_co2,
                UI_LABEL_X_POS,
                UI_LABEL_Y_POS+UI_LABEL_Y_OFFEST,
                "CO2 Content: 70%");
    my_ui.bar_label_light = lv_label_set(my_ui.home_top_gb_layer,
                my_ui.bar_label_light,
                UI_LABEL_X_POS+(UI_LABEL_X_OFFEST*1),
                UI_LABEL_Y_POS+UI_LABEL_Y_OFFEST,
                "Light Intensity: 50%");
    my_ui.bar_label_water = lv_label_set(my_ui.home_top_gb_layer,
                my_ui.bar_label_water,
                UI_LABEL_X_POS+(UI_LABEL_X_OFFEST*2),
                UI_LABEL_Y_POS,
                "Soil Moisture: 50%");
    my_ui.bar_label_soil = lv_label_set(my_ui.home_top_gb_layer,
                my_ui.bar_label_soil,
                UI_LABEL_X_POS+(UI_LABEL_X_OFFEST*2),
                UI_LABEL_Y_POS+UI_LABEL_Y_OFFEST,
                "Water Remaining: 50%");
    
    lv_label_set_style(my_ui.bar_label_temp, LV_LABEL_STYLE_MAIN, &my_ui.bar_label_style);
    lv_label_set_style(my_ui.bar_label_humi, LV_LABEL_STYLE_MAIN, &my_ui.bar_label_style);  
    lv_label_set_style(my_ui.bar_label_co2, LV_LABEL_STYLE_MAIN, &my_ui.bar_label_style);  
    lv_label_set_style(my_ui.bar_label_light, LV_LABEL_STYLE_MAIN, &my_ui.bar_label_style);  
    lv_label_set_style(my_ui.bar_label_water, LV_LABEL_STYLE_MAIN, &my_ui.bar_label_style);  
    lv_label_set_style(my_ui.bar_label_soil, LV_LABEL_STYLE_MAIN, &my_ui.bar_label_style);    
    
    draw_home();
}

//static void event_popup_draw() {

//    switch(my_ui.event) {

//        case EVENT_TEMP:
//            

//        break;

//        // ....
//    }
//}

void lv_draw_home(void) {

    my_ui.ui_list = UI_HOME;
}


lv_obj_t* lv_btn_set(lv_obj_t* scr, lv_obj_t* btn, lv_coord_t btn_w, lv_coord_t btn_h, lv_coord_t x, lv_coord_t y, lv_event_cb_t event_cb) {

    btn = lv_btn_create(scr, NULL);
    lv_obj_set_size(btn, btn_w, btn_h);
    lv_obj_set_pos(btn, x, y);
    lv_obj_set_event_cb(btn, event_cb);
    return btn;
}

lv_obj_t* lv_label_set(lv_obj_t* scr, lv_obj_t* label, lv_coord_t x, lv_coord_t y,const char *txt) {

    label = lv_label_create(scr, NULL);
    lv_obj_set_pos(label, x, y);
    lv_label_set_text(label,txt);
    return label;
}

lv_obj_t* lv_bar_set(lv_obj_t* scr, lv_obj_t* bar, lv_coord_t bar_w, lv_coord_t bar_h, lv_coord_t x, lv_coord_t y,int16_t bar_min, int16_t bar_max ,lv_event_cb_t event_cb) {

    bar = lv_slider_create(scr, NULL);
    lv_obj_set_size(bar, bar_w, bar_h);
    lv_obj_set_pos(bar, x, y);
    lv_slider_set_range(bar, bar_min, bar_max);
    lv_obj_set_event_cb(bar, event_cb);
    return bar;
}

lv_obj_t* lv_set_kb(lv_obj_t* scr, lv_obj_t *kb, lv_event_cb_t event_cb) { 

    static lv_style_t rel_style, pr_style;

    lv_style_copy(&rel_style, &lv_style_btn_rel);
    rel_style.body.radius = 0;
    rel_style.body.border.width = 1;

    lv_style_copy(&pr_style, &lv_style_btn_pr);
    pr_style.body.radius = 0;
    pr_style.body.border.width = 1;

    kb = lv_kb_create(scr, NULL);
    lv_kb_set_cursor_manage(kb, true);
    lv_kb_set_style(kb, LV_KB_STYLE_BG, &lv_style_transp_tight);
    lv_kb_set_style(kb, LV_KB_STYLE_BTN_REL, &rel_style);
    lv_kb_set_style(kb, LV_KB_STYLE_BTN_PR, &pr_style);
    lv_obj_set_event_cb(kb, event_cb);
}

lv_obj_t* lv_set_ta(lv_obj_t* scr, lv_obj_t *ta, lv_obj_t *kb) { 

    ta = lv_ta_create(scr, NULL); 
    lv_obj_align(ta, NULL, LV_ALIGN_IN_TOP_MID, 0, 10);
    // lv_ta_set_text(ta, "password");
    lv_kb_set_ta(kb, ta);
    return ta;
}


void my_lv_obj_del(lv_obj_t *obj) {
    //lv_obj_clear(obj);
}







