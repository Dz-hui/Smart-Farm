#include "fsl_iomuxc.h"
#include "fsl_gpio.h"  
  
#include "pad_config.h"
#include "step.h"
#include "core_delay.h"


/* �������ž�ʹ��ͬ����PAD���� */
#define STEP_PAD_CONFIG_DATA            (SRE_0_SLOW_SLEW_RATE| \
                                        DSE_6_R0_6| \
                                        SPEED_2_MEDIUM_100MHz| \
                                        ODE_0_OPEN_DRAIN_DISABLED| \
                                        PKE_0_PULL_KEEPER_DISABLED| \
                                        PUE_0_KEEPER_SELECTED| \
                                        PUS_0_100K_OHM_PULL_DOWN| \
                                        HYS_0_HYSTERESIS_DISABLED)   
										
										

static void STEP_IOMUXC_MUX_Config(void)
{
  /* ���İ��LED�� */    
  /* �������ŵĸ���ģʽΪGPIO����ʹ��SION���� */
  IOMUXC_SetPinMux(STEP_IN1_IOMUXC, 0U);

  /* RGB LED�ƣ�ʹ��ͬ����IOMUXC MUX���� */  
  IOMUXC_SetPinMux(STEP_IN2_IOMUXC, 0U); 
  IOMUXC_SetPinMux(STEP_IN3_IOMUXC, 0U);  
  IOMUXC_SetPinMux(STEP_IN4_IOMUXC, 0U);
}

/**
* @brief  ��ʼ��LED���IOMUXC��MUX��������
* @param  ��
* @retval ��
*/
static void STEP_IOMUXC_PAD_Config(void)
{
  /* ���İ��LED�� */    
  IOMUXC_SetPinConfig(STEP_IN1_IOMUXC, STEP_PAD_CONFIG_DATA);  
 
  /* RGB LED�ƣ�ʹ��ͬ����IOMUXC PAD���� */ 
  IOMUXC_SetPinConfig(STEP_IN2_IOMUXC, STEP_PAD_CONFIG_DATA); 
  IOMUXC_SetPinConfig(STEP_IN3_IOMUXC, STEP_PAD_CONFIG_DATA); 
  IOMUXC_SetPinConfig(STEP_IN4_IOMUXC, STEP_PAD_CONFIG_DATA);  
}


 /**
  * @brief  ��ʼ��LED��ص�GPIOģʽ
  * @param  ��
  * @retval ��
  */
static void STEP_GPIO_Mode_Config(void)
{     
  /* ����gpio��ʼ�����ýṹ�� */
  gpio_pin_config_t step_config;      
    
   /** ���İ��LED�ƣ�GPIO���� **/       
  step_config.direction = kGPIO_DigitalOutput; //���ģʽ
  step_config.outputLogic =  0;                //Ĭ�ϸߵ�ƽ    
  step_config.interruptMode = kGPIO_NoIntmode; //��ʹ���ж�
  
  /* ��ʼ�� LED GPIO. */
  GPIO_PinInit(STEP_IN1_PORT, STEP_IN1_GPIO_PIN, &step_config);
  
  /* ʹ��ͬ����LED config����RGB LED�� */
  GPIO_PinInit(STEP_IN2_PORT, STEP_IN2_GPIO_PIN, &step_config);
  GPIO_PinInit(STEP_IN3_PORT, STEP_IN3_GPIO_PIN, &step_config);
  GPIO_PinInit(STEP_IN4_PORT, STEP_IN4_GPIO_PIN, &step_config);
}

/**
  * @brief  ��ʼ������LED��IO
  * @param  ��
  * @retval ��
  */
void STEP_GPIO_Config(void)
{
  /* ��ʼ��GPIO���á����ԡ�ģʽ */
  STEP_IOMUXC_MUX_Config();
  STEP_IOMUXC_PAD_Config();
  STEP_GPIO_Mode_Config();
}


/**��ʱ��ת��**/
void curtain_down(void)
{
	uint8_t i;
	for(i=0;i<4;i++)
	{
		switch(i)
		{
			case 0:
				GPIO_PinWrite(STEP_IN1_PORT,STEP_IN1_GPIO_PIN,1);
				GPIO_PinWrite(STEP_IN2_PORT,STEP_IN2_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN3_PORT,STEP_IN3_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN4_PORT,STEP_IN4_GPIO_PIN,0);
			break;
			
			case 1:
				GPIO_PinWrite(STEP_IN2_PORT,STEP_IN2_GPIO_PIN,1);
				GPIO_PinWrite(STEP_IN1_PORT,STEP_IN1_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN3_PORT,STEP_IN3_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN4_PORT,STEP_IN4_GPIO_PIN,0);
			break;
			
			case 2:
				GPIO_PinWrite(STEP_IN3_PORT,STEP_IN3_GPIO_PIN,1);
				GPIO_PinWrite(STEP_IN2_PORT,STEP_IN2_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN1_PORT,STEP_IN1_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN4_PORT,STEP_IN4_GPIO_PIN,0);
			break;
			
			case 3:
				GPIO_PinWrite(STEP_IN4_PORT,STEP_IN4_GPIO_PIN,1);
				GPIO_PinWrite(STEP_IN2_PORT,STEP_IN2_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN3_PORT,STEP_IN3_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN1_PORT,STEP_IN1_GPIO_PIN,0);
			break;
				
		}
		
		CPU_TS_Tmr_Delay_US(4000);
	}
	
}

/**˳ʱ��ת��**/
void curtain_up(void)
{
	uint8_t i;
	for(i=0;i<4;i++)
	{
		switch(i)
		{
			case 0:
				GPIO_PinWrite(STEP_IN4_PORT,STEP_IN4_GPIO_PIN,1);
				GPIO_PinWrite(STEP_IN2_PORT,STEP_IN2_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN3_PORT,STEP_IN3_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN1_PORT,STEP_IN1_GPIO_PIN,0);

			break;
			
			case 1:
				GPIO_PinWrite(STEP_IN3_PORT,STEP_IN3_GPIO_PIN,1);
				GPIO_PinWrite(STEP_IN1_PORT,STEP_IN1_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN2_PORT,STEP_IN2_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN4_PORT,STEP_IN4_GPIO_PIN,0);

			break;
			
			case 2:
				GPIO_PinWrite(STEP_IN2_PORT,STEP_IN2_GPIO_PIN,1);
				GPIO_PinWrite(STEP_IN1_PORT,STEP_IN1_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN3_PORT,STEP_IN3_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN4_PORT,STEP_IN4_GPIO_PIN,0);

			break;
			
			case 3:
				GPIO_PinWrite(STEP_IN1_PORT,STEP_IN1_GPIO_PIN,1);
				GPIO_PinWrite(STEP_IN2_PORT,STEP_IN2_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN3_PORT,STEP_IN3_GPIO_PIN,0);
				GPIO_PinWrite(STEP_IN4_PORT,STEP_IN4_GPIO_PIN,0);

			break;
				
		}
		CPU_TS_Tmr_Delay_US(4000);
	}
		

}

void curtain_stop(void)
{
	GPIO_PinWrite(STEP_IN1_PORT,STEP_IN1_GPIO_PIN,0);
	GPIO_PinWrite(STEP_IN2_PORT,STEP_IN2_GPIO_PIN,0);
	GPIO_PinWrite(STEP_IN3_PORT,STEP_IN3_GPIO_PIN,0);
	GPIO_PinWrite(STEP_IN4_PORT,STEP_IN4_GPIO_PIN,0);
	
}





