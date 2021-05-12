/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-03-21 01:08:14
*@FilePath: ??���ָ�???��??Smart-Farm??���ָ�???��??Libraries??���ָ�???��??hardware??���ָ�???��??step.h
*@Drscription: 
***********************************************************************/
#ifndef __STEP__H
#define __STEP__H 

#include "fsl_common.h"

#define STEP_IN1_PORT             			GPIO2
#define STEP_IN1_GPIO_PIN         			(23U)
#define STEP_IN1_IOMUXC           			IOMUXC_GPIO_B1_07_GPIO2_IO23

#define STEP_IN2_PORT             			GPIO2
#define STEP_IN2_GPIO_PIN         			(21U)
#define STEP_IN2_IOMUXC           			IOMUXC_GPIO_B1_05_GPIO2_IO21

#define STEP_IN3_PORT             			GPIO2
#define STEP_IN3_GPIO_PIN         			(24U)
#define STEP_IN3_IOMUXC           			IOMUXC_GPIO_B1_08_GPIO2_IO24

#define STEP_IN4_PORT             			GPIO1
#define STEP_IN4_GPIO_PIN         			(20U)
#define STEP_IN4_IOMUXC           			IOMUXC_GPIO_AD_B1_04_GPIO1_IO20

#define STEP_DIR_UP         0
#define STEP_DIR_DOWN       1

typedef enum {
	STEP_STOP,				// motor is stop status
	STEP_IN_MOVE,			// motor is in move 
	STEP_IDLE,				// idle ,can ctrl 
}STEP_STATUS_DEF;

typedef enum {
	CURTAIN_ON,	//
	CURTAIN_OFF,	//
}CURTAIN_STATUS_DEF;

#define NEED_TO_RUN_STEP			1250

typedef struct {
	uint8_t 			curtain_dir:1;
	uint32_t 			step_move;
	uint8_t 			motor_num;			// 0-3
	STEP_STATUS_DEF		step_status;
    uint32_t            step_delay;   
	CURTAIN_STATUS_DEF	curtain_status;      
}STEP_DEF;
extern STEP_DEF user_step;

void STEP_GPIO_Config(void);
void user_step_init(void);
void curtain_down(void);
void curtain_up(void);
void curtain_stop(void);



#endif


