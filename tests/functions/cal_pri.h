#ifndef BUBBLE_SORT
#define BUBBLE_SORT
#include <stdio.h>
#include <stdlib.h>
#include "../types/process.h"


void calculate_priority(PROCESS *p_process)

/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
void calculate_priority(PROCESS *p_process)
{
    /* IDEA: p_process->priority = ( | p_process->priority | +  p_process->quantome) / 2;
    // To recalculate the priority of the running process, use the following formula:
    // new_priority (PRI) = ( |old_priority| + quantum_used) / 2
    // ROUNDING to the nearest whole number; 
    // if the process is blocked, set this priority negative, otherwise it will be positive */
    if(p_process->state == 'B')
        p_process->priority -= p_process->priority * 2;
    return;
}
#endif
