#ifndef __pins_rt1052_def_h
#define __pins_rt1052_def_h

#include "user_config.h"

#define SOIL_ADC_PIN
#define DISTANCE_ADC_PIN
#define DHT11_PIN

/* User key pins define */
#if USER_KEY_NUM == 0
#define d
#elif USER_KEY_NUM == 1
#define USER_KEY1_PIN
#elif USER_KEY_NUM == 2
#define USER_KEY1_PIN
#define USER_KEY2_PIN
#endif



#endif /* end */
