#ifndef __STEP__H
#define __STEP__H 

#include "fsl_common.h"

#define STEP_IN1_PORT             			GPIO2
#define STEP_IN1_GPIO_PIN         			(28U)
#define STEP_IN1_IOMUXC           			IOMUXC_GPIO_B1_12_GPIO2_IO28

#define STEP_IN2_PORT             			GPIO2
#define STEP_IN2_GPIO_PIN         			(29U)
#define STEP_IN2_IOMUXC           			IOMUXC_GPIO_B1_13_GPIO2_IO29

#define STEP_IN3_PORT             			GPIO1
#define STEP_IN3_GPIO_PIN         			(14U)
#define STEP_IN3_IOMUXC           			IOMUXC_GPIO_AD_B0_14_GPIO1_IO14

#define STEP_IN4_PORT             			GPIO1
#define STEP_IN4_GPIO_PIN         			(19U)
#define STEP_IN4_IOMUXC           			IOMUXC_GPIO_AD_B1_03_GPIO1_IO19

#define STEP_DIR_UP         0
#define STEP_DIR_DOWN       1

typedef enum {
	STEP_STOP,				// motor is stop status
	STEP_IN_MOVE,			// motor is in move 
	STEP_IDLE,				// idle ,can ctrl 
}STEP_STATUS_DEF;

typedef struct {
	uint8_t 			curtain_dir:1;
	uint8_t 			step_move;
	uint8_t 			motor_num;			// 0-3
	STEP_STATUS_DEF		step_status;
    uint32_t            step_delay;         
}STEP_DEF;
extern STEP_DEF user_step;

void STEP_GPIO_Config(void);
void curtain_down(void);
void curtain_up(void);
void curtain_stop(void);



#endif


