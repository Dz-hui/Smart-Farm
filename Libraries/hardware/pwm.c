/***********************************************************************
*@Author: Dz_hui
*@Date: 2020-06-12 17:05:51
*@FilePath: ??径分隔???替??新建文件夹??径分隔???替??Libraries??径分隔???替??hardware??径分隔???替??pwm.c
*@Drscription: 
***********************************************************************/
#include "pwm.h"
#include "pad_config.h"

#include "fsl_qtmr.h"
#include "fsl_gpio.h"
#include "fsl_iomuxc.h"

/*pad参数设置*/
#define PEM_PAD_SETTING_DATA    (SRE_0_SLOW_SLEW_RATE| \
                                 DSE_6_R0_6| \
								 SPEED_2_MEDIUM_100MHz| \
								 ODE_0_OPEN_DRAIN_DISABLED| \
								 PKE_1_PULL_KEEPER_ENABLED| \
								 PUE_1_PULL_SELECTED| \
								 PUS_2_100K_OHM_PULL_UP| \
								 HYS_0_HYSTERESIS_DISABLED)


/***********************************************************************
*@Function: 
*@Input: 
*@Return: none
*@Author: Dz_hui
*@Date: 2020-06-12 17:17:16
*@Drscription: 
***********************************************************************/
void pwm_gpio_config(void)
{
    gpio_pin_config_t gpio_Config;
    
    gpio_Config.direction=kGPIO_DigitalOutput;
	gpio_Config.outputLogic=1;
	gpio_Config.interruptMode=kGPIO_NoIntmode;
    
    IOMUXC_SetPinConfig(QTMR_CH0_IOMUXC,PEM_PAD_SETTING_DATA);
    IOMUXC_SetPinMux(QTMR_CH0_IOMUXC,0U);
	GPIO_PinInit(QTMR_CH0_GPIO_PORT,QTMR_CH0_GPIO_PIN,&gpio_Config);
	
	#if 1
	gpio_Config.direction=kGPIO_DigitalOutput;
	gpio_Config.outputLogic=1;
	gpio_Config.interruptMode=kGPIO_NoIntmode;
	
	IOMUXC_SetPinConfig(FAN_QTMR_CH1_IOMUXC,PEM_PAD_SETTING_DATA);
    IOMUXC_SetPinMux(FAN_QTMR_CH1_IOMUXC,0U);
	GPIO_PinInit(FAN_QTMR_CH1_GPIO_PORT,FAN_QTMR_CH1_GPIO_PIN,&gpio_Config);
    #endif
}

/***********************************************************************
*@Function: void QTMR_PWM_config(void)
*@Input: 
*@Return: none
*@Author: Dz_hui
*@Date: 2020-06-12 17:36:18
*@Drscription: 
***********************************************************************/
void QTMR_PWM_config(void)
{
    qtmr_config_t qtmr_config;
#if 1
    pwm_gpio_config();
    QTMR_GetDefaultConfig(&qtmr_config);
	qtmr_config.primarySource=kQTMR_ClockDivide_8;
    QTMR_Init(QTMR_PORT,QTMR_CHANNLE,&qtmr_config);
	//QTMR_StopTimer(QTMR_PORT,QTMR_CHANNLE);
    QTMR_SetupPwm(QTMR_PORT, QTMR_CHANNLE, QTMR_PWM_FREQ, 0, false, QTMR_SOURCE_CLOCK / 8);
	QTMR_StartTimer(QTMR_PORT,QTMR_CHANNLE,kQTMR_PriSrcRiseEdge);
#endif

#if 1
	QTMR_GetDefaultConfig(&qtmr_config);
	qtmr_config.primarySource=kQTMR_ClockDivide_8;
    QTMR_Init(FAN_QTMR_PORT,FAN_QTMR_CHANNLE,&qtmr_config);
	QTMR_SetupPwm(FAN_QTMR_PORT,FAN_QTMR_CHANNLE,QTMR_PWM_FREQ,1,false,QTMR_SOURCE_CLOCK / 8);
	QTMR_StartTimer(FAN_QTMR_PORT,FAN_QTMR_CHANNLE,kQTMR_PriSrcRiseEdge);
#endif
}


