/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-03-21 01:08:14
*@FilePath: ??¾¶·Ö¸ô???Ìæ??Smart-Farm??¾¶·Ö¸ô???Ìæ??Libraries??¾¶·Ö¸ô???Ìæ??rtthread??¾¶·Ö¸ô???Ìæ??app??¾¶·Ö¸ô???Ìæ??app.c
*@Drscription: 
***********************************************************************/
/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-03-21 01:08:14
*@FilePath: ??¾¶·Ö¸ô???Ìæ??Smart-Farm??¾¶·Ö¸ô???Ìæ??Libraries??¾¶·Ö¸ô???Ìæ??rtthread??¾¶·Ö¸ô???Ìæ??app??¾¶·Ö¸ô???Ìæ??app.c
*@Drscription: 
***********************************************************************/
#include "app.h"
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "lv_apps\demo\demo.h"
#include "lv_tests\lv_test_theme\lv_test_theme_1.h"
#include "lv_tests\lv_test_theme\lv_test_theme_2.h"

#include "stdlib.h"
#include "stdio.h"

rt_thread_t lv_thread = RT_NULL;
#define LV_THREAD_SIZE				1024*50
void gui_lvgl_init(void *parg);

void gui_lvgl_thread_init(void) {

	lv_thread = rt_thread_create(	"lv thread",
									gui_lvgl_init,
									NULL,
									LV_THREAD_SIZE,
									3,
									20);

	if(lv_thread != RT_NULL)
		rt_thread_startup(lv_thread);
	else 
		DEBUG_PRINT("lv_thread ERR");
}

void gui_lvgl_init(void *parg) {

    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();

	lv_draw_init();

	while(1) {
		
		lv_task_handler();
		rt_thread_delay(5);
	}
}


rt_thread_t gizwit_thread = RT_NULL;
#define GIZWIT_THREAD_SIZE				10*1024
void gizwit_init(void *parg);


void gizwit_thread_init(void) {

	gizwit_thread = rt_thread_create(	"gizwit thread",
										gizwit_init,
										NULL,
										GIZWIT_THREAD_SIZE,
										3,
										20);

	if(gizwit_thread != RT_NULL)
	{
		rt_thread_startup(gizwit_thread);
	}
	else 
		DEBUG_PRINT("gizwit_thread ERR");
}


bool check_gizwitsHandle(void) {

	if(currentDataPoint.valueBH1750 != lastDataPoint.valueBH1750) return true;

	return false;
}

void gizwit_init(void *parg) {

	//³õÊ¼»¯»úÖÇÔÆ
    gizwitsInit();
	//ÅäÖÃ»úÖÇÔÆ
	userInit();

	static bool is_need_to_handle = true;

	while(1) {

		// »úÖÇÔÆÉÏÐÐ
		is_need_to_handle = check_gizwitsHandle();
		if(is_need_to_handle) {
			userHandle();
			is_need_to_handle = false;
		}
		gizwitsHandle((dataPoint_t *)&currentDataPoint);
		rt_thread_delay(1000);
	}
}


rt_thread_t adc_thread = RT_NULL;
#define ADC_THREAD_SIZE				1024
void adc_init(void *parg);

void adc_thread_init(void) {

	adc_thread = rt_thread_create(	"adc thread",
										adc_init,
										NULL,
										ADC_THREAD_SIZE,
										5,
										20);

	if(adc_thread != RT_NULL)
	{
		rt_thread_startup(adc_thread);
	}
	else 
		DEBUG_PRINT("adc_thread ERR");
}

void adc_init(void *parg) {
	while(1) {
		adc_measure(ADC,DISTANCE_ADC_CHANNLE_GROUP,DISTANCE_ADC_CHANNLE);
		adc_measure(ADC,SOIL_ADC_CHANNLE_GROUP,SOIL_ADC_CHANNLE);
		//printf("hello\n");
		rt_thread_mdelay(500);
	}
}


rt_thread_t bh1750_thread = RT_NULL;
#define BH1750_THREAD_SIZE	1024
void bh1750_init(void *parg);

void bh1750_thread_init(void) {

	bh1750_thread = rt_thread_create(	"bh1750 thread",
										bh1750_init,
										NULL,
										BH1750_THREAD_SIZE,
										5,
										20);

	if(bh1750_thread != RT_NULL)
	{
		rt_thread_startup(bh1750_thread);
	}
	else 
		DEBUG_PRINT("bh1750_thread ERR");
}

void bh1750_init(void *parg) {

	while(1) {

		bh1750_measure();
		//printf("hello\n");
		rt_thread_mdelay(500);
		
	}
}

rt_thread_t step_thread = RT_NULL;
#define STEP_THREAD_SIZE	1024
void step_init(void *parg);

void step_thread_init(void) {

	step_thread = rt_thread_create(	"step thread",
										step_init,
										NULL,
										STEP_THREAD_SIZE,
										3,
										20);

	if(step_thread != RT_NULL)
	{
		rt_thread_startup(step_thread);
	}
	else 
		DEBUG_PRINT("step_thread ERR");
}

void step_init(void *parg) {

	user_step_init();
	while(1) {
		curtain_down();
		rt_thread_mdelay(4);
	}
}


rt_thread_t fan_thread = RT_NULL;
#define FAN_THREAD_SIZE	1024
void fan_init(void *parg);

void fan_thread_init(void) {

	fan_thread = rt_thread_create(	"fan thread",
										fan_init,
										NULL,
										FAN_THREAD_SIZE,
										3,
										20);

	if(fan_thread != RT_NULL)
	{
		rt_thread_startup(fan_thread);
	}
	else 
		DEBUG_PRINT("fan_thread ERR");
}

void fan_init(void *parg) {
	while(1) {
		//QTMR_SetupPwm(FAN_QTMR_PORT,FAN_QTMR_CHANNLE,QTMR_PWM_FREQ,0,false,QTMR_SOURCE_CLOCK / 128);
		//GPIO_PinWrite(PUMP_GPIO,PUMP_GPIO_PIN , 1U);
		QTMR_SetupPwm(QTMR_PORT,QTMR_CHANNLE,QTMR_PWM_FREQ,20,false,QTMR_SOURCE_CLOCK / 128);
		//QTMR_StartTimer(QTMR_PORT,QTMR_CHANNLE,kQTMR_PriSrcRiseEdge);
		printf("he\n");
		rt_thread_mdelay(1000);
		
	}
}