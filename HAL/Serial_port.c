#include "Serial_port.h"

SERIAL_RING_BUF_DEF serial_ring_buff;



// #if defined(HAS_USER_Serial)
#if 1
void serial_port_init(uint32_t baoud) {


}
#endif

void ring_buff_init(SERIAL_RING_BUF_DEF *rb) {
    rb->tx_head = 0;
    rb->tx_tail = 0;
    rb->tx_length = 0;
    rb->rx_length = 0;
}

void ring_buf_tx_write_data(SERIAL_RING_BUF_DEF *rb,uint8_t data) {

    if(rb->tx_length >= USER_SERIAL_TX_BUFF)   //Judge whether the queue is full
        return;

    rb->tx_buffer[rb->tx_tail] = data;
    rb->tx_tail++;
    rb->tx_length++;
}

void ring_buf_tx_read_data(SERIAL_RING_BUF_DEF *rb,uint8_t *data) {

    if(rb->tx_length == 0) 
        return;

    *data = rb->tx_buffer[rb->tx_head];
    rb->tx_head++;
    rb->tx_length--;
}

void ring_buf_rx_write_data(SERIAL_RING_BUF_DEF *rb,uint8_t data) {

    if(rb->rx_length >= USER_SERIAL_RX_BUFF)   //Judge whether the queue is full
        return;

    rb->rx_buffer[rb->rx_tail] = data;
    rb->rx_tail++;
    rb->rx_length++;
}

void ring_buf_rx_read_data(SERIAL_RING_BUF_DEF *rb,uint8_t *data) {

    if(rb->rx_length == 0) 
        return;

    *data = rb->rx_buffer[rb->rx_head];
    rb->rx_head++;
    rb->rx_length--;
}


// serial port handle define
#if defined(User_Serial_Port)
void USER_SERIAL_PORT_HANDLE() {

    /* receive handle */
    if (rb->tx_status ==) {
        if(rb->status == IN_RX_NO_FULL) {


        }
    }
}
#endif








