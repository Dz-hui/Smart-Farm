/**
  ******************************************************************
  * @file    bsp_led.c
  * @author  fire
  * @version V1.1
  * @date    2018-xx-xx
  * @brief   ledӦ�ú����ӿ�
  ******************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ��  i.MXRT1052������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************
  */
#include "fsl_iomuxc.h"
#include "fsl_gpio.h"  
  
#include "pad_config.h"  
#include "pump.h"   

/*******************************************************************************
 * ��
 ******************************************************************************/
/* �������ž�ʹ��ͬ����PAD���� */
#define PUMP_PAD_CONFIG_DATA            (SRE_0_SLOW_SLEW_RATE| \
                                        DSE_6_R0_6| \
                                        SPEED_2_MEDIUM_100MHz| \
                                        ODE_0_OPEN_DRAIN_DISABLED| \
                                        PKE_0_PULL_KEEPER_DISABLED| \
                                        PUE_0_KEEPER_SELECTED| \
                                        PUS_0_100K_OHM_PULL_DOWN| \
                                        HYS_0_HYSTERESIS_DISABLED)   
    /* ����˵�� : */
    /* ת������: ת��������
      ����ǿ��: R0/6 
      �������� : medium(100MHz)
      ��©����: �ر� 
      ��/����������: �ر�
      ��/������ѡ��: �������������ѹرգ�������Ч��
      ����/����ѡ��: 100Kŷķ�����������ѹرգ�������Ч��
      �ͻ�������: �ر� */     

/*******************************************************************************
 * ����
 ******************************************************************************/
static void PUMP_IOMUXC_MUX_Config(void);
static void PUMP_IOMUXC_PAD_Config(void);
static void PUMP_GPIO_Mode_Config(void);

/**
* @brief  ��ʼ��LED���IOMUXC��MUX��������
* @param  ��
* @retval ��
*/
static void PUMP_IOMUXC_MUX_Config(void)
{
  IOMUXC_SetPinMux(PUMP_IOMUXC, 0U); 
}

/**
* @brief  ��ʼ��LED���IOMUXC��MUX��������
* @param  ��
* @retval ��
*/
static void PUMP_IOMUXC_PAD_Config(void)
{
  /* ���İ��LED�� */    
  //IOMUXC_SetPinConfig(CORE_BOARD_LED_IOMUXC, LED_PAD_CONFIG_DATA);  
 
  /* RGB LED�ƣ�ʹ��ͬ����IOMUXC PAD���� */ 
  IOMUXC_SetPinConfig(PUMP_IOMUXC, PUMP_PAD_CONFIG_DATA); 
 
}


 /**
  * @brief  ��ʼ��LED��ص�GPIOģʽ
  * @param  ��
  * @retval ��
  */
static void PUMP_GPIO_Mode_Config(void)
{     
  /* ����gpio��ʼ�����ýṹ�� */
  gpio_pin_config_t led_config;      
    
      
  led_config.direction = kGPIO_DigitalOutput; //���ģʽ
  led_config.outputLogic =  1;                //Ĭ�ϸߵ�ƽ    
  led_config.interruptMode = kGPIO_NoIntmode; //��ʹ���ж�
  

  GPIO_PinInit(PUMP_GPIO, PUMP_GPIO_PIN, &led_config);
  
}

/**
  * @brief  ��ʼ������LED��IO
  * @param  ��
  * @retval ��
  */
void PUMP_GPIO_Config(void)
{
  /* ��ʼ��GPIO���á����ԡ�ģʽ */
  PUMP_IOMUXC_MUX_Config();
  PUMP_IOMUXC_PAD_Config();
  PUMP_GPIO_Mode_Config();
}


/*********************************************END OF FILE**********************/
