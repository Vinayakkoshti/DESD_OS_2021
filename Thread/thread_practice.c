#include<stdio.h>
#include<pthread.h>
void*example(void*arr)
{
    printf("%s\n",(char*)arr);
}

int main()
{
    pthread_t thd;
    pthread_t thd2;
    char arr[]="Hello vinayak\n";
    char brr[]="Hello Buddy\n";

    pthread_create(&thd,NULL,example,arr);
    pthread_create(&thd2,NULL,example,brr);
    pthread_join(thd,NULL);
    pthread_join(thd2,NULL);
    return 0;
}