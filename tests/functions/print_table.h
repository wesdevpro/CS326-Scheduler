#ifndef PRINT_TABLE
#define PRINT_TABLE
#include <stdio.h>
#include <stdlib.h>
#include "../types/process.h"

#define MAX_PID           999 
                            /* TODO: Add DOCS ...*/

void print_table(PROCESS *p_table);
    /* TODO: Add docs ... */

/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
void print_table(PROCESS *p_table)
{
    printf("\nPID   CPU Used   MAX TIME   SATE   PRI   QUANTUM USED   BLK TIME   WAIT TKS");
    while(p_table      =   p_table->p_next_process,
          p_table->id  != MAX_PID)
    {
        printf("\n%3d%8d%11d%8c%8d%10d%13d%12d", p_table->id, p_table->cpu_used, p_table->max_time, p_table->state, p_table->priority, p_table->quantum, p_table->block_time, p_table->wait_time);
    }
}
#endif
