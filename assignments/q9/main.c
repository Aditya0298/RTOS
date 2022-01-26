/*Find the fields that are maintained in the Task Control Block / Process Control Block 
of the RTOS you are using.
=process control block
pointer=>process state=>process number=>program counter=>register=>memory limits=>open file lists
=>misc:accounting and status data
=task control block
=>task ID=>priority=>status=>registers=>program counter=>status registers=>pointer to next TCB
