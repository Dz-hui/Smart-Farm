/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-02 19:53:47
*@FilePath: ??���ָ�???��??Smart-Farm??���ָ�???��??Libraries??���ָ�???��??rtthread??���ָ�???��??app??���ָ�???��??rt_task_gizwit.h
*@Drscription: 
***********************************************************************/
#ifndef _rt_task_gizwit_h
#define _rt_task_gizwit_h

#include "main.h"

#define GIZWIT_THREAD_SIZE				10*1024
#define GIZWIT_THREAD_PRIO              3

void gizwit_init(void *parg);
void gizwit_thread_init(void);

//extern rt_thread_t gizwit_thread ;


#endif