/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-02 20:48:02
*@FilePath: ??¾¶·Ö¸ô???Ìæ??ÐÂ½¨ÎÄ¼þ¼Ð??¾¶·Ö¸ô???Ìæ??Libraries??¾¶·Ö¸ô???Ìæ??rtthread??¾¶·Ö¸ô???Ìæ??app??¾¶·Ö¸ô???Ìæ??rt_task_control.c
*@Drscription: 
***********************************************************************/
#include "rt_task_control.h"

rt_thread_t ctrl_thread = RT_NULL;


// void ctrl_thread_init(void) {

// 	ctrl_thread = rt_thread_create(	"step thread",
// 										ctrl_init,
// 										NULL,
// 										CTROL_THREAD_SIZE,
// 										CTROL_THREAD_PRIO,
// 										20);

// 	if(ctrl_thread != RT_NULL)
// 	{
// 		rt_thread_startup(ctrl_thread);
// 	}
// 	else 
// 		DEBUG_PRINT("step_thread ERR");
// }

// void ctrl_init(void *parg) {

// 	user_step_init();
// 	while(1) {
// 		curtain_down();
// 		rt_thread_mdelay(4);
// 	}
// }


void ctrl_thread_init(void) {

	ctrl_thread = rt_thread_create(	"step thread",
										ctrl_init,
										NULL,
										CTROL_THREAD_SIZE,
										CTROL_THREAD_PRIO,
										20);

	if(ctrl_thread != RT_NULL)
	{
		rt_thread_startup(ctrl_thread);
	}
	else 
		DEBUG_PRINT("step_thread ERR");
}

void led_pwm(uint8_t duty)
{
	// QTMR_SetupPwm(QTMR_PORT,QTMR_CHANNLE,QTMR_PWM_FREQ, duty, false,QTMR_SOURCE_CLOCK / 128);  
	QTMR_SetupPwm(QTMR_PORT, QTMR_CHANNLE, QTMR_PWM_FREQ, duty, false, QTMR_SOURCE_CLOCK / 8);
}

void fan_pwm(uint8_t duty)
{
	// QTMR_SetupPwm(FAN_QTMR_PORT, FAN_QTMR_CHANNLE, QTMR_PWM_FREQ, duty, false,QTMR_SOURCE_CLOCK / 128);
	QTMR_SetupPwm(FAN_QTMR_PORT, FAN_QTMR_CHANNLE, QTMR_PWM_FREQ, duty, false, QTMR_SOURCE_CLOCK / 8);
}

void ctrl_init(void *parg) {

	user_step_init();
	
	while(1) {
		
		if(user_step.step_move != 0) {
			user_step.step_status = STEP_IN_MOVE;
			if(user_step.curtain_dir == 0) {
				curtain_down();
			}else{
				curtain_up();
			}
		}
		else {
			user_step.step_status = STEP_IDLE;
			curtain_stop();
		}

		rt_thread_delay(10);
	}
}
