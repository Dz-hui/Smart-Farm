/***********************************************************************
*@Author: Dz_hui
*@Date: 2020-06-12 17:05:43
*@FilePath: ??¾¶·Ö¸ô???Ìæ??Smart-Farm??¾¶·Ö¸ô???Ìæ??Libraries??¾¶·Ö¸ô???Ìæ??hardware??¾¶·Ö¸ô???Ìæ??pwm.h
*@Drscription: 
***********************************************************************/
#ifndef __PWM__H
#define __PWM__H

#include "fsl_common.h"


#define QTMR_CH0_GPIO_PORT          GPIO1
#define QTMR_CH0_GPIO_PIN           (18U)
#define QTMR_CH0_IOMUXC             IOMUXC_GPIO_AD_B1_02_QTIMER3_TIMER2    

#define QTMR_PORT                   TMR3
#define QTMR_CHANNLE                kQTMR_Channel_2

#define FAN_QTMR_CH1_GPIO_PORT          GPIO2
#define FAN_QTMR_CH1_GPIO_PIN           (27U)
#define FAN_QTMR_CH1_IOMUXC         IOMUXC_GPIO_B1_11_QTIMER4_TIMER3    

#define FAN_QTMR_PORT               TMR4
#define FAN_QTMR_CHANNLE            kQTMR_Channel_3

#define QTMR_PWM_FREQ               50000
#define QTMR_PWM_DUTY_CYCLE         10

#define QTMR_SOURCE_CLOCK           CLOCK_GetFreq(kCLOCK_IpgClk)

void QTMR_PWM_config(void);

#endif /*__PWM__H*/

