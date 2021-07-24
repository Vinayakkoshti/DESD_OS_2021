#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t PID;
    pid_t PPID;

    printf("PID : %d\n",getpid());
    printf("PPID : %d\n",getppid());
    return 0;
}