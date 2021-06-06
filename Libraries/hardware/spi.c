/***********************************************************************
*@Author: sola
*@Date: 2019-11-20 20:57:48
*@FilePath: \RT1052\Libraries\hardware\spi.c
*@Drscription: 
***********************************************************************/
#include "spi.h"


#define SPI_PAD_CONFIG_DATA            (IOMUXC_SW_PAD_CTL_PAD_SRE(1) | \
                                        IOMUXC_SW_PAD_CTL_PAD_DSE(6) | \
                                        IOMUXC_SW_PAD_CTL_PAD_SPEED(3) | \
                                        IOMUXC_SW_PAD_CTL_PAD_ODE(0) | \
                                        IOMUXC_SW_PAD_CTL_PAD_PKE(1) | \
                                        IOMUXC_SW_PAD_CTL_PAD_PUE(0) | \
                                        IOMUXC_SW_PAD_CTL_PAD_PUS(0) | \
                                        IOMUXC_SW_PAD_CTL_PAD_HYS(0))


