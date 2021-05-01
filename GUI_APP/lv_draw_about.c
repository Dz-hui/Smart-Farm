/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-01 19:03:18
*@FilePath: ??径分隔???替??Smart-Farm??径分隔???替??GUI_APP??径分隔???替??lv_draw_about.c
*@Drscription: 
***********************************************************************/
#include "lv_draw_about.h"
extern MY_UI_T my_ui; 
extern UI_HOME_T home_obj;

static void back_btn_cb(lv_obj_t *btn, lv_event_t event)
{
   if (event == LV_EVENT_RELEASED)
   {
       lv_clean_home();
       display_home();
   }
}


lv_obj_t* draw_about(void)
{
    lv_obj_t* text = lv_label_create(my_ui.home_buttom_gb_layer, NULL);
    static lv_style_t text_style;
    lv_style_copy(&text_style, &lv_style_plain_color);//样式拷贝
    text_style.text.font = &lv_font_roboto_28;//在样式中使用字体
    text_style.text.color = LV_COLOR_BLACK;
    lv_label_set_style(text, LV_LABEL_STYLE_MAIN, &text_style);//设置样式
    lv_label_set_text(text, "                                       FW : V1.0\n                                Author : He Jiahui\nClass :Electronic Information Engineering Class 1701");
    lv_obj_align(text, my_ui.home_buttom_gb_layer, LV_ALIGN_CENTER, 0, 0);
    back_btn(my_ui.home_buttom_gb_layer, home_obj.back_btn, back_btn_cb, 100, 40, 680, 350, "BACK");

}
