
#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"


#include "systick.h"
#include "fsl_debug_console.h"
#include "fsl_common.h"
#include "main.h"
#include "bsp_touch_gtxx.h"
#include "bsp_i2c_touch.h"
#include "rt_task_control.h"


int main(void)
{
    gui_lvgl_thread_init();
    gizwit_thread_init();
    //dht11_thread_init();
    adc_thread_init();
    //bh1750_thread_init();
    ctrl_thread_init();
}

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


void Board_Config(void) 
{
    BOARD_ConfigMPU();
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();
}

/****************************END OF FILE**********************/
