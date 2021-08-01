#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t id;

    id=fork();
    if(id==0)
    {
         //here if parent process finishesh 1st and child process does not finishes so child process 
        //take care by parents parent process i.e (systemd)/(init)
       
        printf("Child pid : %d\n",getpid());
        sleep(10);
        printf("..\n");
    }
    else
    {
        sleep(2);
        printf("Parent pid : %d\n",getpid());
    }

    return 0;
}