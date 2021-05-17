/**
  ******************************************************************
  * @file    bsp_usart.c
  * @author  fire
  * @version V1.1
  * @date    2018-xx-xx
  * @brief   uart应用函数接口
  ******************************************************************
  * @attention
  *
  * 实验平台:野火  i.MXRT1052开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************
  */

#include "board.h"
#include "fsl_iomuxc.h"
#include "fsl_gpio.h"
#include "fsl_lpuart.h"
#include "pad_config.h"
#include "fsl_debug_console.h"
#include "exit.h"
#include "bsp_uart.h"
#include "gizwits_protocol.h"
#include "gizwits_product.h"
#include "main.h"

/**
* @brief  初�?�化uart配置参数
* @param  �?
* @retval �?
*/
void UART_ModeConfig(void)
{
  /*定义串口配置参数结构体变量，用于保存串口的配�?信息*/
  lpuart_config_t config;
  
  /*调用固件库函数得到默认的串口配置参数，在默�?�的配置参数基�?�上修�?*/
  LPUART_GetDefaultConfig(&config);
  config.baudRate_Bps = DEBUG_UART_BAUDRATE;  //波特�?
  config.enableRx = DEBUG_UART_ENABLE_RESIVE; //�?否允许接收数�?
  config.enableTx = DEBUG_UART_ENABLE_SEND;   //�?否允许发送数�?
  config.parityMode = kLPUART_ParityDisabled;
  config.dataBitsCount = kLPUART_EightDataBits;
  // config.stopBitCount = kLPUART_OneStopBit;
  // config.isMsb = false;

  /*调用固件库函数，将修改好的配�?信息写入到串口的配置寄存器中*/
  LPUART_Init(DEBUG_UARTx, &config, BOARD_DEBUG_UART_CLK_FREQ);
  
  /*允�?�接收中�?*/
  LPUART_EnableInterrupts(DEBUG_UARTx, kLPUART_RxDataRegFullInterruptEnable);
  
  /*设置�?�?优先�?,*/
  IRQN_priority(4,1,1,DEBUG_UART_IRQ);
  /*使能�?�?*/
  EnableIRQ(DEBUG_UART_IRQ);
}

 /**
* @brief  初�?�化uart引脚功能
* @param  �?
* @retval �?
*/
void UART_IOMUXC_MUX_Config(void)
{
  /* RX和TX引脚 */
  IOMUXC_SetPinMux(UART_RX_IOMUXC, 0U);                                   
  IOMUXC_SetPinMux(UART_TX_IOMUXC, 0U); 
}

 /**
* @brief  初�?�化uart相关IOMUXC的PAD属性配�?
* @param  �?
* @retval �?
*/
void UART_IOMUXC_PAD_Config(void)
{
  IOMUXC_SetPinConfig(UART_RX_IOMUXC, UART_RX_PAD_CONFIG_DATA);
  IOMUXC_SetPinConfig(UART_TX_IOMUXC, UART_TX_PAD_CONFIG_DATA);
}
  /**
* @brief  初�?�化uart,并开�?了收发功�?
* @param  �?
* @retval �?
*/
void UART_Config(void)
{
  UART_IOMUXC_MUX_Config();
  UART_IOMUXC_PAD_Config();
  UART_ModeConfig();
}

  /**
* @brief  发送一�?字�?? 
* @param  base:选择�?�?
* @param  data:将�?�发送的数据
* @retval �?
*/
void Uart_SendByte(LPUART_Type *base, uint8_t data)
{
  LPUART_WriteByte( base, data);
  while (!(base->STAT & LPUART_STAT_TDRE_MASK));
}

  /**
* @brief  发送一�?字�?�串 
* @param  base:选择�?�?
* @param  data:将�?�发送的数据
* @retval �?
*/
void Uart_SendString( LPUART_Type *base,  const char *str)
{
  LPUART_WriteBlocking( base, (const uint8_t *)str, strlen(str));
}
 
  /**
* @brief  发送一�?16位数  
* @param  base:选择�?�?
* @param  data:将�?�发送的数据
* @retval �?
*/
void Uart_SendHalfWord(LPUART_Type *base, uint16_t ch)
{
  uint8_t temp_h, temp_l;
  
  /* 取出高八�? */
  temp_h = (ch&0XFF00)>>8;
  /* 取出低八�? */
  temp_l = ch&0XFF; 

  /* 发送高�?�? */
  LPUART_WriteByte( base, temp_h);
  while (!(base->STAT & LPUART_STAT_TDRE_MASK));
  
  /* 发送低�?�? */ 
  LPUART_WriteByte( base, temp_l);
  while (!(base->STAT & LPUART_STAT_TDRE_MASK));  
}
 

/******************串口接收�?�?服务函数********************/
void DEBUG_UART_IRQHandler(void)
{
  uint8_t Temp;
  /*串口接收到数�?*/
  rt_interrupt_enter();
  if ((kLPUART_RxDataRegFullFlag)&LPUART_GetStatusFlags(DEBUG_UARTx))
  {
    /*读取数据*/
    Temp = LPUART_ReadByte(DEBUG_UARTx);
    gizPutData(&Temp, 1);
    /*将�?�取到的数据写入到缓冲区*/
   // Uart_SendByte(DEBUG_UARTx,Temp);
  }
  rt_interrupt_leave();
}

