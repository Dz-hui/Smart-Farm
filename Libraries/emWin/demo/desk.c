/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2013  SEGGER Microcontroller GmbH & Co. KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

** emWin V5.22 - Graphical user interface for embedded applications **
emWin is protected by international copyright laws.   Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with a license and should not be re-
distributed in any way. We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : BASIC_HelloWorld.c
Purpose     : Simple demo drawing "Hello world"
----------------------------------------------------------------------
*/


#include "GUI.h"
#include "WM.h"
#include "DIALOG.h"
#include "PROGBAR.h"
#include "stdio.h"
#include "dht11.h"
#include "struct.h"

emwin_status_typedef emwin_status;
emwin_button_typedef button_status;

// uint8_t lightness_value=0;

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
#define ID_WINDOW1	  (GUI_ID_USER + 0x01)
#define ID_PROGBAR	  (GUI_ID_USER + 0x02)
#define ID_TEXT_1	  (GUI_ID_USER + 0x03)
#define ID_TEXT_2	  (GUI_ID_USER + 0x04)
#define ID_WINDOW2	  (GUI_ID_USER + 0x05)
#define ID_TEXT_3	  (GUI_ID_USER + 0x06)
#define ID_BUTTON_1   (GUI_ID_USER + 0x07)
#define ID_BUTTON_2   (GUI_ID_USER + 0x08)
#define ID_BUTTON_3   (GUI_ID_USER + 0x09)
#define ID_BUTTON_4   (GUI_ID_USER + 0x0A)
#define ID_FRAMEWIN_1 (GUI_ID_USER + 0x0B)
#define ID_BUTTON_5   (GUI_ID_USER + 0x0C)
#define ID_BUTTON_6   (GUI_ID_USER + 0x0D)
#define ID_BUTTON_7   (GUI_ID_USER + 0x0E)
#define ID_BUTTON_8   (GUI_ID_USER + 0x0F)
#define ID_BUTTON_9   (GUI_ID_USER + 0X10)
#define ID_FRAMEWIN_2 (GUI_ID_USER + 0x11)
#define ID_SLIDER	  (GUI_ID_USER + 0x12)
#define ID_EDIT	      (GUI_ID_USER + 0x13)
#define ID_TEXT_4	  (GUI_ID_USER + 0x14)
#define ID_TEXT_5	  (GUI_ID_USER + 0x13)
#define ID_TEXT_6	  (GUI_ID_USER + 0x14)
#define ID_TEXT_7	  (GUI_ID_USER + 0x15)
#define ID_TEXT_8	  (GUI_ID_USER + 0x16)
#define ID_TEXT_9	  (GUI_ID_USER + 0x17)
#define ID_BUTTON_10   (GUI_ID_USER + 0X30)
#define ID_BUTTON_11   (GUI_ID_USER + 0X19)
#define ID_BUTTON_12   (GUI_ID_USER + 0X20)
#define ID_TEXT_10	  (GUI_ID_USER + 0x21)
#define ID_TEXT_11	  (GUI_ID_USER + 0x22)
#define ID_TEXT_12	  (GUI_ID_USER + 0x23)
#define ID_TEXT_13	  (GUI_ID_USER + 0x24)
#define ID_TEXT_14	  (GUI_ID_USER + 0x25)
#define ID_TEXT_15	  (GUI_ID_USER + 0x26)


extern GUI_CONST_STORAGE GUI_BITMAP bmfarm;
extern GUI_CONST_STORAGE GUI_BITMAP bmhumidity;
extern GUI_CONST_STORAGE GUI_BITMAP bmthermometer;
extern GUI_CONST_STORAGE GUI_BITMAP bmco2;
extern GUI_CONST_STORAGE GUI_BITMAP bmbrightness;
extern GUI_CONST_STORAGE GUI_BITMAP bmsoil;
extern GUI_CONST_STORAGE GUI_BITMAP bmsmartfarm;
extern GUI_CONST_STORAGE GUI_BITMAP bmcurtains;
extern GUI_CONST_STORAGE GUI_BITMAP bmfan;
extern GUI_CONST_STORAGE GUI_BITMAP bmwatering;
extern GUI_CONST_STORAGE GUI_BITMAP bmlight;
extern GUI_CONST_STORAGE GUI_BITMAP bmbackground;
extern GUI_CONST_STORAGE GUI_BITMAP bmcurtain;
extern GUI_CONST_STORAGE GUI_BITMAP bmwater;

static const GUI_WIDGET_CREATE_INFO  _aDialogCreate1[] = {
	{WINDOW_CreateIndirect, "window", ID_WINDOW1, 0, 0, 800, 480, 0, 0, 0},
	{TEXT_CreateIndirect, "text1", ID_TEXT_1, 220, 300, 500, 100, 0, 0, 0},
	{PROGBAR_CreateIndirect, "progbar",ID_PROGBAR, 600, 420, 190, 20,0, 0, 0},
	{TEXT_CreateIndirect, "text2", ID_TEXT_2, 650, 450, 100, 20, 0, 0, 0}
};

