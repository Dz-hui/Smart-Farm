/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-01 16:37:37
*@FilePath: ??¾¶·Ö¸ô???Ìæ??Smart-Farm??¾¶·Ö¸ô???Ìæ??Libraries??¾¶·Ö¸ô???Ìæ??hardware??¾¶·Ö¸ô???Ìæ??Gizwits??¾¶·Ö¸ô???Ìæ??gizwits_product.h
*@Drscription: 
***********************************************************************/
/**
************************************************************
* @file         gizwits_product.h
* @brief        Corresponding gizwits_product.c header file (including product hardware and software version definition)
* @author       Gizwits
* @date         2017-07-19
* @version      V03030000
* @copyright    Gizwits
* 
* @note         æœºæ™ºäº?.å?ä¸ºæ™ºèƒ½ç¡¬ä»¶è€Œç”Ÿ
*               Gizwits Smart Cloud  for Smart Products
*               é“¾æ¥|å¢å€¼Öµ|å¼€æ”¾|ä¸?ç«‹|å®‰å…¨|è‡?æœ‰|è‡?ç”±|ç”Ÿæ€?
*               www.gizwits.com
*
***********************************************************/
#ifndef _GIZWITS_PRODUCT_H
#define _GIZWITS_PRODUCT_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
#include "gizwits_protocol.h"

/**
* MCU software version
*/
#define SOFTWARE_VERSION "03030000"
/**
* MCU Hardware version
*/
#define HARDWARE_VERSION "03010100"

/**
* Communication module type
*/
#define MODULE_TYPE 0 //0,WIFI ;1,GPRS





extern dataPoint_t currentDataPoint;

void userInit(void);
void userHandle(void);
void mcuRestart(void);
void gizTimerMs(void);
int32_t uartWrite(uint8_t *buf, uint32_t len);
int8_t gizwitsEventProcess(eventInfo_t *info, uint8_t *data, uint32_t len);

#ifdef __cplusplus
}
#endif

#endif
