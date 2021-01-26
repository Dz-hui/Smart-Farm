/***********************************************************************
*@Author: Dz_hui
*@Date: 2020-09-16 16:33:06
*@FilePath: ??径分隔???替??RT1052_emwin??径分隔???替??Libraries??径分隔???替??hardware??径分隔???替??adc.h
*@Drscription: 
***********************************************************************/
#ifndef   __ADC_SOIL__H
#define   __ADC_SOIL__H

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

#define ADC                                         ADC1
#define DISTANCE_ADC_CHANNLE_GROUP                  (0U)
#define DISTANCE_ADC_CHANNLE                        (0U)

#define SOIL_ADC_CHANNLE_GROUP                      (0U)
#define SOIL_ADC_CHANNLE                            (10U)



typedef float MEASURE_F;
#define ADC_MEASURE_QUEUE_BUFF_SIZE		10


typedef enum {
	IDLE,			// 空闲状态，可以采集接收buffer
	IN_CALC,		// 正在等待计算，不能填充BUFF
	RE_CALC,		// 计算完成，清空BUFF中
}MEASURE_STATUS_DEF;

typedef enum {
	soil,
	distance,
}MEASURE_NUM;


typedef struct {
	MEASURE_F 				adc_measure_value;
	MEASURE_F 				adc_measure_queue_buffer[ADC_MEASURE_QUEUE_BUFF_SIZE];
	uint32_t 			    adc_measure_buff_length;
	MEASURE_STATUS_DEF		adc_measure_status;
}MEASURE_DATA_DEF;
extern MEASURE_DATA_DEF soil_data;
extern MEASURE_DATA_DEF distance_data;

void adc_mode_config(void);
uint16_t adc_measure(ADC_Type *base, uint32_t channelGroup,uint32_t channelNumber);

MEASURE_F data_adc_get(ADC_Type *base, uint32_t channelGroup,uint32_t channelNumber,MEASURE_DATA_DEF *sd,MEASURE_NUM adc_measure_num);
void adc_measure_write_byte(MEASURE_DATA_DEF *sd, MEASURE_F data);
void adc_measure_read_buffer(MEASURE_DATA_DEF *sd, MEASURE_F *data);
MEASURE_F adc_measure_calc(MEASURE_DATA_DEF *sd, MEASURE_F *data);

float GP2Y0E03_DateRead(void);



#endif /*__ADC_SOIL__H*/
