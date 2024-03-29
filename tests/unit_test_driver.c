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
#include "./functions/insert_process.h"
#include "./functions/print_table.h"
#include "./functions/get_running.h"
#include "./functions/swap_process.h"

/**********************************************************************/
/*                           Symbolic Constants                       */
/**********************************************************************/
#define TEST_COUNT 5 /* TODO: Add docs ... */

/**********************************************************************/
/*                           Function Prototypes                      */
/**********************************************************************/
PROCESS *test_create_table (TEST *p_test_result);
    /* TODO: Add docs ... */ 
void test_insert_process(TEST *p_test_result, PROCESS *p_table);
    /* TODO: add docs ... */
void test_print_table(TEST *p_test_result, PROCESS *p_table);
    /* TODO: add docs ... */
void test_get_run(TEST *p_test_result, PROCESS *p_table);
    /* TODO: add docs ... */
void test_swap(TEST *p_test_result, PROCESS *p_table);
    /* TODO: add docs ... */
void test_free_table(TEST *p_test_results);
    /* TODO: add functions below ...    */
    /* NOTE: This will be done last ... */

/**********************************************************************/
/*                          Program Structures                        */
/**********************************************************************/
int main()
{
    PROCESS *p_table;
    TEST    test_table[TEST_COUNT]; 
    int     test_results; 

    printf("\nUnit Test Are Now Running!");
    
    /* NOTE: This is Test 1 ... */
    p_table = test_create_table(&test_table[0]);

    /* NOTE: This is Test 2 ... */
    test_insert_process(&test_table[1], p_table); 

    /* NOTE: This is Test 3 ... */
    test_print_table(&test_table[2], p_table); 
    
    /* NOTE: This is Test 5 ... */
    test_swap(&test_table[3], p_table);

    test_results = check_results(test_table, TEST_COUNT);
    print_results(test_table, TEST_COUNT);

    return test_results;
}

PROCESS *test_create_table(TEST *p_test_result)
{
    PROCESS *p_table; /* TODO: Add docs ... */ 

    p_test_result->id     = 1;
    p_test_result->action = 1;
    
    printf("\n\nTest 1 is now running!"); 

    p_table = create_table();
    if(p_table                     != NULL && p_table->id == 0 && 
       p_table->p_next_process     != NULL && 
       p_table->p_next_process->id == 999  &&
       p_table->p_next_process->p_next_process == NULL)
    {
        p_test_result->action = 0;
    }
    
    printf("\nTest 2 is now is complete");
    
    return p_table;
}

void test_insert_process(TEST *p_test_result, PROCESS *p_table)
{
    p_test_result->id     = 2;
    p_test_result->action = 1;
    
    printf("\n\nTest 2 is now running!");
    insert_process(p_table, 2);
    insert_process(p_table, 4);
    insert_process(p_table, 1);
    insert_process(p_table, 3);
    insert_process(p_table, 5);

    /* NOTE: checking list resaults here ... */
    if(p_table->p_next_process->id == 1 &&
       p_table->p_next_process->p_next_process->id == 2 &&
       p_table->p_next_process->p_next_process->p_next_process->id == 3 &&
       p_table->p_next_process->p_next_process->p_next_process->p_next_process->id == 4 &&
       p_table->p_next_process->p_next_process->p_next_process->p_next_process->p_next_process->id == 5)
    {
        p_test_result->action = 0;
    }
    printf("\nTest 2 is now is complete");

    return;
}

void test_print_table(TEST *p_test_result, PROCESS *p_table)
{
    /* NOTE: Setting test paramaters... */
    p_test_result->id     = 3;
    p_test_result->action = 1;

    printf("\n\nTest 3 is now running!"); 
    /* TODO: add docs ... */
    printf("\n\n");
    print_table(p_table);
   
    /* NOTE: this test must be manually checked */
    p_test_result->action = 0;
    
    printf("\nTest 3 is now is complete");
    
    return;
}

void test_swap(TEST *p_test_result, PROCESS *p_table)
{
    p_test_result->id     = 4;
    p_test_result->action = 1;
    PROCESS *p_one = p_table->p_next_process,
            *p_two = p_table->p_next_process->p_next_process->p_next_process;

    print_table(p_table);
    swap_processes(p_one, p_two);
    print_table(p_table);


    return;
}
