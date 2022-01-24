//create 2 task with priority 10,20 print their own messages 
#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>


TaskHandle_t task_handle1;
TaskHandle_t task_handle2;

void task1(void *pv)
{ 
    printf("task 1 is saying hello guys good morning\n");
    vTaskDelete(task_handle1);
}
void task2(void *pv)
{
printf("task 2 is saying hello guys how are you\n");
vTaskDelete(task_handle2);
}
void app_main()
{
    BaseType_t result1;
    BaseType_t result2;
    result1 = xTaskCreate(task1,"hello",2048,NULL,10,&task_handle1);
    result2 = xTaskCreate(task2,"guys",2048,NULL,20,&task_handle2);
}



