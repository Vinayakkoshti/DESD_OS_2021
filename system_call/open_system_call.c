#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdlib.h>
#include<string.h>

//printf is buffered so systeam call will work untill buffer is flushed so by
// using \n in printf or using fflush function we flush buffer

int main()
{

    int fd; //file discripter gives value of file
            //0,1,2 are fixed fd for stdin,stdout and stderr 

    char buff[50];

//    write(1,buff,strlen(buff));
 //    fflush(stdout);
      printf("check");// \n to flush buufer and to print in new line

      
      
    //fd=open("vinayak.txt",O_CREAT,S_IRWXU); //create new file in current directory and RWX permission to only user.
     
      fd=open("vinayak.txt",O_RDWR);//open file in Read write mode
        
       if (fd==-1)//file discripter gives -1 if error in opening file
       {
           printf("Error in file opening");
           exit(EXIT_FAILURE);
       }
       
	printf("Enter data to store in file\n");

        int count;
       
      
      //read is system call
      count = read(0,buff,7);//read data from standard input and save to buff array
        // here 0 means stdin standard input (console)
      printf("Count : %d\n",count);//read return how many byte was readed
      
      printf("buff : %s\n",buff);//printf is library call

       //write is system call 
      write(fd,buff,strlen(buff)); // write data from buff to file which discribed by file discripter

      write(1,buff,strlen(buff));//write data on output (console) from buff 
        //here 1 means stdout standard output (console)

        close(fd);//close file discribed by file discripter
  exit(EXIT_SUCCESS);
}
