#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "fsl_common.h"


#define PUMP_GPIO                GPIO1
#define PUMP_GPIO_PIN            (4U)
#define PUMP_IOMUXC              IOMUXC_GPIO_AD_B0_04_GPIO1_IO04
         
#define PUMP_OFF()               GPIO_PinWrite(PUMP_GPIO, PUMP_GPIO_PIN, 0U)
#define PUMP_ON()                GPIO_PinWrite(PUMP_GPIO, PUMP_GPIO_PIN, 1U)

#define ON  1
#define OFF 0


   
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


void PUMP_GPIO_Config(void);

#endif /* __BSP_LED_H */
