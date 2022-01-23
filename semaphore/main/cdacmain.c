#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/semphr.h>

SemaphoreHandle_t firstsemaphore;
//SemaphoreHandle_t secondsemaphore;

void sem1(void *pv)
{
    int sensordata =0;
    while(1){
        xSemaphoreGive(firstsemaphore);
        sensordata++;
        printf("sensor data %d\n",sensordata);

vTaskDelay(1000 / portTICK_PERIOD_MS);
}
}
void sem2(void *pv)
{
    int alarmdata =0;
    while(1){
        xSemaphoreTake(firstsemaphore,portMAX_DELAY);
//        alarmdata++;
        printf("alarm data is %d\n",alarmdata);
        
vTaskDelay(1000  / portTICK_PERIOD_MS);
    }

}
void app_main()
{
   firstsemaphore  = xSemaphoreCreateBinary();
   xTaskCreate(sem1,"hello",2048,NULL,5,NULL);
   xTaskCreate(sem2, "aditya",2048,NULL,3,NULL);
xSemaphoreTake(firstsemaphore, portMAX_DELAY);
}