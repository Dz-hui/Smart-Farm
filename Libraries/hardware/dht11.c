#include "dht11.h"
#include "pad_config.h"
#include "fsl_gpio.h"
#include "fsl_iomuxc.h"
#include "core_delay.h"
#include "stdio.h"
#include "struct.h"

// DHT11_Data_TypeDef dht11_data;


// #define DHT11_PAD_CONFIG_DATA          (IOMUXC_SW_PAD_CTL_PAD_SRE(0) | \
//                                         IOMUXC_SW_PAD_CTL_PAD_DSE(6) | \
//                                         IOMUXC_SW_PAD_CTL_PAD_SPEED(2) | \
//                                         IOMUXC_SW_PAD_CTL_PAD_ODE(0) | \
//                                         IOMUXC_SW_PAD_CTL_PAD_PKE(0) | \
//                                         IOMUXC_SW_PAD_CTL_PAD_PUE(0) | \
//                                         IOMUXC_SW_PAD_CTL_PAD_PUS(0) | \
//                                         IOMUXC_SW_PAD_CTL_PAD_HYS(0))

// /****************************************************************
// *@function: dht11_gpio_init
// *@input   : none
// *@output  : none
// *@describe: DHT11的GPIO口初始化
// *@author  : sola
// ****************************************************************/
// void dht11_gpio_init(void)
// { 
// 	gpio_pin_config_t dht11_Config;

// 	IOMUXC_SetPinMux(DHT11_IOMUXC,0);
// 	IOMUXC_SetPinConfig(DHT11_IOMUXC,DHT11_PAD_CONFIG_DATA);
	
// 	dht11_Config.direction = kGPIO_DigitalOutput;
// 	dht11_Config.interruptMode = kGPIO_NoIntmode;
// 	dht11_Config.outputLogic = 0U;
// 	GPIO_PinInit(DHT11_PORT, DHT11_PIN, &dht11_Config);
// }

// /****************************************************************
// *@function: DHT11_MODE
// *@input   : mode    （0/1）
// *@output  : none
// *@describe: DHT11 GPIO输入输出模式选择
// *@author  : sola
// ****************************************************************/
// void DHT11_MODE(uint8_t mode)
// {
// 	gpio_pin_config_t dht11_Config;
// 	if(mode == 0)
// 	{
// 		dht11_Config.direction = kGPIO_DigitalInput;
// 		dht11_Config.interruptMode = kGPIO_NoIntmode;
// 		dht11_Config.outputLogic = 0;
// 		GPIO_PinInit(DHT11_PORT, DHT11_PIN, &dht11_Config);
// 	}
// 	else if(mode == 1)
// 	{
// 		dht11_Config.direction = kGPIO_DigitalOutput;
// 		dht11_Config.interruptMode = kGPIO_NoIntmode;
// 		dht11_Config.outputLogic = 0;
// 		GPIO_PinInit(DHT11_PORT, DHT11_PIN, &dht11_Config);
// 	}
// }


// /*---------------------------应用层----------------------------*/

// /****************************************************************
// *@function: dht11_delay
// *@input   : n (MHz)  
// *@output  : none
// *@describe: 延时
// *@author  : sola
// ****************************************************************/
// void wait(unsigned long n)
// {   
// 	do{
// 	n--;
// 	}while(n);
// }

// /****************************************************************
// *@function: dht11_init
// *@input   : none
// *@output  : none
// *@describe: DHT11 起始信号
// *@author  : sola
// ****************************************************************/
// void dht11_config(void)
// {
//     __DHT11_GPIO_INIT();
// }

// /****************************************************************
// *@function: ReadByte
// *@input   : none
// *@output  : temp
// *@describe: 读一个字节
// *@author  : sola
// ****************************************************************/
// uint8_t ReadByte(void) {

// 	uint8_t i, temp = 0;

// 	for(i=0;i<8;i++) {

// 		while(__DHT11_READ() == 0);
		
// 		CPU_TS_Tmr_Delay_US(40);//rt_thread_udelay(40);//__DHT11_DELAY_US(40);               //40us

// 		if(__DHT11_READ() == 1) {

// 			while(__DHT11_READ() == 1);

// 			temp |= (uint8_t)(0x01<<(7-i));
// 		}
// 		else {
			
// 			temp &= (uint8_t)~(0x01<<(7-i));
// 		}
// 	}	
// 	return temp;
// } 

// /****************************************************************
// *@function: Read_DHT11
// *@input   : *DHT11_Data
// *@output  : temp
// *@describe: DHT11 读数据
// *@author  : sola
// ****************************************************************/
// uint8_t Read_DHT11(DHT11_Data_TypeDef *DHT11_Data) {
    
// 	__DHT11_MODE(1);            //配置为输出
	
// 	__DHT11_OUT_L();            //拉低
	
