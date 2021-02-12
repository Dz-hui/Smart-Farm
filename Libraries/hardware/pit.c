/***********************************************************************
*@Author: Dz_hui
*@Date: 2020-09-22 16:09:44
*@FilePath: ??¾¶·Ö¸ô???Ìæ??RT1052_test??¾¶·Ö¸ô???Ìæ??DEMO??¾¶·Ö¸ô???Ìæ??hardware??¾¶·Ö¸ô???Ìæ??pit.c
*@Drscription: 
***********************************************************************/

#include "pit.h"
#include "fsl_pit.h"

/***********************************************************************
*@Function: 
*@Input: 
*@Return: none
*@Author: Dz_hui
*@Date: 2020-09-22 16:13:16
*@Drscription: 
***********************************************************************/
void pit_timer_config(void) {

    pit_config_t pit_config;
	
	CLOCK_SetMux(kCLOCK_PerclkMux,1U);

    CLOCK_SetDiv(kCLOCK_PerclkDiv,0U);

    PIT_GetDefaultConfig(&pit_config);

    PIT_Init(PIT,&pit_config);

    PIT_SetTimerPeriod(PIT,PIT_CHANNLE,USEC_TO_COUNT(500000,PIT_SOURCE_CLOCK));
	
	PIT_StartTimer(PIT,PIT_CHANNLE);
}
