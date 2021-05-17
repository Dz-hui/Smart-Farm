#ifndef __CORE_DELAY_H
#define __CORE_DELAY_H

#include "fsl_common.h"

#define GET_CPU_ClkFreq()       CLOCK_GetFreq(kCLOCK_CpuClk)

#define CPU_TS_INIT_IN_DELAY_FUNCTION   1  


uint32_t CPU_TS_TmrRd(void);
void CPU_TS_TmrInit(void);

void CPU_TS_Tmr_Delay_US(uint32_t us);
#define CPU_TS_Tmr_Delay_MS(ms)     CPU_TS_Tmr_Delay_US(ms*1000)
#define CPU_TS_Tmr_Delay_S(s)       CPU_TS_Tmr_Delay_MS(s*1000)


#endif /* __CORE_DELAY_H */
