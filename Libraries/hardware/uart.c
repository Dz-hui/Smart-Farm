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
#include "exit.h"

#define LPUART_PAD    				(SRE_0_SLOW_SLEW_RATE| \
									DSE_6_R0_6| \
									SPEED_1_MEDIUM_100MHz| \
									ODE_0_OPEN_DRAIN_DISABLED| \
									PKE_1_PULL_KEEPER_ENABLED| \
									PUE_0_KEEPER_SELECTED| \
									PUS_0_100K_OHM_PULL_DOWN| \
									HYS_0_HYSTERESIS_DISABLED)

lpuart_config_t uart_hw_config;

void lpuart_hw_gpio_init(LPUART_Type *base) {

	if(base == LPUART1) { 	
#if (defined(LPUART1_TX_PIN)&&defined(LPUART1_RX_PIN))
		IOMUXC_SetPinConfig(LPUART1_TX_MUX, LPUART_PAD);
		IOMUXC_SetPinConfig(LPUART1_RX_MUX, LPUART_PAD);
		IOMUXC_SetPinMux(LPUART1_RX_MUX,0U);
		IOMUXC_SetPinMux(LPUART1_TX_MUX,0U);
#else
		IOMUXC_SetPinConfig(LPUART1_TX_MUX,LPUART_PAD);
		IOMUXC_SetPinConfig(LPUART1_RX_MUX,LPUART_PAD);
		IOMUXC_SetPinMux(LPUART1_RX_MUX,0U);
		IOMUXC_SetPinMux(LPUART1_TX_MUX,0U);
#endif
	}
	else if(base == LPUART2) {
#if (defined(LPUART2_TX_PIN)&&defined(LPUART2_RX_PIN))
		IOMUXC_SetPinConfig(LPUART2_TX_MUX,LPUART_PAD);
		IOMUXC_SetPinConfig(LPUART2_RX_MUX,LPUART_PAD);
		IOMUXC_SetPinMux(LPUART2_RX_MUX,0U);
		IOMUXC_SetPinMux(LPUART2_TX_MUX,0U);
#else 

#endif
	}
	else if(base == LPUART3) {
#if (defined(LPUART3_TX_PIN)&&defined(LPUART3_RX_PIN))
		IOMUXC_SetPinConfig(LPUART3_TX_MUX,LPUART_PAD);
		IOMUXC_SetPinConfig(LPUART3_RX_MUX,LPUART_PAD);
		IOMUXC_SetPinMux(LPUART3_RX_MUX,0U);
		IOMUXC_SetPinMux(LPUART3_TX_MUX,0U);
#else 

#endif
	}
	else if(base == LPUART4) {
#if (defined(LPUART4_TX_PIN)&&defined(LPUART4_RX_PIN))
		IOMUXC_SetPinConfig(LPUART4_TX_MUX,LPUART_PAD);
		IOMUXC_SetPinConfig(LPUART4_RX_MUX,LPUART_PAD);
		IOMUXC_SetPinMux(LPUART4_RX_MUX,0U);
		IOMUXC_SetPinMux(LPUART4_TX_MUX,0U);
#else 

#endif
	}
	else if(base == LPUART5) {
#if (defined(LPUART5_TX_PIN)&&defined(LPUART5_RX_PIN))
		IOMUXC_SetPinConfig(LPUART5_TX_MUX,LPUART_PAD);
		IOMUXC_SetPinConfig(LPUART5_RX_MUX,LPUART_PAD);
		IOMUXC_SetPinMux(LPUART5_RX_MUX,0U);
		IOMUXC_SetPinMux(LPUART5_TX_MUX,0U);
#else 

#endif
	}
	else if(base == LPUART6) {
#if (defined(LPUART6_TX_PIN)&&defined(LPUART6_RX_PIN))
		IOMUXC_SetPinConfig(LPUART6_TX_MUX,LPUART_PAD);
		IOMUXC_SetPinConfig(LPUART6_RX_MUX,LPUART_PAD);
		IOMUXC_SetPinMux(LPUART6_RX_MUX,0U);
		IOMUXC_SetPinMux(LPUART6_TX_MUX,0U);
#else 

#endif
	}
	else if(base == LPUART7) {
#if (defined(LPUART7_TX_PIN)&&defined(LPUART7_RX_PIN))
		IOMUXC_SetPinConfig(LPUART7_TX_MUX,LPUART_PAD);
		IOMUXC_SetPinConfig(LPUART7_RX_MUX,LPUART_PAD);
		IOMUXC_SetPinMux(LPUART7_RX_MUX,0U);
		IOMUXC_SetPinMux(LPUART7_TX_MUX,0U);
#else 

#endif
	}
	else if(base == LPUART8) {
#if (defined(LPUART3_TX_PIN)&&defined(LPUART3_RX_PIN))
		IOMUXC_SetPinConfig(LPUART8_TX_MUX,LPUART_PAD);
		IOMUXC_SetPinConfig(LPUART8_RX_MUX,LPUART_PAD);
		IOMUXC_SetPinMux(LPUART8_RX_MUX,0U);
		IOMUXC_SetPinMux(LPUART8_TX_MUX,0U);
#else 

#endif
	}
}

