#ifndef __Serial_port_h
#define __Serial_port_h

#include "user_config.h"
#include "pins_rt1052_def.h"
#include "fsl_common.h"


typedef enum {
    IN_TRANS,
    IN_RECEIVE,
    IN_IDLE,
    IN_TX_NO_FULL,
    IN_RX_NO_FULL,
    IN_TRANS_BUFF_FULL,
    IN_RECEIVE_BUFF_FULL,
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
