//Swap the priority and observe the changes in the output. 
//What is your conclusion on the sequence of printing the messages.
//answer = earlier when we run the task 1 with priority 5 will print after that task2 with priortiy
//10 will print but in second run task 2 will run beacuse it has higher priority.
#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
TaskHandle_t handle1;
TaskHandle_t  handle2;
void task1(void *pv)
{
    while (1)
    {
    
    
    printf("hello task 1\n");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
}
}
void task2(void *pv)
{
    while(1){
    printf("hello task 2\n");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
}
}
void app_main()
{
    BaseType_t result1;
    BaseType_t result2;

    result1 = xTaskCreate(task1,"hello",2048,NULL,5,&handle1);
    result2 = xTaskCreate(task2,"hello",2048,NULL,10,&handle2);
}