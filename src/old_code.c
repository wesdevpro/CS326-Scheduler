    /* Loop processing a 100 processes on the cpu                     */
    while(p_running = get_running(p_process_table->p_start,
                                                p_process_table->p_end),
          p_process_table->next_pid <= MAX_PID)
    { 
        /* Schedule a process to run, if none are already running */
        if(p_running == NULL)
        {
           printf("\n\nBEFORE SCHEDULING CPU:  NEXT PID = %d, Number of Processes = %d", p_process_table->next_pid, p_process_table->count);
           print_table(p_process_table->p_start, p_process_table->count); 
           schedule_process(p_process_table);
           printf("\n\nAFTER SCHEDULING CPU:  NEXT PID = %d, Number of Processes = %d", p_process_table->next_pid, p_process_table->count);
           print_table(p_process_table->p_start, p_process_table->count);
        }
        else
        {
            /* Terminate the running process, if the process has      */ 
            /* reached it's max time on the cpu                       */
            if(p_running->cpu_used == p_running->max_time)
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
       
        clock_ticks++;

