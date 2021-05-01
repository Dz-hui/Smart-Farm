/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-01 18:52:36
*@FilePath: ??径分隔???替??Smart-Farm??径分隔???替??GUI_APP??径分隔???替??lv_home_status.c
*@Drscription: 
***********************************************************************/
#include "lv_home_status.h"
extern UI_HOME_T home_obj;

void fan_dispaly(lv_obj_t *par)
{
    home_obj.home_fan_text = lv_label_create(par, NULL);
    static lv_style_t text_style;
    lv_style_copy(&text_style, &lv_style_plain_color);//样式拷贝
    text_style.text.font = &lv_font_roboto_28;//在样式中使用字体
    text_style.text.color = LV_COLOR_BLACK;
    lv_label_set_style(home_obj.home_fan_text, LV_LABEL_STYLE_MAIN, &text_style);//设置样式
    lv_label_set_text(home_obj.home_fan_text, "Wind Speed : 0 %");
    lv_obj_set_pos(home_obj.home_fan_text, 200, 300);
    //lv_task_create(update_date_cb, 100, LV_TASK_PRIO_MID, NULL);
}

void curtain_dispaly(lv_obj_t* par)
{
    home_obj.home_curtain_text = lv_label_create(par, NULL);
    static lv_style_t text_style;
    lv_style_copy(&text_style, &lv_style_plain_color);//样式拷贝
    text_style.text.font = &lv_font_roboto_28;//在样式中使用字体
    text_style.text.color = LV_COLOR_BLACK;
    lv_label_set_style( home_obj.home_curtain_text, LV_LABEL_STYLE_MAIN, &text_style);//设置样式
    lv_label_set_text( home_obj.home_curtain_text, "Curtain Status  : OFF");
    lv_obj_set_pos( home_obj.home_curtain_text, 500, 300);
    //lv_task_create(update_date_cb, 100, LV_TASK_PRIO_MID, NULL);
}

void led_dispaly(lv_obj_t* par)
{
    home_obj.home_led_text = lv_label_create(par, NULL);
    static lv_style_t text_style;
    lv_style_copy(&text_style, &lv_style_plain_color);//样式拷贝
    text_style.text.font = &lv_font_roboto_28;//在样式中使用字体
    text_style.text.color = LV_COLOR_BLACK;
    lv_label_set_style(home_obj.home_led_text, LV_LABEL_STYLE_MAIN, &text_style);//设置样式
    lv_label_set_text(home_obj.home_led_text, "Light Brightness : 0 %");
    lv_obj_set_pos(home_obj.home_led_text, 500,340);
    //lv_task_create(update_date_cb, 100, LV_TASK_PRIO_MID, NULL);
}


void pump_dispaly(lv_obj_t* par)
{
    home_obj.home_pump_text = lv_label_create(par, NULL);
    static lv_style_t text_style;
    lv_style_copy(&text_style, &lv_style_plain_color);//样式拷贝
    text_style.text.font = &lv_font_roboto_28;//在样式中使用字体
    text_style.text.color = LV_COLOR_BLACK;
    lv_label_set_style(home_obj.home_pump_text, LV_LABEL_STYLE_MAIN, &text_style);//设置样式
    lv_label_set_text(home_obj.home_pump_text, "Pump Status : OFF");
    lv_obj_set_pos(home_obj.home_pump_text, 200, 340);
    //lv_task_create(update_date_cb, 100, LV_TASK_PRIO_MID, NULL);
}

void device_text_dispaly(lv_obj_t* par)
{
    home_obj.device_text = lv_label_create(par, NULL);
    static lv_style_t text_style;
    lv_style_copy(&text_style, &lv_style_plain_color);//样式拷贝
    text_style.text.font = &lv_font_roboto_28;//在样式中使用字体
    text_style.text.color = LV_COLOR_BLACK;
    lv_label_set_style(home_obj.device_text, LV_LABEL_STYLE_MAIN, &text_style);//设置样式
    lv_label_set_text(home_obj.device_text, "DEVICE\nSTATUS");
    lv_obj_set_pos(home_obj.device_text, 40, 300);

}