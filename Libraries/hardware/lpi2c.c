/***********************************************************************
*@Author: Dz_hui
*@Date: 2020-06-02 19:24:01
*@FilePath: ??径分隔???替??RT1052_emwin1.2??径分隔???替??RT1052_emwin??径分隔???替??Libraries??径分隔???替??hardware??径分隔???替??lpi2c.c
*@Drscription: 
***********************************************************************/
#include "lpi2c.h"
#include "fsl_gpio.h"
#include "fsl_lpi2c.h"
#include "pad_config.h"
#include "stdio.h"
#include "core_delay.h"
#include "fsl_iomuxc.h"
#include "struct.h"


uint8_t BH1750_write_reg = 0x10;
//uint8_t SGP30_init_air_quality[2]={0x20,0x03};
//uint8_t SGP30_measure_air_quality[2]={0x20,0x08};
//uint8_t SGP30_reset=0x06;

uint8_t BH1750_readbuff[2];
//uint8_t SGP30_readbuff[6];
/***********************************************************************
*@Function: void LPI2C_PAD_config(void)
*@Input: 
*@Return: none
*@Author: Dz_hui
*@Date: 2020-06-02 19:29:49
*@Drscription: pad配置
***********************************************************************/
void LPI2C_PAD_config(void)
{
    IOMUXC_SetPinConfig(LPI2C_SDA_IOMUXC,LPI2C_PAD_SETTING_DATA);
    IOMUXC_SetPinConfig(LPI2C_SCL_IOMUXC,LPI2C_PAD_SETTING_DATA);
}

/***********************************************************************
*@Function: void LPI2C_IOMUXC_config(void)
*@Input: 
*@Return: none
*@Author: Dz_hui
*@Date: 2020-06-02 19:38:45
*@Drscription: MUX配置
***********************************************************************/
void LPI2C_IOMUXC_config(void)
{
    IOMUXC_SetPinMux(LPI2C_SCL_IOMUXC,1U);
    IOMUXC_SetPinMux(LPI2C_SDA_IOMUXC,1U);
}

/***********************************************************************
*@Function: void LPI2C_MODE_config(void)
*@Input: 
*@Return: none
*@Author: Dz_hui
*@Date: 2020-06-02 19:41:14
*@Drscription: LPI2C的模式配置
***********************************************************************/
void LPI2C_MODE_config(void)
{
    lpi2c_master_config_t masterConfig;

    /*选择PLL3作为LPI2C的时钟源480/8=60M*/
    /*LPI2C六分频     LPI2C=10MHz*/
    CLOCK_SetMux(kCLOCK_Lpi2cMux,LPI2C_CLOCK_SOURCE);
    CLOCK_SetDiv(kCLOCK_Lpi2cDiv,LPI2C_CLOCK_DIV);

    /*默认LPI2C的初始配置*/
    LPI2C_MasterGetDefaultConfig(&masterConfig);
    /*LPI2C通讯速率=400KHz*/
    masterConfig.baudRate_Hz=LPI2C_BAUDRATE;
    
    LPI2C_MasterInit(LPI2C_PORT,&masterConfig,LPI2C_CLOCK_SOURE_FREQ);
}

/***********************************************************************
*@Function: void LPI2C_config(void)
*@Input: 
*@Return: none
*@Author: Dz_hui
*@Date: 2020-06-02 20:05:45
*@Drscription: LPI2C初始化
***********************************************************************/
void LPI2C_config(void)
{
    LPI2C_PAD_config();
    LPI2C_IOMUXC_config();
    LPI2C_MODE_config();
}

/***********************************************************************
*@Function: void LPI2C_writebyte(uint8_t addr,uint8_t subaddr,uint8_t *data)
*@Input: 
*@Return: none
*@Author: Dz_hui
*@Date: 2020-06-02 20:07:11
*@Drscription: LPI2C写数据
***********************************************************************/
uint8_t LPI2C_writebyte(uint8_t addr,uint8_t subaddr,uint8_t data)
{
    lpi2c_master_transfer_t lpi2c_transfer;
    status_t reval=kStatus_Fail;
    
    lpi2c_transfer.direction=kLPI2C_Write;
	lpi2c_transfer.slaveAddress=(addr>>1);
	lpi2c_transfer.subaddress=subaddr;
	lpi2c_transfer.subaddressSize=SLAVER_INIT_SIZE;
	lpi2c_transfer.data=&data;
	lpi2c_transfer.dataSize=0x01;
	lpi2c_transfer.flags=kLPI2C_TransferDefaultFlag;
    
    reval=LPI2C_MasterTransferBlocking(LPI2C_PORT,&lpi2c_transfer);

    if(reval==kStatus_Success)
    {
        return 1;
    }

    else
    {
        return 0;
    }  

}

