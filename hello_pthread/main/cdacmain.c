#include <stdio.h>
#include<pthread.h>
void *helloESPThread(void *arg)
{
printf("thread function\n");
return NULL;
}
void app_main(){
pthread_t thread_id;
printf("hello esp\n");
pthread_create(&thread_id, NULL, helloESPThread,NULL);
pthread_join(thread_id, NULL);
}



