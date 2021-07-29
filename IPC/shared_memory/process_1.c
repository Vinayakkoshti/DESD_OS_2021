#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>   
#include<stdio.h>
#include<unistd.h>


int *count;

int main()
{
    int shmd;
    int num;
    
    shmd=shm_open("/di",O_RDWR | O_CREAT,S_IRWXU);
    ftruncate(shmd,sizeof(int));

    count=(int*)mmap(NULL,sizeof(int),PROT_READ | PROT_WRITE,MAP_SHARED,shmd,0);

   
   
    while(1)
   {
      scanf("%d",&num);
      *count=num;
   }
    return 0;
}