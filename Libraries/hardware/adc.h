/***********************************************************************
*@Author: Dz_hui
*@Date: 2020-09-16 16:33:06
*@FilePath: ??¾¶·Ö¸ô???Ìæ??RT1052_test??¾¶·Ö¸ô???Ìæ??DEMO??¾¶·Ö¸ô???Ìæ??hardware??¾¶·Ö¸ô???Ìæ??adc_soil.h
*@Drscription: 
***********************************************************************/
#ifndef   __ADC_SOIL__H

#define    __ADC_SOIL__H

#include "fsl_common.h"

#define SOIL_GPIO_PIN                               (21U)
#define SOIL_GPIO_PORT                              GPIO1
#define SOIL_GPIO_IOMUXC                            IOMUXC_GPIO_AD_B1_05_GPIO1_IO21   

#define DISTANCE_GPIO_PIN                           (27U)
#define DISTANCE_GPIO_PORT                          GPIO1
#define DISTANCE_GPIO_IOMUXC                        IOMUXC_GPIO_AD_B1_11_GPIO1_IO27   

#define DISTANCE_GPIO1_GPIO_PORT                    GPIO1
#define DISTANCE_GPIO1_GPIO_PIN                     (04U)
#define DISTANCE_GPIO1_IOMUXC                       IOMUXC_GPIO_AD_B0_04_GPIO1_IO04

#define DISTANCE_VIN_GPIO_PORT                      GPIO1
#define DISTANCE_VIN_GPIO_PIN                       (03U)
#define DISTANCE_VIN_IOMUXC                         IOMUXC_GPIO_AD_B0_03_GPIO1_IO03

#define ADC_ETC_CHANNLE_x                           16

#define ADC                                         ADC1
#define DISTANCE_ADC_CHANNLE_GROUP                  (6U)
#define DISTANCE_ADC_CHANNLE                        (0U)

#define SOIL_ADC_CHANNLE_GROUP                      (4U)
#define SOIL_ADC_CHANNLE                            (10U)

#define ADC_ETC_XBARA_TRIGGLE_CHANNEL               (3U)
#define ADC_ETC_CHAIN_LENTH                          1

#define ADC_IRQ                                     ADC1_IRQn
#define ADC_IRQHandler                              ADC1_IRQHandler

typedef struct
{
	float soil_val;
	float distance_val;
	
}adc_data_typedef;

void adc_config(void);
void xbar_config(void);

float soil_adc_get(void);
float GP2Y0E03_DateRead(void);

#endif /*__ADC_SOIL__H*/
