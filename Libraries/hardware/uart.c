/***********************************************************************
*@Author: Dz_hui
*@Date: 2020-06-01 10:45:12
*@FilePath: ??���ָ�???��??Smart-Farm??���ָ�???��??Libraries??���ָ�???��??hardware??���ָ�???��??uart.c
*@Drscription: 
***********************************************************************/

#include "uart.h"
#include "board.h"
#include "pad_config.h"
#include "fsl_iomuxc.h"
#include "fsl_gpio.h"
#include "fsl_lpuart.h"
#include "board.h"
#include "fsl_debug_console.h"
#include "stdio.h"
#include "exit.h"
#include "gizwits_protocol.h"

/*pad��������*/
#define UART1_TX_PAD_SETTING_DATA    (SRE_0_SLOW_SLEW_RATE| \
                                  DSE_6_R0_6| \
								  SPEED_1_MEDIUM_100MHz| \
								  ODE_0_OPEN_DRAIN_DISABLED| \
								  PKE_1_PULL_KEEPER_ENABLED| \
								  PUE_0_KEEPER_SELECTED| \
								  PUS_0_100K_OHM_PULL_DOWN| \
								  HYS_0_HYSTERESIS_DISABLED)

#define UART1_RX_PAD_SETTING_DATA    (SRE_0_SLOW_SLEW_RATE| \
                                  DSE_6_R0_6| \
								  SPEED_1_MEDIUM_100MHz| \
								  ODE_0_OPEN_DRAIN_DISABLED| \
								  PKE_1_PULL_KEEPER_ENABLED| \
								  PUE_0_KEEPER_SELECTED| \
								  PUS_0_100K_OHM_PULL_DOWN| \
								  HYS_0_HYSTERESIS_DISABLED)
								  

/***********************************************************************
*@Function: void UART_PAD_config(void)
*@Input: 
*@Return: none
*@Author: Dz_hui
*@Date: 2020-06-01 10:59:37
*@Drscription: pad����
***********************************************************************/
void UART1_PAD_config(void)
{
    IOMUXC_SetPinConfig(USB_UART_RX_IOMUXC,UART1_RX_PAD_SETTING_DATA);
    IOMUXC_SetPinConfig(USB_UART_TX_IOMUXC,UART1_TX_PAD_SETTING_DATA);
}



/***********************************************************************
*@Function: void UART_IOMUXC_config(void)
*@Input: 
*@Return: none
*@Author: Dz_hui
*@Date: 2020-06-01 11:04:14
*@Drscription: MUX����
***********************************************************************/
void UART1_IOMUXC_config(void)
{
    IOMUXC_SetPinMux(USB_UART_RX_IOMUXC,0U);
    IOMUXC_SetPinMux(USB_UART_TX_IOMUXC,0U);
}


/***********************************************************************
*@Function: void UART_MODE_config(void)
*@Input: 
*@Return: none
*@Author: Dz_hui
*@Date: 2020-06-01 11:08:39
*@Drscription: ���ڵ�ģʽ����
***********************************************************************/
void UART1_MODE_config(void)
{
    lpuart_config_t uart_config;
    /*Ĭ�ϳ�ʼ����*/
    LPUART_GetDefaultConfig(&uart_config);
    uart_config.enableRx=true;
    uart_config.enableTx=true;
	
	LPUART_Init(USB_UART_PORT,&uart_config,USB_UART_CLK_FREQ);
	
	/*��������ж�*/
	LPUART_EnableInterrupts(USB_UART_PORT, kLPUART_RxDataRegFullInterruptEnable);
  
	/*�����ж����ȼ�,*/
	IRQN_priority(4,1,1,LPUART1_IRQn);
	/*ʹ���ж�*/
	EnableIRQ(LPUART1_IRQn);
	
}
	 
/***********************************************************************
*@Function: void USB_UART_config(void)
*@Input: 
*@Return: none
*@Author: Dz_hui
*@Date: 2020-06-01 11:30:06
*@Drscription: ���ڳ�ʼ�� 
***********************************************************************/
void USB_UART_config(void)
{
    UART1_PAD_config();
    UART1_IOMUXC_config();
    UART1_MODE_config();
}

/***********************************************************************
*@Function: void UART_senddata(LPUART_Type *base,uint8_t data)
*@Input: 
*@Return: none
*@Author: Dz_hui
*@Date: 2020-06-01 11:31:16
*@Drscription: ���ڷ���һ���ֽ�
***********************************************************************/
void UART_senddata(LPUART_Type *base,uint8_t data)
{
    LPUART_WriteByte(base,data);
    while (!(base->STAT & LPUART_STAT_TDRE_MASK));
}

/***********************************************************************
*@Function: void UART_sendstring(LPUART_Type *base,const char *str  )
*@Input: 
*@Return: none
*@Author: Dz_hui
*@Date: 2020-06-01 11:38:30
*@Drscription: ���ڷ����ַ���
***********************************************************************/
void UART_sendstring(LPUART_Type *base,const char *str  )
{
    LPUART_WriteBlocking(base,(uint8_t *)str,strlen(str));
}

/***********************************************************************
*@Function: int fputc(int ch, FILE * f)
*@Input: 
*@Return: none
*@Author: Dz_hui
*@Date: 2020-06-01 12:22:24
*@Drscription: �ض���printf����
***********************************************************************/
int fputc(int ch, FILE * f)
{
    UART_senddata(USB_UART_PORT,(uint8_t )ch);
    
    return ch;
}

void LPUART1_IRQHandler(void)
{
	uint8_t ucTemp;
  /*���ڽ��յ�����*/
	if ((kLPUART_RxDataRegFullFlag)&LPUART_GetStatusFlags(USB_UART_PORT))
	{
    /*��ȡ����*/
		ucTemp = LPUART_ReadByte(USB_UART_PORT);
    
     /*����ȡ��������д�뵽������*/
		UART_senddata(USB_UART_PORT,ucTemp);
	}
	
}






