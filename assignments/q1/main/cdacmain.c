#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t handle1;
TaskHandle_t handle2;

void task1(void *pv)
{
while(1)
{
    printf("here is task one with lower priority\n");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
}
}
void task2(void *pv)
{
    while(1)
    {
        printf("here is task two with higher priority\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
void app_main()
{
    BaseType_t  result1;
    BaseType_t  result2;
result1 = xTaskCreate( task1,"hello",2048,NULL,5,&handle1);
result2 = xTaskCreate(task2,"aditya",2048,NULL,10,&handle2);

}
