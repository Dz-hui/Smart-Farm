/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-01 19:03:35
*@FilePath: ??¾¶·Ö¸ô???Ìæ??Smart-Farm??¾¶·Ö¸ô???Ìæ??GUI_APP??¾¶·Ö¸ô???Ìæ??lv_draw_about.h
*@Drscription: 
***********************************************************************/
#ifndef __lv_draw_about_h
#define __lv_draw_about_h

#include "main.h"


typedef enum {



    ABOUT_LABEL_FW_X_POS = 350,
    ABOUT_LABEL_FW_Y_POS = 120,

    ABOUT_LABEL_AUTHOR_X_POS = 300,
    ABOUT_LABEL_AUTHOR_Y_POS = 170,

    ABOUT_LABEL_CLASS_X_POS = 80,
    ABOUT_LABEL_CLASS_Y_POS = 220,

    ABOUT_BTN_back_X_POS = 690,
    ABOUT_BTN_back_Y_POS = 350,
    ABOUT_BTN_BACK_W = 100,
    ABOUT_BTN_BACK_H = 40,

    ABOUT_label_back_X_POS = 705,
    ABOUT_label_back_Y_POS = 355,
    

}ABOUT_LABEL_POS;


typedef struct {

    lv_obj_t *about_label_fw;
    lv_obj_t *about_label_author;
    lv_obj_t *about_label_class;
    lv_obj_t *about_label_back;

    lv_style_t about_label_style;
    
    lv_obj_t *about_back_btn;
    
}UI_ABOUT_T;



lv_obj_t* draw_about(void);

#endif

