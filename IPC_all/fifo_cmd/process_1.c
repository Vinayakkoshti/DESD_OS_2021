#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    fd=open("vi_fifo",O_WRONLY);
    write(fd,"Vinayak\n",9);
    close(fd);
    return 0;

}