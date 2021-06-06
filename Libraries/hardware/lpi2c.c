/***********************************************************************
*@Author: Dz_hui
*@Date: 2020-06-02 19:24:01
*@FilePath: ??���ָ�???��??Smart-Farm??���ָ�???��??Libraries??���ָ�???��??hardware??���ָ�???��??lpi2c.c
*@Drscription: 
***********************************************************************/
#include "i2c.h"
#include "fsl_gpio.h"
#include "fsl_lpi2c.h"
#include "pad_config.h"
#include "stdio.h"
#include "core_delay.h"
#include "fsl_iomuxc.h"
#include "lpi2c.h"


uint8_t BH1750_write_reg[1] ={0x10};
//uint8_t SGP30_init_air_quality[2]={0x20,0x03};
//uint8_t SGP30_measure_air_quality[2]={0x20,0x08};
//uint8_t SGP30_reset=0x06;

uint8_t BH1750_readbuff[2];
//uint8_t SGP30_readbuff[6];

void LPI2C_PAD_config(void)
{
    IOMUXC_SetPinConfig(LPI2C_SDA_IOMUXC,LPI2C_PAD_SETTING_DATA);
    IOMUXC_SetPinConfig(LPI2C_SCL_IOMUXC,LPI2C_PAD_SETTING_DATA);
}

void LPI2C_IOMUXC_config(void)
{
    IOMUXC_SetPinMux(LPI2C_SCL_IOMUXC,1U);
    IOMUXC_SetPinMux(LPI2C_SDA_IOMUXC,1U);
}

void LPI2C_MODE_config(void)
{
    lpi2c_master_config_t masterConfig;
    CLOCK_SetMux(kCLOCK_Lpi2cMux,LPI2C_CLOCK_SOURCE);
    CLOCK_SetDiv(kCLOCK_Lpi2cDiv,LPI2C_CLOCK_DIV);
    LPI2C_MasterGetDefaultConfig(&masterConfig);
    masterConfig.baudRate_Hz=LPI2C_BAUDRATE;
    LPI2C_MasterInit(LPI2C_PORT,&masterConfig,LPI2C_CLOCK_SOURE_FREQ);
}
void LPI2C_config(void)
{
    LPI2C_PAD_config();
    LPI2C_IOMUXC_config();
    LPI2C_MODE_config();
}

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
		*data = reval;
}

void BH1750_writebyte(void)
{
	LPI2C_MasterStart(LPI2C_PORT, BH1705_ADDR, kLPI2C_Write);
	LPI2C_MasterSend(LPI2C_PORT,&BH1750_write_reg,1);
	LPI2C_MasterStop(LPI2C_PORT);
}

void BH1750_readdata(void)
{
	LPI2C_MasterStart(LPI2C_PORT,BH1705_ADDR,kLPI2C_Read);
	LPI2C_MasterReceive(LPI2C_PORT,&BH1750_readbuff,2);
	LPI2C_MasterStop(LPI2C_PORT);
}

float bh1750_measure(void)
{
	float light;

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
		 light = (float)( (BH1750_readbuff[0]<<8 ) | BH1750_readbuff[1]) / (float)3.6;
     }
     printf("light = %f\n",light);
	 return light;
}







