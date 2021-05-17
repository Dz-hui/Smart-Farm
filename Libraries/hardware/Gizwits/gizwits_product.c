/**
************************************************************
* @file         gizwits_product.c
* @brief        Gizwits control protocol processing, and platform-related hardware initialization 
* @author       Gizwits
* @date         2017-07-19
* @version      V03030000
* @copyright    Gizwits
*
* @note         Gizwits is only for smart hardware
*               Gizwits Smart Cloud for Smart Products
*               Links | Value Added | Open | Neutral | Safety | Own | Free | Ecology
*               www.gizwits.com
*
***********************************************************/
#include <stdio.h>
#include <string.h>
#include "gizwits_product.h"
#include "rt_task_lvgl.h"
#include "fsl_lpuart.h"
#include "pump.h"
#include "rt_task_control.h"

static uint32_t timerMsCount;

/** Current datapoint */
dataPoint_t currentDataPoint;

/**@} */
/**@name Gizwits User Interface
* @{
*/

/**
* @brief Event handling interface

* Description:

* 1. Users can customize the changes in WiFi module status

* 2. Users can add data points in the function of event processing logic, such as calling the relevant hardware peripherals operating interface

* @param [in] info: event queue
* @param [in] data: protocol data
* @param [in] len: protocol data length
* @return NULL
* @ref gizwits_protocol.h
*/
int8_t gizwitsEventProcess(eventInfo_t *info, uint8_t *gizdata, uint32_t len)
{
  uint8_t i = 0;
  dataPoint_t *dataPointPtr = (dataPoint_t *)gizdata;
  moduleStatusInfo_t *wifiData = (moduleStatusInfo_t *)gizdata;
  protocolTime_t *ptime = (protocolTime_t *)gizdata;
  
#if MODULE_TYPE
  gprsInfo_t *gprsInfoData = (gprsInfo_t *)gizdata;
#else
  moduleInfo_t *ptModuleInfo = (moduleInfo_t *)gizdata;
#endif

  if((NULL == info) || (NULL == gizdata))
  {
    return -1;
  }

  for(i=0; i<info->num; i++)
  {
    switch(info->event[i])
    {
      case EVENT_pump:
        currentDataPoint.valuepump = dataPointPtr->valuepump;
        GIZWITS_LOG("Evt: EVENT_pump %d \n", currentDataPoint.valuepump);
        if(0x01 == currentDataPoint.valuepump)
        {
          PUMP_ON();
          my_ctrl.pump_status =1;
        }
        else
        {
          //user handle  
          PUMP_OFF(); 
          my_ctrl.pump_status = 0; 
        }
        break;
      case EVENT_curtain:
        currentDataPoint.valuecurtain = dataPointPtr->valuecurtain;
        GIZWITS_LOG("Evt: EVENT_curtain %d \n", currentDataPoint.valuecurtain);
        if(0x01 == currentDataPoint.valuecurtain)
        {
          //user handle
          if(user_step.step_status != STEP_IN_MOVE) {
            user_step.step_move = NEED_TO_RUN_STEP;
            user_step.curtain_dir = 1;
            user_step.curtain_status = CURTAIN_ON;
            my_ctrl.curtain_status = 1; 
          }
        }
        else
        {
          //user handle  
          if(user_step.step_status != STEP_IN_MOVE) { 
            user_step.step_move = NEED_TO_RUN_STEP;
            user_step.curtain_dir = 0;
            user_step.curtain_status = CURTAIN_OFF;
            my_ctrl.curtain_status = 0; 
          } 
        }
        break;


      case EVENT_brightness:
        currentDataPoint.valuebrightness = dataPointPtr->valuebrightness;
        GIZWITS_LOG("Evt:EVENT_brightness %d\n",currentDataPoint.valuebrightness);
        //user handle
        led_pwm(currentDataPoint.valuebrightness);
        my_ctrl.led_value = currentDataPoint.valuebrightness;
        break;
      case EVENT_fan:
        currentDataPoint.valuefan = dataPointPtr->valuefan;
        GIZWITS_LOG("Evt:EVENT_fan %d\n",currentDataPoint.valuefan);
        //user handle
        fan_pwm(currentDataPoint.valuefan*30);
        my_ctrl.fan_mode = currentDataPoint.valuefan;
        break;


      case WIFI_SOFTAP:
        break;
      case WIFI_AIRLINK:
        break;
      case WIFI_STATION:
        break;
      case WIFI_CON_ROUTER:
 
        break;
      case WIFI_DISCON_ROUTER:
 
        break;
      case WIFI_CON_M2M:
 
        break;
      case WIFI_DISCON_M2M:
        break;
      case WIFI_RSSI:
        GIZWITS_LOG("RSSI %d\n", wifiData->rssi);
        break;
      case TRANSPARENT_DATA:
        GIZWITS_LOG("TRANSPARENT_DATA \n");
        //user handle , Fetch data from [data] , size is [len]
        break;
      case WIFI_NTP:
        GIZWITS_LOG("WIFI_NTP : [%d-%d-%d %02d:%02d:%02d][%d] \n",ptime->year,ptime->month,ptime->day,ptime->hour,ptime->minute,ptime->second,ptime->ntp);
        break;
      case MODULE_INFO:
            GIZWITS_LOG("MODULE INFO ...\n");
      #if MODULE_TYPE
            GIZWITS_LOG("GPRS MODULE ...\n");
            //Format By gprsInfo_t
      #else
            GIZWITS_LOG("WIF MODULE ...\n");
            //Format By moduleInfo_t
            GIZWITS_LOG("moduleType : [%d] \n",ptModuleInfo->moduleType);
      #endif
    break;
      default:
        break;
    }
  }

  return 0;
}

