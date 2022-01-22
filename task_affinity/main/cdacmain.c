#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
 
 void alarmtask(void *pv){
     while(1){
  //   printf("hello alarm task\n");
     printf("alarm task cpu id %d\n",uxTaskPriorityGet(NULL));
     vTaskDelay(1000 / portTICK_PERIOD_MS);
 }
 }
 void app_main(){
     xTaskCreate(alarmtask,"aditya",2048,NULL,5,NULL);
 }