bool lpuart_hw_init(LPUART_Type *base, uint32_t baud) {
	lpuart_hw_gpio_init(base);
	LPUART_GetDefaultConfig(&uart_hw_config);
	uart_hw_config.baudRate_Bps = baud;
    uart_hw_config.enableRx=true;
    uart_hw_config.enableTx=true;
	LPUART_Init(base, &uart_hw_config, BOARD_DebugConsoleSrcFreq());
	return true;
}

void lpuart_hw_enable_interrupt(LPUART_Type *base ,uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority) {

	IRQn_Type IRQn;
	if(base == LPUART1)			IRQn = LPUART1_IRQn;
	else if(base == LPUART2)	IRQn = LPUART2_IRQn;
	else if(base == LPUART3)	IRQn = LPUART3_IRQn;
	else if(base == LPUART4)	IRQn = LPUART4_IRQn;
	else if(base == LPUART5)	IRQn = LPUART5_IRQn;
	else if(base == LPUART6)	IRQn = LPUART6_IRQn;
	else if(base == LPUART7)	IRQn = LPUART7_IRQn;
	else if(base == LPUART8)	IRQn = LPUART8_IRQn;
	LPUART_EnableInterrupts(base, kLPUART_RxDataRegFullInterruptEnable);
	IRQN_priority(PriorityGroup, PreemptPriority, SubPriority, IRQn);
	EnableIRQ(IRQn);
}

void lpuart_sendbyte(LPUART_Type *base, uint8_t data)
{
  LPUART_WriteByte( base, data);
  while (!(base->STAT & LPUART_STAT_TDRE_MASK));
}


void lpuart_sendstring( LPUART_Type *base,  const char *str)
{
  LPUART_WriteBlocking( base, (const uint8_t *)str, strlen(str));
}

void lpuart_send_16_data(LPUART_Type *base, uint16_t ch)
{
  uint8_t temp_h, temp_l;
  temp_h = (ch&0XFF00)>>8;
  temp_l = ch&0XFF; 

  LPUART_WriteByte( base, temp_h);
  while (!(base->STAT & LPUART_STAT_TDRE_MASK));
  
  LPUART_WriteByte( base, temp_l);
  while (!(base->STAT & LPUART_STAT_TDRE_MASK));  
}

void LPUART3_IRQHandler(void) {
	uint8_t temp;
	rt_interrupt_enter();
	if ((kLPUART_RxDataRegFullFlag)&LPUART_GetStatusFlags(GIZWITS_SERIAL))
	{
		temp = LPUART_ReadByte(GIZWITS_SERIAL);
		gizPutData(&temp, 1);
	}
	rt_interrupt_leave();
}











