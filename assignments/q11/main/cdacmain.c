/*question= What is the API for deleting a task? Write a program demonstrate this capability.*/
/*answer = void vTaskDelete( TaskHandle_t xTask ); */
#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t taskhandle1;

void task_one(void *pv)
{
    printf("hello this is task one\n");
    vTaskDelete(taskhandle1);
}
void app_main()
{
     BaseType_t result;
   result = xTaskCreate(task_one, "hello_guys",2048,NULL,5,&taskhandle1);

}
