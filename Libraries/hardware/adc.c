/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-01-06 23:27:08
*@FilePath: ??径分隔???替??Smart-Farm??径分隔???替??Libraries??径分隔???替??hardware??径分隔???替??adc.c
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
    /*初始化ADC相关的IOMUXC的MUX复用配置*/
    IOMUXC_SetPinMux(SOIL_GPIO_IOMUXC,0U);
    IOMUXC_SetPinMux(DISTANCE_GPIO_IOMUXC,0U);
    IOMUXC_SetPinMux(DISTANCE_GPIO1_IOMUXC,0U);
    IOMUXC_SetPinMux(DISTANCE_VIN_IOMUXC,0U);
}

void adc_iomuxc_pad_config(void)
{
    /*初始化ADC外部输入引脚的PAD属性*/
    IOMUXC_SetPinConfig(SOIL_GPIO_IOMUXC,ADC_PAD_SETTING);
    IOMUXC_SetPinConfig(DISTANCE_GPIO_IOMUXC,ADC_PAD_SETTING);
    IOMUXC_SetPinConfig(DISTANCE_GPIO1_IOMUXC,ADC_PAD_SETTING);
    IOMUXC_SetPinConfig(DISTANCE_VIN_IOMUXC,ADC_PAD_SETTING);
}

void adc_gpio_config(void)
{
    gpio_pin_config_t adc_pin_config;
    adc_pin_config.direction = kGPIO_DigitalInput;
	adc_pin_config.interruptMode = kGPIO_NoIntmode; //不使用中断

	GPIO_PinInit(SOIL_GPIO_PORT,SOIL_GPIO_PIN,&adc_pin_config);
    GPIO_PinInit(DISTANCE_GPIO_PORT,DISTANCE_GPIO_PIN,&adc_pin_config);

    adc_pin_config.direction = kGPIO_DigitalOutput;
	adc_pin_config.interruptMode = kGPIO_NoIntmode;
	adc_pin_config.outputLogic = 0;
	GPIO_PinInit(DISTANCE_VIN_GPIO_PORT,DISTANCE_VIN_GPIO_PIN,&adc_pin_config);
    GPIO_PinInit(DISTANCE_GPIO1_GPIO_PORT,DISTANCE_GPIO1_GPIO_PIN,&adc_pin_config);  
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
    
    CPU_TS_Tmr_Delay_US(5000);
    GPIO_WritePinOutput(DISTANCE_VIN_GPIO_PORT,DISTANCE_VIN_GPIO_PIN,1);
    CPU_TS_Tmr_Delay_US(5000);
    GPIO_WritePinOutput(DISTANCE_GPIO1_GPIO_PORT,DISTANCE_GPIO1_GPIO_PIN,1);

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
	printf("adc_value=%d\n",ADC_GetChannelConversionValue(base, channelGroup));
    return ADC_GetChannelConversionValue(base, channelGroup);
}

/***********************************************************************
*@Function: 
*@Input: 
*@Return: none
*@Author: Dz_hui
*@Date: 2021-01-26 23:00:49
*@Drscription: 
***********************************************************************/
void soil_data_init(void) {

    soil_data.adc_measure_buff_length = 0;
    soil_data.adc_measure_status = IDLE;
    soil_data.adc_measure_value = 0;
}

/***********************************************************************
*@Function: 
*@Input: 
*@Return: none
*@Author: Dz_hui
*@Date: 2021-01-26 23:01:24
*@Drscription: 
***********************************************************************/
MEASURE_F data_adc_get(ADC_Type *base, uint32_t channelGroup,uint32_t channelNumber, MEASURE_DATA_DEF *sd, MEASURE_NUM adc_measure_num) {   
    
    MEASURE_F value = 0;
    uint8_t adc_num = adc_measure_num;
    adc_channel_config_t adc_channle_config;
    
    adc_channle_config.channelNumber = channelNumber;
    ADC_SetChannelConfig(base, channelGroup, &adc_channle_config);

    value = adc_measure(base,channelGroup,channelNumber);
    if(adc_num == 0)
        value =((4095-value)/4095)*100;
    else  if(adc_num == 1)
        value =-((((value/4095)*(float)3.3)-(float)2.35)/(float)0.035);

    adc_measure_write_byte(sd, value);
    return value;
}

/***********************************************************************
*@Function: 
*@Input: 
*@Return: none
*@Author: sola
*@Date: 2021-01-26 23:01:24
*@Drscription: 
***********************************************************************/
void adc_measure_write_byte(MEASURE_DATA_DEF *sd, MEASURE_F data) {

    if((sd->adc_measure_buff_length >= ADC_MEASURE_QUEUE_BUFF_SIZE) || (sd->adc_measure_status == IN_CALC)) 
        return;
    if(sd->adc_measure_status == RE_CALC) 
        sd->adc_measure_status = IDLE;

    sd->adc_measure_queue_buffer[sd->adc_measure_buff_length] = data;
    sd->adc_measure_buff_length++;
    
    if(sd->adc_measure_buff_length == ADC_MEASURE_QUEUE_BUFF_SIZE) 
        sd->adc_measure_status = IN_CALC;
}

/***********************************************************************
*@Function: 
*@Input: 
*@Return: none
*@Author: sola
*@Date: 2021-01-26 23:01:24
*@Drscription: 
***********************************************************************/
void adc_measure_read_buffer(MEASURE_DATA_DEF *sd, MEASURE_F *data) {

    if((sd->adc_measure_buff_length == 0)) {
        sd->adc_measure_status = IDLE;
        return ;
    }
    memcpy(data, sd->adc_measure_queue_buffer, sd->adc_measure_buff_length);
    sd->adc_measure_buff_length = 0;
} 

/***********************************************************************
*@Function: 
*@Input: 
*@Return: none
*@Author: sola
*@Date: 2021-01-26 23:01:24
*@Drscription: 
***********************************************************************/
MEASURE_F adc_measure_calc(MEASURE_DATA_DEF *sd, MEASURE_F *data) {

    sd->adc_measure_status = IN_CALC;
    MEASURE_F value = 0;
    adc_measure_read_buffer(sd, data);

    for (uint32_t i=0; i<ADC_MEASURE_QUEUE_BUFF_SIZE; i++) {
        value = value + data[i];
    }
    value = value / ADC_MEASURE_QUEUE_BUFF_SIZE;
    sd->adc_measure_status = RE_CALC;
    return value;
}

