#ifndef CHECK_RST
#define CHECK_RST
#include "./testrst.h"

/**********************************************************************/
/*                           Function Prototypes                      */
/**********************************************************************/
int check_results(TEST *p_result_table, int table_count);
    /* TODO: Add docs ... */

/**********************************************************************/
/*                           TODO: Add docs ...                       */
/**********************************************************************/
int check_results(TEST *p_result_table, int table_count)
{
    TEST *p_result;  /* TODO: add docs ... */
    int  result = 0; /* TODO: add docs ... */ 
   
    for(p_result = p_result_table; 
            (p_result - p_result_table) < table_count; p_result++)
    {
        if(p_result->action == 1)
            result = 1;
    }
    return result;
}
#endif
