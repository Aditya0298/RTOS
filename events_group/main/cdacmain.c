#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/event_groups.h>

TaskHandle_t temperature;
TaskHandle_t pressure;
TaskHandle_t weather;

EventGroupHandle_t climate;

const __uint32_t temp_bit = (1 << 0);
const __uint32_t pres_bit = (1 << 1);
const __uint32_t all_bits = (temp_bit | pres_bit);
 void temp(void *pv)
 {
     while(1){
printf("this is temperature task\n");
     xEventGroupSetBits(climate,temp_bit);
     vTaskDelay(1000 / portTICK_PERIOD_MS);
 }
 }
 void pres(void *pv)
 {
     while(1){
         printf("this is pressure task\n");
     xEventGroupSetBits(climate,pres_bit);
     //printf("this is pressure task");
     vTaskDelay(pdMS_TO_TICKS(2000));
     }
 }
 void weat(void *pv)
 {
     while(1){
         printf("this is weather task\n");
 uint32_t result;
     result = xEventGroupWaitBits(climate,all_bits,pdTRUE,pdTRUE,pdMS_TO_TICKS(5000));
vTaskDelete(NULL);     
     }
 }
 void app_main()
 {
     climate = xEventGroupCreate();
     xTaskCreate(temp,"temp_task",2048,NULL,5,&temperature);
     xTaskCreate(pres,"pressure_task",2048,NULL,5,&pressure);
     xTaskCreate(weat,"weather_task",2048,NULL,5,&weather);
  //   while(1){
//printf("this is appmain hello\n");

  //}
   }