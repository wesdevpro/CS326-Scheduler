#ifndef BUBBLE_SORT
#define BUBBLE_SORT
#include <stdio.h>
#include <stdlib.h>
#include "../types/process.h"

#define INSERT_PROCESS_ERR 3

void insert_process(PROCESS *p_table, int process_id);
    /* TODO: Add docs ... */

/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
void insert_process(PROCESS *p_table, int process_id)
{
    PROCESS *p_current  = p_table->p_next_process,
                                   /* TODO: add docs */
            *p_new,                /* TODO: add docs */
            *p_previous = p_table; /* TODO: add docs */

    while(process_id > p_current->id)
    {
        p_previous = p_current;
        p_current  = p_current->p_next_process; 
    }

    if((p_new = (PROCESS *) malloc(sizeof(PROCESS))) == NULL) 
    {
        exit(INSERT_PROCESS_ERR);
    }

    p_new->id = process_id;
    p_new->cpu_used   = 0;
    p_new->priority   = 0;
    p_new->quantum    = 0;
    p_new->wait_time  = 0;
    p_new->state      = 'R';
    p_new->max_time   = (rand() % 18) + 1;
    if(((rand() % 3) + 1) == 1)
        p_new->block_time = 6;
    else
        p_new->block_time = (int) (rand() % 5) + 1;



    /* TODO: Add creation requirements of a process here...*/
    p_new->p_next_process      = p_current;
    p_previous->p_next_process = p_new;
}
#endif