static const GUI_WIDGET_CREATE_INFO _aDialogCreate2[] = {
	{WINDOW_CreateIndirect, "window2", ID_WINDOW2, 0, 0, 800, 480, 0, 0, 0},
	{BUTTON_CreateIndirect, "", ID_BUTTON_1, 730, 152, 50, 50, 0, 0, 0},
	{BUTTON_CreateIndirect, "", ID_BUTTON_2, 675, 217, 50, 50, 0, 0, 0},
	{BUTTON_CreateIndirect, "", ID_BUTTON_3, 620, 292, 50, 50, 0, 0, 0},
	{BUTTON_CreateIndirect, "", ID_BUTTON_4, 730, 292, 50, 50, 0, 0, 0},
	{BUTTON_CreateIndirect, "", ID_BUTTON_10, 620, 152, 50, 50, 0, 0, 0},
	{BUTTON_CreateIndirect, "", ID_BUTTON_12, 720, 10, 70, 70, 0, 0, 0},
	{TEXT_CreateIndirect, "", ID_TEXT_5, 140, 170, 50, 50, 0, 0, 0},
	{TEXT_CreateIndirect, "", ID_TEXT_6, 140, 254, 50, 50, 0, 0, 0},
	{TEXT_CreateIndirect, "", ID_TEXT_7, 140, 330, 50, 50, 0, 0, 0},
	{TEXT_CreateIndirect, "", ID_TEXT_8, 450, 170, 50, 50, 0, 0, 0},
	{TEXT_CreateIndirect, "", ID_TEXT_9, 450, 254, 50, 50, 0, 0, 0},
	{TEXT_CreateIndirect, "", ID_TEXT_10, 625, 100, 150, 50, 0, 0, 0},
	{TEXT_CreateIndirect, "", ID_TEXT_11, 450, 330, 50, 50, 0, 0, 0},
	{TEXT_CreateIndirect, "", ID_TEXT_12, 180, 100, 200,50 , 0, 0, 0},

};

static const GUI_WIDGET_CREATE_INFO _aDialogCreate3[] = {
	{FRAMEWIN_CreateIndirect, "Please select wind speed ", ID_FRAMEWIN_1, 200, 80, 250, 280, 0, 0, 0},
	{BUTTON_CreateIndirect, "0", ID_BUTTON_5, 15, 15, 100, 100, 0, 0, 0},
	{BUTTON_CreateIndirect, "1", ID_BUTTON_6, 125, 15, 100, 100, 0, 0, 0},
	{BUTTON_CreateIndirect, "2", ID_BUTTON_7, 15, 125, 100, 100, 0, 0, 0},
	{BUTTON_CreateIndirect, "3", ID_BUTTON_8, 125, 125, 100, 100, 0, 0, 0},
	{BUTTON_CreateIndirect, "close", ID_BUTTON_11, 180, 230, 60, 25, 0, 0, 0}
};



static const GUI_WIDGET_CREATE_INFO _aDialogCreate4[] ={
	{FRAMEWIN_CreateIndirect, "Please change the brightness", ID_FRAMEWIN_2, 200, 80, 250, 250, 0, 0, 0},
	{SLIDER_CreateIndirect, "", ID_SLIDER, 25, 60, 200, 75, 0, 0, 0},
	{EDIT_CreateIndirect, "", ID_EDIT, 100, 150, 50, 50, 0, 0, 0},
	{BUTTON_CreateIndirect, "close",ID_BUTTON_9, 180, 200, 60, 25, 0, 0, 0}
};


WM_HWIN CreateFramewim(void);
void invalidprogbar(WM_HWIN hWin);
static void _cbDialog2(WM_MESSAGE *pMsg);
static void _cbDialog1(WM_MESSAGE *pMsg);
static void _cbDialog3(WM_MESSAGE *pMsg);
static void _cbDialog4(WM_MESSAGE *pMsg);
static void _cbbutton1(WM_MESSAGE *pMsg);
static void _cbbutton2(WM_MESSAGE *pMsg);
static void _cbbutton3(WM_MESSAGE *pMsg);
static void _cbbutton0(WM_MESSAGE *pMsg);
static void _cbbuttonclose(WM_MESSAGE *pMsg);
static void _cbbuttondefault(WM_MESSAGE *pMsg);

extern DHT11_Data_TypeDef  dht11_data;
extern uint8_t BH1750_readbuff[2];
unsigned int co2_value=35;
extern float soil;
extern float distance_val;;
unsigned int thermometer_value=30;
char brightness[20];
char humi[20];
char co2[20];
char soilhumi[20];
char thermometer[20];


