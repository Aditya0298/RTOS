#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include<freertos/queue.h>

QueueHandle_t raspberry;

void sendingdata(void *ak)
{
    int sendingdata =0;
    while(1){
        sendingdata++;
        printf("sending task data is %d\n",sendingdata);
         xQueueSend(raspberry,&sendingdata,portMAX_DELAY);
         vTaskDelay(1000 /portTICK_PERIOD_MS);
        
    }
}
void receivingdata(void *ak)
{
    int receivingdata =0;
    while(1){

  xQueueReceive(raspberry,&receivingdata,portMAX_DELAY);
    printf("receiving data is %d",receivingdata);
    }
}
void app_main(){
    raspberry = xQueueCreate( 10,sizeof(int));
    xTaskCreate(sendingdata,"aditya",2048,NULL,5,NULL);
    xTaskCreate(receivingdata,"kaushik",2048,NULL,3,NULL);
    printf("hello message_queue\n");
}
