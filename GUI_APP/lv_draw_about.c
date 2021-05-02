/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-01 19:03:18
*@FilePath: ??¾¶·Ö¸ô???Ìæ??Smart-Farm??¾¶·Ö¸ô???Ìæ??GUI_APP??¾¶·Ö¸ô???Ìæ??lv_draw_about.c
*@Drscription: 
***********************************************************************/
#include "lv_draw_about.h"
extern MY_UI_T my_ui; 
UI_ABOUT_T about_obj;


static void about_back_btn_cb(lv_obj_t *btn, lv_event_t event)
{
   if (event == LV_EVENT_RELEASED)
   {
       lv_clean_home();
       draw_home();
   }
}


lv_obj_t* draw_about(void)
{

    lv_style_copy(&about_obj.about_label_style, &lv_style_plain);
    about_obj.about_label_style.text.color = LV_COLOR_WHITE;
    about_obj.about_label_style.text.font = &lv_font_roboto_28;
    
    about_obj.about_label_fw=lv_label_set(my_ui.home_buttom_gb_layer,
                                            about_obj.about_label_fw,
                                            ABOUT_LABEL_FW_X_POS,
                                            ABOUT_LABEL_FW_Y_POS,
                                            "FW : V1.0");

    about_obj.about_label_author=lv_label_set(my_ui.home_buttom_gb_layer,
                                            about_obj.about_label_author,
                                            ABOUT_LABEL_AUTHOR_X_POS,
                                            ABOUT_LABEL_AUTHOR_Y_POS,
                                            "Author : He Jiahui");

    about_obj.about_label_class=lv_label_set(my_ui.home_buttom_gb_layer,
                                            about_obj.about_label_class,
                                            ABOUT_LABEL_CLASS_X_POS,
                                            ABOUT_LABEL_CLASS_Y_POS,
                                            "Class :Electronic Information Engineering Class 1701");
    
    lv_label_set_style(about_obj.about_label_fw, LV_LABEL_STYLE_MAIN, &about_obj.about_label_style);
    lv_label_set_style(about_obj.about_label_author, LV_LABEL_STYLE_MAIN, &about_obj.about_label_style);
    lv_label_set_style(about_obj.about_label_class, LV_LABEL_STYLE_MAIN, &about_obj.about_label_style);

    lv_btn_set(my_ui.home_buttom_gb_layer, 
               about_obj.about_back_btn,
               ABOUT_BTN_BACK_W, 
               ABOUT_BTN_BACK_H,
               ABOUT_BTN_back_X_POS,
               ABOUT_BTN_back_Y_POS,
               about_back_btn_cb);

   about_obj.about_label_back = lv_label_set(my_ui.home_buttom_gb_layer,
                about_obj.about_label_back,
                ABOUT_label_back_X_POS,
                ABOUT_label_back_Y_POS,
                "BACK");
   lv_label_set_style(about_obj.about_label_back, LV_LABEL_STYLE_MAIN, &about_obj.about_label_style);
   

}


