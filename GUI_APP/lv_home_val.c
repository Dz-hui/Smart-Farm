/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-02 02:23:15
*@FilePath: ??���ָ�???��??Smart-Farm??���ָ�???��??GUI_APP??���ָ�???��??lv_home_val.c
*@Drscription: 
***********************************************************************/
/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-01 18:26:03
*@FilePath: ??���ָ�???��??Smart-Farm??���ָ�???��??GUI_APP??���ָ�???��??lv_home_val.c
*@Drscription: 
***********************************************************************/
#include "lv_home_val.h"





void home_display_val(lv_obj_t* par, lv_obj_t* text, lv_task_cb_t text_cb, int text_pos_x, int text_pos_y, const char* txt)
{
    text = lv_label_create(par, NULL);
    static lv_style_t text_style;
    lv_style_copy(&text_style, &lv_style_plain_color);//��ʽ����
    text_style.text.font = &lv_font_roboto_28;//����ʽ��ʹ������
    text_style.text.color = LV_COLOR_BLACK;
    lv_label_set_style(text, LV_LABEL_STYLE_MAIN, &text_style);//������ʽ
    lv_label_set_text(text, txt);//"Temperature: 35 C"
    lv_obj_set_pos(text, text_pos_x, text_pos_y);
    //lv_task_create(update_date_cb, 100, LV_TASK_PRIO_MID, NULL);
}
