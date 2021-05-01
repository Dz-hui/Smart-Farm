/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-01 16:56:40
*@FilePath: ??���ָ�???��??Smart-Farm??���ָ�???��??GUI_APP??���ָ�???��??lv_home_btn.c
*@Drscription: 
***********************************************************************/
#include "lv_home_btn.h"





void page_btn(lv_obj_t* par, lv_obj_t* btn, lv_event_cb_t btn_cb, int btn_pos_x, int btn_pos_y, const char* text)
{
    lv_style_t page_btn_release;
	lv_style_t page_btn_press;
    
    lv_style_copy(&page_btn_release, &lv_style_plain_color);
    //���ô�ɫ�ı���
    page_btn_release.body.main_color = LV_COLOR_BLACK;
    page_btn_release.body.grad_color = LV_COLOR_BLACK;
    page_btn_release.body.opa = LV_OPA_COVER;//���ñ���ɫ��ȫ��͸��

    //1.2 ����״̬�µ���ʽ
    lv_style_copy(&page_btn_press, &lv_style_plain_color);
    page_btn_press.body.opa = LV_OPA_0;//���ñ���ɫ͸��
    //page_btn_press.body.border.part = LV_BORDER_FULL;
    //���ñ߿����ɫ
    page_btn_press.body.border.color = LV_COLOR_MAKE(0xd8, 0xbf, 0xd8);
    //page_btn_press.body.border.width = 2;//���ñ߿�Ŀ��

    btn = lv_btn_create(par, NULL);
    lv_obj_set_size(btn, 160, 160);//���ô�С
    lv_obj_set_pos(btn, btn_pos_x, btn_pos_y);
    // lv_btn_set_style(btn, LV_BTN_STYLE_REL, &page_btn_release);
    // lv_btn_set_style(btn, LV_BTN_STYLE_PR, &page_btn_press);
    lv_obj_set_click(btn, true);//ʹ�ܵ��
    lv_obj_set_event_cb(btn, btn_cb);//���ð����¼��ص�

    lv_obj_t* btn_label = lv_label_create(btn, NULL);
    static lv_style_t page_label_style;
    lv_style_copy(&page_label_style, &lv_style_plain_color);
    page_label_style.text.color = LV_COLOR_WHITE;
    page_label_style.text.font = &lv_font_roboto_28;
    lv_label_set_style(btn_label, LV_LABEL_STYLE_MAIN, &page_label_style);
    lv_label_set_text(btn_label, text);
    lv_obj_align(btn_label, btn, LV_ALIGN_CENTER, 0, 0);
}

