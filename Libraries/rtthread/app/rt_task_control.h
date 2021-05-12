/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-02 20:47:46
*@FilePath: ??���ָ�???��??Smart-Farm??���ָ�???��??Libraries??���ָ�???��??rtthread??���ָ�???��??app??���ָ�???��??rt_task_control.h
*@Drscription: 
***********************************************************************/
#ifndef _rt_task_control_h
#define _rt_task_control_h

#include "main.h"

#define CTROL_THREAD_SIZE				1024
#define CTROL_THREAD_PRIO               6





extern rt_thread_t ctrl_thread ;

void ctrl_init(void *parg);
void ctrl_thread_init(void);

#endif
