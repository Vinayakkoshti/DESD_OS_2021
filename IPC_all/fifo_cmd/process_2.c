#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define SIZE 64

int main()
{
    int fd;
    unsigned char buff[SIZE];
    fd=open("vi_fifo",O_RDONLY);
    read(fd,buff,SIZE);
    printf("MSG: %s\n",buff);
    close(fd);
    return 0;

}