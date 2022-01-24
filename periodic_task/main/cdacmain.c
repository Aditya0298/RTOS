#include <stdio.h>

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

void sensortask( void *pvhello)
{
    while(1)
    {
        printf("sensor task hello aditya\n");
        vTaskDelay(1000/portTICK_PERIOD_MS);

    }
}
void app_main(){
    xTaskCreate(sensortask, "aditya",2048,NULL,5,NULL);
    printf("hello world this is sensor task with delay 1 sec\n");
}
