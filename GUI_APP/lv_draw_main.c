/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-01 16:37:36
*@FilePath: ??¾¶·Ö¸ô???Ìæ??Smart-Farm??¾¶·Ö¸ô???Ìæ??GUI_APP??¾¶·Ö¸ô???Ìæ??lv_draw_main.c
*@Drscription: 
***********************************************************************/
#include "lv_draw_main.h" 

MY_UI_T my_ui; 


void lv_draw_init(void) {
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
    
    draw_home();
}

static void event_popup_draw(const char *text) {

    switch(my_ui.event) {

        case EVENT_TEMP:
        break;

        // ....
    }
}

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

lv_obj_t* lv_label_align_set(lv_obj_t* scr, lv_obj_t* label, const char *txt) {

    label = lv_label_create(scr, NULL);
    lv_label_set_text(label,txt);
    lv_obj_align(label,scr,LV_ALIGN_CENTER,0,0);
    return label;
}

void my_lv_obj_del(lv_obj_t *obj) {
    //lv_obj_clear(obj);
}







