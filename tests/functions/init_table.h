#ifndef INIT_TABLE
#define INIT_TABLE
#include <stdio.h>
#include <stdlib.h>
#include "../types/process.h"


#define HEADER_ALLOC_ERR  0 /* TODO: ADD DOCS ... */
#define TRAILER_ALLOC_ERR 1 /* TODO: ADD DOCS ... */
#define MAX_PID           999 
                            /* TODO: Add DOCS ...*/

PROCESS* create_table();
    /* TODO: Add docs ... */

/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
PROCESS* create_table()
{
    PROCESS *p_new_table; /* TODO: Add docs ... */

    /* TODO: Add docs ... */
    if((p_new_table = (PROCESS *) malloc(sizeof(PROCESS))) == NULL)
    {
        printf("\nError %d in create table.", HEADER_ALLOC_ERR);
        printf("\nCannot allocate memory for the table header.");
        printf("\nThe program is aborting.");
        exit(HEADER_ALLOC_ERR);
    }
    p_new_table->id = 0;

    /* TODO: Add docs ... */
    if((p_new_table->p_next_process = 
                           (PROCESS *) malloc(sizeof(PROCESS))) == NULL)
    {
        printf("\nError %d in create table.", TRAILER_ALLOC_ERR);
        printf("\nCannot allocate memory for the table trailer.");
        printf("\nThe program is aborting.");
        exit(TRAILER_ALLOC_ERR); 
    }
    /* FIX: add constants for the 999 value. */
    p_new_table->p_next_process->id             = MAX_PID;
    p_new_table->p_next_process->p_next_process = NULL;
    
    return p_new_table;
}
#endif