GUI_RECT  rect;
GUI_RECT  rect1;

void invalidprogbar(WM_HWIN hWin)
{
	 rect.x0=0;
	 rect.y0=0;
	 rect.x1=800;
	 rect.y1=480;
 
	WM_InvalidateRect(hWin,&rect);
}



static void _cbDialog1(WM_MESSAGE *pMsg)
{
	WM_HWIN hItem;
	static unsigned int progbar_val=0;
	switch(pMsg->MsgId){
	case WM_INIT_DIALOG:
		hItem = pMsg->hWin;
		WINDOW_SetBkColor(hItem,0x40E0D0);

		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_1);
		TEXT_SetText(hItem, "Welcom to the smart farm");
		TEXT_SetFont(hItem, &GUI_Font32B_ASCII);
		TEXT_SetTextColor(hItem, 0x6A5ACD);

		hItem =WM_GetDialogItem(pMsg->hWin, ID_PROGBAR);
		PROGBAR_SetFont(hItem, &GUI_FontComic24B_ASCII);
		PROGBAR_SetMinMax(hItem, 0, 100);

		hItem = WM_GetDialogItem(pMsg->hWin, ID_TEXT_2);
		TEXT_SetFont(hItem,&GUI_Font20_ASCII);
		TEXT_SetText(hItem,"turning on...");
		TEXT_SetTextColor(hItem,GUI_BLACK);

		break;

	case WM_PAINT:
		GUI_DrawBitmap(&bmsmartfarm, 240, 10);
		hItem = WM_GetDialogItem(pMsg->hWin,ID_PROGBAR);
		progbar_val = PROGBAR_GetValue(hItem);
		PROGBAR_SetValue(hItem,progbar_val+1);
		if(progbar_val==100)
		{
			//GUI_CreateDialogBox(_aDialogCreate2, GUI_COUNTOF(_aDialogCreate2), _cbDialog2, WM_HBKWIN, 0, 0);
		}
		break;

	default:
		WM_DefaultProc(pMsg);
		break;
	}
		
}


WM_HWIN CreateFramewim(void)
{
	WM_HWIN hwim;

	hwim = GUI_CreateDialogBox(_aDialogCreate1, GUI_COUNTOF(_aDialogCreate1), _cbDialog1, WM_HBKWIN, 0, 0 );

	return hwim;
}




