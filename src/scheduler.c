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
#define HEADER_ALLOC_ERR   0 /* TODO: ADD DOCS ... */
#define TRAILER_ALLOC_ERR  1 /* TODO: ADD DOCS ... */
#define MAX_PID            100 
                             /* TODO: Add DOCS ...*/
#define MIN_COUNT          0 /* TODO: Add DOCS ... */
#define MAX_COUNT          10 /* TODO: ADD DOCS ... */ 
                             /* TODO: ADD DCOS ... */
#define INSERT_PROCESS_ERR 3 /* TODO: Add DOCS ... */
#define ENQUEUE_ERR        4 /* TODO: Add DOCS ... */

#define BLOCKED 'B' /* TODO: Add docs ... */
#define RUNNING 'N' /* TODO: Add docs ... */

#define READY   'R' /* TODO: Add docs ... */


/**********************************************************************/
/*                          Program Structures                        */
/**********************************************************************/
/* The specifications of a process                                    */
struct process {
          int     block_time, /* TODO: Add docs                       */
                  cpu_used,   /* TODO: Add docs                       */
                  id,         /* TODO: Add docs                       */
                  max_time,   /* TODO: Add docs                       */
                  priority,   /* TODO: Add docs                       */
                  quantum,    /* TODO: Add docs                       */ 
                  wait_time;  /* TODO: Add docs                       */
          char    state;      /* TODO: Add docs                       */
   struct process *p_next_process;
                              /* TODO: Add Docs                       */
};
typedef struct process PROCESS;

/* The spceification of a process queue table                         */
struct table {
   int     count,    /* TODO: ... */
           next_pid; /* TODO: ... */
   PROCESS *p_end,   /* TODO: ... */
           *p_start; /* TODO: ... */
    

};
typedef struct table TABLE;

/**********************************************************************/
/*                           Function Prototypes                      */
/**********************************************************************/
TABLE* initalize_table();
    /* TODO: Add docs ... */
TABLE *create_table();
    /* TODO: Add docs ... */
void enqueue(TABLE *p_table);
    /* TODO: Add docs ... */
void print_table(PROCESS *p_start, int count);
    /* TODO: Add docs ... */
void dequeue(TABLE *p_table);
    /* TODO: Add docs ... */
schedule_process(p_process_table);
    /* TODO: Add docs ... */
void sort_table();
    /* TODO: Add docs ... */
void block_process(PROCESS *p_process);
    /* TODO: Add docs ... */
void ready_process(PROCESS *p_process);
    /* TODO: Add docs ... */
void recalculate_priority(PROCESS *p_process);
    /* TODO: Add docs ... */

/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
    int     clock_ticks = 0;  /* The total count of clock ticks       */
    TABLE   *p_process_table; /* The table of process to be scheduled */
    PROCESS *p_running;       /* Points to the process that's running */
  
    /* Initalize the process table with five processes                */
    p_process_table = initalize_table();

    /* Loop processing a 100 processes on the cpu                     */
    while(p_running = get_running(p_process_table),
          p_process_table->next_pid <= MAX_PID)
    { 
        /* Schedule a process to run, if none are already running */
        if(p_running == NULL)
        {
            printf("\n\nBEFORE SCHEDULING CPU:  NEXT PID = %d, Number of Processes = %d", p_process_table->next_pid, p_process_table->count);
            print_table(p_process_table->p_start, p_process_table->count);
           /*  
           schedule_process(p_process_table); */
           printf("\n\nAFTER SCHEDULING CPU:  NEXT PID = %d, Number of Processes = %d", p_process_table->next_pid, p_process_table->count);
           print_table(p_process_table->p_start, p_process_table->count);
        }
        else
        {
            /* Terminate the running process, if the process has      */ 
            /* reached it's max time on the cpu                       */
            if(p_running->clock_time == p_running->max_time)
            {
                
            }
           
            /* Block the running process, if the process has reached  */
            /* its block time                                         */
            if(p_running->cpu_used == p_running->block_time)
            {
                block_process(p_running);

            }
        }

        /* Insert a new process, if the random is one and the table   */
        /* contains less than ten elements                            */
        if((rand() % 5) + 1 == 1 && p_process_table->count < MAX_COUNT)
        {
            enqueue(p_process_table);
        }

        /* Unblock a process, if the random number is equal one       */
        if((rand() % 20) + 1 == 1)
        {
            printf("\n Should block!");
        }
       
        /
        clock_ticks++;
    }

    printf("\n\n\n\n\n");
    return 0;
}

