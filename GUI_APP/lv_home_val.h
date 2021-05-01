/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-01 18:26:15
*@FilePath: ??¾¶·Ö¸ô???Ìæ??Smart-Farm??¾¶·Ö¸ô???Ìæ??GUI_APP??¾¶·Ö¸ô???Ìæ??lv_home_val.h
*@Drscription: 
***********************************************************************/
#ifndef __lv_home_val_h
#define __lv_home_val_h

#include "main.h"

static void event_handler_temp(lv_obj_t* obj, lv_event_t event) ;
static void event_handler_humi(lv_obj_t* obj, lv_event_t event) ;
static void event_handler_co2(lv_obj_t* obj, lv_event_t event) ;
static void event_handler_soil(lv_obj_t* obj, lv_event_t event) ;
static void event_handler_lighting(lv_obj_t* obj, lv_event_t event) ;
static void event_handler_water(lv_obj_t* obj, lv_event_t event) ;


void home_display_val(lv_obj_t* par, lv_obj_t* text, lv_task_cb_t text_cb, int text_pos_x, int text_pos_y, const char* txt);

#endif


