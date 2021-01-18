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
#include "bsp_uart.h"
#include "dht11.h"
#include "fsl_qtmr.h"
#include "rtthread.h"
#include "struct.h"

static uint32_t timerMsCount;

/** Current datapoint */
dataPoint_t currentDataPoint;
gizwits_status_typedef gizwits_status;
gizwits_data_typedef gizwits_data;


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
          gizwits_status.G_pump_status = 1;
        }
        else
        {
          gizwits_status.G_pump_status = 0;  
        }
        break;
      case EVENT_curtain_down:
        currentDataPoint.valuecurtain_down = dataPointPtr->valuecurtain_down;
        GIZWITS_LOG("Evt: EVENT_curtain_down %d \n", currentDataPoint.valuecurtain_down);
        if(0x01 == currentDataPoint.valuecurtain_down)
        { 
			    gizwits_status.G_curtain_down_status=1;				
        }
        else
        {
		      gizwits_status.G_curtain_down_status=0;
        }
      case EVENT_curtain_up:
        currentDataPoint.valuecurtain_up = dataPointPtr->valuecurtain_up;
        GIZWITS_LOG("Evt: EVENT_curtain_up %d \n", currentDataPoint.valuecurtain_up);
        if(0x01 == currentDataPoint.valuecurtain_up)
        {
          gizwits_status.G_curtain_up_status=1;
        }
        else
        {
          gizwits_status.G_curtain_up_status=0;   
        }
        break;
      case EVENT_default:
        currentDataPoint.valuedefault = dataPointPtr->valuedefault;
        GIZWITS_LOG("Evt: EVENT_default %d \n", currentDataPoint.valuedefault);
        if(0x01 == currentDataPoint.valuedefault)
        {
          gizwits_status.G_default_status=1;
        }
        else
        {
          gizwits_status.G_default_status=0;   
        }
        break;


      case EVENT_brightness:
        currentDataPoint.valuebrightness = dataPointPtr->valuebrightness;
        GIZWITS_LOG("Evt:EVENT_brightness %d\n",currentDataPoint.valuebrightness);
        //user handle
        break;
      case EVENT_fan:
        currentDataPoint.valuefan = dataPointPtr->valuefan;
        GIZWITS_LOG("Evt:EVENT_fan %d\n",currentDataPoint.valuefan);
        //user handle
		if(currentDataPoint.valuefan == 1)
		{
			gizwits_status.G_fan_status =1;
		}
		else if(currentDataPoint.valuefan == 2)
		{
			gizwits_status.G_fan_status =2;
		}
		else if(currentDataPoint.valuefan == 3)
		{
			gizwits_status.G_fan_status =3;
		}
		else if(currentDataPoint.valuefan == 0)
		{
			gizwits_status.G_fan_status =0;
		}
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
 /*
    currentDataPoint.valueBH1750 = ;//Add Sensor Data Collection
    currentDataPoint.valueCO2 = ;//Add Sensor Data Collection
    currentDataPoint.valuetemp = ;//Add Sensor Data Collection
    currentDataPoint.valuehumi = ;//Add Sensor Data Collection
    currentDataPoint.valuesoil = ;//Add Sensor Data Collection
    currentDataPoint.valuedistant = ;//Add Sensor Data Collection

    */
	currentDataPoint.valueBH1750 = gizwits_data.G_bh1750_data ;//Add Sensor Data Collection
//    currentDataPoint.valueCO2 = ;//Add Sensor Data Collection
    currentDataPoint.valuetemp = gizwits_data.G_temp_data;//((float)dht11_data.temp_int +(((float)dht11_data.temp_deci)/10));//Add Sensor Data Collection
    currentDataPoint.valuehumi = gizwits_data.G_humi_data;//((float)dht11_data.humi_int +(((float)dht11_data.humi_deci)/10));//Add Sensor Data Collection
    currentDataPoint.valuesoil = gizwits_data.G_soil_data;//soil;//Add Sensor Data Collection
    currentDataPoint.valuedistant = gizwits_data.G_distant_data;//distance_val;//Add Sensor Data Collection

    
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
    
      currentDataPoint.valuepump = 0;
      currentDataPoint.valuecurtain_down = 0;
      currentDataPoint.valuecurtain_up = 0;
      currentDataPoint.valuedefault = 0;
      currentDataPoint.valuebrightness = 0;
      currentDataPoint.valuefan = 0;
      currentDataPoint.valueBH1750 = 0;
      currentDataPoint.valueCO2 = 0;
      currentDataPoint.valuetemp = 0;
      currentDataPoint.valuehumi = 0;
      currentDataPoint.valuesoil = 0;
      currentDataPoint.valuedistant = 0;
    

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
//void TIMER_IRQ_FUN(void)
//{
//  gizTimerMs();
//}

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
		Uart_SendByte(DEBUG_UARTx,buf[i]);
        if(i >=2 && buf[i] == 0xFF)
        {
          //Serial port to achieve the function, the 0x55 sent to the module
          //USART_SendData(UART, 0x55);//STM32 test demo
			Uart_SendByte(DEBUG_UARTx,0x55);
        }
    }


    
    return len;
}


