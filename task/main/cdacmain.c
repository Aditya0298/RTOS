#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t xHandleTaskLog; //opague datatype
void tasklog(void *pvparameter) //void pointer and giving parameter

{
printf("tasklog\n");
vTaskDelete(xHandleTaskLog);

}
void app_main(){
    BaseType_t result; //opaque data type defining result
result = xTaskCreate(tasklog, "aditya",2048,NULL,5,&xHandleTaskLog); //tasklog = pointer to task aditya any string 2048 stack size null parameter , 5 priority,&xhandletasklog handle
if(result == pdPASS)
{
    printf("tasklog created\n");

}
else{
    printf("tasklog not created\n");
}
}