static void _cbDialog2(WM_MESSAGE *pMsg)
{
	WM_HWIN hItem;
	unsigned int ID=0;
	unsigned int Ncode=0;
	// static unsigned int button1_flg=0;
	// static unsigned int button3_flg=0;
	// static unsigned int button10_flg=0;
	// static unsigned int button12_flg=0;

	switch (pMsg->MsgId){
	case WM_INIT_DIALOG:
		hItem = pMsg->hWin;
		WINDOW_SetBkColor(hItem,0xEF5160);

		hItem = WM_GetDialogItem(pMsg->hWin,ID_BUTTON_1);
		BUTTON_SetBitmap(hItem,BUTTON_BI_UNPRESSED,&bmcurtains);

		hItem = WM_GetDialogItem(pMsg->hWin,ID_BUTTON_2);
		BUTTON_SetBitmap(hItem,BUTTON_BI_UNPRESSED,&bmfan);

		hItem = WM_GetDialogItem(pMsg->hWin,ID_BUTTON_3);
		BUTTON_SetBitmap(hItem,BUTTON_BI_UNPRESSED,&bmwatering);

		hItem = WM_GetDialogItem(pMsg->hWin,ID_BUTTON_4);
		BUTTON_SetBitmap(hItem,BUTTON_BI_UNPRESSED,&bmlight);
	
		hItem = WM_GetDialogItem(pMsg->hWin,ID_BUTTON_10);
		BUTTON_SetBitmap(hItem,BUTTON_BI_UNPRESSED,&bmcurtain);

		hItem = WM_GetDialogItem(pMsg->hWin,ID_BUTTON_12);
		WM_SetCallback(hItem,_cbbuttondefault);

		
		hItem = WM_GetDialogItem(pMsg->hWin,ID_TEXT_5);
		TEXT_SetTextColor(hItem,GUI_BLACK);
		TEXT_SetTextAlign(hItem, GUI_TA_VCENTER | GUI_TA_HCENTER);
		TEXT_SetFont(hItem,&GUI_Font32B_ASCII);
		TEXT_SetText(hItem,"");

		hItem = WM_GetDialogItem(pMsg->hWin,ID_TEXT_6);
		TEXT_SetTextColor(hItem,GUI_BLACK);
		TEXT_SetTextAlign(hItem, GUI_TA_VCENTER | GUI_TA_HCENTER);
		TEXT_SetFont(hItem,&GUI_Font32B_ASCII);
		TEXT_SetText(hItem,"");

		hItem = WM_GetDialogItem(pMsg->hWin,ID_TEXT_7);
		TEXT_SetTextColor(hItem,GUI_BLACK);
		TEXT_SetTextAlign(hItem, GUI_TA_VCENTER | GUI_TA_HCENTER);
		TEXT_SetFont(hItem,&GUI_Font32B_ASCII);
		TEXT_SetText(hItem,"");

		hItem = WM_GetDialogItem(pMsg->hWin,ID_TEXT_8);
		TEXT_SetTextColor(hItem,GUI_BLACK);
		TEXT_SetTextAlign(hItem, GUI_TA_VCENTER | GUI_TA_HCENTER);
		TEXT_SetFont(hItem,&GUI_Font32B_ASCII);
		TEXT_SetText(hItem,"");

		hItem = WM_GetDialogItem(pMsg->hWin,ID_TEXT_9);
		TEXT_SetTextColor(hItem,GUI_BLACK);
		TEXT_SetTextAlign(hItem, GUI_TA_VCENTER | GUI_TA_HCENTER);
		TEXT_SetFont(hItem,&GUI_Font32B_ASCII);
		TEXT_SetText(hItem,"");
		
		hItem = WM_GetDialogItem(pMsg->hWin,ID_TEXT_11);
		TEXT_SetTextColor(hItem,GUI_BLACK);
		TEXT_SetTextAlign(hItem, GUI_TA_VCENTER | GUI_TA_HCENTER);
		TEXT_SetFont(hItem,&GUI_Font32B_ASCII);
		TEXT_SetText(hItem,"");

		hItem = WM_GetDialogItem(pMsg->hWin,ID_TEXT_10);
		TEXT_SetTextColor(hItem,GUI_BLACK);
		TEXT_SetTextAlign(hItem, GUI_TA_VCENTER | GUI_TA_HCENTER);
		TEXT_SetFont(hItem,&GUI_Font24B_ASCII);
		TEXT_SetText(hItem,"Control");

		hItem = WM_GetDialogItem(pMsg->hWin,ID_TEXT_12);
		TEXT_SetTextColor(hItem,GUI_BLACK);
		TEXT_SetTextAlign(hItem, GUI_TA_VCENTER | GUI_TA_HCENTER);
		TEXT_SetFont(hItem,&GUI_Font24B_ASCII);
		TEXT_SetText(hItem,"Environmental Data");


		break;

	case WM_PAINT:
		hItem = pMsg->hWin;
		GUI_DrawBitmap(&bmbackground,0,0);
		GUI_DrawBitmap(&bmhumidity, 20,142);
		GUI_DrawBitmap(&bmthermometer,20,232);
		GUI_DrawBitmap(&bmco2,320,312);
		GUI_DrawBitmap(&bmbrightness,310,142);
		GUI_DrawBitmap(&bmsoil,320,232);
		GUI_DrawBitmap(&bmwater,20,312);
		
		GUI_SetColor(GUI_BLACK);
		GUI_SetFont(&GUI_Font32B_ASCII);
		sprintf(humi,"%d",dht11_data.humi_int);
		sprintf(thermometer,"%d",dht11_data.temp_int);
		sprintf(co2,"%3d",co2_value);
		sprintf(brightness,"%3d",BH1750_readbuff[0]+BH1750_readbuff[1]);
		sprintf(soilhumi,"%2d",(uint8_t)soil);

		hItem = WM_GetDialogItem(pMsg->hWin,ID_TEXT_5);
		TEXT_SetTextColor(hItem,GUI_BLACK);
		TEXT_SetTextAlign(hItem, GUI_TA_VCENTER | GUI_TA_HCENTER);
		TEXT_SetFont(hItem,&GUI_Font32B_ASCII);
		TEXT_SetText(hItem,humi);

		hItem = WM_GetDialogItem(pMsg->hWin,ID_TEXT_6);
		TEXT_SetTextColor(hItem,GUI_BLACK);
		TEXT_SetTextAlign(hItem, GUI_TA_VCENTER | GUI_TA_HCENTER);
		TEXT_SetFont(hItem,&GUI_Font32B_ASCII);
		TEXT_SetText(hItem,thermometer);

		hItem = WM_GetDialogItem(pMsg->hWin,ID_TEXT_7);
		TEXT_SetTextColor(hItem,GUI_BLACK);
		TEXT_SetTextAlign(hItem, GUI_TA_VCENTER | GUI_TA_HCENTER);
		TEXT_SetFont(hItem,&GUI_Font32B_ASCII);
		TEXT_SetText(hItem,co2);

		hItem = WM_GetDialogItem(pMsg->hWin,ID_TEXT_8);
		TEXT_SetTextColor(hItem,GUI_BLACK);
		TEXT_SetTextAlign(hItem, GUI_TA_VCENTER | GUI_TA_HCENTER);
		TEXT_SetFont(hItem,&GUI_Font32B_ASCII);
		TEXT_SetText(hItem,brightness);

		hItem = WM_GetDialogItem(pMsg->hWin,ID_TEXT_9);
		TEXT_SetTextColor(hItem,GUI_BLACK);
		TEXT_SetTextAlign(hItem, GUI_TA_VCENTER | GUI_TA_HCENTER);
		TEXT_SetFont(hItem,&GUI_Font32B_ASCII);
		TEXT_SetText(hItem,soilhumi);


		break;

	case WM_NOTIFY_PARENT:
		ID =WM_GetId(pMsg->hWinSrc);
		Ncode = pMsg->Data.v;
		switch (ID){
		case ID_BUTTON_1:
			switch(Ncode){
			case WM_NOTIFICATION_CLICKED:
				break;
			case WM_NOTIFICATION_RELEASED:
				button_status.E_button_curtain_up = 1-button_status.E_button_curtain_up;
				if(button_status.E_button_curtain_up!=0)   
				{
					emwin_status.E_curtain_up_status= 1;
				}
				else
				{
					emwin_status.E_curtain_up_status = 0;
				}
				break;
			}
			break;

		case ID_BUTTON_2:
			switch(Ncode){
			case WM_NOTIFICATION_CLICKED:
				break;
			case WM_NOTIFICATION_RELEASED:
				GUI_CreateDialogBox(_aDialogCreate3, GUI_COUNTOF(_aDialogCreate3), _cbDialog3, WM_HBKWIN, 0, 0);
				break;
			}
			break;

		case ID_BUTTON_3:
			
			switch(Ncode){
			case WM_NOTIFICATION_CLICKED:
				break;
			case WM_NOTIFICATION_RELEASED:
				button_status.E_button_pump = 1-button_status.E_button_pump;
				if(button_status.E_button_pump!=0)   
				{
					emwin_status.E_pump_status = 1;
				}
				else
				{
					emwin_status.E_pump_status = 0;
				}
				break;
			}
			break;

		case ID_BUTTON_4:
			hItem = WM_GetDialogItem(pMsg->hWin,ID_TEXT_3);
			switch(Ncode){
			case WM_NOTIFICATION_CLICKED:
				break;
			case WM_NOTIFICATION_RELEASED:
				GUI_CreateDialogBox(_aDialogCreate4,GUI_COUNTOF(_aDialogCreate4),_cbDialog4,WM_HBKWIN,0,0);
				break;
			}
			break;

			case ID_BUTTON_10:
			
			switch(Ncode){
			case WM_NOTIFICATION_CLICKED:
				break;
			case WM_NOTIFICATION_RELEASED:
				button_status.E_button_curtain_down = 1-button_status.E_button_curtain_down;
				if(button_status.E_button_curtain_down!=0)   
				{
					emwin_status.E_curtain_down_status=1;
				}
				else
				{
					emwin_status.E_curtain_down_status =0;
				}
				break;
			}
			break;


			case ID_BUTTON_12:
			switch(Ncode){
			case WM_NOTIFICATION_CLICKED:
				break;
			case WM_NOTIFICATION_RELEASED:
				// button12_flg = 1-button12_flg;
				// if(button12_flg!=0)   
				// {
					emwin_status.E_default_status =1;
				// }
				// else
				// {
					// emwin_status.E_default_status =0;
				// }
				break;
			}
			break;

		}
		break;
			
	default:
		WM_DefaultProc(pMsg);
		break;

	}

}


