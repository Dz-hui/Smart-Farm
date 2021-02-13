#include "lv_draw_temp.h"


lv_obj_t* temp_scr;

lv_obj_t* btn_up;
lv_obj_t* btn_down;
lv_obj_t* btn_cancle;

lv_obj_t* label_up;
lv_obj_t* label_down;
lv_obj_t* label_cancle;


lv_style_t temp_style;



static void event_btn_cancle(lv_obj_t* obj, lv_event_t event) {

    if (event == LV_EVENT_RELEASED) {
        lv_obj_del(temp_scr);
	}
}

static void event_btn_up(lv_obj_t* obj, lv_event_t event) {

    if (event == LV_EVENT_RELEASED) {

	}
}

static void event_btn_down(lv_obj_t* obj, lv_event_t event) {

    if (event == LV_EVENT_RELEASED) {

	}
}


void draw_temp(void) {

    temp_scr = lv_obj_create(scr, NULL);
    lv_obj_set_size(temp_scr, 400,200);
    lv_obj_set_pos(temp_scr, 200,100);

    lv_style_copy(&temp_style, &lv_style_scr);
    temp_style.body.main_color = LV_COLOR_MAKE(193,255,193);
    temp_style.body.grad_color = LV_COLOR_MAKE(0,255,0);
    lv_obj_set_style(temp_scr, &temp_style);

    btn_cancle = lv_btn_create(temp_scr,NULL);
    lv_obj_set_size(btn_cancle, 100,50);
    lv_obj_set_pos(btn_cancle, 250,130);
    lv_obj_set_event_cb(btn_cancle, event_btn_cancle);

    btn_up = lv_btn_create(temp_scr,NULL);
    lv_obj_set_size(btn_up, 100,80);
    lv_obj_set_pos(btn_up, 30,10);
    lv_obj_set_event_cb(btn_up, event_btn_up);

    btn_down = lv_btn_create(temp_scr,NULL);
    lv_obj_set_size(btn_down, 100,80);
    lv_obj_set_pos(btn_down, 30,110);
    lv_obj_set_event_cb(btn_down, event_btn_down);

    mks_lvgl_label_set(temp_scr, label_cancle, 280, 145, "#ffffff Return#");
    mks_lvgl_label_set(temp_scr, label_up, 60, 40, "#ffffff UP#");
    mks_lvgl_label_set(temp_scr, label_down, 60, 140, "#ffffff DOWN#");
}


