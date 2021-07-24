#include<stdio.h>
#include <pthread.h>

void*thread_fun(void*data)
{
    printf("In thread\n");
}

int main()
{
    pthread_t thred; // thread variable
    printf("Before thread creation\n");
    pthread_create(&thred,NULL,thread_fun,NULL);
    printf("After thread\n");

    pthread_join(thred,NULL); // put main thread/program in wait state to complete thread .
    
    return 0;
}