/**********************************************************************/
/*                                                                    */
/* Program Name: unit_test_driver.c - TODO: Add docs ...              */
/*                                                                    */
/* Author:       Wesley Ford                                          */
/* Course:       CS326, Operating Systems                             */
/* Date Written: April 3, 2023                                        */
/*                                                                    */
/**********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "./common/testrst.h"
#include "./common/check_results.h"
#include "./common/print_results.h"

/**********************************************************************/
/*                         Data Types Imports                         */
/**********************************************************************/
#include "./types/process.h"

/**********************************************************************/
/*                         Data Types Imports                         */
/**********************************************************************/
#include "./functions/free_table.h"
#include "./functions/init_table.h"


/**********************************************************************/
/*                           Symbolic Constants                       */
/**********************************************************************/
#define TEST_COUNT 1 /* TODO: Add docs ... */

/**********************************************************************/
/*                           Function Prototypes                      */
/**********************************************************************/
void test_create_table(TEST *p_test_result);
    /* TODO: Add docs ... */ 

/**********************************************************************/
/*                          Program Structures                        */
/**********************************************************************/
int main()
{
    TEST test_table[TEST_COUNT]; 
    int  test_results; 

    printf("\nUnit Test Are Now Running!");
    test_create_table(&test_table[0]);

    test_results = check_results(test_table, TEST_COUNT);
    print_results(test_table, TEST_COUNT);

    return test_results;
}

void test_create_table(TEST *p_test_result)
{
    PROCESS *p_table; /* TODO: Add docs ... */ 

    p_test_result->id     = 1;
    p_test_result->action = 1;

    p_table = create_table();
    if(p_table                     != NULL && p_table->id == 0 && 
       p_table->p_next_process     != NULL && 
       p_table->p_next_process->id == 999  &&
       p_table->p_next_process->p_next_process == NULL)
    {
        p_test_result->action = 0;
    }
    free_table(p_table);
    return;
}
