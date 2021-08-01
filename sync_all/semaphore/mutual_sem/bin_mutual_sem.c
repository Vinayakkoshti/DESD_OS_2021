#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>


int count = 0;
sem_t sem_count; //semaphore variable

void * incThread(void *data)
{
    while(1)
    {
        sem_wait(&sem_count); // it decrease sem_count value
        count++;
        printf("INC : %d\n",count);
        sem_post(&sem_count);// it increase sem_count value
    }
}
void * decThread(void *data)
{
    while(1)
    {
        sem_wait(&sem_count);// it decrease sem_count value
        count--;
        printf("DEC : %d\n",count);
        sem_post(&sem_count);// it increase sem_count value
    }
}
int main()
{
    pthread_t thd1,thd2;

    sem_init(&sem_count,0,1);//initialize semaphore used in thread (by putting 0 ) and initial value 1(by putting 1)
    

    pthread_create(&thd1,NULL,incThread,NULL);
    pthread_create(&thd2,NULL,decThread,NULL);
    pthread_join(thd1,NULL);
    pthread_join(thd2,NULL);

    sem_destroy(&sem_count);//destroy semaphore.
    return 0;
}