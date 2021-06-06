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
#include "main.h"

float soil_val;    
float distant_val;
float distance_val;
uint8_t soil_conversion_flg=0;
uint8_t distant_conversion_flg=0;


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

void hal_adc_gpio_config(void) {

    gpio_pin_config_t adc_pin_config;
    adc_pin_config.direction = kGPIO_DigitalInput;
	adc_pin_config.interruptMode = kGPIO_NoIntmode; 

#if defined(USE_SOIL_ADC)
    GPIO_PinInit(SOIL_GPIO_PORT, SOIL_GPIO_PIN, &adc_pin_config);
    IOMUXC_SetPinMux(SOIL_GPIO_IOMUXC,0U);
    IOMUXC_SetPinConfig(SOIL_GPIO_IOMUXC, ADC_PAD_SETTING);
#endif

#if defined(USE_LIGHT_ADC) 
    GPIO_PinInit(LIGHT_GPIO_PORT, LIGHT_GPIO_PIN, &adc_pin_config);
    IOMUXC_SetPinMux(LIGHT_GPIO_IOMUXC, 0U);
    IOMUXC_SetPinConfig(LIGHT_GPIO_IOMUXC, ADC_PAD_SETTING);
#endif

#if defined(USE_DISTANCE_ADC) 
    GPIO_PinInit(DISTANCE_GPIO_PORT, DISTANCE_GPIO_PIN, &adc_pin_config);
    IOMUXC_SetPinMux(DISTANCE_GPIO_IOMUXC, 0U);
    IOMUXC_SetPinConfig(DISTANCE_GPIO_IOMUXC, ADC_PAD_SETTING);
#endif
}

void hal_adc_config(void) {
    adc_config_t adc_config;

    // adc use 12bit
    ADC_GetDefaultConfig(&adc_config);
    ADC_Init(ADC_PORT, &adc_config);
    if(kStatus_Success == ADC_DoAutoCalibration(ADC_PORT)) {
        DEBUG_PRINT("Check Succeed\n");
    }
    else {
        DEBUG_PRINT("Check Error\n");
    }
}

void hal_adc_init(void) {

    hal_adc_gpio_config();
    hal_adc_config();
}

uint16_t hal_adc_get(ADC_Type *base, uint32_t channelGroup, uint32_t channelNumber) {
    adc_channel_config_t adc_channle_config;
	adc_channle_config.channelNumber = channelNumber;
	adc_channle_config.enableInterruptOnConversionCompleted = true;
	ADC_SetChannelConfig(base,channelGroup,&adc_channle_config);
	while(1U == ADC_GetChannelStatusFlags(base,channelGroup)) {
        // need add time count ;
    }
    return ADC_GetChannelConversionValue(base, channelGroup);
}


float soil_value_get(void) {
	return (((float)4095-(float)hal_adc_get(ADC_PORT ,SOIL_ADC_CHANNLE_GROUP, SOIL_ADC_CHANNLE))/4095)*100;
}

float distance_value_get(void) {
	return -(((((float)hal_adc_get(ADC_PORT,DISTANCE_ADC_CHANNLE_GROUP,DISTANCE_ADC_CHANNLE)/(float)4095)*(float)3.3)-(float)2.35)/(float)0.035);
}

float light_value_get(void) {
	return ((float)hal_adc_get(ADC_PORT,LIGHT_ADC_CHANNLE_GROUP,LIGHT_ADC_CHANNLE)/(float)4095*100);
}