/***********************************************************************
*@Function: void LPI2C_readdata(uint8_t addr,uint8_t subaddr,uint8_t data)
*@Input: 
*@Return: none
*@Author: Dz_hui
*@Date: 2020-06-02 20:43:41
*@Drscription: LPI2C读数据
***********************************************************************/
void LPI2C_readdata(uint8_t addr,uint8_t subaddr,uint8_t *data)
{
    lpi2c_master_transfer_t lpi2c_transfer;
    status_t reval=kStatus_Fail;
    
    lpi2c_transfer.direction=kLPI2C_Read;
	lpi2c_transfer.slaveAddress=(addr>>1);
	lpi2c_transfer.subaddress=subaddr;
	lpi2c_transfer.subaddressSize=SLAVER_INIT_SIZE;
	lpi2c_transfer.data=data;
	lpi2c_transfer.dataSize=0x02;
	lpi2c_transfer.flags=kLPI2C_TransferDefaultFlag;
    
    reval=LPI2C_MasterTransferBlocking(LPI2C_PORT,&lpi2c_transfer);   
}

void BH1750_writebyte(void)
{
	LPI2C_MasterStart(LPI2C_PORT,BH1705_ADDR,kLPI2C_Write);
	LPI2C_MasterSend(LPI2C_PORT,&BH1750_write_reg,1);
	LPI2C_MasterStop(LPI2C_PORT);
}

void BH1750_readdata(void)
{
	float light;
	LPI2C_MasterStart(LPI2C_PORT,BH1705_ADDR,kLPI2C_Read);
	LPI2C_MasterReceive(LPI2C_PORT,&BH1750_readbuff,2);
	LPI2C_MasterStop(LPI2C_PORT);
	CPU_TS_Tmr_Delay_US(180000);
	printf("光照强度=%f\n",light);
	

}

// void xxxx()
// {
//     // if(statuss == write_starus)
//     // {
//     //     BH1750_writebyte(); 
//     //     statuss = read_status;
//     // }
//     // else if
//     // {
//     //     BH1750_readdata();
//     //     statuss = write_starus;
//     // }

//     switch(statuss)
//     {
//         case write_starus:
//             BH1750_writebyte(); 
//         break;
//         case :
//             BH1750_readdata();
//         break;
//         default:
//         break;
//     }
// }

float BH1750_measure(void)
{
	// BH1750_writebyte();  
	// CPU_TS_Tmr_Delay_US(180000);
	// BH1750_readdata();
	// CPU_TS_Tmr_Delay_US(1000000);
	float light =0;
    static uint8_t statuss =1;
    if(statuss == 1)
     {
         BH1750_writebyte(); 
         statuss = 0;
     }
     else if(statuss == 0)
     {
         BH1750_readdata();
         statuss = 1;
		 light=(float)((BH1750_readbuff[0]<<8)|BH1750_readbuff[1])/(float)3.6;
		 printf("光照强度=%f\n",light);
     }
	 return light;
	
}


/********************************SGP30*********************************/
//void SGP30_writebyte(uint8_t *buff1,uint8_t *buff2)
//{
//	LPI2C_MasterStart(LPI2C_PORT,SGP30_ADDR,kLPI2C_Write);
//	LPI2C_MasterSend(LPI2C_PORT,&buff1,1);
//	LPI2C_MasterSend(LPI2C_PORT,&buff2,1);
//	LPI2C_MasterStop(LPI2C_PORT);
//	
//}


//uint32_t SGP30_readdata(void)
//{
//	uint32_t data;
//	
//	LPI2C_MasterStart(LPI2C_PORT,SGP30_ADDR,kLPI2C_Read);
//	LPI2C_MasterReceive(LPI2C_PORT,&SGP30_readbuff,6);
//	LPI2C_MasterStop(LPI2C_PORT);
//	
//	data=(SGP30_readbuff[0]<<24)|((SGP30_readbuff[1]<<16)|(SGP30_readbuff[3]<<8)|SGP30_readbuff[4]);
//	
//	return data;
//	
//}

//void SGP30_config(void)
//{
//	uint16_t co2_data;
//	SGP30_writebyte(&SGP30_init_air_quality[0],&SGP30_init_air_quality[1]);
//	CPU_TS_Tmr_Delay_US(1000000);
//	SGP30_writebyte(&SGP30_measure_air_quality[0],&SGP30_measure_air_quality[1]);
//	
//	CPU_TS_Tmr_Delay_US(1000000);
//	
//	co2_data=(SGP30_readdata()&0xffff0000)>>16;
//	
//	while(co2_data==400)
//	{
//		DEBUG_PRINT("\n");
//		SGP30_writebyte(&SGP30_measure_air_quality[0],&SGP30_measure_air_quality[1]);
//		CPU_TS_Tmr_Delay_US(1000000);
//		co2_data=(SGP30_readdata()&0xffff0000)>>16;
//		CPU_TS_Tmr_Delay_US(250000);
//	}


//	printf("初始化完成\n");
//	
//		
//}

//void SGP30_measure(void)
//{
//	SGP30_writebyte(&SGP30_measure_air_quality[0],&SGP30_measure_air_quality[1]);
//	SGP30_readdata();
//	printf("co2=%d ppm\nTVOC=%d ppb\n",(SGP30_readbuff[0]<<8)|SGP30_readbuff[1],(SGP30_readbuff[3]<<8)|SGP30_readbuff[4]);
//	CPU_TS_Tmr_Delay_US(1000000);

//	
//}

//void SGP30_soft_reset(void)
//{
//	LPI2C_MasterStart(LPI2C_PORT,0x00,kLPI2C_Write);
//	LPI2C_MasterSend(LPI2C_PORT,&SGP30_reset,1);
//	LPI2C_MasterStop(LPI2C_PORT);
//}