WM_HWIN CreateFramewim1(void)
{
	WM_HWIN hwim;

	hwim = 	GUI_CreateDialogBox(_aDialogCreate2, GUI_COUNTOF(_aDialogCreate2), _cbDialog2, WM_HBKWIN, 0, 0);

	return hwim;
}

static void _cbDialog3(WM_MESSAGE *pMsg)
{
	WM_HWIN hItem;
	unsigned int ID;
	unsigned int Ncode;

	switch (pMsg->MsgId){
	case WM_INIT_DIALOG:
		hItem = pMsg->hWin;
		FRAMEWIN_SetClientColor(hItem,GUI_BLACK);

		hItem = WM_GetDialogItem(pMsg->hWin,ID_BUTTON_5);
		WM_SetCallback(hItem,_cbbutton0);

		hItem = WM_GetDialogItem(pMsg->hWin,ID_BUTTON_6);
		WM_SetCallback(hItem,_cbbutton1);

		hItem = WM_GetDialogItem(pMsg->hWin,ID_BUTTON_7);
		WM_SetCallback(hItem,_cbbutton2);

		hItem = WM_GetDialogItem(pMsg->hWin,ID_BUTTON_8);
		WM_SetCallback(hItem,_cbbutton3);

		hItem = WM_GetDialogItem(pMsg->hWin,ID_BUTTON_11);
		WM_SetCallback(hItem,_cbbuttonclose);


		hItem = WM_GetDialogItem(pMsg->hWin,ID_TEXT_4);
		TEXT_SetTextColor(hItem,GUI_WHITE);

		break;

	case WM_NOTIFY_PARENT:
		ID = WM_GetId(pMsg->hWinSrc);
		Ncode = pMsg->Data.v;
		switch (ID){
		case ID_BUTTON_5:
			
			switch (Ncode){
			case WM_NOTIFICATION_CLICKED:
				break;
			case WM_NOTIFICATION_RELEASED:
				emwin_status.E_fan_status = 0;
				break;
			}
			break;

		case ID_BUTTON_6:
			
			switch (Ncode){
			case WM_NOTIFICATION_CLICKED:
				break;
			case WM_NOTIFICATION_RELEASED:
				emwin_status.E_fan_status = 1;
				break;
			}
			break;

		case ID_BUTTON_7:
			switch (Ncode){
			case WM_NOTIFICATION_CLICKED:
				break;
			case WM_NOTIFICATION_RELEASED:
				emwin_status.E_fan_status = 2;
				break;
			}
			break;
		
		case ID_BUTTON_8:
			switch (Ncode){
			case WM_NOTIFICATION_CLICKED:
				break;
			case WM_NOTIFICATION_RELEASED:
				emwin_status.E_fan_status =3;
				break;
			}
			break;
			
			
			case ID_BUTTON_11:
			switch (Ncode){
			case WM_NOTIFICATION_CLICKED:
				break;
			case WM_NOTIFICATION_RELEASED:
				GUI_EndDialog(pMsg->hWin,0);
				break;
			}
			break;
			
		}
		default:
		WM_DefaultProc(pMsg);
		break;
    }
}



