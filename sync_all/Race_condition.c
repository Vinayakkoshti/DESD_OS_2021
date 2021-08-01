#include<stdio.h>
#include<pthread.h>
int count = 0;
void * incThread(void *data)
{
    while(1)
    {
        count++;
        printf("INC : %d\n",count);
    }
}
void * decThread(void *data)
{
    while(1)
    {
        count--;
        printf("DEC : %d\n",count);
    }
}
int main()
{
    pthread_t thd1,thd2;
    pthread_create(&thd1,NULL,incThread,NULL);
    pthread_create(&thd2,NULL,decThread,NULL);
    pthread_join(thd1,NULL);
    pthread_join(thd2,NULL);
    return 0;
}