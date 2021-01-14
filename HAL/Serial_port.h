#ifndef __Serial_port_h
#define __Serial_port_h

#include "user_config.h"
#include "pins_rt1052_def.h"
#include "fsl_common.h"

#define __LPUART(x)_IRQHandler              LPUART##x##_IRQHandler
#define LPUART_IRQHandler(x)                __LPUART(x)_IRQHandler 

#if defined(User_Serial_Port)

    #if defined(HAS_USER_Serial == 1)
        #define USER_SERIAL_PORT_HANDLE    LPUART_IRQHandler(HAS_USER_Serial)
    #elif defined(HAS_USER_Serial == 2)
        #define USER_SERIAL_PORT_HANDLE    LPUART_IRQHandler(HAS_USER_Serial)
    #elif defined(HAS_USER_Serial == 3)
        #define USER_SERIAL_PORT_HANDLE    LPUART_IRQHandler(HAS_USER_Serial)
    #elif defined(HAS_USER_Serial == 4)
        #define USER_SERIAL_PORT_HANDLE    LPUART_IRQHandler(HAS_USER_Serial)
    #elif defined(HAS_USER_Serial == 5)
        #define USER_SERIAL_PORT_HANDLE    LPUART_IRQHandler(HAS_USER_Serial)
    #elif defined(HAS_USER_Serial == 6)
        #define USER_SERIAL_PORT_HANDLE    LPUART_IRQHandler(HAS_USER_Serial)
    #elif defined(HAS_USER_Serial == 7)
        #define USER_SERIAL_PORT_HANDLE    LPUART_IRQHandler(HAS_USER_Serial)
    #elif defined(HAS_USER_Serial == 8)
        #define USER_SERIAL_PORT_HANDLE    LPUART_IRQHandler(HAS_USER_Serial)
    #else 
        #error:serial port set not in 1....8, please reset;
    #endif
#endif

typedef enum {
    IN_TRANS,               // serial tran in now
    IN_RECEIVE,             // serial receive in now 
    IN_IDLE,                // serial in idle
    IN_TX_NO_FULL,          // serial's trans buffer can write 
    IN_RX_NO_FULL,          // serial's receive buffer can not read
    IN_TRANS_BUFF_FULL,     // serial's tans buffer is full 
    IN_RECEIVE_BUFF_FULL,   // serial's receive buffer is full 
}SERIAL_STATUS_DEF;

typedef struct {
    uint32_t                tx_head;
    uint32_t                tx_tail;
    uint32_t                rx_head;
    uint32_t                rx_tail;
    uint8_t                 tx_buffer[USER_SERIAL_TX_BUFF];
    uint8_t                 rx_buffer[USER_SERIAL_RX_BUFF];
    uint32_t                tx_length;
    uint32_t                rx_length; 
    SERIAL_STATUS_DEF       tx_status;
    SERIAL_STATUS_DEF       rx_status;
}SERIAL_RING_BUF_DEF;

#endif
