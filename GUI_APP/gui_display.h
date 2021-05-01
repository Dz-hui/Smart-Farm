#ifndef __TEST_H__
#define __TEST_H__

#ifdef __cplusplus
extern "C" {
#endif

	/*********************
	 *      INCLUDES
	 *********************/
#include "stdio.h"
#ifdef LV_CONF_INCLUDE_SIMPLE
#include "lvgl.h"
#include "lv_ex_conf.h"
#else
#include "lvgl/lvgl.h"
#include "lv_ex_conf.h"
#include "lv_conf.h"
#include "gizwits_product.h"
#endif

#define CURTAIN "\xee\x9b\x95"
#define FAN     "\xee\x98\x92"
#define WATER   "\xee\x98\xad"
#define LED     "\xee\x98\xb6"
#define DIALOG_WIDTH        400
#define DIALOG_HEIGTH       350
#define BUTTON_WIDTH        50
#define BUTTON_HEIGTH       50
#define DIALOG_BOTTOM_PADDING 10

typedef struct
{
	lv_obj_t* date_text;
	lv_obj_t* time_text;

}time_typedef_t;

typedef struct
{
	lv_obj_t* water;
	lv_obj_t* fan;
	lv_obj_t* led;
	lv_obj_t* curtain;

}control_typedef_t;

typedef struct
{
	lv_obj_t* temp_lmeter;
	lv_obj_t* temp_num_label;
	lv_style_t temp_main_style;

	lv_obj_t* humi_lmeter;
	lv_obj_t* humi_num_label;
	lv_style_t humi_main_style;

	lv_obj_t* soil_lmeter;
	lv_obj_t* soil_num_label;
	lv_style_t soil_main_style;

	lv_obj_t* light_lmeter;
	lv_obj_t* light_num_label;
	lv_style_t light_main_style;

	lv_obj_t* co2_lmeter;
	lv_obj_t* co2_num_label;
	lv_style_t co2_main_style;

	lv_obj_t* water_lmeter;
	lv_obj_t* water_num_label;
	lv_style_t water_main_style;

}display_typedef_t;

typedef struct
{
	lv_obj_t* fan_dialog;
	lv_obj_t* fan_cancel;
	lv_obj_t* fan_1;
	lv_obj_t* fan_2;
	lv_obj_t* fan_3;
	lv_obj_t* fan_0;

	lv_obj_t* curtain_dialog;
	lv_obj_t* curtain_cancel;
	lv_obj_t* curtain_on;
	lv_obj_t* curtain_off;

	lv_obj_t* water_dialog;
	lv_obj_t* water_cancel;
	lv_obj_t* water_on;
	lv_obj_t* water_off;

	lv_obj_t* led_dialog;
	lv_obj_t* led_cancel;
	lv_obj_t* led_label;

}dialog_typedef_t;

typedef struct
{
	uint16_t year;
	uint8_t mon;
	uint8_t date;
	uint8_t hour;
	uint8_t min;
	uint8_t sec;
	uint8_t temp_value;
	uint8_t humi_value;
	uint8_t soil_value;
	uint8_t light_value;
	uint8_t co2_value;
	uint8_t water_value;

}value_typedef_t;

typedef struct
{
	lv_style_t my_style_btn_release;//按钮释放状态下的样式
	lv_style_t my_style_btn_press;//按钮按下时的样式

}btn_typedef_t;

typedef struct
{
	time_typedef_t time;
	control_typedef_t control_obj;
	display_typedef_t display_obj;
	dialog_typedef_t dialog_obj;
	value_typedef_t obj_value;
	btn_typedef_t btn_status;

}ui_typdef_t;



void update_date_cb(lv_task_t* task);
void update_time_cb(lv_task_t* task);
void temp_task_cb(lv_task_t* task);
void humi_task_cb(lv_task_t* task);
void soil_task_cb(lv_task_t* task);
void light_task_cb(lv_task_t* task);
void co2_task_cb(lv_task_t* task);
void water_task_cb(lv_task_t* task);
static void control_event_handler(lv_obj_t* obj, lv_event_t event);
lv_obj_t* fan_dialog_create(lv_obj_t* parent);
lv_obj_t* curtain_dialog_create(lv_obj_t* parent);
lv_obj_t* water_dialog_create(lv_obj_t* parent);
lv_obj_t* led_dialog_create(lv_obj_t* parent);

static void fan_btn_cb(lv_obj_t* obj, lv_event_t event);
static void curtain_btn_cb(lv_obj_t* obj, lv_event_t event);
static void water_btn_cb(lv_obj_t* obj, lv_event_t event);
static void led_event_handler(lv_obj_t* slider, lv_event_t event);
void smart_farm_display(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // __TEST_H__