static void _cbDialog4(WM_MESSAGE *pMsg)
{
	WM_HWIN hItem;
	WM_HWIN hSlider;
	int Ncode;
	int ID;

	switch(pMsg->MsgId){
	case WM_INIT_DIALOG:
		hItem = pMsg->hWin;
		FRAMEWIN_SetClientColor(hItem,GUI_BLACK);

		hItem = WM_GetDialogItem(pMsg->hWin,ID_SLIDER);
		SLIDER_SetRange(hItem,0,100);

		hItem = WM_GetDialogItem(pMsg->hWin,ID_BUTTON_9);
		WM_SetCallback(hItem,_cbbuttonclose);
		

		hItem= WM_GetDialogItem(pMsg->hWin,ID_EDIT);
		EDIT_SetText(hItem,"000");
		EDIT_SetTextColor(hItem,EDIT_CI_ENABLED,GUI_WHITE);
		EDIT_SetTextAlign(hItem, GUI_TA_VCENTER | GUI_TA_HCENTER);
		EDIT_SetFont(hItem,&GUI_Font20B_ASCII);
		EDIT_SetDecMode(hItem,0,0,100,0,GUI_EDIT_NORMAL);
		EDIT_SetBkColor(hItem,EDIT_CI_ENABLED,GUI_BLACK);
		break;

	case WM_NOTIFY_PARENT:
		ID = WM_GetId(pMsg->hWinSrc);
		Ncode = pMsg->Data.v;
		switch (ID){
		case ID_SLIDER:
			switch (Ncode){
			case WM_NOTIFICATION_CLICKED:
				break;
			case WM_NOTIFICATION_RELEASED:
				break;
			case WM_NOTIFICATION_VALUE_CHANGED:
				hItem = WM_GetDialogItem(pMsg->hWin,ID_EDIT);
				hSlider = WM_GetDialogItem(pMsg->hWin,ID_SLIDER);
				button_status.E_light_val = SLIDER_GetValue(hSlider);
				EDIT_SetValue(hItem,button_status.E_light_val);
				if(button_status.E_light_val>0)
				{
					emwin_status.E_light_status =1;
				}
				else
				{
					emwin_status.E_light_status =0;
				}
				break;
			}
			break;

		case ID_BUTTON_9:
			switch(Ncode){
			case WM_NOTIFICATION_CLICKED:
				break;
			case WM_NOTIFICATION_RELEASED:
				GUI_EndDialog(pMsg->hWin, 0);
				break;
			}
			break;

		default:
			WM_DefaultProc(pMsg);
			break;
		}
	}
	
}


