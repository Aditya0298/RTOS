//task periodic with periodicity 500ms
#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t periodicity_task;

void task1(void *pv)
{
    while(1)
    {
        printf("hello we are creating the periodic task\n");
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}
void app_main()
{
     BaseType_t result;
     result = xTaskCreate(task1,"hello",2048,NULL,5,&periodicity_task);

}