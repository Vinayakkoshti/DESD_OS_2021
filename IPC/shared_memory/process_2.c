
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>   
#include<stdio.h>
#include<unistd.h>

#include <fcntl.h>    
#include <sys/stat.h> 

#include<string.h>

char *count;
unsigned char buff[64];
ssize_t readq;

int main()
{
    int shmd; //discriptor 
    
    shmd=shm_open("/vi",O_RDWR | O_CREAT,S_IRWXU);
    ftruncate(shmd,sizeof(buff));

    count=(char*)mmap(NULL,sizeof(int),PROT_READ | PROT_WRITE,MAP_SHARED,shmd,0); //map memory 
    

        printf("string : %s\n",count);
       // readq=read(shmd,buff,sizeof(buff));
        strcpy(buff,count);
    
        printf("length of msg : %ld\n",strlen(buff));

              
    return 0;
}