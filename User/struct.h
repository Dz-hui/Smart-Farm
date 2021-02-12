
#ifndef __STRUCT__H
#define __STRUCT__H

#include "main.h"

typedef  struct
{
    bool E_curtain_up_status;
    bool E_curtain_down_status;
    bool E_pump_status;
    bool E_default_status;
    uint8_t E_fan_status;
	bool E_light_status;
}emwin_status_typedef;
extern emwin_status_typedef emwin_status;

typedef struct
{
    bool G_curtain_up_status;
    bool G_curtain_down_status;
    bool G_pump_status;
    bool G_default_status;
    uint8_t G_led_status;
    uint8_t G_fan_status;

}gizwits_status_typedef;
extern gizwits_status_typedef gizwits_status;

typedef struct 
{
    float G_humi_data;
	float G_temp_data;
    float G_bh1750_data;
    float G_soil_data;
    float G_distant_data;
    float G_co2_data;
    
}gizwits_data_typedef;

extern gizwits_data_typedef gizwits_data;

typedef struct 
{
    bool E_button_curtain_up;
    bool E_button_curtain_down;
    bool E_button_pump;
    bool E_button_default;
    uint8_t E_light_val;
    
}emwin_button_typedef;

extern emwin_button_typedef button_status;



#endif