static void _cbbutton0(WM_MESSAGE *pMsg)
{
	GUI_RECT rect;
	WM_HWIN hwin;
	hwin= pMsg->hWin;

	switch(pMsg->MsgId){
	case WM_PAINT:
		WM_GetClientRect(&rect);
		if(BUTTON_IsPressed(hwin))
		{
			GUI_SetColor(GUI_BLUE);
			GUI_SetBkColor(GUI_BLUE);
			GUI_FillEllipse(rect.x1 / 2,rect.y1 / 2,rect.x1 / 2,rect.y1 / 2);

			GUI_SetColor(GUI_BLACK);
			GUI_DrawEllipse(rect.x1/2,rect.y1/2,rect.x1/2,rect.y1/2);

		}

		else
		{
			GUI_SetColor(GUI_BLACK);
			GUI_SetBkColor(GUI_BLACK);
			GUI_FillEllipse(rect.x1 / 2,rect.y1 / 2,rect.x1 / 2,rect.y1 / 2);

			GUI_SetColor(GUI_BLACK);
			GUI_DrawEllipse(rect.x1/2,rect.y1/2,rect.x1/2,rect.y1/2);
			
		}
		GUI_SetColor(GUI_WHITE);
		GUI_SetFont(&GUI_Font24B_ASCII);
		GUI_DispStringInRect("0",&rect,GUI_TA_HCENTER|GUI_TA_VCENTER);
		break;

		default:
		BUTTON_Callback(pMsg);
		break;
	}

}



static void _cbbutton1(WM_MESSAGE *pMsg)
{
	GUI_RECT rect;
	WM_HWIN hwin;
	hwin= pMsg->hWin;

	switch(pMsg->MsgId){
	case WM_PAINT:
		WM_GetClientRect(&rect);
		if(BUTTON_IsPressed(hwin))
		{
			GUI_SetColor(GUI_BLUE);
			GUI_SetBkColor(GUI_BLUE);
			GUI_FillEllipse(rect.x1 / 2,rect.y1 / 2,rect.x1 / 2,rect.y1 / 2);

			GUI_SetColor(GUI_BLACK);
			GUI_DrawEllipse(rect.x1/2,rect.y1/2,rect.x1/2,rect.y1/2);

		}

		else
		{
			GUI_SetColor(GUI_BLACK);
			GUI_SetBkColor(GUI_BLACK);
			GUI_FillEllipse(rect.x1 / 2,rect.y1 / 2,rect.x1 / 2,rect.y1 / 2);

			GUI_SetColor(GUI_BLACK);
			GUI_DrawEllipse(rect.x1/2,rect.y1/2,rect.x1/2,rect.y1/2);
			
		}
		GUI_SetColor(GUI_WHITE);
		GUI_SetFont(&GUI_Font24B_ASCII);
		GUI_DispStringInRect("1",&rect,GUI_TA_HCENTER|GUI_TA_VCENTER);
		break;

		default:
		BUTTON_Callback(pMsg);
		break;
	}

}


static void _cbbutton2(WM_MESSAGE *pMsg)
{
	GUI_RECT rect;
	WM_HWIN hwin;
	hwin= pMsg->hWin;

	switch(pMsg->MsgId){
	case WM_PAINT:
		WM_GetClientRect(&rect);
		if(BUTTON_IsPressed(hwin))
		{
			GUI_SetColor(GUI_BLUE);
			GUI_SetBkColor(GUI_BLUE);
			GUI_FillEllipse(rect.x1 / 2,rect.y1 / 2,rect.x1 / 2,rect.y1 / 2);

			GUI_SetColor(GUI_BLACK);
			GUI_DrawEllipse(rect.x1/2,rect.y1/2,rect.x1/2,rect.y1/2);

		}

		else
		{
			GUI_SetColor(GUI_BLACK);
			GUI_SetBkColor(GUI_BLACK);
			GUI_FillEllipse(rect.x1 / 2,rect.y1 / 2,rect.x1 / 2,rect.y1 / 2);

			GUI_SetColor(GUI_BLACK);
			GUI_DrawEllipse(rect.x1/2,rect.y1/2,rect.x1/2,rect.y1/2);
			
		}
		GUI_SetColor(GUI_WHITE);
		GUI_SetFont(&GUI_Font24B_ASCII);
		GUI_DispStringInRect("2",&rect,GUI_TA_HCENTER|GUI_TA_VCENTER);
		break;

		default:
		BUTTON_Callback(pMsg);
		break;
	}

}

