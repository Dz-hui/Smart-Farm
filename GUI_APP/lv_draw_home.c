#include "lv_draw_home.h"



static lv_obj_t* bk_img;

static lv_obj_t* imgbtn_curtain;  
static lv_obj_t* imgbtn_water;
static lv_obj_t* imgbtn_temp;

static lv_obj_t* label_curtain;  
static lv_obj_t* label_water;

LV_IMG_DECLARE(background);		//��������ͼƬ
LV_IMG_DECLARE(curtain);		//��������ͼƬ


static void event_handler_temp(lv_obj_t* obj, lv_event_t event) {

    if (event == LV_EVENT_RELEASED) {

        draw_temp();
	}
}


void draw_home(void) {

    // ����������
    scr = lv_obj_create(NULL, NULL);
    scr = lv_scr_act();

    // ���Ʊ���ͼ
    bk_img = lv_img_create(scr, NULL);
    lv_img_set_src(bk_img, &background);

    // lv_obj_t * bar1 = lv_bar_create(scr, NULL);
    // lv_obj_set_size(bar1, 200, 30);
    // lv_obj_align(bar1, NULL, LV_ALIGN_CENTER, 0, 0);
    // lv_bar_set_anim_time(bar1, 1000);
    // lv_bar_set_value(bar1, 100, LV_ANIM_ON);

    lv_imgbtn_creat_mks(scr, imgbtn_temp, &curtain, &curtain, LV_ALIGN_CENTER, -250, -100, event_handler_temp);
}

void lv_clean_home(void) {
	lv_obj_clean(scr);
}
