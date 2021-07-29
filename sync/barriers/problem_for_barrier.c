#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void*i2c_thread(void*data)
{
    printf("I2C Started....\n");
    sleep(2);
    printf("I2C completed.\n");
}
void*uart_thread(void*data)
{
    printf("uart Started....\n");
    sleep(3);
    printf("uart completed.\n");
}
void*ethernet_thread(void*data)
{
    printf("ethernet Started....\n");
    sleep(6);
    printf("ethernet completed.\n");
}

int main()
{
    pthread_t i2c,uart,ethernet;


    pthread_create(&i2c,NULL,i2c_thread,NULL);
    pthread_create(&uart,NULL,uart_thread,NULL);
    pthread_create(&ethernet,NULL,ethernet_thread,NULL);

    pthread_join(i2c,NULL);
    pthread_join(uart,NULL);
    pthread_join(ethernet,NULL);
    
    return 0;
}