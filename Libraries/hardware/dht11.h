/***********************************************************************
*@Author: Dz_hui
*@Date: 2020-11-19 20:25:57
*@FilePath: ??径分隔???替??Smart-Farm??径分隔???替??Libraries??径分隔???替??hardware??径分隔???替??dht11.h
*@Drscription: 
***********************************************************************/
#ifndef __DHT11__H
#define __DHT11__H


#include "fsl_common.h"

/*底层接口*/
#define __DHT11_GPIO_INIT()     dht11_gpio_init()
#define __DHT11_MODE(MODE)      DHT11_MODE(MODE)
#define __DHT11_OUT_H()         GPIO_PinWrite(DHT11_PORT,DHT11_PIN,1U)
#define __DHT11_OUT_L()         GPIO_PinWrite(DHT11_PORT,DHT11_PIN,0U)
#define __DHT11_READ()          GPIO_PinRead(DHT11_PORT,DHT11_PIN)    
// #define __DHT11_DELAY_MS(nms)   delay_ms(nms)
// #define __DHT11_DELAY_US(nms)   delay_us(nms)
#define __DHT11_DELAY_MS(nms)   CPU_TS_Tmr_Delay_US(nms*1000)
#define __DHT11_DELAY_US(nms)   CPU_TS_Tmr_Delay_US(nms*1000)


/*硬件接口*/
#define __DHT11_PIN_CLK()       
#define DHT11_PIN              	28U 
#define DHT11_PORT              GPIO1
#define DHT11_IOMUXC       		IOMUXC_GPIO_AD_B1_12_GPIO1_IO28
/*延时函数*/
#define  SYSCLK                             600000000/1000000                   //指明CPU工作频率为(SystemCoreClock/1000000)MHz
#define  A                                  12                                   //一次循环所花的周期数
#define  B                                  2                                   //调用、初始化、返回总共所用的周期数
#define  delay_us(nus)                      wait(((nus)*(SYSCLK)-(B))/(A))
// #define  delay_ms(nms)                      delay_us((nms)*1000)
// #define  delay_s(ns)                        delay_ms((ns)*1000)

/*结构体成员定义*/
typedef struct
{
	uint8_t  humi_int;		//湿度的整数部分
	uint8_t  humi_deci;	 	//湿度的小数部分
	uint8_t  temp_int;	 	//温度的整数部分
	uint8_t  temp_deci;	 	//温度的小数部分
	uint8_t  check_sum;	 	//校验和
		                 
}DHT11_Data_TypeDef;




/*函数声明*/
void  wait(unsigned long n);
void dht11_config(void);
uint8_t ReadByte(void);
uint8_t Read_DHT11(DHT11_Data_TypeDef *DHT11_Data);
void DHT11_PRINTF(void);
void dht11_lvgl_display(DHT11_Data_TypeDef *dht11);


#endif
