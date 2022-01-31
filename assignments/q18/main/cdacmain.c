#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>

QueueHandle_t hello_queue;
int intsend =5;
void task1(void *pv)
{
    while(1)
    {
        intsend++;
        printf("the queue one is here %d/n",intsend);
xQueueSend("elephant",task1,portMAX_DELAY);
 vTaskDelay(pdMS_TO_TICKS(2000));
    }
}
void task2(void *pv)
{
    //int result2 = 0;
    while(1)
    {
      //  result2++;
        //printf("queue two is here %d\n",result2);
        xQueueReceive(hello_queue,task2,portMAX_DELAY);
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}
void app_main()
{
    hello_queue = xQueueCreate(5,sizeof(int));
    xTaskCreate(task1,"hello",2048,NULL,5,NULL);
    xTaskCreate(task2,"hello",2048,NULL,3,NULL);
    printf("hello aditya/n");


}