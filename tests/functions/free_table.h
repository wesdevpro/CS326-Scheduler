#ifndef FREE_TABLE
#define FREE_TABLE
#include <stdio.h>
#include <stdlib.h>
#include "../types/process.h"

void free_table(PROCESS *p_table);
    /* TODO: Add docs ... */

/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
void free_table(PROCESS *p_table)
{
    free(p_table->p_next_process);
    free(p_table);
    return;
}
#endif
