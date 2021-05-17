/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-02 19:52:24
*@FilePath: ??���ָ�???��??�½��ļ���??���ָ�???��??Libraries??���ָ�???��??rtthread??���ָ�???��??app??���ָ�???��??rt_task_gizwit.c
*@Drscription: 
***********************************************************************/
#include "rt_task_gizwit.h"

rt_thread_t gizwit_thread = RT_NULL;

void gizwit_thread_init(void) {

	gizwit_thread = rt_thread_create(	"gizwit thread",
										gizwit_init,
										NULL,
										GIZWIT_THREAD_SIZE,
										GIZWIT_THREAD_PRIO,
										20);

	if(gizwit_thread != RT_NULL)
	{
		rt_thread_startup(gizwit_thread);
	}
	else 
		DEBUG_PRINT("gizwit_thread ERR");
}


bool check_gizwitsHandle(void) {

	//if(currentDataPoint.valueBH1750 != lastDataPoint.valueBH1750) return true;
	return false;
}

void giz_data_updata(void) {

	currentDataPoint.valueBH1750 = my_sensor.lighting_value;
	currentDataPoint.valuetemp = my_sensor.temp_value;
	currentDataPoint.valuehumi = my_sensor.humi_value;

	currentDataPoint.valuetemp = 28.8;
	currentDataPoint.valuehumi = 71;

	currentDataPoint.valuesoil = my_sensor.soil_value;
	currentDataPoint.valueCO2 = 356;

	if(my_ctrl.fan_mode == 0) currentDataPoint.valuefan = 0;
	else if(my_ctrl.fan_mode == 1) currentDataPoint.valuefan = 30;
	else if(my_ctrl.fan_mode == 2) currentDataPoint.valuefan = 60;
	else if(my_ctrl.fan_mode == 3) currentDataPoint.valuefan = 90;
	
	if(my_ctrl.pump_status == 0)	currentDataPoint.valuepump = false;
	else if(my_ctrl.pump_status == 1)	currentDataPoint.valuepump = true;

	if(my_ctrl.curtain_status == 0) currentDataPoint.valuecurtain = false;
	else if(my_ctrl.curtain_status == 1)	currentDataPoint.valuecurtain = true;
}

void gizwit_init(void *parg) {

	// key_init();
	GPT_Config(); 
	// UART_Config();
#if defined(USR_GIZWITS)
	lpuart_hw_init(GIZWITS_SERIAL, GIZWITS_BAUD);
	lpuart_hw_enable_interrupt(GIZWITS_SERIAL,4,1,1);
#endif
    gizwitsInit();
    userInit();
	// gizwitsSetMode(WIFI_AIRLINK_MODE);
	while(1) {	

		// if(K1_READ == 0) {
		// 	DEBUG_PRINT("giz enter WIFI_AIRLINK_MODE");
		// 	gizwitsSetMode(WIFI_AIRLINK_MODE);
		// } 
		
		rt_enter_critical();
		giz_data_updata();
		gizwitsHandle((dataPoint_t *)&currentDataPoint);
		userHandle();
		rt_exit_critical();
		rt_thread_delay(100);
	}
}
