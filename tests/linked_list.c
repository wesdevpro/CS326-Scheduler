#include <stdio.h>
#include <stdlib.h>

/**********************************************************************/
/*                           Symbolic Constants                       */
/**********************************************************************/
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

/**********************************************************************/
/*                           Function Prototypes                      */
/**********************************************************************/
PROCESS *initalize_table();
    /* TODO: Add docs ... */
PROCESS *create_table();
    /* TODO: Add docs ... */
void insert_process(PROCESS *p_table, int pid);
    /* TODO: Add docs ... */
void print_table(PROCESS *p_table);
    /* TODO: Add docs ... */
void sort_table(PROCESS *p_table);
    /* TODO: Add docs ... */






/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
    PROCESS *p_process_table; /* TODO: Add docs ... */
    int     next_pid = 6;     /* TODO: Add docs ... */

    /* TODO: Add docs ... */
    p_process_table = initalize_table();

    /* NOTE: HAHAH */
    print_table(p_process_table);
    sort_table(p_process_table);
    return 0;
}

/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
PROCESS *initalize_table()
{
    PROCESS *p_new_table;

    p_new_table = create_table();
    insert_process(p_new_table, 1);
    insert_process(p_new_table, 2);
    insert_process(p_new_table, 3);
    insert_process(p_new_table, 4);
    insert_process(p_new_table, 5);
    return p_new_table;
}

/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
PROCESS *create_table()
{
    PROCESS *p_new_table; /* TODO: Add docs ... */

    if((p_new_table = (PROCESS *) malloc(sizeof(PROCESS))) == NULL)
    {
        /* FIX: UPDATE THE PRINT STATEMENTS  ... */
        printf("\nError %d in create table.", TRAILER_ALLOC_ERR);
        printf("\nCannot allocate memory for the table trailer.");
        printf("\nThe program is aborting.");
        /* FIX: Correct the error code with a constant...*/
        exit(1);
    }
    p_new_table->id = 0; /* FIX: */

    if((p_new_table->p_next_process 
                        = (PROCESS *) malloc(sizeof(PROCESS))) == NULL)
    {
        /* FIX: UPDATE THE PRINT STATEMENTS  ... */
        printf("\nError %d in create table.", TRAILER_ALLOC_ERR);
        printf("\nCannot allocate memory for the table trailer.");
        printf("\nThe program is aborting.");
        /* FIX: Correct the error code with a constant...*/
        exit(1);
    }
    p_new_table->p_next_process->id = 100; /* TODO: */
    p_new_table->p_next_process->p_next_process = NULL;

    return p_new_table;
}

/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
void insert_process(PROCESS *p_table, int pid)
{
    PROCESS *p_new_process; /* TODO: Add docs ... */

    if((p_new_process = (PROCESS *) malloc(sizeof(PROCESS))) == NULL)
    {
        /* FIX: UPDATE THE PRINT STATEMENTS  ... */
        printf("\nError %d in create table.", TRAILER_ALLOC_ERR);
        printf("\nCannot allocate memory for the table trailer.");
        printf("\nThe program is aborting.");
        /* FIX: Correct the error code with a constant...*/
        exit(1);
    }
    
    p_new_process->id         = pid;
    p_new_process->cpu_used   = 0;
    p_new_process->priority   = 0;
    p_new_process->quantum    = 0;
    p_new_process->wait_time  = 0;
    p_new_process->state      = 'R';
    p_new_process->max_time   = (rand() % 18) + 1;
    if(((rand() % 3) + 1) == 1)
        p_new_process->block_time = 6;
    else
        p_new_process->block_time = (int) (rand() % 5) + 1;
    p_new_process->p_next_process = p_table->p_next_process;
    p_table->p_next_process       = p_new_process;
    return; 
}

/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
void print_table(PROCESS *p_table)
{
    printf("\nPID   CPU Used   MAX TIME   SATE   PRI   QUANTUM USED");
    printf("   BLK TIME   WAIT TKS");
    
    while(p_table                 =  p_table->p_next_process,
          p_table->p_next_process != NULL)
    {
        printf("\n%3d%8d", p_table->id,         p_table->cpu_used);
        printf("%11d%8c",  p_table->max_time,   p_table->state);
        printf("%8d%10d",  p_table->priority,   p_table->quantum);
        printf("%13d%12d", p_table->block_time, p_table->wait_time);

    }
    return;
}

void sort_table(PROCESS *p_table)
{
    PROCESS *p_next;

    while(p_table     =  p_table->p_next_process,
          p_table->id < TABLE_TRAILER)
    {
        p_next = p_table->p_next_process;
        while(p_next->id < TABLE_TRAILER)
        {
            if(p_table->id > p_next->id)
            {
                printf("\nSWAP"); 
            }
        }
    }
    return;
}