/**********************************************************************/
/*     Create and initalize the process table with five processes     */
/**********************************************************************/
TABLE* initalize_table()
{
    TABLE *p_table; /* Points to the new process table                */
    
    p_table = create_table();
    enqueue(p_table);
    enqueue(p_table);
    enqueue(p_table);
    enqueue(p_table);
    enqueue(p_table);
    return p_table;
}

/**********************************************************************/
/*         Create and allocate memory for a new process table         */
/**********************************************************************/
TABLE *create_table()
{
    TABLE *p_new_table; /* Points to the new process table            */

    if((p_new_table = (TABLE *) malloc(sizeof(TABLE))) == NULL)
    {
        printf("\nError %d in create table.", HEADER_ALLOC_ERR);
        printf("\nCannot allocate memory for the table header.");
        printf("\nThe program is aborting.");
        exit(HEADER_ALLOC_ERR);
    } 
    p_new_table->count     = MIN_COUNT;
    p_new_table->next_pid  = 1;
    p_new_table->p_start  = NULL;
    p_new_table->p_end = NULL;
    return p_new_table;
}

/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
void enqueue(TABLE *p_table)
{
    PROCESS *p_new; /* TODO: Add docs ... */
    
    if((p_new = (PROCESS *) malloc(sizeof(PROCESS))) == NULL) 
    {
        /* FIX: UPDATE THE PRINT STATEMENTS  ... */
        printf("\nError %d in create table.", TRAILER_ALLOC_ERR);
        printf("\nCannot allocate memory for the table trailer.");
        printf("\nThe program is aborting.");
        exit(INSERT_PROCESS_ERR);
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
   
    if(p_table->count == MIN_COUNT)
        p_table->p_start = p_new;
    else
        p_table->p_end->p_next_process = p_new;
    p_table->p_end = p_new;
    p_table->count++;
    p_table->next_pid++;
    return;
}

/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
void print_table(PROCESS *p_start, int count)
{
    int counter; /* TODO: Add dcos .. */

    printf("\nPID   CPU Used   MAX TIME   SATE   PRI   QUANTUM USED");
    printf("   BLK TIME   WAIT TKS");
    for(counter = 1; counter <= count; counter++)
    {
        printf("\n%3d%8d", p_start->id,         p_start->cpu_used);
        printf("%11d%8c",  p_start->max_time,   p_start->state);
        printf("%8d%10d",  p_start->priority,   p_start->quantum);
        printf("%13d%12d", p_start->block_time, p_start->wait_time);
        p_start = p_start->p_next_process;
    }
    return;
}

/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
void dequeue(TABLE *p_table)
{
    PROCESS *p_process; /* TODO: ADD DOCS ...*/

    if(p_table->count == MIN_COUNT)
    {
        p_process        = p_table->p_start;
        p_table->p_start =  NULL;
        p_table->p_end   = NULL;
    }
    else
    {
        p_process        = p_table->p_start;
        p_table->p_start = p_table->p_start->p_next_process; 
    }
    p_table->count--;
    free(p_process);
    return;
}

/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
void block_process(PROCESS *p_process)
{
    p_process->state   = BLOCKED;
    p_process->quanrum = 0;
    recalculate_prioriity(p_process);
}

/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
void recalculate_priority(PROCESS *p_process)
{
    p_proces->priority = 
                    (abs(p_process->priority) + p_process->quantum) / 2;
    if(p_process->state == BLOCKED)
        priority *= -1;
    return;
}
