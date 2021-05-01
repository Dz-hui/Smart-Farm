#include "rt_task_temp.h"


rt_thread_t dht11_thread = RT_NULL;
#define DHT11_THREAD_SIZE			1024    
#define DHT11_THREAD_PRIO           5

void dht11_init(void *parg);

void dht11_thread_init(void) {

	dht11_thread = rt_thread_create(	"dht11 thread",
										dht11_init,
										NULL,
										DHT11_THREAD_SIZE,
										DHT11_THREAD_PRIO,
										20);

	if(dht11_thread != RT_NULL)
	{
		rt_thread_startup(dht11_thread);
	}
	else 
		DEBUG_PRINT("dht11_thread ERR");
}

void dht11_init(void *parg) {

    uint8_t is_read_succeed = 0; 
	while(1) {

        // ÁÙ½ç¶Î
        is_read_succeed = Read_DHT11(&dht11_data);  
        // ÁÙ½ç¶Î¡ª¡ªend

        if(is_read_succeed) dht11_lvgl_display(&dht11_data);
		rt_thread_mdelay(200);
	}
}
