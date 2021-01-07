/***********************************************************************
*@Author: Dz_hui
*@Date: 2020-09-22 16:09:57
*@FilePath: ??���ָ�???��??RT1052_test??���ָ�???��??DEMO??���ָ�???��??hardware??���ָ�???��??pit.h
*@Drscription: 
***********************************************************************/
#ifndef __PIT__H
#define __PIT__H


#include "fsl_common.h"

#define PIT_CHANNLE             kPIT_Chnl_0
#define PIT_SOURCE_CLOCK        CLOCK_GetFreq(kCLOCK_OscClk)

void pit_timer_config(void);
void pit_start_timer(void);


#endif /*__PIT__H*/
