#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>   
#include<stdio.h>
#include<unistd.h>

#include <fcntl.h>    
#include <sys/stat.h> 
#include <semaphore.h>

int *count;

int main()
{
    int shmd;
    
    shmd=shm_open("/di",O_RDWR | O_CREAT,S_IRWXU);
    ftruncate(shmd,sizeof(int));

    count=(int*)mmap(NULL,sizeof(int),PROT_READ | PROT_WRITE,MAP_SHARED,shmd,0);
    
    while(1)
    {
        printf("DEC : %d\n",*count);
        sleep(1);
              
    }
    return 0;
}