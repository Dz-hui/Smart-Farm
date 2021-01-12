#ifndef __user_config_h
#define __user_config_h


/*
 Generally speaking, the default output will be based on the output serial port of wildfire's 
 i.MX RT 1052 development board. However, you can redefine it by yourself. After selecting the
 serial port number, you need to add the corresponding serial port pin to do the corresponding 
 initialization. HAS_USER_Serial It is used to turn on or block some initialization functions
*/
// #define User_Serial_Port     
#define USER_SERIAL_TX_BUFF                 128
#define USER_SERIAL_RX_BUFF                 48
#if defined(User_Serial_Port)
#define HAS_USER_Serial                     1           //user serial port
#define User_Serial_Port_TX
#define User_Serial_Port_RX
#endif

/*
 Here you can customize the number of cases to initialize KEY
*/
#define USER_KEY_NUM                2


#endif
