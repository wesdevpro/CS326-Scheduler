#ifndef PROGRAM_STRUCTS
#define PROGRAM_STRUCTS  

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

#endif
