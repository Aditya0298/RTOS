/* question= List the customization options for creating a task for the RTOS you are using.
eg. priority etc
answer = for craeting a task
1.go to freertos and in api search task creation
2. we have to create a task handle_t;
3.we have to create a void app_main
4. in appmain we have to create a basetype_t
5.then we have to create a xTaskCreate
6. in xTaskCreate = 1.first argument is give function name 2.type any string 3.stack size 
any size 4.parameters arguments 5. priority of the task 6. handle name is given   
#=XtaskCreate(func_name,"hello",2048=stack,NULL=parameters,5=priority,&task_handle);
