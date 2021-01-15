/***********************************************************************
*@Author: Dz_hui
*@Date: 2020-09-16 16:32:46
*@FilePath: ??径分隔???替??RT1052_test??径分隔???替??DEMO??径分隔???替??hardware??径分隔???替??adc_soil.c
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

float soil_val;    
float soil;
float distant_val;
float distance_val;
uint8_t soil_conversion_flg=0;
uint8_t distant_conversion_flg=0;


SOIL_DATA_DEF soil_data;

/***********************************************************************
*@Drscription: SOIL_PAD_CONFIG
***********************************************************************/
#define ADC_PAD_SETTING      (SRE_0_SLOW_SLEW_RATE|\
                              DSE_4_R0_4|\
                              SPEED_1_MEDIUM_100MHz|\
                              ODE_0_OPEN_DRAIN_DISABLED|\
                              PKE_0_PULL_KEEPER_DISABLED|\
                              PUE_0_KEEPER_SELECTED|\
                              PUS_2_100K_OHM_PULL_UP|\
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

void soil_gpio_config(void)
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
void adc_mode_config(void)
{
    adc_config_t adc_config;
    adc_channel_config_t adc_channle_config;
    
    ADC_GetDefaultConfig(&adc_config);
    adc_config.resolution = kADC_Resolution12Bit;
    ADC_Init(ADC,&adc_config);
    ADC_EnableHardwareTrigger(ADC,true);
    
	adc_channle_config.channelNumber = ADC_ETC_CHANNLE_x;
    /*使能转换完成中断*/
	adc_channle_config.enableInterruptOnConversionCompleted = false;
    ADC_SetChannelConfig(ADC,SOIL_ADC_CHANNLE_GROUP,&adc_channle_config);
    
    adc_channle_config.channelNumber = ADC_ETC_CHANNLE_x;
    adc_channle_config.enableInterruptOnConversionCompleted = false;
    ADC_SetChannelConfig(ADC,DISTANCE_ADC_CHANNLE_GROUP,&adc_channle_config);
    
    if(kStatus_Success == ADC_DoAutoCalibration(ADC))
        printf("校准完成\n");
    else 
        printf("校准失败\n");
}

void adc_ect_config(void)
{
    adc_etc_config_t adc_ectconfig;
    adc_etc_trigger_config_t adc_etctriggerconfig;
    adc_etc_trigger_chain_config_t adc_etctriggerchainconfig;

    ADC_ETC_GetDefaultConfig(&adc_ectconfig);
	adc_ectconfig.enableTSCBypass = false;//该位允许使用ADC2
	adc_ectconfig.XBARtriggerMask = 1<<ADC_ETC_XBARA_TRIGGLE_CHANNEL;
    ADC_ETC_Init(ADC_ETC,&adc_ectconfig);
    
	adc_etctriggerconfig.enableSyncMode = false;
	adc_etctriggerconfig.enableSWTriggerMode = false;
	adc_etctriggerconfig.triggerChainLength = ADC_ETC_CHAIN_LENTH;
	adc_etctriggerconfig.triggerPriority = 0U;
	adc_etctriggerconfig.sampleIntervalDelay = 0U;
	adc_etctriggerconfig.initialDelay = 0U;
    ADC_ETC_SetTriggerConfig(ADC_ETC, ADC_ETC_XBARA_TRIGGLE_CHANNEL, &adc_etctriggerconfig);

	adc_etctriggerchainconfig.enableB2BMode = true;
	adc_etctriggerchainconfig.ADCHCRegisterSelect = 1<<SOIL_ADC_CHANNLE_GROUP;
	adc_etctriggerchainconfig.ADCChannelSelect = SOIL_ADC_CHANNLE;
	adc_etctriggerchainconfig.InterruptEnable = kADC_ETC_Done0InterruptEnable;
    ADC_ETC_SetTriggerChainConfig(ADC_ETC,ADC_ETC_XBARA_TRIGGLE_CHANNEL,0U,&adc_etctriggerchainconfig);
    
	adc_etctriggerchainconfig.ADCHCRegisterSelect = 1<<DISTANCE_ADC_CHANNLE_GROUP;
	adc_etctriggerchainconfig.ADCChannelSelect = DISTANCE_ADC_CHANNLE;
	adc_etctriggerchainconfig.InterruptEnable = kADC_ETC_Done1InterruptEnable;
    ADC_ETC_SetTriggerChainConfig(ADC_ETC,ADC_ETC_XBARA_TRIGGLE_CHANNEL,1U,&adc_etctriggerchainconfig);

    IRQN_priority(4,6,1,ADC_ETC_IRQ0_IRQn);
    IRQN_priority(4,6,0,ADC_ETC_IRQ1_IRQn);

    EnableIRQ(ADC_ETC_IRQ0_IRQn);
    EnableIRQ(ADC_ETC_IRQ1_IRQn);
    
}

