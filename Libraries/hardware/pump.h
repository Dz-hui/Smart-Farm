/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-03-21 01:08:14
*@FilePath: ??径分隔???替??Smart-Farm??径分隔???替??Libraries??径分隔???替??hardware??径分隔???替??pump.h
*@Drscription: 
***********************************************************************/
#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "fsl_common.h"

/*********************************************************
 * LED GPIO端口、引脚号及IOMUXC复用宏定义
 *********************************************************/

#define PUMP_GPIO                GPIO1
#define PUMP_GPIO_PIN            (4U)
#define PUMP_IOMUXC              IOMUXC_GPIO_AD_B0_04_GPIO1_IO04


/** 控制LED灯亮灭的宏，
  * LED低电平亮，设置ON=0，OFF=1
  * 若LED高电平亮，把宏设置成ON=1 ，OFF=0 即可
 */
#define ON  1
#define OFF 0

/* 使用标准的固件库控制IO 
   使用范例：CORE_BOARD_LED(ON); */
   
#define   CORE_BOARD_LED(a) if (a)  \
          GPIO_PinWrite(CORE_BOARD_LED_GPIO, CORE_BOARD_LED_GPIO_PIN, 0U);\
          else    \
          GPIO_PinWrite(CORE_BOARD_LED_GPIO, CORE_BOARD_LED_GPIO_PIN, 1U);

#define   RGB_RED_LED(a)  if (a)  \
          GPIO_PinWrite(RGB_RED_LED_GPIO, RGB_RED_LED_GPIO_PIN, 0U);\
          else    \
          GPIO_PinWrite(RGB_RED_LED_GPIO, RGB_RED_LED_GPIO_PIN, 1U);

#define   RGB_GREEN_LED(a)  if (a)  \
          GPIO_PinWrite(RGB_RGB_GREEN_LED_GPIO, RGB_RGB_GREEN_LED_GPIO_PIN, 0U);\
          else    \
          GPIO_PinWrite(RGB_GREEN_LED_GPIO, RGB_GREEN_LED_GPIO_PIN, 1U);

#define   RGB_BLUE_LED(a) if (a)  \
          GPIO_PinWrite(RGB_BLUE_LED_GPIO, RGB_BLUE_LED_GPIO_PIN, 0U);\
          else    \
          GPIO_PinWrite(RGB_BLUE_LED_GPIO, RGB_BLUE_LED_GPIO_PIN, 1U);     



typedef enum{ 

   PUMO_NONE,
   PUMP_RUN,
   PUMP_STOP,
}PUMP_STATUS_T;


typedef struct {
   
   PUMP_STATUS_T ump_status;
   uint32_t pump_tick_start;
   uint32_t pump_tick_end;

}PUMP_CTRL_T;


/*******************************************************************************
 * 函数声明
 ******************************************************************************/
void PUMP_GPIO_Config(void);

#endif /* __BSP_LED_H */
