/***********************************************************************
*@Author: Dz_hui
*@Date: 2020-06-04 13:11:03
*@FilePath: \DEMO\hardware\exit.c
*@Drscription: 
***********************************************************************/
#include "exit.h"
#include "core_cm7.h"
/***********************************************************************
*@Function:void IRNQ_priority(uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority,IRQn_Type IRQn) 
*@Input: 
*@Return: none
*@Author: Dz_hui
*@Date: 2020-06-04 13:18:08
*@Drscription: �����ж����ȼ�
               ���ȼ���ֻ������4-7
               ����4�������ȼ�0-7 �����ȼ�0-1
               ����5�������ȼ�0-3 �����ȼ�0-3
               ����6�������ȼ�0-1 �����ȼ�0-7
               ����7���������ȼ�   �����ȼ�0-15
***********************************************************************/
void IRQN_priority(uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority,IRQn_Type IRQn)
{
    uint8_t encode=0;

    NVIC_SetPriorityGrouping(PriorityGroup);
    encode=NVIC_EncodePriority(PriorityGroup,PreemptPriority,SubPriority);
    NVIC_SetPriority(IRQn,encode);   

}


