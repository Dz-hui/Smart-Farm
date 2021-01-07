#include "app.h"


extern emwin_status_typedef emwin_status;

/* UI 线程 */
static rt_thread_t gui_thread = RT_NULL; //定义线程控制块
void gui_thread_entry(void *parameter); //定义线程函数
/* 触摸线程 */
static rt_thread_t touch_thread = RT_NULL; //定义线程控制块
void touch_thread_entry(void *parameter); //定义线程函数

static rt_thread_t gizwits_thread = RT_NULL;
static void gizwits_thread_entry(void *parameter);

static rt_thread_t dht11_thread = RT_NULL;
static void  dht11_thread_entry(void *parameter);

static rt_thread_t bh1750_thread = RT_NULL;
static void bh1750_thread_entry(void* parameter);

static rt_thread_t soil_thread = RT_NULL;
static void soil_thread_entry(void* parameter);

static rt_thread_t distant_thread = RT_NULL;
static void distant_thread_entry(void* parameter);

static rt_thread_t pump_thread = RT_NULL;
static void pump_thread_entry(void* parameter);

static rt_thread_t curtain_up_thread = RT_NULL;
static void curtain_up_thread_entry(void* parameter);

static rt_thread_t curtain_down_thread = RT_NULL;
static void curtain_down_thread_entry(void* parameter);

static rt_thread_t brightness_thread = RT_NULL;
static void brightness_thread_entry(void* parameter);

static rt_thread_t fan_thread = RT_NULL;
static void fan_thread_entry(void* parameter);

static rt_thread_t default_thread = RT_NULL;
static void default_thread_entry(void* parameter);



void gui_thread_entry(void *parameter)
{
	DEBUG_PRINT("enter gui_thread thread");
	GUI_Init();
    WM_MULTIBUF_Enable(1);
	GUIDEMO_Main();
	

	while(1)
	{	
		//GUIDEMO_Main();
		GUI_Main();
		rt_thread_delay(20);
	}
}

void touch_thread_entry(void *parameter)
{
	I2C_Touch_Init();
	GTP_Init_Panel();
	while(1)
	{	
		rt_enter_critical();
		GT9xx_get_on_point();
		rt_exit_critical();
		rt_thread_delay(20);
	}
}


static void gizwits_thread_entry(void *parameter)
{
	while(1)
	{
		rt_enter_critical();  
        userHandle();
        gizwitsHandle((dataPoint_t *)&currentDataPoint); 
        rt_exit_critical(); 
		rt_thread_delay(100);
	}
}

static void  dht11_thread_entry(void *parameter)
{
	while(1)
	{
		rt_enter_critical();
		Read_DHT11(&dht11_data);
		rt_exit_critical(); 
		rt_thread_delay(1000);
	}
}

static void bh1750_thread_entry(void* parameter)
{
	while(1)
	{
		rt_enter_critical();
		gizwits_data.G_bh1750_data = BH1750_measure();
		rt_exit_critical(); 
		rt_thread_delay(1000);	
	}
}


static void distant_thread_entry(void* parameter)
{
	while(1)
	{
		rt_enter_critical();
		

		gizwits_data.G_distant_data = GP2Y0E03_DateRead();
		
		rt_exit_critical();
		rt_thread_delay(1000);
	}
}


static void soil_thread_entry(void* parameter)
{
	while(1)
	{
		rt_enter_critical();
		gizwits_data.G_soil_data = soil_adc_get();
		rt_exit_critical();
		rt_thread_delay(1000);
	}
}

static void pump_thread_entry(void* parameter)
{
	while(1)
	{
		rt_enter_critical();
		if(gizwits_status.G_pump_status == 1 || emwin_status.E_pump_status == 1)
		{
			GPIO_PinWrite(PUMP_GPIO, PUMP_GPIO_PIN, 0U); 
		}
		else if(gizwits_status.G_pump_status == 0 && emwin_status.E_pump_status == 0)
		{
			GPIO_PinWrite(PUMP_GPIO, PUMP_GPIO_PIN, 1U); 
		}
		rt_exit_critical();
		rt_thread_delay(100);
	}
}

static void curtain_up_thread_entry(void* parameter)
{
	uint8_t n;
	while(1)
	{
		rt_enter_critical();

		if(gizwits_status.G_curtain_up_status==1 || emwin_status.E_curtain_up_status==1)
		{
			for(n=100;n>0;n--)
			{
				curtain_up();
			}	
		}
		else if(gizwits_status.G_curtain_up_status==0 && emwin_status.E_curtain_up_status==0)	
		{
			curtain_stop();
			
		}	

		rt_exit_critical(); 

		rt_thread_delay(4);
		
		
	}
}

