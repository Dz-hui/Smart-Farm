/***********************************************************************
*@Date: 2020-05-22 02:22:45
*@LastEditors: Please set LastEditors
*@LastEditTime: 2021-05-06 23:26:08
*@FilePath: ??���ָ�???��??Smart-Farm??���ָ�???��??User??���ָ�???��??main.h
***********************************************************************/
#ifndef __main_h
#define __main_h

#include "stdint.h"
#include "fsl_qtmr.h"

#include "board.h"

#include "led.h"
#include "key.h"
#include "bsp_lcd.h"
#include "bsp_i2c_touch.h"
#include "bsp_touch_gtxx.h"

#include "dht11.h"
#include "mpu6050.h"


#include "rtboard.h"
// #include "app.h"

#include "uart.h"
#include "gizwits_product.h" 
#include "gpt.h"
#include "i2c.h"
#include "lpi2c.h"
#include "pump.h"
#include "step.h"
#include "pwm.h"

#include "struct.h"
#include "lvgl/lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "lv_draw_main.h"
#include "lv_draw_home.h"
#include "lv_draw_ctrl.h"
#include "lv_draw_setting.h"
#include "lv_draw_about.h"

#include "rt_task_adc.h"
#include "rt_task_lvgl.h"
#include "rt_task_temp.h"
#include "rt_task_gizwit.h"
#include "rt_task_key.h"



#define SUCCESS							    1
#define ERROR					    	    0

#define DEBUG_SWITCH                        1
#if DEBUG_SWITCH
#define DEBUG_ERROR(fmt,arg...)             do{printf("<<-ERROR->> [%d]"fmt"\r\n",__LINE__, ##arg);}while(0)
#define DEBUG_PRINT(fmt,arg...)             do{printf("<<-DEBUG->> [%d]"fmt"\r\n",__LINE__, ##arg);}while(0)                       
#else
#define DEBUG_ERROR(fmt,arg...)
#define DEBUG_PRINT(fmt,arg...)
#endif 

/*-------------------------------------------------Config-----------------------------------------------*/
#define USE_SERIAL_DEBUG
#if defined(USE_SERIAL_DEBUG)
    #define DEBUG_SERIAL            LPUART1 
    #define DEBUG_BAUD              115200
#endif

#define USR_GIZWITS
#if defined(USR_GIZWITS)
    #define GIZWITS_SERIAL          LPUART3 
    #define GIZWITS_BAUD            9600
#endif

#define USE_KEY_ON_CORE
// #define USE_KEY_ON_BOARD

#define USE_DHT11






void Print_Log(void);
void Board_Config(void);


#endif
