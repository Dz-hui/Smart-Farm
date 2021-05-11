
/***********************************************************************
*@Author: sola
*@Date: 2019-11-16 19:58:35
*@FilePath: ??¾¶·Ö¸ô???Ìæ??Smart-Farm??¾¶·Ö¸ô???Ìæ??User??¾¶·Ö¸ô???Ìæ??main.c
*@Drscription: 
***********************************************************************/
 
#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"


#include "systick.h"
#include "fsl_debug_console.h"
#include "fsl_common.h"
#include "main.h"
#include "bsp_touch_gtxx.h"
#include "bsp_i2c_touch.h"


/***********************************************************************
*@Function: 
*@Input: 
*@Return: none
*@Author: sola
*@Date: 2019-11-17 20:15:06
*@Drscription: 
***********************************************************************/
int main(void)
{
    gui_lvgl_thread_init();
    gizwit_thread_init();
    //dht11_thread_init();
    adc_thread_init();
    //bh1750_thread_init();
    //ctrl_thread_init();
}

/***********************************************************************
*@Function: 
*@Input: 
*@Return: none
*@Author: sola
*@Date: 2019-11-19 23:31:46
*@Drscription: 
***********************************************************************/
void Print_Log(void)
{
    DEBUG_PRINT("\r\n");
    DEBUG_PRINT("CPU:             %d Hz", CLOCK_GetFreq(kCLOCK_CpuClk));
    DEBUG_PRINT("AHB:             %d Hz", CLOCK_GetFreq(kCLOCK_AhbClk));
    DEBUG_PRINT("SEMC:            %d Hz", CLOCK_GetFreq(kCLOCK_SemcClk));
    DEBUG_PRINT("SYSPLL:          %d Hz", CLOCK_GetFreq(kCLOCK_SysPllClk));
    DEBUG_PRINT("SYSPLLPFD0:      %d Hz", CLOCK_GetFreq(kCLOCK_SysPllPfd0Clk));
    DEBUG_PRINT("SYSPLLPFD1:      %d Hz", CLOCK_GetFreq(kCLOCK_SysPllPfd1Clk));
    DEBUG_PRINT("SYSPLLPFD2:      %d Hz", CLOCK_GetFreq(kCLOCK_SysPllPfd2Clk));
    DEBUG_PRINT("SYSPLLPFD3:      %d Hz", CLOCK_GetFreq(kCLOCK_SysPllPfd3Clk));	
}

/***********************************************************************
*@Function: 
*@Input: 
*@Return: none
*@Author: sola
*@Date: 2019-11-19 23:31:50
*@Drscription: 
***********************************************************************/
void Board_Config(void) 
{
    BOARD_ConfigMPU();
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();
}

/****************************END OF FILE**********************/
