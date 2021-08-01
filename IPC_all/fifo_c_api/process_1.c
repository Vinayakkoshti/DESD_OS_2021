#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>  
#include <sys/stat.h>

int main()
{
    int fd;
    mkfifo("vi_fifo",S_IRWXU); //if not present create fifo file with read write mode for user

    fd=open("vi_fifo",O_WRONLY);
    write(fd,"Vinayak\n",9);
    close(fd);
    return 0;

}