/**
* User data acquisition

* Here users need to achieve in addition to data points other than the collection of data collection, can be self-defined acquisition frequency and design data filtering algorithm

* @param none
* @return none
*/
void userHandle(void)
{
  // currentDataPoint.valueBH1750 = 12;//Add Sensor Data Collection
  // currentDataPoint.valueCO2 = 12;//Add Sensor Data Collection
  // currentDataPoint.valuetemp =13 ;//Add Sensor Data Collection
  // currentDataPoint.valuehumi = 11;//Add Sensor Data Collection
  // currentDataPoint.valuesoil = 11;//Add Sensor Data Collection
  // currentDataPoint.valuedistant = 34;//Add Sensor Data Collection

  currentDataPoint.valueBH1750 = my_sensor.lighting_value;//Add Sensor Data Collection
  currentDataPoint.valueCO2 = 12;//Add Sensor Data Collection
  currentDataPoint.valuetemp =my_sensor.temp_value;//Add Sensor Data Collection
  currentDataPoint.valuehumi = my_sensor.humi_value;//Add Sensor Data Collection
  currentDataPoint.valuesoil = my_sensor.soil_value;//Add Sensor Data Collection
  currentDataPoint.valuedistant = my_sensor.distance_value;//Add Sensor Data Collection
}

/**
* Data point initialization function

* In the function to complete the initial user-related data
* @param none
* @return none
* @note The developer can add a data point state initialization value within this function
*/
void userInit(void)
{
    memset((uint8_t*)&currentDataPoint, 0, sizeof(dataPoint_t));
    
    /** Warning !!! DataPoint Variables Init , Must Within The Data Range **/ 
    /*
      currentDataPoint.valuepump = ;
      currentDataPoint.valuecurtain = ;
      currentDataPoint.valuebrightness = ;
      currentDataPoint.valuefan = ;
      currentDataPoint.valueBH1750 = ;
      currentDataPoint.valueCO2 = ;
      currentDataPoint.valuetemp = ;
      currentDataPoint.valuehumi = ;
      currentDataPoint.valuesoil = ;
      currentDataPoint.valuedistant = ;
    */

}


/**
* @brief  gizTimerMs

* millisecond timer maintenance function ,Millisecond increment , Overflow to zero

* @param none
* @return none
*/
void gizTimerMs(void)
{
    timerMsCount++;
}

/**
* @brief gizGetTimerCount

* Read system time, millisecond timer

* @param none
* @return System time millisecond
*/
uint32_t gizGetTimerCount(void)
{
    return timerMsCount;
}

/**
* @brief mcuRestart

* MCU Reset function

* @param none
* @return none
*/
void mcuRestart(void)
{

}
/**@} */

/**
* @brief TIMER_IRQ_FUN

* Timer Interrupt handler function

* @param none
* @return none
*/
void TIMER_IRQ_FUN(void)
{
  gizTimerMs();
}

/**
* @brief UART_IRQ_FUN

* UART Serial interrupt function ，For Module communication

* Used to receive serial port protocol data between WiFi module

* @param none
* @return none
*/
void UART_IRQ_FUN(void)
{
  uint8_t value = 0;
  //value = USART_ReceiveData(USART2);//STM32 test demo
  gizPutData(&value, 1);
}


/**
* @brief uartWrite

* Serial write operation, send data to the WiFi module

* @param buf      : Data address
* @param len       : Data length
*
* @return : Not 0,Serial send success;
*           -1，Input Param Illegal
*/
int32_t uartWrite(uint8_t *buf, uint32_t len)
{
    uint32_t i = 0;
    uint8_t ach = 0x55;
    
    if(NULL == buf)
    {
        return -1;
    }
    
    #ifdef PROTOCOL_DEBUG
    GIZWITS_LOG("MCU2WiFi[%4d:%4d]: ", gizGetTimerCount(), len);
    for(i=0; i<len; i++)
    {
        GIZWITS_LOG("%02x ", buf[i]);
    }
    GIZWITS_LOG("\n");
    #endif

    for(i=0; i<len; i++)
    {
        //USART_SendData(UART, buf[i]);//STM32 test demo
        //Serial port to achieve the function, the buf[i] sent to the module
         lpuart_sendbyte(GIZWITS_SERIAL, buf[i]);
        if(i >=2 && buf[i] == 0xFF)
        {
          //Serial port to achieve the function, the 0x55 sent to the module
          //USART_SendData(UART, 0x55);//STM32 test demo
          lpuart_sendbyte(GIZWITS_SERIAL, ach);
        }
    }


    
    return len;
}


