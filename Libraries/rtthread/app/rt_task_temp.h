#ifndef _rt_task_temp_h
#define _rt_task_temp_h

#include "main.h"

#define DHT11_THREAD_SIZE			1024    
#define DHT11_THREAD_PRIO           5

void dht11_thread_init(void);
void dht11_init(void *parg);

#endif