// 	CPU_TS_Tmr_Delay_US(18000);//rt_thread_delay(18);//__DHT11_DELAY_MS(18);       //18ms
	
// 	__DHT11_OUT_H();            //拉高
    
//   	CPU_TS_Tmr_Delay_US(13);//rt_thread_udelay(13)//__DHT11_DELAY_US(13);       //13us
// 	__DHT11_MODE(0);            //配置为输入

// 	if(__DHT11_READ() == 0) {
// 		DEBUG_PRINT("DHT11 __DHT11_READ == 0\n");

// 		while(__DHT11_READ() == 0);

// 		while(__DHT11_READ() == 1);

// 		DHT11_Data->humi_int= ReadByte();   //读取湿度整数

// 		DHT11_Data->humi_deci= ReadByte();  //读取湿度小数

// 		DHT11_Data->temp_int= ReadByte();   //读取温度整数

// 		DHT11_Data->temp_deci= ReadByte();  //读取温度整数

// 		DHT11_Data->check_sum= ReadByte();  //应答读取

// 		__DHT11_MODE(1);                    //配置为输出

// 		__DHT11_OUT_H();

// 		DEBUG_PRINT("DHT11 need to check\n");

// 		if(DHT11_Data->check_sum == 
//                                     DHT11_Data->humi_int 	+ 
//                                     DHT11_Data->humi_deci 	+ 
//                                     DHT11_Data->temp_int	+ 
//                                     DHT11_Data->temp_deci) {
// 			printf("\r\n\r\n湿度为%d.%d ％RH ，温度为 %d.%d℃ \r\n",
//                                                                 dht11_data.humi_int,
//                                                                 dht11_data.humi_deci,
//                                                                 dht11_data.temp_int,
//                                                                 dht11_data.temp_deci);
// 			return 1;								
// 		}
// 		else {		
// 			printf("\nDHT11 READ ERROR\r\n");	
// 			return 0;
// 		}
// 	}else {
// 		DEBUG_PRINT("DHT11 __DHT11_READ == 1\n");
// 		return 0;
// 	}
// }


// /****************************************************************
// *@function: DHT11_PRINTF
// *@input   : none
// *@output  : none
// *@describe: DHT11 打印数据
// *@author  : sola
// ****************************************************************/
// #if 1
// void DHT11_PRINTF(void) {

// 	uint8_t is_read_succeed = 0;
	
// 	is_read_succeed = Read_DHT11(&dht11_data);



//     if(Read_DHT11(&dht11_data) == 1) {
              
//             printf("\r\n\r\n湿度为%d.%d ％RH ，温度为 %d.%d℃ \r\n",
//                                                                 dht11_data.humi_int,
//                                                                 dht11_data.humi_deci,
//                                                                 dht11_data.temp_int,
//                                                                 dht11_data.temp_deci);
//   } 
//   else 
//   {
// 		printf("\nDHT11 READ ERROR\r\n");
//   }
// }

// void dht11_lvgl_display(DHT11_Data_TypeDef *dht11) {
// 	DEBUG_PRINT("Enter DHT11\n");
// 	uint8_t is_read_succeed = 0;
// 	is_read_succeed = Read_DHT11(&dht11_data);
// 	if(is_read_succeed == 1) {
// 		dht11_data.humi_value = (float)dht11_data.humi_int + (dht11_data.humi_deci)/100;
// 		dht11_data.temp_value = (float)dht11_data.temp_int + (dht11_data.temp_deci)/100;
// 	}
// }

// #endif

DHT11_Data_TypeDef dht11_data;


#define DHT11_PAD_CONFIG_DATA          (IOMUXC_SW_PAD_CTL_PAD_SRE(0) | \
                                        IOMUXC_SW_PAD_CTL_PAD_DSE(6) | \
                                        IOMUXC_SW_PAD_CTL_PAD_SPEED(2) | \
                                        IOMUXC_SW_PAD_CTL_PAD_ODE(0) | \
                                        IOMUXC_SW_PAD_CTL_PAD_PKE(0) | \
                                        IOMUXC_SW_PAD_CTL_PAD_PUE(0) | \
                                        IOMUXC_SW_PAD_CTL_PAD_PUS(0) | \
                                        IOMUXC_SW_PAD_CTL_PAD_HYS(0))

/****************************************************************
*@function: dht11_gpio_init
*@input   : none
*@output  : none
*@describe: DHT11的GPIO口初始化
*@author  : sola
****************************************************************/
void dht11_gpio_init(void)
{ 
	gpio_pin_config_t dht11_Config;

	IOMUXC_SetPinMux(DHT11_IOMUXC,0);
	
	dht11_Config.direction = kGPIO_DigitalOutput;
	dht11_Config.interruptMode = kGPIO_NoIntmode;
	dht11_Config.outputLogic = 0U;
	GPIO_PinInit(DHT11_PORT, DHT11_PIN, &dht11_Config);
}

