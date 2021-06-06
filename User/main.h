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



#include "rtboard.h"
// #include "app.h"

#include "gizwits_product.h" 

#include "uart.h"
#include "gpt.h"
#include "i2c.h"
#include "lpi2c.h"
#include "pump.h"
#include "step.h"
#include "pwm.h"

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

/*
 * Debug serial config
 * Defualt serial com   :LPUART1
 * Defualt baud         :115200
*/
#define USE_SERIAL_DEBUG
#if defined(USE_SERIAL_DEBUG)
    #define DEBUG_SERIAL            LPUART1 
    #define DEBUG_BAUD              115200
#endif

/*
 * Gizwits(Wifi serial)
 * Defualt serial com   :LPUART1
 * Defualt baud         :115200
*/
#define USR_GIZWITS
#if defined(USR_GIZWITS)

    #define USE_WIFI_UART
    // #define USR_WIFI_SPI
    #if defined(USE_WIFI_UART)
        #define GIZWITS_SERIAL          LPUART3 
        #define GIZWITS_BAUD            9600
    #elif defined(USR_WIFI_SPI)
        #define GIZWITS_SPI             LPUART3 
        #define GIZWITS_BAUD            1Mbs
    #endif

#endif

/*
 * user key
 * On core or On board
*/
#define USE_USER_KEY
#if defined(USE_USER_KEY)
    #define USE_KEY_ON_CORE
    // #define USE_KEY_ON_BOARD
#endif

/*
 * user DH11
*/
#define USE_TEMP_COLLECT
#if defined(USE_TEMP_COLLECT)
#define USE_DHT11
// #define USE_DHT21
#endif

/*
 * user Soil
*/
#define USE_SOIL
#if defined(USE_SOIL)
    /* use adc to collect data */
    #define USE_SOIL_ADC
    #if defined(USE_SOIL_ADC)
        /* defien sensor channel (is not ment adc channel)*/
        #define USE_SOIL_CH0
        // #define USE_SOIL_CH1
        // #define USR_SOIL_CH2
        // #define USE_SOIL_CH3
        // #define USE_SOIL_CH4
        // #define USR_SOIL_CH5
        // #define USE_SOIL_CH6
        // #define USR_SOIL_CH7
    #endif
#endif

/*
 * user Light collect
*/
#define USE_LIGHT_C
#if defined(USE_LIGHT_C) 

    #define USE_LIGHT_ADC
    #if defined(USE_LIGHT_ADC)
        // #define USE_LIGHT_CH0
        #define USE_LIGHT_CH1
        // #define USR_LIGHT_CH2
        // #define USE_LIGHT_CH3
        // #define USE_LIGHT_CH4
        // #define USR_LIGHT_CH5
        // #define USE_LIGHT_CH6
        // #define USR_LIGHT_CH7
    #endif
#endif

/*
 * user Distance collect
*/
#define USE_DISTANCE_C
#if defined(USE_DISTANCE_C)

    #define USE_DISTANCE_ADC
    #if defined(USE_DISTANCE_ADC)
        // #define USE_LIGHT_CH0
        // #define USE_DISTANCE_CH1
        #define USR_DISTANCE_CH2
        // #define USE_DISTANCE_CH3
        // #define USE_DISTANCE_CH4
        // #define USR_DISTANCE_CH5
        // #define USE_DISTANCE_CH6
        // #define USR_DISTANCE_CH7
    #endif

#endif




void Print_Log(void);
void Board_Config(void);


#endif
