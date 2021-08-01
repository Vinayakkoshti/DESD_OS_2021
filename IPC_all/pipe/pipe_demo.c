#include <unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/syscall.h>

#define SIZE 64

int main()
{
    unsigned char buff[SIZE];
    unsigned char buff1[SIZE];
    int pip[2];// pipe require int array of two size one for write[1] and one for read[0]
    int pip_2[2];// for second pipe
    pid_t id;//for fork
    
    pipe(pip);//passing pip variable to create pipe 
    //pipe should create before fork coz pipe is only between relational procecess
  
    pipe(pip_2); // created second pipe
  
    id =fork();

    if(id==0) //fork return 0 for child
    {
            printf("child.\n");
            close(pip[1]); // close write end pip[1]==write
            read(pip[0],buff,SIZE);
            printf("child: msg recived from parent: %s\n",buff);
            close(pip[0]);

            //reply
            close(pip_2[0]);// close read end
            write(pip_2[1],"OK\n",4);
            close(pip_2[1]);
    }
    else
    {
        printf("Parent.\n");
        close(pip[0]);//close read end pip[0]==read end
        write(pip[1],"Vinayak\n",9);//write data in write end
        close(pip[1]);

        close(pip_2[1]);
        read(pip_2[0],buff1,SIZE);
        printf(" Parent : msg recived from child: %s\n",buff1);
        close(pip_2[0]);
    }
    return 0;
}