static void curtain_down_thread_entry(void* parameter)
{
	uint8_t n;
	while(1)
	{
		rt_enter_critical();
		if(gizwits_status.G_curtain_down_status==1 || emwin_status.E_curtain_down_status==1)
		{
			for(n=100;n>0;n--)
			{
				curtain_down();
			}	
		}
		else if(gizwits_status.G_curtain_down_status==0 && emwin_status.E_curtain_down_status==0)	
		{
			curtain_stop();
		}			
		rt_exit_critical();
		
		rt_thread_delay(100);
	}
}

static void fan_thread_entry(void* parameter)
{
	while(1)
	{
		
		rt_enter_critical();
		if(gizwits_status.G_fan_status ==1  )
		{
			QTMR_SetupPwm(FAN_QTMR_PORT,FAN_QTMR_CHANNLE,QTMR_PWM_FREQ,20,false,QTMR_SOURCE_CLOCK / 128);
		}
		else if(gizwits_status.G_fan_status== 2 )
		{
			QTMR_SetupPwm(FAN_QTMR_PORT,FAN_QTMR_CHANNLE,QTMR_PWM_FREQ,50,false,QTMR_SOURCE_CLOCK / 128);
		}
		else if(gizwits_status.G_fan_status == 3)
		{
			QTMR_SetupPwm(FAN_QTMR_PORT,FAN_QTMR_CHANNLE,QTMR_PWM_FREQ,90,false,QTMR_SOURCE_CLOCK / 128);
		}
		
		if(emwin_status.E_fan_status==1)
		{
			QTMR_SetupPwm(FAN_QTMR_PORT,FAN_QTMR_CHANNLE,QTMR_PWM_FREQ,20,false,QTMR_SOURCE_CLOCK / 128);
		}
		
		else if(emwin_status.E_fan_status==2)
		{
			QTMR_SetupPwm(FAN_QTMR_PORT,FAN_QTMR_CHANNLE,QTMR_PWM_FREQ,50,false,QTMR_SOURCE_CLOCK / 128);
		}
		
		else if(emwin_status.E_fan_status==3)
		{
			QTMR_SetupPwm(FAN_QTMR_PORT,FAN_QTMR_CHANNLE,QTMR_PWM_FREQ,90,false,QTMR_SOURCE_CLOCK / 128);
		}
		
		if(gizwits_status.G_fan_status == 0 && emwin_status.E_fan_status==0)
		{
			QTMR_SetupPwm(FAN_QTMR_PORT,FAN_QTMR_CHANNLE,QTMR_PWM_FREQ,0,false,QTMR_SOURCE_CLOCK / 128);

		}
		rt_exit_critical();
		rt_thread_delay(100);
		
	}
}

static void brightness_thread_entry(void* parameter)
{
	while(1)
	{
		rt_enter_critical();
		if(currentDataPoint.valuebrightness>0 )
		{
			QTMR_StartTimer(QTMR_PORT,QTMR_CHANNLE,kQTMR_PriSrcRiseEdge);
			QTMR_SetupPwm(QTMR_PORT,QTMR_CHANNLE,QTMR_PWM_FREQ,100-currentDataPoint.valuebrightness,false,QTMR_SOURCE_CLOCK / 128);
		}
		if(emwin_status.E_light_status==1)
		{
			
			QTMR_StartTimer(QTMR_PORT,QTMR_CHANNLE,kQTMR_PriSrcRiseEdge);
			QTMR_SetupPwm(QTMR_PORT,QTMR_CHANNLE,QTMR_PWM_FREQ,100-button_status.E_light_val,false,QTMR_SOURCE_CLOCK / 128);
		}
		if(currentDataPoint.valuebrightness ==0 && emwin_status.E_light_status==0)
		{
			QTMR_StopTimer(QTMR_PORT,QTMR_CHANNLE);
		}
		rt_exit_critical();
		rt_thread_delay(100);
	}
}

