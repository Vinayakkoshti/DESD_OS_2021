/*

Problem :
    Access 3 buffers/sharead_resource  using 5 threads  use counting semaphore for synchronization.

*/

/*

Algorithm to solve 
1) get array of structure for buffer/sharead_resource.
2) write two function one for giving buffer if free ( if not put that thread in wait state ).
3) and one for realising buffer tails buffer is free now.
4) create 5 threads.
5) in each thread access at least one buffer by calling step-2. 
6) after using buffer realise that buffer by calling step-3.

*/


/*

    Note : In this program write system call used instead of printf beacouse to see clean contex switch
        as printf is library call and also is uses buffer which need to be flush 
        it take some time to print on console so to avoid this and watch clean write system call used. 

*/



#include <semaphore.h>
#include<pthread.h>
#include<stdio.h>
#include<string.h>
#include <unistd.h>


sem_t sem;
int sval; // save semaphore cuurent value

struct resource
{

    char buff[50];

};

struct resource buffer[3];

char * getbuff()
{
    sem_wait(&sem); // it decrement value of semaphore

    //get semaphore value after wait beacouse array start from 0th index
    //if we used before wait at first access it become buffer[3] which is not available

    sem_getvalue(&sem,&sval); // gives current value of semaphore
    
    return buffer[sval].buff; // return address of buffer pointed by which buffer is free

}

void putbuff()
{
    sem_post(&sem); //it increament value of semaphore

}

void * thread_1(void *data)
{
    char *th_buff=getbuff();       // getting the buffer i.e addr of free buffer
    
    char str[50] ="thread_1 Accesed buff\n";
    
    strcpy(th_buff,str);            // coping string to that buffer
    

    write(1,th_buff,sizeof(str));   // printing string on console using shared_reaource/buffer
    write(1,"thread_1 realised buffer...\n",29);

    sleep(2);

    putbuff();                      // relising buffer
    
}


void *thread_2(void*data)
{
    char *th_buff=getbuff();

    char str[50] ="thread_2 Accesed buff\n";
    
    strcpy(th_buff,str);

    write(1,th_buff,sizeof(str));
    write(1,"thread_2 realised buffer...\n",29);

    sleep(2);

    putbuff();
    
}


void *thread_3(void*data)
{
    char *th_buff=getbuff();
    
    char str[50] ="thread_3 Accesed buff\n";
    
    strcpy(th_buff,str);
    
    write(1,th_buff,sizeof(str));
    write(1,"thread_3 realised buffer...\n",29);

    sleep(2);

    putbuff();
    
}


void *thread_4(void*data)
{
    char *th_buff = getbuff();
    
    char str[50] ="thread_4 Accesed buff\n";
    
    strcpy(th_buff,str);

    write(1,th_buff,sizeof(str));
    write(1,"thread_4 realised buffer...\n",29);

    sleep(2);

    putbuff();
    
}


void *thread_5(void*data)
{
    char *th_buff = getbuff(); 

    char str[50] ="thread_5 Accesed buff\n";
    
    strcpy(th_buff,str);
       
    write(1,th_buff,sizeof(str));
    write(1,"thread_5 realised buffer...\n",29);

    sleep(2);

    putbuff();
    
}

int main()
{
    struct resource buffer[3];

    pthread_t td1,td2,td3,td4,td5;

    sem_init(&sem,0,3); // initial value of semaphore 3 beacouse we have 3 shared resource
    
    //creating threads

    pthread_create(&td1,NULL,thread_1,NULL); 
    pthread_create(&td2,NULL,thread_2,NULL);
    pthread_create(&td3,NULL,thread_3,NULL);
    pthread_create(&td4,NULL,thread_4,NULL);
    pthread_create(&td5,NULL,thread_5,NULL);

   
    // wait for thread to join
    pthread_join(td1,NULL);
    pthread_join(td2,NULL);
    pthread_join(td3,NULL);
    pthread_join(td4,NULL);
    pthread_join(td5,NULL);
 
    return 0;
}