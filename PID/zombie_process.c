#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t id;

    id=fork();
    if(id==0)
    {
        
        printf("Child pid : %d\n",getpid());
    }
    else
    {
        //here if child process finishesh 1st and parents process does not finishes so parent process become
        //in zombie state command to check :  ps -el |  zom 
        
        sleep(6); 
        printf("Parent pid : %d\n",getpid());
    }

    return 0;
}