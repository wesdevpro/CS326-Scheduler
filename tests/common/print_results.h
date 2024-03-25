#ifndef PRINT_RST
#define PRINT_RST
#include <stdio.h>
#include "./testrst.h"

void print_results(TEST *p_result_table, int table_count);
    /* TODO: Add docs ... */

/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
void print_results(TEST *p_result_table, int table_count)
{
    TEST *p_result;  /* TODO: add docs ... */
   
    for(p_result = p_result_table; 
            (p_result - p_result_table) < table_count; p_result++)
    {
        printf("\nTEST #%d - %s", p_result->id,
                         (p_result->action == 0) ? "PASSED" : "FAILED");
    }
    return;
}
#endif
