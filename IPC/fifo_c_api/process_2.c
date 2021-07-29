#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>


#define SIZE 64

int main()
{
    int fd;
    unsigned char buff[SIZE];
    
    mkfifo("vi_fifo",S_IRWXU);//if not present create fifo file with read write mode for user
    
    fd=open("vi_fifo",O_RDONLY);
    read(fd,buff,SIZE);
    printf("MSG: %s\n",buff);
    close(fd);
    return 0;

}