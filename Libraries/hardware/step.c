#include "fsl_iomuxc.h"
#include "fsl_gpio.h"  
  
#include "pad_config.h"
#include "step.h"
#include "core_delay.h"


STEP_DEF user_step;

/* 所有引脚均使用同样的PAD配置 */
#define STEP_PAD_CONFIG_DATA            (SRE_0_SLOW_SLEW_RATE| \
                                        DSE_6_R0_6| \
                                        SPEED_2_MEDIUM_100MHz| \
                                        ODE_0_OPEN_DRAIN_DISABLED| \
                                        PKE_0_PULL_KEEPER_DISABLED| \
                                        PUE_0_KEEPER_SELECTED| \
                                        PUS_0_100K_OHM_PULL_DOWN| \
                                        HYS_0_HYSTERESIS_DISABLED)   
										
										

static void STEP_IOMUXC_MUX_Config(void)
{
  /* 步进电机 */    
  /* 设置引脚的复用模式为GPIO，不使用SION功能 */
  IOMUXC_SetPinMux(STEP_IN1_IOMUXC, 0U);

  /* 步进电机，使用同样的IOMUXC MUX配置 */  
  IOMUXC_SetPinMux(STEP_IN2_IOMUXC, 0U); 
  IOMUXC_SetPinMux(STEP_IN3_IOMUXC, 0U);  
  IOMUXC_SetPinMux(STEP_IN4_IOMUXC, 0U);
}

/**
* @brief  初始化步进电机相关IOMUXC的MUX复用配置
* @param  无
* @retval 无
*/
static void STEP_IOMUXC_PAD_Config(void)
{
  /* 步进电机 */    
  IOMUXC_SetPinConfig(STEP_IN1_IOMUXC, STEP_PAD_CONFIG_DATA);  
 
  /* 步进电机，使用同样的IOMUXC PAD配置 */ 
  IOMUXC_SetPinConfig(STEP_IN2_IOMUXC, STEP_PAD_CONFIG_DATA); 
  IOMUXC_SetPinConfig(STEP_IN3_IOMUXC, STEP_PAD_CONFIG_DATA); 
  IOMUXC_SetPinConfig(STEP_IN4_IOMUXC, STEP_PAD_CONFIG_DATA);  
}


 /**
  * @brief  初始化步进电机相关的GPIO模式
  * @param  无
  * @retval 无
  */
static void STEP_GPIO_Mode_Config(void)
{     
  /* 定义gpio初始化配置结构体 */
  gpio_pin_config_t step_config;      
    
   /** 步进电机，GPIO配置 **/       
  step_config.direction = kGPIO_DigitalOutput; //输出模式
  step_config.outputLogic =  0;                //默认高电平    
  step_config.interruptMode = kGPIO_NoIntmode; //不使用中断
  
  /* 初始化步进电机 */
  GPIO_PinInit(STEP_IN1_PORT, STEP_IN1_GPIO_PIN, &step_config);
  GPIO_PinInit(STEP_IN2_PORT, STEP_IN2_GPIO_PIN, &step_config);
  GPIO_PinInit(STEP_IN3_PORT, STEP_IN3_GPIO_PIN, &step_config);
  GPIO_PinInit(STEP_IN4_PORT, STEP_IN4_GPIO_PIN, &step_config);
}

/**
  * @brief  初始化步进电机IO
  * @param  无
  * @retval 无
  */
void STEP_GPIO_Config(void)
{
  /* 初始化GPIO复用、属性、模式 */
  STEP_IOMUXC_MUX_Config();
  STEP_IOMUXC_PAD_Config();
  STEP_GPIO_Mode_Config();
}



void user_step_init(void) {

	user_step.curtain_dir = 0;
	user_step.motor_num = 0;
	user_step.step_delay = 4; 
	user_step.step_move = 0;
	user_step.step_status = STEP_STOP;
}

void step_move(uint8_t ch1,uint8_t ch2,uint8_t ch3,uint8_t ch4) {

	GPIO_PinWrite(STEP_IN1_PORT,STEP_IN1_GPIO_PIN,ch1);
	GPIO_PinWrite(STEP_IN2_PORT,STEP_IN2_GPIO_PIN,ch2);
	GPIO_PinWrite(STEP_IN3_PORT,STEP_IN3_GPIO_PIN,ch3);
	GPIO_PinWrite(STEP_IN4_PORT,STEP_IN4_GPIO_PIN,ch4);
}


/**逆时针转动**/
void curtain_down(void)
{
	switch(user_step.motor_num)
	{
		case 0:
			step_move(1,0,0,0);
			user_step.motor_num++;
			user_step.step_status = STEP_IN_MOVE;
		break;
		
		case 1:
			step_move(0,1,0,0);
			user_step.motor_num++;
			user_step.step_status = STEP_IN_MOVE;
		break;
		
		case 2:
			step_move(0,0,1,0);
			user_step.motor_num++;
			user_step.step_status = STEP_IN_MOVE;
		break;
		
		case 3:
			step_move(0,0,0,1);
			user_step.motor_num = 0;
			user_step.step_status = STEP_STOP;
		break;
	}
}

/**顺时针转动**/
void curtain_up(void)
{
	switch(user_step.motor_num)
	{
		case 0:
		step_move(0,0,0,1);
		user_step.motor_num++;
		user_step.step_status = STEP_IN_MOVE;
		break;
		
		case 1:
		step_move(0,0,1,0);
		user_step.motor_num++;
		user_step.step_status = STEP_IN_MOVE;
		break;
		
		case 2:
		step_move(0,1,0,0);
		user_step.motor_num++;
		user_step.step_status = STEP_IN_MOVE;
		break;
		
		case 3:
		step_move(1,0,0,0);
		user_step.motor_num = 0;
		user_step.step_status = STEP_STOP;
		break;
	}
}

void curtain_stop(void)
{
	GPIO_PinWrite(STEP_IN1_PORT,STEP_IN1_GPIO_PIN,0);
	GPIO_PinWrite(STEP_IN2_PORT,STEP_IN2_GPIO_PIN,0);
	GPIO_PinWrite(STEP_IN3_PORT,STEP_IN3_GPIO_PIN,0);
	GPIO_PinWrite(STEP_IN4_PORT,STEP_IN4_GPIO_PIN,0);
	
}





