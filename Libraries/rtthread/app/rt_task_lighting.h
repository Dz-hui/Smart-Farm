/***********************************************************************
*@Author: Dz_hui
*@Date: 2021-05-02 20:43:33
*@FilePath: ??���ָ�???��??Smart-Farm??���ָ�???��??Libraries??���ָ�???��??rtthread??���ָ�???��??app??���ָ�???��??rt_task_lighting.h
*@Drscription: 
***********************************************************************/
#ifndef _rt_task_linghting_h
#define _rt_task_linghting_h

#include "main.h"

#define BH1750_THREAD_SIZE	        1024
#define BH1750_THREAD_PRIO              5



extern rt_thread_t bh1750_thread ;

void bh1750_init(void *parg);
void bh1750_thread_init(void);

#endif