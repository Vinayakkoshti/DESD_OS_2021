#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t ID,PID;
    PID=getpid();
    printf("Process ID : %d\n",getpid());
    ID=fork();
    if(PID==getpid())
    {
    printf("parent ID : %d\n",getpid());
    }
    else if (ID==0)
    {
        printf("Child ID :%d\n",ID);
        printf("Process ID : %d\n",getpid());
    }

        return 0;
}