/***********************************************************************
*@Function: 
*@Input: 
*@Return: none
*@Author: Dz_hui
*@Date: 2020-09-16 18:45:45
*@Drscription: 
***********************************************************************/
void adc_config(void)
{
    adc_iomuxc_mux_config();
    adc_iomuxc_pad_config();
    soil_gpio_config();
    
    CPU_TS_Tmr_Delay_US(5000);
    GPIO_PinWrite(DISTANCE_VIN_GPIO_PORT,DISTANCE_VIN_GPIO_PIN,1);
    CPU_TS_Tmr_Delay_US(5000);
    GPIO_PinWrite(DISTANCE_GPIO1_GPIO_PORT,DISTANCE_GPIO1_GPIO_PIN,1);

    adc_mode_config();
    adc_ect_config();
}

void xbar_config(void)
{
    XBARA_Init(XBARA1);
    XBARA_SetSignalsConnection(XBARA1,kXBARA1_InputPitTrigger0,kXBARA1_OutputAdcEtcXbar0Trig3);
}

/**********************************************************************************************************************/


void soil_data_init(void) {
    soil_data.soil_buff_length = 0;
    soil_data.soil_status = IDLE;
    soil_data.soil_value = 0;
}

SOIL_F soil_adc_get(void) {   
    SOIL_F value = 0;
    value = ADC_GetChannelConversionValue(ADC,SOIL_ADC_CHANNLE_GROUP);
    value =((4095-value)/4095)*100;
    soil_write_byte(&soil_data, value);
    return value;
}

void soil_write_byte(SOIL_DATA_DEF *sd, SOIL_F data) {

    if((sd->soil_buff_length >= SOIL_QUEUE_BUFF_SIZE) || (sd->soil_status != IN_CALC)) 
        return;
    if(sd->soil_status == RE_CALC) 
        sd->soil_status = IDLE;

    sd->soil_queue_buffer[sd->soil_buff_length] = data;
    sd->soil_buff_length++;
    
    if(sd->soil_buff_length == SOIL_QUEUE_BUFF_SIZE) 
        sd->soil_status = IN_CALC;
}

void soil_read_buffer(SOIL_DATA_DEF *sd, SOIL_F *data) {

    if((sd->soil_buff_length == 0)) {
        sd->soil_status = IDLE;
        return ;
    }
    memcpy(data, sd->soil_queue_buffer, sd->soil_buff_length);
    sd->soil_buff_length = 0;
}

SOIL_F soil_calc(SOIL_DATA_DEF *sd, SOIL_F *data) {

    sd->soil_status = IN_CALC;
    SOIL_F value = 0;
    soil_read_buffer(sd, data);

    for (uint32_t i=0; i<SOIL_QUEUE_BUFF_SIZE; i++) {
        value = value + data[i];
    }
    value = value / SOIL_QUEUE_BUFF_SIZE;
    sd->soil_status = RE_CALC;
    return value;
}

/**********************************************************************************************************************/

float GP2Y0E03_DateRead(void) {
	float adc_data = 0,distant = 0;
    distance_val =  ADC_GetChannelConversionValue(ADC,DISTANCE_ADC_CHANNLE_GROUP);
	distance_val = (float)distance_val/(float)4095*(float)3.3;	    //得出电压
	distance_val = -((distance_val-(float)2.35)/(float)0.035);		//计算出距离
	printf("distant=%f\n",distance_val);
	return distance_val;
}




#if 0
void ADC_IRQHandler(void)
{
    adc_soil_flg = true;
    
    soil_val =  ADC_GetChannelConversionValue(SOIL_ADC,SOIL_ADC_CHANNLE_GROUP);
    
}
#endif



void ADC_ETC_IRQ0_IRQHandler(void)
{
    ADC_ETC_ClearInterruptStatusFlags(ADC_ETC,kADC_ETC_Trg3TriggerSource,kADC_ETC_Done0StatusFlagMask);
    soil_val = ADC_ETC_GetADCConversionValue(ADC_ETC,ADC_ETC_XBARA_TRIGGLE_CHANNEL,0U);
    soil_conversion_flg = true;

}

void ADC_ETC_IRQ1_IRQHandler(void)
{
    ADC_ETC_ClearInterruptStatusFlags(ADC_ETC,kADC_ETC_Trg3TriggerSource,kADC_ETC_Done1StatusFlagMask);
    distant_val = ADC_ETC_GetADCConversionValue(ADC_ETC,ADC_ETC_XBARA_TRIGGLE_CHANNEL,1U);
    distant_conversion_flg = true;
	
    
}

