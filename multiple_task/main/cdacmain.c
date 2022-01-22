#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
TaskHandle_t xHandleTaskLog1;
TaskHandle_t xHandleTaskLog2;
 void tasklog1(void *pvparameter1){
     printf("tasklog_1");
     vTaskDelete(xHandleTaskLog1);
 }
 void tasklog2(void *pvparameter2)
 {
     printf("tasklog_2");
     vTaskDelete(xHandleTaskLog2);

 }
 void app_main(){
     BaseType_t result1;
     BaseType_t result2;
     result1 = xTaskCreate(tasklog1, "aditya",2048,NULL,5,&xHandleTaskLog1);
     if (result1 == pdPASS){
         printf("tasklog1 created\n");
     }
     result2 =xTaskCreate(tasklog2, "kaushik",2048,NULL,10,&xHandleTaskLog2);
     if (result2 == pdPASS){
         printf("tasklog2 is created\n");
     }
 }
