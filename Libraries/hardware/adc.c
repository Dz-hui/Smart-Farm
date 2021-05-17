/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-01-06 23:27:08
*@FilePath: ??���ָ�???��??�½��ļ���??���ָ�???��??Libraries??���ָ�???��??hardware??���ָ�???��??adc.c
*@Drscription: 
***********************************************************************/


#include "adc.h"
#include "pad_config.h"

#include "exit.h"
#include "fsl_gpio.h"
#include "fsl_adc.h"
#include "fsl_adc_etc.h"
#include "fsl_xbara.h"
#include "fsl_iomuxc.h"
#include "stdio.h"
#include "core_delay.h"
#include "fsl_common.h"

float soil_val;    
//float soil;
float distant_val;
float distance_val;
uint8_t soil_conversion_flg=0;
uint8_t distant_conversion_flg=0;


MEASURE_DATA_DEF soil_data;

/***********************************************************************
*@Drscription: SOIL_PAD_CONFIG
***********************************************************************/
#define ADC_PAD_SETTING      (SRE_0_SLOW_SLEW_RATE|\
                              DSE_6_R0_6 |\
                              SPEED_2_MEDIUM_100MHz|\
                              ODE_0_OPEN_DRAIN_DISABLED|\
                              PKE_0_PULL_KEEPER_DISABLED|\
                              PUE_0_KEEPER_SELECTED|\
                              PUS_0_100K_OHM_PULL_DOWN|\
                              HYS_0_HYSTERESIS_DISABLED)

                
/***********************************************************************
*@Function: 
*@Input: 
*@Return: none
*@Author: Dz_hui
*@Date: 2020-09-16 16:47:11
*@Drscription: 
***********************************************************************/
void adc_iomuxc_mux_config(void)
{
    /*��ʼ��ADC��ص�IOMUXC��MUX��������*/
    IOMUXC_SetPinMux(SOIL_GPIO_IOMUXC,0U);
    IOMUXC_SetPinMux(LIGHT_GPIO_IOMUXC,0U);
    
    IOMUXC_SetPinMux(DISTANCE_GPIO_IOMUXC,0U);
    // IOMUXC_SetPinMux(DISTANCE_GPIO1_IOMUXC,0U);
    // IOMUXC_SetPinMux(DISTANCE_VIN_IOMUXC,0U);
}

void adc_iomuxc_pad_config(void)
{
    /*��ʼ��ADC�ⲿ�������ŵ�PAD����*/
    IOMUXC_SetPinConfig(SOIL_GPIO_IOMUXC,ADC_PAD_SETTING);
    IOMUXC_SetPinConfig(LIGHT_GPIO_IOMUXC,ADC_PAD_SETTING);

//     IOMUXC_SetPinConfig(DISTANCE_GPIO_IOMUXC,ADC_PAD_SETTING);
//     IOMUXC_SetPinConfig(DISTANCE_GPIO1_IOMUXC,ADC_PAD_SETTING);
//     IOMUXC_SetPinConfig(DISTANCE_VIN_IOMUXC,ADC_PAD_SETTING);
}

void adc_gpio_config(void)
{
    gpio_pin_config_t adc_pin_config;
    adc_pin_config.direction = kGPIO_DigitalInput;
	adc_pin_config.interruptMode = kGPIO_NoIntmode; //��ʹ���ж�

	GPIO_PinInit(SOIL_GPIO_PORT, SOIL_GPIO_PIN,&adc_pin_config);
    GPIO_PinInit(LIGHT_GPIO_PORT,LIGHT_GPIO_PIN,&adc_pin_config);
    // GPIO_PinInit(DISTANCE_GPIO_PORT,DISTANCE_GPIO_PIN,&adc_pin_config);
    
    // adc_pin_config.direction = kGPIO_DigitalOutput;
	// adc_pin_config.interruptMode = kGPIO_NoIntmode;
	// adc_pin_config.outputLogic = 0;
	// GPIO_PinInit(DISTANCE_VIN_GPIO_PORT,DISTANCE_VIN_GPIO_PIN,&adc_pin_config);
    // GPIO_PinInit(DISTANCE_GPIO1_GPIO_PORT,DISTANCE_GPIO1_GPIO_PIN,&adc_pin_config);  
}

/***********************************************************************
*@Function: 
*@Input: 
*@Return: none
*@Author: Dz_hui
*@Date: 2020-09-16 17:04:32
*@Drscription: 
***********************************************************************/
void adc_config(void)
{
    adc_config_t adc_config;

    adc_gpio_config();
    adc_iomuxc_mux_config();
    adc_iomuxc_pad_config();
    
    //CPU_TS_Tmr_Delay_US(5000);
    // GPIO_WritePinOutput(DISTANCE_VIN_GPIO_PORT,DISTANCE_VIN_GPIO_PIN,1);
    //CPU_TS_Tmr_Delay_US(5000);
    // GPIO_WritePinOutput(DISTANCE_GPIO1_GPIO_PORT,DISTANCE_GPIO1_GPIO_PIN,1);

    ADC_GetDefaultConfig(&adc_config);
    ADC_Init(ADC,&adc_config);
    if( kStatus_Success == ADC_DoAutoCalibration(ADC) )
        printf("Check Succeed\n");
    else 
        printf("Check Error\n");
    
}

/***********************************************************************
*@Function: 
*@Input: 
*@Return: none
*@Author: Dz_hui
*@Date: 2020-09-16 17:04:32
*@Drscription: 
***********************************************************************/
uint16_t adc_measure(ADC_Type *base, uint32_t channelGroup,uint32_t channelNumber)
{
	adc_channel_config_t adc_channle_config;
	adc_channle_config.channelNumber = channelNumber;
	adc_channle_config.enableInterruptOnConversionCompleted = true;
	ADC_SetChannelConfig(base,channelGroup,&adc_channle_config);
	while(1U == ADC_GetChannelStatusFlags(base,channelGroup));
    return ADC_GetChannelConversionValue(base, channelGroup);
}



