#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/timers.h>
TimerHandle_t hellotimer;
int count = 0;

void turnmotoroff(TimerHandle_t xTimer)
{
    count++;
    printf("turn motor off\n");
if(count == 5)
{
    printf("i am switching off the timer\n");
    xTimerStop(xTimer,1000);
}
}
void app_main()
{
hellotimer =  xTimerCreate("motor",pdMS_TO_TICKS(100),pdTRUE,&hellotimer,turnmotoroff);
xTimerStart(hellotimer,0);
while(1)
{
    printf("main task\n");
    vTaskDelay(1000 / portTICK_PERIOD_MS);

}            
}