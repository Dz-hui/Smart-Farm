/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2019  SEGGER Microcontroller GmbH                *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V6.10 - Graphical user interface for embedded applications **
All  Intellectual Property rights  in the Software belongs to  SEGGER.
emWin is protected by  international copyright laws.  Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with the following terms:

The software has been licensed to  ARM LIMITED whose registered office
is situated at  110 Fulbourn Road,  Cambridge CB1 9NJ,  England solely
for  the  purposes  of  creating  libraries  for  ARM7, ARM9, Cortex-M
series,  and   Cortex-R4   processor-based  devices,  sublicensed  and
distributed as part of the  MDK-ARM  Professional  under the terms and
conditions  of  the   End  User  License  supplied  with  the  MDK-ARM
Professional. 
Full source code is available at: www.segger.com

We appreciate your understanding and fairness.
----------------------------------------------------------------------
Licensing information
Licensor:                 SEGGER Software GmbH
Licensed to:              ARM Ltd, 110 Fulbourn Road, CB1 9NJ Cambridge, UK
Licensed SEGGER software: emWin
License number:           GUI-00181
License model:            LES-SLA-20007, Agreement, effective since October 1st 2011 
Licensed product:         MDK-ARM Professional
Licensed platform:        ARM7/9, Cortex-M/R4
Licensed number of seats: -
----------------------------------------------------------------------
File        : LCDConf.c
Purpose     : Display controller configuration

This file was created to be used with the iMXRT10520 EVK/EVKB board.

It requires the proper fsl header files which are provided by NXP.

---------------------------END-OF-HEADER------------------------------
*/
#include "GUI.h"
#include "GUIDRV_Lin.h"
#include "LCDConf.h"
#include "bsp_lcd.h"
#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "fsl_gpio.h"
#include "fsl_elcdif.h"

/*********************************************************************
*
*       LCD configuration
*
**********************************************************************
*/
#define LCD_BITS_PER_PIXEL 16
#define LCD_BYTES_PER_PIXEL (LCD_BITS_PER_PIXEL / 8)

#define COLOR_CONVERSION    GUICC_M565
#define DISPLAY_DRIVER      GUIDRV_LIN_16


/*********************************************************************
*
*       Layer configuration (to be modified)
*
**********************************************************************
*/
#define XSIZE_PHYS 800
#define YSIZE_PHYS 480

//
// Buffers / VScreens
//
#define NUM_BUFFERS  2 // Number of multiple buffers to be used (at least 1 buffer)
#define NUM_VSCREENS 1 // Number of virtual  screens to be used (at least 1 screen)

//
// Define number of layers for this configuration file. Must be equal or less than in GUIConf.h!
//
#undef  GUI_NUM_LAYERS
#define GUI_NUM_LAYERS 1


#define VRAM_ADDR (uint32_t)s_psBufferLcd
/*********************************************************************
*
*       Configuration checking
*
**********************************************************************
*/
#ifndef   VRAM_ADDR
#ifdef __SES_ARM
  #define VRAM_ADDR (U32)(&_aVRAM0[0])
#else
  #define VRAM_ADDR (uint32_t)s_psBufferLcd
#endif
#endif
#ifndef   XSIZE_PHYS
  #error Physical X size of display is not defined!
#endif
#ifndef   YSIZE_PHYS
  #error Physical Y size of display is not defined!
#endif
#ifndef   COLOR_CONVERSION
  #error Color conversion not defined!
#endif
#ifndef   DISPLAY_DRIVER
  #error No display driver defined!
#endif



#ifdef __SES_ARM
U32 _aVRAM0[XSIZE_PHYS * YSIZE_PHYS * NUM_BUFFERS * NUM_VSCREENS * LCD_BYTES_PER_PIXEL] __attribute__ ((section (".GUI_RAM")));
#endif

//static volatile int               _PendingBuffer = -1;

