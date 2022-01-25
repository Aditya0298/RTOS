// ques = Create a task to suspend itself after 1200 ms and resume it from another task
#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t taskhandle1;
TaskHandle_t taskhandle2;

void task_one(void *pv)
{
while(1)
{
    printf("here we have to suspend task after 1200ms\n");
    vTaskDelay(1200 / portTICK_PERIOD_MS);
    vTaskSuspend(taskhandle1);
}
}
void task_two(void *pv)
{
    while(1)
    {
        vTaskResume(taskhandle1);
        printf("now task 2 will continue \n");
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}
void app_main()
{
     BaseType_t result1;
      BaseType_t result2;
      result1 = xTaskCreate(task_one,"hello",2048,NULL,5,&taskhandle1);
      result2 = xTaskCreate(task_two,"hello",2048,NULL,5,&taskhandle2);
}
