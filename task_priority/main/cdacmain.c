#include <stdio.h>

#include <freertos/FreeRTOS.h>
#include<freertos/task.h>

void sensortask(void *pv){
    int count =0;
    while(1){
        count++;
        printf("sensor task %d\n",uxTaskPriorityGet(NULL));
        if(count ==200)
        {
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }
    }
    }
void alarmtask(void *pv){
    printf("alarm task %d\n",uxTaskPriorityGet(NULL));
    vTaskDelay(1000 / portTICK_PERIOD_MS);

}
void app_main(){
    xTaskCreate(sensortask,"aditya",2048,NULL,5,NULL);
     xTaskCreate(alarmtask,"kaushik",2048,NULL,3,NULL);
}