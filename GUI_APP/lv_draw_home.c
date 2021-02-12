#include "lv_draw_home.h"



static lv_obj_t* bk_img;

static lv_obj_t* imgbtn_curtain;  
static lv_obj_t* imgbtn_water;

static lv_obj_t* label_curtain;  
static lv_obj_t* label_water;

LV_IMG_DECLARE(background);		//先申明此图片

void draw_home(void) {

    // 创建主界面
    scr = lv_obj_create(NULL, NULL);
    scr = lv_scr_act();

    // 绘制背景图
    bk_img = lv_img_create(scr, NULL);
    lv_img_set_src(bk_img, &background);

    lv_obj_t * bar1 = lv_bar_create(scr, NULL);
    lv_obj_set_size(bar1, 200, 30);
    lv_obj_align(bar1, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_bar_set_anim_time(bar1, 1000);
    lv_bar_set_value(bar1, 100, LV_ANIM_ON);
}

void lv_clean_home(void) {
	lv_obj_clean(scr);
}
