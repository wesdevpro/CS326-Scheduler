THE main() FUNCTION LOOP
------------------------
The main() function will:

    Initialize the process table
        At the beginning of the main() function, an initialize function is called; it initializes 
        the process table with exactly 5 starting (Ready) processes
   
   Loop for 99 processes, repeatedly doing the following (not necessarily in this order):
      Processing a clock tick (interrupt); the clock is 60Hz so it ticks (interrupts the 
         CPU) 60 times a second; the process table will be appropriately updated EACH 
         clock tick; so each loop through the main() function is 1 clock tick
        There are 6 clock ticks in 1 quantum and 60 clock ticks per second (60Hz clock); so a 
        quantum is 100 milliseconds
        
      
      Terminating the running process if it has reached its maximum CPU time (MAX Time)
      
      Preempting the running process if it blocked or used all of its quantum, 
         recalculating its priority, and immediately placing it at the END of the proper 
         process queue, based on its new priority
        A process becomes Blocked when it has used the number of clock ticks that is equal to 
         its blocking time (BLK TIME), and its blocking time never changes
         A process is terminated (removed from the process table) when it reaches its MAX Time
      
      Scheduling the next process if necessary, scheduling ROUND ROBIN WITHIN EACH 
         priority queue, where -1 is the highest priority, -2 the next highest, 
         ..., -n, 0, 1, ..., n (i.e., n is the lowest priority)
        There may be at most 1 processed marked as ruNning (state N); all other processes are 
        either Ready (state R) or Blocked (state B)
         Each time a process is scheduled to the CPU, it may use at most 1 quantum
      
      Make ready any Blocked processes that have become unblocked
        At EACH clock tick (that is, EVERY time through the main() function loop):
            There is a 1 in 20 chance EACH Blocked process becomes unblocked
            (EVERY Blocked process is given this chance to become unblocked)
      
      Placing any newly arrived processes into the process table
        At EACH clock tick (that is, EVERY time through the main() function loop):
            There is a 1 in 5 chance a new process will be added
        There can be a maximum of 10 processes in the process table; new processes will not 
        arrive if the process table is currently full
   
   The loop stops when the process ID (PID) reaches the value 100
    The rest of the main() function (the loop) calls functions to accomplish the tasks it 
    needs; this loop will terminate, and the scheduling will end, when PID 100 becomes 
    the next process to enter the queues
   
   THE ABOVE LOOP IS DONE EVERY CLOCK TICK

MISCELLANEOUS OTHER INFORMATION (use where necessary)
-----------------------------------------------------
All processes are kept in a single process table by priority (PRI); the process table 
   is ALWAYS displayed BEFORE and AFTER scheduling the CPU, with priorities shown from 
   highest to lowest (-1, -2, -3, ..., -n, 0, 1, 2, ..., n); all processes with the same 
   priority are kept in the same queue
In addition to the normal program operation, your program will be STRESS tested against 
   the following two conditions:
      1. All processes in the process table become Blocked; the output should be:
            BEFORE: The last unblocked process is ruNning and has used its BLK TIME
            AFTER:  All processes are blocked (there are no Ready nor ruNning processes)
            BEFORE: One or more processes have become Ready (or are newly arrived)
            AFTER:  The highest priority Ready process is now ruNning
      2. The process table becomes empty (Number of Processes = 0); the output should be:
            BEFORE: The last process is ruNning and reached its MAX Time (is terminating)
            AFTER:  The process table is empty (only the 2 heading lines are printed)
            BEFORE: A new Ready process has arrived
            AFTER:  The newly arrived process is now ruNning
Note, every BEFORE is followed by an AFTER (there are the same number of BEFORE/AFTER's); 
so, every time a BEFORE table is printed, ALWAYS print an AFTER table


