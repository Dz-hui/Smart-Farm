#ifndef __UART_H
#define __UART_H

#include "fsl_common.h"


#define UART_RX_GPIO                GPIO1
#define UART_RX_GPIO_PIN            (23U)
#define UART_RX_IOMUXC              IOMUXC_GPIO_AD_B1_07_LPUART3_RX

#define UART_TX_GPIO                GPIO1
#define UART_TX_GPIO_PIN            (22U)
#define UART_TX_IOMUXC              IOMUXC_GPIO_AD_B1_06_LPUART3_TX


#define DEBUG_UARTx LPUART3
#define DEBUG_UART_IRQ LPUART3_IRQn
#define DEBUG_UART_IRQHandler LPUART3_IRQHandler

#define  DEBUG_UART_BAUDRATE           9600U
#define  DEBUG_UART_STOP_BIT           kLPUART_OneStopBit
#define  DEBUG_UART_ENABLE_SEND        true
#define  DEBUG_UART_ENABLE_RESIVE      true

/*******************************************************************************
 * uart3��������
 ******************************************************************************/
#define UART_RX_PAD_CONFIG_DATA            (SRE_0_SLOW_SLEW_RATE| \
                                            DSE_6_R0_6| \
                                            SPEED_0_LOW_50MHz| \
                                            ODE_0_OPEN_DRAIN_DISABLED| \
                                            PKE_1_PULL_KEEPER_ENABLED| \
                                            PUE_1_PULL_SELECTED| \
                                            PUS_3_22K_OHM_PULL_UP| \
                                            HYS_0_HYSTERESIS_DISABLED) 


#define UART_TX_PAD_CONFIG_DATA            (SRE_0_SLOW_SLEW_RATE| \
                                            DSE_6_R0_6| \
                                            SPEED_0_LOW_50MHz| \
                                            ODE_0_OPEN_DRAIN_DISABLED| \
                                            PKE_1_PULL_KEEPER_ENABLED| \
                                            PUE_0_KEEPER_SELECTED| \
                                            PUS_3_22K_OHM_PULL_UP| \
                                            HYS_0_HYSTERESIS_DISABLED)


/*******************************************************************************
 * ��������
 ******************************************************************************/
 void UART_Config(void);
 void UART_ModeConfig(void);
 void UART_IOMUXC_MUX_Config(void);
 void UART_IOMUXC_PAD_Config(void);
 
 void Uart_SendByte(LPUART_Type *base, uint8_t data);
 void Uart_SendString( LPUART_Type *base, const char *str);
 void Uart_SendHalfWord(LPUART_Type *base, uint16_t ch);




#endif /* __UART_H */


