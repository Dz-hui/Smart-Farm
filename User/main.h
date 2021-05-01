/***********************************************************************
*@Date: 2020-05-22 02:22:45
*@LastEditors: Please set LastEditors
*@LastEditTime: 2021-05-01 22:47:38
*@FilePath: ??¾¶·Ö¸ô???Ìæ??Smart-Farm??¾¶·Ö¸ô???Ìæ??User??¾¶·Ö¸ô???Ìæ??main.h
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
#include "app.h"

#include "bsp_uart.h"  
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
#include "lv_draw_main.h"
#include "lv_draw_ctrl.h"
#include "lv_draw_setting.h"
#include "lv_draw_about.h"
#include "lv_draw_ctrl.h"
#include "lv_control_display.h"


typedef struct
{
    short gyro_data[3];
    short arce_data[3];
    uint8_t flag:1;
    float adc_v_get;
    
}global_flag_t;

typedef struct
{
    char lcd_adc_str[20];
    char lcd_mpu_g_str[20];
    
}global_lcd_string_t;

extern global_flag_t global_flag;
extern global_lcd_string_t global_lcd_string;

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

void Print_Log(void);
void Board_Config(void);


#endif
