#include<stdio.h>
#include<pthread.h>

int count = 0;
pthread_mutex_t mutex; //mutex handler

void * incThread(void *data)
{
    while(1)
    {
        pthread_mutex_lock(&mutex);//lock mutex no other thread will get access to shared resource.
        count++;
        printf("INC : %d\n",count);
        pthread_mutex_unlock(&mutex);//unlock mutex now other thread will get access to shared resource.
    }
}
void * decThread(void *data)
{
    while(1)
    {
        pthread_mutex_lock(&mutex);//lock mutex no other thread will get access to shared resource.
        count--;
        printf("DEC : %d\n",count);
        pthread_mutex_unlock(&mutex);//unlock mutex now other thread will get access to shared resource.
    }
}
int main()
{
    pthread_t thd1,thd2;
   //mutex shuld be created before thread
    pthread_mutex_init(&mutex,NULL); //initialise mutex i.e create a mutex with mutex handler
   
    pthread_create(&thd1,NULL,incThread,NULL);
    pthread_create(&thd2,NULL,decThread,NULL);
    pthread_join(thd1,NULL);
    pthread_join(thd2,NULL);

    pthread_mutex_destroy(&mutex);//delete mutex
    return 0;
}