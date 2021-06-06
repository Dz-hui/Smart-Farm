/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-03-21 01:08:14
*@FilePath: ??���ָ�???��??�½��ļ���??���ָ�???��??Libraries??���ָ�???��??hardware??���ָ�???��??adc.h
*@Drscription: 
***********************************************************************/
/***********************************************************************
*@Author: Dz_hui
*@Date: 2020-09-16 16:33:06
*@FilePath: ??���ָ�???��??Smart-Farm??���ָ�???��??Libraries??���ָ�???��??hardware??���ָ�???��??adc.h
*@Drscription: 
***********************************************************************/
#ifndef   __ADC_SOIL__H
#define   __ADC_SOIL__H

#include "fsl_common.h"
// #include "main.h"

#define DISTANCE_GPIO_PIN   						(26U)
#define DISTANCE_GPIO_PORT  						GPIO1
#define DISTANCE_GPIO_IOMUXC						IOMUXC_GPIO_AD_B1_10_GPIO1_IO26//IOMUXC_GPIO_AD_B0_10_GPIO1_IO10   //GPIO_AD_B1_10 

#define SOIL_GPIO_PIN                          		(27U)
#define SOIL_GPIO_PORT                         		GPIO1
#define SOIL_GPIO_IOMUXC                       		IOMUXC_GPIO_AD_B1_11_GPIO1_IO27// IOMUXC_GPIO_AD_B0_11_GPIO1_IO11   //GPIO_AD_B1_11

#define LIGHT_GPIO_PIN                           	(14U)//(11U)
#define LIGHT_GPIO_PORT                          	GPIO1
#define LIGHT_GPIO_IOMUXC                       	IOMUXC_GPIO_AD_B0_14_GPIO1_IO14// IOMUXC_GPIO_AD_B0_11_GPIO1_IO11   //GPIO_AD_B1_11

#define ADC_PORT								ADC1

#define DISTANCE_ADC_CHANNLE_GROUP               	(0U)
#define DISTANCE_ADC_CHANNLE                     	(15U)

#define SOIL_ADC_CHANNLE_GROUP                      	(0U)
#define SOIL_ADC_CHANNLE                            	(0U)

#define LIGHT_ADC_CHANNLE_GROUP                      	(0U)
#define LIGHT_ADC_CHANNLE                            	(3U)

void hal_adc_gpio_config(void);
void hal_adc_config(void);
uint16_t hal_adc_get(ADC_Type *base, uint32_t channelGroup, uint32_t channelNumber);
void hal_adc_init(void);

float soil_value_get(void);
uint16_t soil_value_get_int(void);
float light_value_get(void);


#endif /*__ADC_SOIL__H*/
