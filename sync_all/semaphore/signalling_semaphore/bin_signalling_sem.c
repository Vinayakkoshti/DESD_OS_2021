#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

#include <fcntl.h>    
#include <sys/stat.h> 
#include <semaphore.h>



//here ether thread will execute first
// output_thread execute first it will print sum if input_thread execute first
// and in between this context switch happen then in output_thread sum will give wrong answer 
// so data will corrupt to avoid this signalling semaphore will be use. 
//in signalling semaphore when one thread/process done then it send signal to anather thread/process to execute that process
//so while scanf executing if contex switch happen other thread will in wait state so no data will currpt in buffer variables
//here waitng thread meant to  critical section.  

//signalling semaphore can be achived by using two semaphore

int x,y,sum;
sem_t s1,s2;

void*input_thread(void*data)
{
    while(1)
    {
        sem_wait(&s1);
        scanf("%d",&x);
        scanf("%d",&y);
        sem_post(&s2);
    }
}
void*output_thread(void*data)
{
    while(1)
    {
        sem_wait(&s2);
        sum=x+y;
        printf("sum : %d\n",sum);
        sem_post(&s1);
    }
}


int main()
{
    pthread_t input,output;
      

    sem_init(&s1,0,1);
    sem_init(&s2,0,0);
    
    pthread_create(&input,NULL,input_thread,NULL);
    pthread_create(&output,NULL,output_thread,NULL);

    pthread_join(input,NULL);
    pthread_join(output,NULL);

    sem_destroy(&s1);
    sem_destroy(&s2);

    return 0;
}