#include "fsl_iomuxc.h"
#include "fsl_gpio.h"  
  
#include "pad_config.h"  
#include "pump.h"   

#define PUMP_PAD_CONFIG_DATA            (SRE_0_SLOW_SLEW_RATE| \
                                        DSE_6_R0_6| \
                                        SPEED_2_MEDIUM_100MHz| \
                                        ODE_0_OPEN_DRAIN_DISABLED| \
                                        PKE_0_PULL_KEEPER_DISABLED| \
                                        PUE_0_KEEPER_SELECTED| \
                                        PUS_0_100K_OHM_PULL_DOWN| \
                                        HYS_0_HYSTERESIS_DISABLED)    

static void PUMP_IOMUXC_MUX_Config(void);
static void PUMP_IOMUXC_PAD_Config(void);
static void PUMP_GPIO_Mode_Config(void);


static void PUMP_IOMUXC_MUX_Config(void)
{
  IOMUXC_SetPinMux(PUMP_IOMUXC, 0U); 
}


static void PUMP_IOMUXC_PAD_Config(void)
{

  IOMUXC_SetPinConfig(PUMP_IOMUXC, PUMP_PAD_CONFIG_DATA); 
}

static void PUMP_GPIO_Mode_Config(void)
{     
  gpio_pin_config_t led_config;      
    
  led_config.direction = kGPIO_DigitalOutput; 
  led_config.outputLogic =  0;                
  led_config.interruptMode = kGPIO_NoIntmode; 
  
  GPIO_PinInit(PUMP_GPIO, PUMP_GPIO_PIN, &led_config);
}

void PUMP_GPIO_Config(void)
{
  PUMP_IOMUXC_MUX_Config();
  PUMP_IOMUXC_PAD_Config();
  PUMP_GPIO_Mode_Config();
}









/*********************************************END OF FILE**********************/