static U32 _aBufferAddress[NUM_BUFFERS] = {
  VRAM_ADDR,
  #if (NUM_BUFFERS > 1)
    VRAM_ADDR + XSIZE_PHYS * YSIZE_PHYS * LCD_BYTES_PER_PIXEL,
  #endif
  #if (NUM_BUFFERS > 2)
    VRAM_ADDR + XSIZE_PHYS * YSIZE_PHYS * LCD_BYTES_PER_PIXEL * 2
  #endif
};

/*********************************************************************
*
*       _InitController
*
* Purpose:
*   Should initialize the display controller
*/
static void _InitController(void) {
  BS_LCD_Init(LCD_INTERRUPT_ENABLE);
}



/*********************************************************************
*
*       LCDIF_IRQHandler
*/
void LCDIF_IRQHandler(void);
void LCDIF_IRQHandler(void) {
  U32 InterruptStatus;
  //
  // Get and clear interrupt status
  //
  InterruptStatus = ELCDIF_GetInterruptStatus(LCDIF);
  ELCDIF_ClearInterruptStatus(LCDIF, InterruptStatus);
  //
  // If frame is done and pending buffer is not -1 confirm buffer
  //
  if (InterruptStatus & kELCDIF_CurFrameDone) {
    if (s_frame_count >= 0) {
      GUI_MULTIBUF_Confirm(s_frame_count);
      s_frame_count = -1;
    }
  }
#if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
#endif
}

/*********************************************************************
*
*       _SwitchBuffer
*/
static void _SwitchBuffer(int Index) {
  U32 Addr;
  //
  // Calculate address of buffer to be used  as visible frame buffer
  //
  Addr = _aBufferAddress[Index];
  //
  // Reload configuration
  //
  ELCDIF_SetNextBufferAddr(LCDIF, Addr);
  //
  // Tell emWin that buffer is used
  //
  s_frame_count = Index;
  while (s_frame_count >= 0) {
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       LCD_X_Config
*
* Purpose:
*   Called during the initialization process in order to set up the
*   display driver configuration.
*   
*/
void LCD_X_Config(void) {

  GUI_MULTIBUF_Config(NUM_BUFFERS);
  GUI_DEVICE_CreateAndLink(DISPLAY_DRIVER, COLOR_CONVERSION, 0, 0);
  LCD_SetSizeEx (0, XSIZE_PHYS, YSIZE_PHYS);
  LCD_SetVSizeEx(0, XSIZE_PHYS, YSIZE_PHYS);
  LCD_SetVRAMAddrEx(0, (void *)VRAM_ADDR);
}

/*********************************************************************
*
*       LCD_X_DisplayDriver
*
* Purpose:
*   This function is called by the display driver for several purposes.
*   To support the according task the routine needs to be adapted to
*   the display controller. Please note that the commands marked with
*   'optional' are not cogently required and should only be adapted if 
*   the display controller supports these features.
*
* Parameter:
*   LayerIndex - Index of layer to be configured
*   Cmd        - Please refer to the details in the switch statement below
*   pData      - Pointer to a LCD_X_DATA structure
*
* Return Value:
*   < -1 - Error
*     -1 - Command not handled
*      0 - Ok
*/
int LCD_X_DisplayDriver(unsigned LayerIndex, unsigned Cmd, void * pData) {
  int r;

  GUI_USE_PARA(LayerIndex);


  switch (Cmd) {

  case LCD_X_INITCONTROLLER: {

    _InitController();
    return 0;
  }
  case LCD_X_SHOWBUFFER: {
    LCD_X_SHOWBUFFER_INFO * pInfo;

    pInfo = (LCD_X_SHOWBUFFER_INFO *)pData;
    _SwitchBuffer(pInfo->Index);
    return 0;
  }
  case LCD_X_ON: {
    LCD_BackLight_ON();
    return 0;
  }
  case LCD_X_OFF: {

    return 0;
  }
  default:
    r = -1;
  }
  return r;
}

void *emWin_memcpy(void *pDst, const void *pSrc, long size)
{
    return memcpy(pDst, pSrc, size);
}

/*************************** End of file ****************************/