static void default_thread_entry(void* parameter)
{
	
	while(1)
	{
		rt_enter_critical();
		if(gizwits_status.G_default_status == 1 || emwin_status.E_default_status==1)
		{
			// QTMR_StopTimer(QTMR_PORT,QTMR_CHANNLE);
			// QTMR_SetupPwm(FAN_QTMR_PORT,FAN_QTMR_CHANNLE,QTMR_PWM_FREQ,0,false,QTMR_SOURCE_CLOCK / 128);
			// curtain_stop();
			// GPIO_PinWrite(PUMP_GPIO, PUMP_GPIO_PIN, 1U); 
			currentDataPoint.valuepump=0;
			currentDataPoint.valuecurtain_down=0;
			currentDataPoint.valuecurtain_up=0;
			currentDataPoint.valuedefault=0;
			currentDataPoint.valuebrightness=0;
			currentDataPoint.valuefan=0;
			button_status.E_button_curtain_down=0;
			button_status.E_button_curtain_up=0;
			button_status.E_button_default=0;
			button_status.E_button_pump=0;
			button_status.E_light_val=0;
			gizwitsHandle((dataPoint_t *)&currentDataPoint); 
		

		}	
		rt_exit_critical();
		rt_thread_delay(100);
	}
	

	
}




void gui_task_init(void)
{
	/* 创建 GUI 线程 */
	gui_thread = rt_thread_create("gui_thread",
									gui_thread_entry,
									RT_NULL,
									60*1024,
									6,
									20);
	if(gui_thread != RT_NULL)
	{
		DEBUG_PRINT("gui_thread creat succeed");
		rt_thread_startup(gui_thread);
	}		
	else
	{
		DEBUG_PRINT("gui_thread creat fail");
	}
}


void gui_touch_task_init(void)
{
	/* 创建 touch 线程 */
	touch_thread = rt_thread_create("gui_thread",
									touch_thread_entry,
									RT_NULL,
									1024,
									4,
									20);
	if(touch_thread != RT_NULL)
	{
		DEBUG_PRINT("gui_thread creat succeed");
		rt_thread_startup(touch_thread);
	}		
	else
	{
		DEBUG_PRINT("gui_thread creat fail");
	}
}

void gizwits_init(void)
{
	gizwits_thread = rt_thread_create("gizwits",gizwits_thread_entry,RT_NULL,10*1024,3,20);
	if(gizwits_thread != RT_NULL)
	{
		rt_thread_startup(gizwits_thread);
	}
	
}

void dht11_init(void)
{
	dht11_thread = rt_thread_create("dht11",dht11_thread_entry,RT_NULL,1024,7,20);
	if(dht11_thread != RT_NULL)
	{
		rt_thread_startup(dht11_thread);
	}
}

void bh1750_init(void)
{
	bh1750_thread = rt_thread_create("bh1750",bh1750_thread_entry,RT_NULL,1024,7,20);
	if(bh1750_thread != RT_NULL)
	{
		rt_thread_startup(bh1750_thread);
	}

	
}


void soil_init(void)
{
	soil_thread = rt_thread_create("soil",soil_thread_entry,RT_NULL,512,7,20);
	if(soil_thread != RT_NULL)
	{
		rt_thread_startup(soil_thread);
	}
}

void distant_init(void)
{
	distant_thread = rt_thread_create("distant",distant_thread_entry,RT_NULL,512,7,20);
	if(distant_thread != RT_NULL)
	{
		rt_thread_startup(distant_thread);
	}
}

void pump_init(void)
{
	pump_thread = rt_thread_create("pump",pump_thread_entry,RT_NULL,512,5,20);
	if(pump_thread != RT_NULL)
	{
		rt_thread_startup(pump_thread);
	}
}	

void curtain_up_init(void)
{
	curtain_up_thread = rt_thread_create("curtain",curtain_up_thread_entry,RT_NULL,512,5,20);
	if(curtain_up_thread != RT_NULL)
	{
		rt_thread_startup(curtain_up_thread);
	}
}
void curtain_down_init(void)
{
	curtain_down_thread = rt_thread_create("curtain",curtain_down_thread_entry,RT_NULL,512,5,20);
	if(curtain_down_thread != RT_NULL)
	{
		rt_thread_startup(curtain_down_thread);
	}
}


void fan_init(void)
{
	fan_thread = rt_thread_create("fan",fan_thread_entry,RT_NULL,1024,5,20);
	if(fan_thread != RT_NULL)
	{
		rt_thread_startup(fan_thread);
	}
}

void brightness_init(void)
{
	brightness_thread = rt_thread_create("brightness",brightness_thread_entry,RT_NULL,512,5,20);
	if(brightness_thread != RT_NULL)
	{
		rt_thread_startup(brightness_thread);
	}
}


void default_init(void)
{
	default_thread = rt_thread_create("default",default_thread_entry,RT_NULL,1024,5,20);
	if(default_thread != RT_NULL)
	{
		rt_thread_startup(default_thread);
	}
}

