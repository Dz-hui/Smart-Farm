/**
  ******************************************************************
  * @file    bsp_led.c
  * @author  fire
  * @version V1.1
  * @date    2018-xx-xx
  * @brief   led应用函数接口
  ******************************************************************
  * @attention
  *
  * 实验平台:野火  i.MXRT1052开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************
  */
#include "fsl_iomuxc.h"
#include "fsl_gpio.h"  
  
#include "pad_config.h"  
#include "pump.h"   

/*******************************************************************************
 * 宏
 ******************************************************************************/
/* 所有引脚均使用同样的PAD配置 */
#define PUMP_PAD_CONFIG_DATA            (SRE_0_SLOW_SLEW_RATE| \
                                        DSE_6_R0_6| \
                                        SPEED_2_MEDIUM_100MHz| \
                                        ODE_0_OPEN_DRAIN_DISABLED| \
                                        PKE_0_PULL_KEEPER_DISABLED| \
                                        PUE_0_KEEPER_SELECTED| \
                                        PUS_0_100K_OHM_PULL_DOWN| \
                                        HYS_0_HYSTERESIS_DISABLED)   
    /* 配置说明 : */
    /* 转换速率: 转换速率慢
      驱动强度: R0/6 
      带宽配置 : medium(100MHz)
      开漏配置: 关闭 
      拉/保持器配置: 关闭
      拉/保持器选择: 保持器（上面已关闭，配置无效）
      上拉/下拉选择: 100K欧姆下拉（上面已关闭，配置无效）
      滞回器配置: 关闭 */     

/*******************************************************************************
 * 声明
 ******************************************************************************/
static void PUMP_IOMUXC_MUX_Config(void);
static void PUMP_IOMUXC_PAD_Config(void);
static void PUMP_GPIO_Mode_Config(void);

/**
* @brief  初始化LED相关IOMUXC的MUX复用配置
* @param  无
* @retval 无
*/
static void PUMP_IOMUXC_MUX_Config(void)
{
  IOMUXC_SetPinMux(PUMP_IOMUXC, 0U); 
}

/**
* @brief  初始化LED相关IOMUXC的MUX复用配置
* @param  无
* @retval 无
*/
static void PUMP_IOMUXC_PAD_Config(void)
{
  /* 核心板的LED灯 */    
  //IOMUXC_SetPinConfig(CORE_BOARD_LED_IOMUXC, LED_PAD_CONFIG_DATA);  
 
  /* RGB LED灯，使用同样的IOMUXC PAD配置 */ 
  IOMUXC_SetPinConfig(PUMP_IOMUXC, PUMP_PAD_CONFIG_DATA); 
}


 /**
  * @brief  初始化LED相关的GPIO模式
  * @param  无
  * @retval 无
  */
static void PUMP_GPIO_Mode_Config(void)
{     
  /* 定义gpio初始化配置结构体 */
  gpio_pin_config_t led_config;      
    
      
  led_config.direction = kGPIO_DigitalOutput; //输出模式
  led_config.outputLogic =  1;                //默认高电平    
  led_config.interruptMode = kGPIO_NoIntmode; //不使用中断
  

  GPIO_PinInit(PUMP_GPIO, PUMP_GPIO_PIN, &led_config);
}

/**
  * @brief  初始化控制LED的IO
  * @param  无
  * @retval 无
  */
void PUMP_GPIO_Config(void)
{
  /* 初始化GPIO复用、属性、模式 */
  PUMP_IOMUXC_MUX_Config();
  PUMP_IOMUXC_PAD_Config();
  PUMP_GPIO_Mode_Config();
}









/*********************************************END OF FILE**********************/
