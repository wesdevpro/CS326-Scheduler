/**********************************************************************/
/*                                                                    */
/* Program Name: scheduler.c - TODO: add docs no more than two lines  */
/*                                                                    */
/* Author:       Wesley Ford                                          */
/* Installation: Pensacola Christian College, Pensacola, Florida      */
/* Course:       CS326, Operating Systems                             */
/* Date Written: Feburary 12, 2024                                    */
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
#include <stdio.h>
#include <stdlib.h>

/**********************************************************************/
/*                           Symbolic Constants                       */
/**********************************************************************/


/**********************************************************************/
/*                          Program Structures                        */
/**********************************************************************/
/* The process tabble                                                 */
struct process {
          int  block_time, /* TODO: Add docs                          */
               cpu_used,   /* TODO: Add docs                          */
               max_time,   /* TODO: Add docs                          */
               priority,   /* TODO: Add docs                          */
               id,         /* TODO: Add docs                          */
               wait_time;  /* TODO: Add docs                          */
          char state;      /* TODO: Add docs                          */
   struct process *p_next_process;
                           /* TODO: Add Docs                          */
};
typedef struct process PROCESS;

/**********************************************************************/
/*                           Function Prototypes                      */
/**********************************************************************/
void print_heading();
    /* TODO: Add Docs */
void calculate_priority(PROCESS *p_process);
    /* TODO: Add Docs */
PROCESS* create_table();
    /* TODO: Add docs */
void initalize_process_table(PROCESS *p_table);
    /* TODO: Add docs */
PROCESS* print_table(PROCESS *p_table, int count);
    /* TODO: Add docs */
void terminate_running_process();
    /* TODO: Add docs */
void recalculate_priority(PROCESS* process)
    /* TODO: Add docs */

/**********************************************************************/
/*                           Main Function                            */
/**********************************************************************/
int main()
{
    PROCESS *p_process_table;
    int current_pid;
    
    /* NOTE: Main should be made of tasks. */

    printf("\nINIT LIST");
    p_process_table = create_table();

    printf("\nLIST INFO");
    printf("\nHEADER ID: %d", p_process_table->id);

    /* NOTE THIS MAY BE THE WRONG TYPE OF LOOP BECAUSE WE DO NOT KNOW EXACTLY WHEN THE LOOP WILL END*/
    /* BUT WE DO KNOW UNDER WHAT CONDITION THE LOOP SHOULD END */
    for(current_pid = 1; current_pid < 100; current_pid++)
    {
        printf("\nBEFORE SCHEDULING CPU:  NEXT PID = %d, Number of Processes = Count", current_pid);
        // SORTING STUFF HERE!
        // DO YOU NEED TO SWITCH THE CONTEXT OF THE CPU HERE OR IS CLOCK TICKS STILL HAPPENING HERE?
        // PRINT TABLE FOR NOW 
        
        printf("\nAFTER SCHEDULING CPU:  NEXT PID = %d, Number of Processes = Count", current_pid);
        

    }

    printf("\nFREEING LIST");
    free(p_process_table->p_next_process);
    free(p_process_table);

    printf("\nGOOD BYE");
    return 0;
}

/*********************************************************************/
/*                    Print the program heading                       */
/**********************************************************************/
void print_heading()
{
    printf("\n\n\n\n\n");
    printf("\n THIS IS A TEMP PROGRAM HEADING");
}

/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
void calculate_priority(PROCESS *p_process)
{
    // IDEA: p_process->priority = ( | p_process->priority | +  p_process->quantome) / 2;
    // To recalculate the priority of the running process, use the following formula:
    // new_priority (PRI) = ( |old_priority| + quantum_used) / 2
    // ROUNDING to the nearest whole number; 
    // if the process is blocked, set this priority negative, otherwise it will be positive
    if(p_process->state == 'B')
        p_process->priority -= p_process->priority * 2;
    return;
}

/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
PROCESS* create_table()
{
    PROCESS *p_new_table;
    
    if((p_new_table = (PROCESS *) malloc(sizeof(PROCESS))) == NULL)
    {
        printf("\nERROR HEADER");
        exit(1);
    }
    p_new_table->id = 0;

    if((p_new_table->p_next_process = (PROCESS *) malloc(sizeof(PROCESS))) == NULL)
    {
        printf("\nERROR TRAILER");
        exit(2);
    }
    p_new_table->p_next_process->id = 100;

    return p_new_table;
}

/**********************************************************************/
/*                    TODO: Add docs                                  */
/**********************************************************************/
void recalculate_priority(PROCESS* process)
{
    process->priority = (abs(process->priority) + 4) / 2;
    return;
}

