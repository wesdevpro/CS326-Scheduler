/**********************************************************************/
/*                                                                    */
/* Program Name: scheduler.c - Simulates the UNIX cpu scheduler for   */
/*                             scheduling 99 processes on the CPU     */
/*                                                                    */
/* Author:       Wesley Ford                                          */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS326, Operating Systems                             */
/* Date Written: April 5, 2024                                        */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/* I pledge this assignment is my own first time work.                */
/* I pledge I did not copy or try to copy work from the Internet.     */
/* I pledge I did not copy or try to copy work from any student.      */
/* I pledge I did not copy or try to copy work from any where else.   */
/* I pledge the only person I asked for help from was my teacher.     */
/* I pledge I did not attempt to help any student on this assignment. */
/* I understand if I violate this pledge I will receive a 0 grade.    */
/*                                                                    */
/*                                                                    */
/*                      Signed: _____________________________________ */
/*                                           (signature)              */
/*                                                                    */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/*                                                                    */
/* This program initalizes a process table then */
/*                                                                    */
/**********************************************************************/
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************/
/*                           Symbolic Constants                       */
/**********************************************************************/
#define MIN_PID 1
#define MAX_PID 100

#define HEADER_ALLOC_ERR   1 /* TODO: ADD DOCS ... */
#define TRAILER_ALLOC_ERR  2 /* TODO: ADD DOCS ... */
#define INSERT_ALLOC_ERR   3 /* TODO: */
#define TABLE_TRAILER      100
#define TABLE_HEADER       0

#define QUANTUM_PER_TICK   6 /* TODO: */

/**********************************************************************/
/*                          Program Structures                        */
/**********************************************************************/
/* The specifications of a process                                    */
struct process {
          int  block_time, /* TODO: Add docs                          */
               cpu_used,   /* TODO: Add docs                          */
               id,         /* TODO: Add docs                          */
               max_time,   /* TODO: Add docs                          */
               priority,   /* TODO: Add docs                          */
               quantum,    /* TODO: Add docs                          */ 
               wait_time;  /* TODO: Add docs                          */
          char state;      /* TODO: Add docs                          */
   struct process *p_next_process;
                           /* TODO: Add Docs                          */
};
typedef struct process PROCESS;

/* TODO: Add docs */
struct process_queue {
    PROCESS *p_start,
            *p_end;
    int     count,
            next_pid;
};
typedef struct process_queue QUEUE;

/**********************************************************************/
/*                           Function Prototypes                      */
/**********************************************************************/
void initalize_table(QUEUE *p_table);
void enqueue(QUEUE *p_table);




/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
    QUEUE process_table;

    initalize_table(&process_table);
    return 0;
}


void initalize_table(QUEUE *p_table)
{
    p_table->count    = 0;
    p_table->next_pid = MIN_PID;
    enqueue(p_table);

    return;
}

void enqueue(QUEUE *p_table)
{
    PROCESS *p_new; /* TODO: Add docs ... */
    
    if((p_new = (PROCESS *) malloc(sizeof(PROCESS))) == NULL) 
    {
        /* FIX: UPDATE THE PRINT STATEMENTS  ... */
        printf("\nError %d in create table.", TRAILER_ALLOC_ERR);
        printf("\nCannot allocate memory for the table trailer.");
        printf("\nThe program is aborting.");
        exit(4);
    }
    p_new->id = p_table->next_pid;
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
   
    if(p_table->count == 0)
        p_table->p_start = p_new;
    else
        p_table->p_end->p_next_process = p_new;
    p_table->p_end = p_new;
    p_table->count++;
    p_table->next_pid++;
    return;
}


