#include "fsl_iomuxc.h"
#include "fsl_gpio.h"  
  
#include "pad_config.h"
#include "step.h"
#include "core_delay.h"


STEP_DEF user_step;

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
  /* �������? */    
  /* �������ŵĸ���ģʽΪGPIO����ʹ��SION���� */
  IOMUXC_SetPinMux(STEP_IN1_IOMUXC, 0U);

  /* ���������ʹ���?����IOMUXC MUX���� */  
  IOMUXC_SetPinMux(STEP_IN2_IOMUXC, 0U); 
  IOMUXC_SetPinMux(STEP_IN3_IOMUXC, 0U);  
  IOMUXC_SetPinMux(STEP_IN4_IOMUXC, 0U);
}

/**
* @brief  ��ʼ������������IOMUXC��MUX��������
* @param  ��
* @retval ��
*/
static void STEP_IOMUXC_PAD_Config(void)
{
  /* �������? */    
  IOMUXC_SetPinConfig(STEP_IN1_IOMUXC, STEP_PAD_CONFIG_DATA);  
 
  /* ���������ʹ���?����IOMUXC PAD���� */ 
  IOMUXC_SetPinConfig(STEP_IN2_IOMUXC, STEP_PAD_CONFIG_DATA); 
  IOMUXC_SetPinConfig(STEP_IN3_IOMUXC, STEP_PAD_CONFIG_DATA); 
  IOMUXC_SetPinConfig(STEP_IN4_IOMUXC, STEP_PAD_CONFIG_DATA);  
}


 /**
  * @brief  ��ʼ�����������ص�GPIOģʽ
  * @param  ��
  * @retval ��
  */
static void STEP_GPIO_Mode_Config(void)
{     
  /* ����gpio��ʼ�����ýṹ�� */
  gpio_pin_config_t step_config;      
    
   /** ���������GPIO���� **/       
  step_config.direction = kGPIO_DigitalOutput; //���ģ�?
  step_config.outputLogic =  0;                //Ĭ�ϸߵ�ƽ    
  step_config.interruptMode = kGPIO_NoIntmode; //��ʹ���ж�
  
  /* ��ʼ���������? */
  GPIO_PinInit(STEP_IN1_PORT, STEP_IN1_GPIO_PIN, &step_config);
  GPIO_PinInit(STEP_IN2_PORT, STEP_IN2_GPIO_PIN, &step_config);
  GPIO_PinInit(STEP_IN3_PORT, STEP_IN3_GPIO_PIN, &step_config);
  GPIO_PinInit(STEP_IN4_PORT, STEP_IN4_GPIO_PIN, &step_config);
}

/**
  * @brief  ��ʼ���������IO
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



void user_step_init(void) {

	user_step.curtain_dir = 0;
	user_step.motor_num = 0;
	user_step.step_delay = 4; 
	user_step.step_move = 0;
	user_step.step_status = STEP_STOP;
	user_step.curtain_status = CURTAIN_OFF;
}

void step_move(uint8_t ch1,uint8_t ch2,uint8_t ch3,uint8_t ch4) {

	if(user_step.step_move == 0) {
		curtain_stop();
		return;
	}
	else {
		user_step.step_move--;
	}

	GPIO_PinWrite(STEP_IN1_PORT,STEP_IN1_GPIO_PIN,ch1);
	GPIO_PinWrite(STEP_IN2_PORT,STEP_IN2_GPIO_PIN,ch2);
	GPIO_PinWrite(STEP_IN3_PORT,STEP_IN3_GPIO_PIN,ch3);
	GPIO_PinWrite(STEP_IN4_PORT,STEP_IN4_GPIO_PIN,ch4);
}


/**��ʱ��ת��**/
void curtain_down(void)
{
	switch(user_step.motor_num)
	{
		case 0:
			step_move(1,0,0,0);
			user_step.motor_num++;
			// user_step.step_status = STEP_IN_MOVE;
		break;
		
		case 1:
			step_move(0,1,0,0);
			user_step.motor_num++;
			// user_step.step_status = STEP_IN_MOVE;
		break;
		
		case 2:
			step_move(0,0,1,0);
			user_step.motor_num++;
			// user_step.step_status = STEP_IN_MOVE;
		break;
		
		case 3:
			step_move(0,0,0,1);
			user_step.motor_num = 0;
			// user_step.step_status = STEP_STOP;
		break;
	}
}

/**˳ʱ��ת��**/
void curtain_up(void)
{
	switch(user_step.motor_num)
	{
		case 0:
		step_move(0,0,0,1);
		user_step.motor_num++;
		// user_step.step_status = STEP_IN_MOVE;
		break;
		
		case 1:
		step_move(0,0,1,0);
		user_step.motor_num++;
		// user_step.step_status = STEP_IN_MOVE;
		break;
		
		case 2:
		step_move(0,1,0,0);
		user_step.motor_num++;
		// user_step.step_status = STEP_IN_MOVE;
		break;
		
		case 3:
		step_move(1,0,0,0);
		user_step.motor_num = 0;
		// user_step.step_status = STEP_STOP;
		break;
	}
}

void curtain_stop(void)
{
	GPIO_PinWrite(STEP_IN1_PORT,STEP_IN1_GPIO_PIN,0);
	GPIO_PinWrite(STEP_IN2_PORT,STEP_IN2_GPIO_PIN,0);
	GPIO_PinWrite(STEP_IN3_PORT,STEP_IN3_GPIO_PIN,0);
	GPIO_PinWrite(STEP_IN4_PORT,STEP_IN4_GPIO_PIN,0);
}