static void _cbbutton3(WM_MESSAGE *pMsg)
{
	GUI_RECT rect;
	WM_HWIN hwin;
	hwin= pMsg->hWin;

	switch(pMsg->MsgId){
	case WM_PAINT:
		WM_GetClientRect(&rect);
		if(BUTTON_IsPressed(hwin))
		{
			GUI_SetColor(GUI_BLUE);
			GUI_SetBkColor(GUI_BLUE);
			GUI_FillEllipse(rect.x1 / 2,rect.y1 / 2,rect.x1 / 2,rect.y1 / 2);

			GUI_SetColor(GUI_BLACK);
			GUI_DrawEllipse(rect.x1/2,rect.y1/2,rect.x1/2,rect.y1/2);

		}

		else
		{
			GUI_SetColor(GUI_BLACK);
			GUI_SetBkColor(GUI_BLACK);
			GUI_FillEllipse(rect.x1 / 2,rect.y1 / 2,rect.x1 / 2,rect.y1 / 2);

			GUI_SetColor(GUI_BLACK);
			GUI_DrawEllipse(rect.x1/2,rect.y1/2,rect.x1/2,rect.y1/2);
			
		}
		GUI_SetColor(GUI_WHITE);
		GUI_SetFont(&GUI_Font24B_ASCII);
		GUI_DispStringInRect("3",&rect,GUI_TA_HCENTER|GUI_TA_VCENTER);
		break;

		default:
		BUTTON_Callback(pMsg);
		break;
	}

}

static void _cbbuttonclose(WM_MESSAGE *pMsg)
{
	GUI_RECT rect;
	WM_HWIN hwin;
	hwin= pMsg->hWin;

	switch(pMsg->MsgId){
	case WM_PAINT:
		WM_GetClientRect(&rect);
		if(BUTTON_IsPressed(hwin))
		{
			GUI_SetColor(GUI_BLUE);
			GUI_SetBkColor(GUI_BLUE);
			GUI_FillEllipse(rect.x1 / 2,rect.y1 / 2,rect.x1 / 2,rect.y1 / 2);

			GUI_SetColor(GUI_BLACK);
			GUI_DrawEllipse(rect.x1/2,rect.y1/2,rect.x1/2,rect.y1/2);

		}

		else
		{
			GUI_SetColor(GUI_BLACK);
			GUI_SetBkColor(GUI_BLACK);
			GUI_FillEllipse(rect.x1 / 2,rect.y1 / 2,rect.x1 / 2,rect.y1 / 2);

			GUI_SetColor(GUI_BLACK);
			GUI_DrawEllipse(rect.x1/2,rect.y1/2,rect.x1/2,rect.y1/2);
			
		}
		GUI_SetColor(GUI_WHITE);
		GUI_SetFont(&GUI_Font24B_ASCII);
		GUI_DispStringInRect("close",&rect,GUI_TA_HCENTER|GUI_TA_VCENTER);
		break;

		default:
		BUTTON_Callback(pMsg);
		break;
	}

}


static void _cbbuttondefault(WM_MESSAGE *pMsg)
{
	GUI_RECT rect;
	WM_HWIN hwin;
	hwin= pMsg->hWin;

	switch(pMsg->MsgId){
	case WM_PAINT:
		WM_GetClientRect(&rect);
		if(BUTTON_IsPressed(hwin))
		{
			GUI_SetColor(0x40E0D0);
			GUI_SetBkColor(0x40E0D0);
			GUI_FillEllipse(rect.x1 / 2,rect.y1 / 2,rect.x1 / 2,rect.y1 / 2);

			GUI_SetColor(0x40E0D0);
			GUI_DrawEllipse(rect.x1/2,rect.y1/2,rect.x1/2,rect.y1/2);

		}

		else
		{
			GUI_SetColor(0x40E0D0);
			GUI_SetBkColor(0x40E0D0);
			GUI_FillEllipse(rect.x1 / 2,rect.y1 / 2,rect.x1 / 2,rect.y1 / 2);

			GUI_SetColor(0x40E0D0);
			GUI_DrawEllipse(rect.x1/2,rect.y1/2,rect.x1/2,rect.y1/2);
			
		}
		GUI_SetColor(GUI_WHITE);
		GUI_SetFont(&GUI_Font24B_ASCII);
		GUI_DispStringInRect("Default",&rect,GUI_TA_HCENTER|GUI_TA_VCENTER);
		break;

		default:
		BUTTON_Callback(pMsg);
		break;
	}

}

/*********************************************************************
*
*       MainTask
*/
void GUIDEMO_Main(void) {
 	WM_HWIN hwin;
	uint8_t n=30;
  	GUI_Init();
  	hwin = CreateFramewim();
	while(n--)
	{
		GUI_Delay(100);
		invalidprogbar(hwin);
 
	}
	GUI_Clear();
	
  
}


void GUI_Main(void)
{
	WM_HWIN hwin;
	GUI_Init();
	hwin=CreateFramewim1();
	while(1)
	{
		GUI_Delay(5);
		invalidprogbar(hwin);
	}
	
 
	
}


/*************************** End of file ****************************/

