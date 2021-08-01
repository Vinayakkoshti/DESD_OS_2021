/*
    2. Open the file /usr/share/dictionary in process P1 and 
    send the strings starting with letter 'm' to process P2 using share memory.
    In process P2 find and print the length of string.
*/


#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>   
#include<stdio.h>
#include<unistd.h>

#include<string.h>


char *count;
unsigned char buff[64]="mahesh\n";

int main()
{
    char ch ;
    char buff[100];
    char str[100];

// getiing string from dictionary

    FILE *fp;
    fp =fopen("/usr/share/dict/american-english","r"); //path of dictionary
   
   while((ch=fgetc(fp))!=EOF)  //read till eof
   {
        fgets(buff,sizeof(buff),fp); // get string in buffer
    
        if(buff[0] == 'm')  //check if 1st letter is 'm' if then store in anather buff str
        {
            strcpy(str,buff);
       
        }
   }
    printf("str: %s\n",str);

// sharing with share memory

    int shmd;
    int num;
    
    shmd=shm_open("/vi",O_RDWR | O_CREAT,S_IRWXU);
    ftruncate(shmd,sizeof(buff));

    count=(char*)mmap(NULL,sizeof(buff),PROT_READ | PROT_WRITE,MAP_SHARED,shmd,0);

    strcpy(count,str);

    return 0;

}