/****************************************************************
*@function: DHT11_MODE
*@input   : mode    （0/1）
*@output  : none
*@describe: DHT11 GPIO输入输出模式选择
*@author  : sola
****************************************************************/
void DHT11_MODE(uint8_t mode)
{
	gpio_pin_config_t dht11_Config;
	if(mode == 0)
	{
		dht11_Config.direction = kGPIO_DigitalInput;
		dht11_Config.interruptMode = kGPIO_NoIntmode;
		dht11_Config.outputLogic = 0;
		GPIO_PinInit(DHT11_PORT, DHT11_PIN, &dht11_Config);
	}
	else if(mode == 1)
	{
		dht11_Config.direction = kGPIO_DigitalOutput;
		dht11_Config.interruptMode = kGPIO_NoIntmode;
		dht11_Config.outputLogic = 0;
		GPIO_PinInit(DHT11_PORT, DHT11_PIN, &dht11_Config);
	}
}


/*---------------------------应用层----------------------------*/

/****************************************************************
*@function: dht11_delay
*@input   : n (MHz)  
*@output  : none
*@describe: 延时
*@author  : sola
****************************************************************/
void wait(unsigned long n)
{   
	do{
	n--;
	}while(n);
}

/****************************************************************
*@function: dht11_init
*@input   : none
*@output  : none
*@describe: DHT11 起始信号
*@author  : sola
****************************************************************/
void dht11_config(void)
{
    __DHT11_GPIO_INIT();
}

/****************************************************************
*@function: ReadByte
*@input   : none
*@output  : temp
*@describe: 读一个字节
*@author  : sola
****************************************************************/
uint8_t ReadByte(void) {

	uint8_t i, temp = 0;

	for(i=0;i<8;i++) {

		while(__DHT11_READ() == 0);
		
		CPU_TS_Tmr_Delay_US(40);//rt_thread_udelay(40);//__DHT11_DELAY_US(40);               //40us

		if(__DHT11_READ() == 1) {

			while(__DHT11_READ() == 1);

			temp |= (uint8_t)(0x01<<(7-i));
		}
		else {
			
			temp &= (uint8_t)~(0x01<<(7-i));
		}
	}	
	return temp;
} 

/****************************************************************
*@function: Read_DHT11
*@input   : *DHT11_Data
*@output  : temp
*@describe: DHT11 读数据
*@author  : sola
****************************************************************/
uint8_t Read_DHT11(DHT11_Data_TypeDef *DHT11_Data) {
    
    
	__DHT11_MODE(1);            //配置为输出
	
	__DHT11_OUT_L();            //拉低
	
	CPU_TS_Tmr_Delay_US(18000);//rt_thread_delay(18);//__DHT11_DELAY_MS(18);       //18ms
	__DHT11_OUT_H();            //拉高
    
    CPU_TS_Tmr_Delay_US(13);//rt_thread_udelay(13)//__DHT11_DELAY_US(13);       //13us

	__DHT11_MODE(0);            //配置为输入

	if(__DHT11_READ() == 0) {

		while(__DHT11_READ() == 0); 

		while(__DHT11_READ() == 1);

		DHT11_Data->humi_int= ReadByte();   //读取湿度整数

		DHT11_Data->humi_deci= ReadByte();  //读取湿度小数

		DHT11_Data->temp_int= ReadByte();   //读取温度整数

		DHT11_Data->temp_deci= ReadByte();  //读取温度整数

		DHT11_Data->check_sum= ReadByte();  //应答读取

		__DHT11_MODE(1);                    //配置为输出

		__DHT11_OUT_H();

		if(DHT11_Data->check_sum == 
                                    DHT11_Data->humi_int + 
                                        DHT11_Data->humi_deci + 
                                            DHT11_Data->temp_int+ 
                                                DHT11_Data->temp_deci) {
			printf("\r\n\r\n湿度为%d.%d ％RH ，温度为 %d.%d℃ \r\n",
                                                                dht11_data.humi_int,
                                                                dht11_data.humi_deci,
                                                                dht11_data.temp_int,
                                                                dht11_data.temp_deci);
		}
		else {		
			printf("\nDHT11 READ ERROR\r\n");	
		}
	}
    return 0;
}


/****************************************************************
*@function: DHT11_PRINTF
*@input   : none
*@output  : none
*@describe: DHT11 打印数据
*@author  : sola
****************************************************************/
#if 1
void DHT11_PRINTF(void) {

    if(Read_DHT11(&dht11_data) == 1) {
              
            printf("\r\n\r\n湿度为%d.%d ％RH ，温度为 %d.%d℃ \r\n",
                                                                dht11_data.humi_int,
                                                                dht11_data.humi_deci,
                                                                dht11_data.temp_int,
                                                                dht11_data.temp_deci);
  } 
  else 
  {
		printf("\nDHT11 READ ERROR\r\n");
  }
}
#endif

















