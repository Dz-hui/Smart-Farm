#include "fsl_iomuxc.h"
#include "fsl_gpio.h"  
  
#include "pad_config.h"
#include "step.h"
#include "core_delay.h"


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
  /* 核心板的LED灯 */    
  /* 设置引脚的复用模式为GPIO，不使用SION功能 */
  IOMUXC_SetPinMux(STEP_IN1_IOMUXC, 0U);

  /* RGB LED灯，使用同样的IOMUXC MUX配置 */  
  IOMUXC_SetPinMux(STEP_IN2_IOMUXC, 0U); 
  IOMUXC_SetPinMux(STEP_IN3_IOMUXC, 0U);  
  IOMUXC_SetPinMux(STEP_IN4_IOMUXC, 0U);
}

/**
* @brief  初始化LED相关IOMUXC的MUX复用配置
* @param  无
* @retval 无
*/
static void STEP_IOMUXC_PAD_Config(void)
{
  /* 核心板的LED灯 */    
  IOMUXC_SetPinConfig(STEP_IN1_IOMUXC, STEP_PAD_CONFIG_DATA);  
 
  /* RGB LED灯，使用同样的IOMUXC PAD配置 */ 
  IOMUXC_SetPinConfig(STEP_IN2_IOMUXC, STEP_PAD_CONFIG_DATA); 
  IOMUXC_SetPinConfig(STEP_IN3_IOMUXC, STEP_PAD_CONFIG_DATA); 
  IOMUXC_SetPinConfig(STEP_IN4_IOMUXC, STEP_PAD_CONFIG_DATA);  
}


 /**
  * @brief  初始化LED相关的GPIO模式
  * @param  无
  * @retval 无
  */
static void STEP_GPIO_Mode_Config(void)
{     
  /* 定义gpio初始化配置结构体 */
  gpio_pin_config_t step_config;      
    
   /** 核心板的LED灯，GPIO配置 **/       
  step_config.direction = kGPIO_DigitalOutput; //输出模式
  step_config.outputLogic =  0;                //默认高电平    
  step_config.interruptMode = kGPIO_NoIntmode; //不使用中断
  
  /* 初始化 LED GPIO. */
  GPIO_PinInit(STEP_IN1_PORT, STEP_IN1_GPIO_PIN, &step_config);
  
  /* 使用同样的LED config配置RGB LED灯 */
  GPIO_PinInit(STEP_IN2_PORT, STEP_IN2_GPIO_PIN, &step_config);
  GPIO_PinInit(STEP_IN3_PORT, STEP_IN3_GPIO_PIN, &step_config);
  GPIO_PinInit(STEP_IN4_PORT, STEP_IN4_GPIO_PIN, &step_config);
}

/**
  * @brief  初始化控制LED的IO
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


/**逆时针转动**/
void curtain_down(void)
{
	uint8_t i;
	for(i=0;i<4;i++)
	{
		switch(i)
		{
			case 0:
				GPIO_PinWrite(STEP_IN1_PORT,STEP_IN1_GPIO_PIN,1);
				GPIO_PinWrite(STEP_IN2_PORT,STEP_IN2_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN3_PORT,STEP_IN3_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN4_PORT,STEP_IN4_GPIO_PIN,0);
			break;
			
			case 1:
				GPIO_PinWrite(STEP_IN2_PORT,STEP_IN2_GPIO_PIN,1);
				GPIO_PinWrite(STEP_IN1_PORT,STEP_IN1_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN3_PORT,STEP_IN3_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN4_PORT,STEP_IN4_GPIO_PIN,0);
			break;
			
			case 2:
				GPIO_PinWrite(STEP_IN3_PORT,STEP_IN3_GPIO_PIN,1);
				GPIO_PinWrite(STEP_IN2_PORT,STEP_IN2_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN1_PORT,STEP_IN1_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN4_PORT,STEP_IN4_GPIO_PIN,0);
			break;
			
			case 3:
				GPIO_PinWrite(STEP_IN4_PORT,STEP_IN4_GPIO_PIN,1);
				GPIO_PinWrite(STEP_IN2_PORT,STEP_IN2_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN3_PORT,STEP_IN3_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN1_PORT,STEP_IN1_GPIO_PIN,0);
			break;
				
		}
		
		CPU_TS_Tmr_Delay_US(4000);
	}
	
}

/**顺时针转动**/
void curtain_up(void)
{
	uint8_t i;
	for(i=0;i<4;i++)
	{
		switch(i)
		{
			case 0:
				GPIO_PinWrite(STEP_IN4_PORT,STEP_IN4_GPIO_PIN,1);
				GPIO_PinWrite(STEP_IN2_PORT,STEP_IN2_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN3_PORT,STEP_IN3_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN1_PORT,STEP_IN1_GPIO_PIN,0);

			break;
			
			case 1:
				GPIO_PinWrite(STEP_IN3_PORT,STEP_IN3_GPIO_PIN,1);
				GPIO_PinWrite(STEP_IN1_PORT,STEP_IN1_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN2_PORT,STEP_IN2_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN4_PORT,STEP_IN4_GPIO_PIN,0);

			break;
			
			case 2:
				GPIO_PinWrite(STEP_IN2_PORT,STEP_IN2_GPIO_PIN,1);
				GPIO_PinWrite(STEP_IN1_PORT,STEP_IN1_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN3_PORT,STEP_IN3_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN4_PORT,STEP_IN4_GPIO_PIN,0);

			break;
			
			case 3:
				GPIO_PinWrite(STEP_IN1_PORT,STEP_IN1_GPIO_PIN,1);
				GPIO_PinWrite(STEP_IN2_PORT,STEP_IN2_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN3_PORT,STEP_IN3_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN4_PORT,STEP_IN4_GPIO_PIN,0);

			break;
				
		}
		CPU_TS_Tmr_Delay_US(4000);
	}
		

}

void curtain_stop(void)
{
	GPIO_PinWrite(STEP_IN1_PORT,STEP_IN1_GPIO_PIN,0);
	GPIO_PinWrite(STEP_IN2_PORT,STEP_IN2_GPIO_PIN,0);
	GPIO_PinWrite(STEP_IN3_PORT,STEP_IN3_GPIO_PIN,0);
	GPIO_PinWrite(STEP_IN4_PORT,STEP_IN4_GPIO_PIN,0);
	
}





