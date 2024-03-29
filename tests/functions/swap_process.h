#ifndef SWAP
#define SWAP
#include <stdio.h>
#include <stdlib.h>
#include "../types/process.h"

void swap_processes(PROCESS *p_process_one, PROCESS* p_process_two);
    /* TODO: Add docs ... */

/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
void swap_processes(PROCESS *p_process_one, PROCESS* p_process_two)
{
    PROCESS temp;

    temp   = *p_process_one;
    *p_process_one = *p_process_two;
    *p_process_two = temp;
    return;
}
#endif

void insert_process(TABLE *p_table, int process_id, int pri);
    /* TODO: Add docs ... */
void print_table(PROCESS *p_table);
    /* TODO: Add docs ... */
PROCESS* get_running(PROCESS *p_table);
    /* TODO: Add docs ... */
int get_count(PROCESS *p_table);
    /* TODO: Add docs ... */
void sort_process(PROCESS *p_table);
    /* TODO: Add docs ... */
void swap_processes(PROCESS *p_process_one, PROCESS* p_process_two);
    /* TODO: Add docs ... */
void recalculate_priority(PROCESS* p_process);
    /* TODO: Add docs ... */

/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
void create_table(PROCESS *p_start, PROCESS *p_end)
{
    if((p_start = (PROCESS *) malloc(sizeof(PROCESS))) == NULL)
    {
        printf("\nError %d in create table.", HEADER_ALLOC_ERR);
        printf("\nCannot allocate memory for the table header.");
        printf("\nThe program is aborting.");
        exit(HEADER_ALLOC_ERR);
    }
    p_new_table->id = MIN_PID;

    if((p_end = (PROCESS *) malloc(sizeof(PROCESS))) == NULL)
    {
        printf("\nError %d in create table.", TRAILER_ALLOC_ERR);
        printf("\nCannot allocate memory for the table trailer.");
        printf("\nThe program is aborting.");
        exit(TRAILER_ALLOC_ERR); 
    }
    p_new_table->p_next_process->id             = MAX_PID;
    p_new_table->p_next_process->p_next_process = NULL;
    p_start->p_next_process                     = p_end;
    return;
}


/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
void insert_process(TABLE *p_table, int process_id, int pri)
{
    PROCESS *p_current  = p_table->p_header->p_next_process,
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
    p_new->priority   = pri;
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


/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
PROCESS *get_running(PROCESS *p_table)
{
    PROCESS *p_running = NULL;

    while(p_table = p_table->p_next_process,
          p_table->state != RUNNING && p_table->p_next_process != NULL);

    if(p_table->id < MAX_PID)
        p_running = p_table;

    return p_running;
}

/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
int get_count(PROCESS *p_table)
{
    int count = 0;

    while(p_table                 = p_table->p_next_process,
          p_table->p_next_process != NULL)
    {
        count++;
    }
    return count;
}

/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
void recalculate_priority(PROCESS* p_process)
{
    p_process->priority = 
                    (abs(p_process->priority) + p_process->quantum) / 2;

    if(p_process->state == BLOCKED)
        p_process->priority *= -1;

    return;
}

/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
void sort_process(PROCESS *p_table)
{
    PROCESS *p_next,
            *p_head = p_table;
    while(p_table                  = p_table->p_next_process,
          p_table->p_next_process != NULL)
    {
        printf("\nDEBUG: #1");
        print_table(p_head); 
        printf("\nDEBUG: #1");
        p_next = p_table;
        while(p_next = p_next->p_next_process,
              p_next->p_next_process != NULL)
        {
            printf("\nDEBUG: #2");
            print_table(p_head);
            print_table(p_table);
            print_table(p_next);
            printf("\nDEBUG: #2");
            if(p_table->priority > p_next->priority)
                swap_processes(p_table, p_next);
        }
        printf("\nDEBUG: #3");
        print_table(p_head); 
        printf("\nDEBUG: #3");
        
    }
    return;
}

/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
void swap_processes(PROCESS *p_process_one, PROCESS* p_process_two)
{
    PROCESS temp;

    printf("\n\nInside Swap:");
    
    printf("\nINIT:");
    printf("\np_one: %d \np_two: %d", p_process_one->id, p_process_two->id);
    temp           = *p_process_one;
    printf("\n\nAFTER First LINE:");
    printf("\np_one: %d \np_two: %d, \nTemp: %d", p_process_one->id, p_process_two->id, temp.id);

    p_process_one = *p_process_two;
    printf("\n\nAFTER 2ND LINE:");
    printf("\np_one: %d \np_two: %d, \nTemp: %d", p_process_one->id, p_process_two->id, temp.id);
     
    *p_process_two = temp;
    printf("\n\nAFTER 3rd LINE:");
    printf("\np_one: %d \np_two: %d, \nTemp: %d", p_process_one->id, p_process_two->id, temp.id);

    printf("\nEND of SWAP!");
    printf("\n\n");
    return;
}


