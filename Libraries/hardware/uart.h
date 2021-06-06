/***********************************************************************
*@Author: Dz_hui
*@Date: 2020-06-01 10:45:12
*@FilePath: \hello_world\component\uart\uart.h
*@Drscription: 
***********************************************************************/
#ifndef __UART__H
#define __UART__H

#include "fsl_common.h"
#include "main.h"

#define LPUART(n)       LPUART ## n


#define USB_UART_TX_GPIO       GPIO1
#define USB_UART_TX_PIN        (12U)
#define USB_UART_TX_IOMUXC     IOMUXC_GPIO_AD_B0_12_LPUART1_TX

#define USB_UART_RX_GPIO       GPOIO1
#define USB_UART_RX_PIN        (13U)
#define USB_UART_RX_IOMUXC     IOMUXC_GPIO_AD_B0_13_LPUART1_RX

#define USB_UART_PORT          LPUART1
#define USB_UART_CLK_FREQ      BOARD_DebugConsoleSrcFreq()

#define UART5_TX_GPIO          GPIO2
#define UART5_TX_PIN           (28U)
#define UART5_TX_IOMUXC        IOMUXC_GPIO_B1_12_LPUART5_TX

#define UART5_RX_GPIO          GPOIO2
#define UART5_RX_PIN           (29U)
#define UART5_RX_IOMUXC        IOMUXC_GPIO_B1_13_LPUART5_RX

#define UART5_PORT             LPUART5   
#define UART5_CLK_FREQ         BOARD_DebugConsoleSrcFreq()

#define LPUART1_TX_PIN   
#define LPUART1_RX_PIN
#define LPUART1_TX_PORT     GPIO1
#define LPUART1_RX_PORT     GPIO1
#define LPUART1_TX_MUX      IOMUXC_GPIO_AD_B0_12_LPUART1_TX
#define LPUART1_RX_MUX      IOMUXC_GPIO_AD_B0_13_LPUART1_RX

// #define LPUART2_TX_PIN   
// #define LPUART2_RX_PIN
// #define LPUART2_TX_PORT     GPIO1
// #define LPUART2_RX_PORT     GPIO1
// #define LPUART2_TX_MUX      IOMUXC_GPIO_AD_B0_12_LPUART1_TX
// #define LPUART2_RX_MUX      IOMUXC_GPIO_AD_B0_13_LPUART1_RX

// #define LPUART2_TX_PIN   
// #define LPUART2_RX_PIN
// #define LPUART2_TX_PORT     GPIO1
// #define LPUART2_RX_PORT     GPIO1
// #define LPUART2_TX_MUX      IOMUXC_GPIO_AD_B0_12_LPUART1_TX
// #define LPUART2_RX_MUX      IOMUXC_GPIO_AD_B0_13_LPUART1_RX

// #define LPUART3_TX_PIN   
// #define LPUART3_RX_PIN
// #define LPUART3_TX_PORT     GPIO1
// #define LPUART3_RX_PORT     GPIO1
// #define LPUART3_TX_MUX      IOMUXC_GPIO_AD_B0_12_LPUART1_TX
// #define LPUART3_RX_MUX      IOMUXC_GPIO_AD_B0_13_LPUART1_RX

// #define LPUART4_TX_PIN   
// #define LPUART4_RX_PIN
// #define LPUART4_TX_PORT     GPIO1
// #define LPUART4_RX_PORT     GPIO1
// #define LPUART4_TX_MUX      IOMUXC_GPIO_AD_B0_12_LPUART1_TX
// #define LPUART4_RX_MUX      IOMUXC_GPIO_AD_B0_13_LPUART1_RX

// #define LPUART5_TX_PIN   
// #define LPUART5_RX_PIN
// #define LPUART5_TX_PORT     GPIO1
// #define LPUART5_RX_PORT     GPIO1
// #define LPUART5_TX_MUX      IOMUXC_GPIO_AD_B0_12_LPUART1_TX
// #define LPUART5_RX_MUX      IOMUXC_GPIO_AD_B0_13_LPUART1_RX

// #define LPUART6_TX_PIN   
// #define LPUART6_RX_PIN
// #define LPUART6_TX_PORT     GPIO1
// #define LPUART6_RX_PORT     GPIO1
// #define LPUART6_TX_MUX      IOMUXC_GPIO_AD_B0_12_LPUART1_TX
// #define LPUART6_RX_MUX      IOMUXC_GPIO_AD_B0_13_LPUART1_RX

// #define LPUART7_TX_PIN   
// #define LPUART7_RX_PIN
// #define LPUART7_TX_PORT     GPIO1
// #define LPUART7_RX_PORT     GPIO1
// #define LPUART7_TX_MUX      IOMUXC_GPIO_AD_B0_12_LPUART1_TX
// #define LPUART7_RX_MUX      IOMUXC_GPIO_AD_B0_13_LPUART1_RX

// #define LPUART8_TX_PIN   
// #define LPUART8_RX_PIN
// #define LPUART8_TX_PORT     GPIO1
// #define LPUART8_RX_PORT     GPIO1
// #define LPUART8_TX_MUX      IOMUXC_GPIO_AD_B0_12_LPUART1_TX
// #define LPUART8_RX_MUX      IOMUXC_GPIO_AD_B0_13_LPUART1_RX

bool lpuart_hw_init(LPUART_Type *base, uint32_t baud);
void lpuart_hw_enable_interrupt(LPUART_Type *base ,uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority);
void lpuart_sendbyte(LPUART_Type *base, uint8_t data);
void lpuart_sendstring( LPUART_Type *base,  const char *str);
void lpuart_send_16_data(LPUART_Type *base, uint16_t ch);

#endif






