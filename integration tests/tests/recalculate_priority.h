#ifndef PRIORITY
#define PRIORITY
#include "data_structs.h"

/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
void recalculate_priority(PROCESS* process)
{
    process->priority = (abs(process->priority) + 4) / 2;
    return;
}

#endif
