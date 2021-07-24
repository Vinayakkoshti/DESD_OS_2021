#include<stdio.h>
#include <pthread.h>

void*UART(void*data)
{
    printf("In UART %d \n",*(int*)data);
}

int main()
{
    int  baudrate1, baudrate2;
    pthread_t thred; // thread variable
    pthread_t second;
    printf("Before thread creation\n");
    baudrate1 = 96000;
    pthread_create(&thred,NULL,UART,&baudrate1);
    baudrate2 = 115200;
    pthread_create(&second,NULL,UART,&baudrate2);
    printf("After thread\n");

    pthread_join(thred,NULL); // put main thread/program in wait state to complete thread .
    pthread_join(second,NULL);
    return 0;
}