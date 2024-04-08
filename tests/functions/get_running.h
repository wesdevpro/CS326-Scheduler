#ifndef GET_RUN
#define GET_RUN
#include <stdio.h>
#include <stdlib.h>
#include "../types/process.h"

PROCESS *get_running(PROCESS *p_table);
    /* TODO: Add docs ... */

/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
PROCESS *get_running(PROCESS *p_table)
{
    PROCESS *p_running = NULL;

    while(p_table = p_table->p_next_process,
          p_table->state != 'N' && p_table->p_next_process != NULL)
        printf("\n Not here");
    if(p_table->id < 999)
        p_running = p_table;

    return p_running;
}
#endif
