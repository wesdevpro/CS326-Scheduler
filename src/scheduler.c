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

struct table {
    int     count,    /* TODO: Add docs ... */
            next_pid; /* TODO: Add docs ... */
    PROCESS *p_front,  /* TODO: Add docs ... */
            *p_rear;   /* TODO: Add docs ... */
};
typedef struct table TABLE;

/**********************************************************************/
/*                           Function Prototypes                      */
/**********************************************************************/
TABLE *initalize_table();
    /* TODO: Add docs ... */
TABLE *create_table();
    /* TODO: Add docs ... */
void enqueue(TABLE *p_table, int pri);
    /* TODO: Add docs ... */
PROCESS *dequeue(TABLE *p_table);
    /* TODO: Add docs ... */
void print_header(const char *context, int count, int next_pid);
    /* TODO: Add docs ... */
void print_table(PROCESS *p_start);
    /* TODO: Add docs ... */
void sort_table(PROCESS *p_front, int count);

/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
    
    TABLE *p_process_table;

    /* TODO: Add docs .... */
    p_process_table = initalize_table();
   
    print_header("BEFORE", p_process_table->next_pid,
                                             p_process_table->count);
    print_table(p_process_table->p_front);
    print_header("BEFORE", p_process_table->next_pid,
                                             p_process_table->count);
    print_table(p_process_table->p_front);


    return 0;
}



/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
TABLE *initalize_table()
{
    TABLE *p_new_table;

    p_new_table = create_table();
    enqueue(p_new_table, 5);
    enqueue(p_new_table, -1);
    enqueue(p_new_table, 3);
    enqueue(p_new_table, 0);
    enqueue(p_new_table, -3);
    return p_new_table;
}

/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
TABLE *create_table()
{
    TABLE *p_new_table;

    if((p_new_table = (TABLE *) malloc(sizeof(TABLE))) == NULL) 
    {
        /* FIX: UPDATE THE PRINT STATEMENTS  ... */
        printf("\nError %d in create table.", TRAILER_ALLOC_ERR);
        printf("\nCannot allocate memory for the table trailer.");
        printf("\nThe program is aborting.");
        exit(4); /* FIX: Fix this .... */
    }
    p_new_table->count    = 0;
    p_new_table->next_pid = MIN_PID;
    return p_new_table;
}

/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
void enqueue(TABLE *p_table, int pri)
{
    PROCESS **pp_front = &p_table->p_front,
                    /* TODO: Add docs ... */
            *p_new, /* TODO: Add docs ... */
            **pp_rear  = &p_table->p_rear;
                    /* TODO: Add docs ... */
    
    if(p_table->count < MAX_PID)
    {
        if((p_new = (PROCESS *) malloc(sizeof(PROCESS))) == NULL) 
        {
            /* FIX: UPDATE THE PRINT STATEMENTS  ... */
            printf("\nError %d in create table.", TRAILER_ALLOC_ERR);
            printf("\nCannot allocate memory for the table trailer.");
            printf("\nThe program is aborting.");
            exit(4); /* FIX: Fix this .... */
        }
        p_new->id = p_table->next_pid;
        p_new->cpu_used       = 0;
        p_new->priority       = pri;
        p_new->quantum        = 0;
        p_new->wait_time      = 0;
        p_new->state          = 'R';
        p_new->max_time       = (rand() % 18) + 1;
        p_new->p_next_process = NULL;
        if(((rand() % 3) + 1) == 1)
            p_new->block_time = 6;
        else
            p_new->block_time = (int) (rand() % 5) + 1;

        if(*pp_front == NULL)
            *pp_front = p_new;
        else
            (*pp_rear)->p_next_process = p_new;
        *pp_rear = p_new;
        p_table->count++;
        p_table->next_pid++;
    }
    return;
}


/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
PROCESS *dequeue(TABLE *p_table)
{
    PROCESS **pp_front = &p_table->p_front,
            /* TODO: Add docs ... */
            **pp_rear  = &p_table->p_rear,
            /* TODO: ADD docs ... */
            *p_top_process;
            /* TODO: Add docs ... */
    if(pp_front != NULL)
    {
        p_top_process = *pp_front;
        *pp_front     = (*pp_front)->p_next_process;
        if(*pp_front == NULL)
            *pp_rear = NULL;
        p_top_process->p_next_process = NULL;
    } 
    return p_top_process;
}

/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
void print_header(const char *context, int count, int next_pid)
{
    printf("\n\n%s SCHEDULING CPU:", context);
    printf("  NEXT PID = %d,", count);
    printf("   Number of Processes = %d", next_pid);
}


/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
void print_table(PROCESS *p_start)
{
    printf("\nPID   CPU Used   MAX Time   SATE   PRI   QUANTUM USED");
    printf("   BLK TIME   WAIT TKS");
    while(p_start != NULL)
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
void sort_table(PROCESS *p_front, int count)
{
    int     outer,
            inner;
            /* TODO: Add docs ... */
    PROCESS *p_next     = p_front->p_next_process,
            *p_previous = NULL;
            /* TODO: ADD docs ... */
  
    for(outer = 1; outer < count; outer++)
    {
        for(inner = 1; inner < count; inner++)
        {
              if(p_next->priority < p_front->priority) 
                /* swap here */
             
        }

    }
    return;
}

/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
