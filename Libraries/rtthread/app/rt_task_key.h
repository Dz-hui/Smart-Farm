/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-06 23:25:16
*@FilePath: ??���ָ�???��??Smart-Farm??���ָ�???��??Libraries??���ָ�???��??rtthread??���ָ�???��??app??���ָ�???��??rt_task_key.h
*@Drscription: 
***********************************************************************/
#ifndef _rt_task_key_h
#define _rt_task_key_h

#include "main.h"

#define KEY_THREAD_SIZE     1024
#define KEY_THREAD_PRIO     3


void key_thread_entry(void *parameter);
void key_thread_init(void);


#endif

