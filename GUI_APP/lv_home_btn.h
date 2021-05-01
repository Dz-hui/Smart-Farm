/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-01 16:56:56
*@FilePath: ??¾¶·Ö¸ô???Ìæ??Smart-Farm??¾¶·Ö¸ô???Ìæ??GUI_APP??¾¶·Ö¸ô???Ìæ??lv_home_btn.h
*@Drscription: 
***********************************************************************/
#ifndef __lv_home_btn_h
#define __lv_home_btn_h

#include "main.h"

void page_btn(lv_obj_t* par, lv_obj_t* btn, lv_event_cb_t btn_cb, int btn_pos_x, int btn_pos_y, const char* text);
static void event_handler_btn_about(lv_obj_t* obj, lv_event_t event) ;
static void event_handler_btn_ctrl(lv_obj_t* obj, lv_event_t event) ;
static void event_handler_btn_setting(lv_obj_t* obj, lv_event_t event) ;

#endif
