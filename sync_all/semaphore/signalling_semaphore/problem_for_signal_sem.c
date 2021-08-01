#include<stdio.h>
#include<pthread.h>

int x,y,sum;
//here ether thread will execute first
// output_thread execute first it will print sum if input_thread execute first
// and in between this context switch happen then in output_thread sum will give wrong answer 
// so data will corrupt to avoid this signalling semaphore will be use. 

void*input_thread(void*data)
{
    while(1)
    {
        scanf("%d",&x);
        scanf("%d",&y);
    }
}
void*output_thread(void*data)
{
    while(1)
    {
        sum=x+y;
        printf("sum : %d\n",sum);
    }
}

int main()
{
    pthread_t input,output;
    pthread_create(&input,NULL,input_thread,NULL);
    pthread_create(&output,NULL,output_thread,NULL);

    pthread_join(input,NULL);
    pthread_join(output,NULL);


    return 0;
}