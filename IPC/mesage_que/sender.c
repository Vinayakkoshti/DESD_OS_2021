#include<stdio.h>
#include <fcntl.h>   
#include <sys/stat.h>
#include <mqueue.h>

mqd_t mq_fd; //message que discriptor
 
 struct mq_attr mq; //attributes

 int main ()
 {
     mq.mq_maxmsg = 4; // max 4 msg
     mq.mq_flags = 0;
     mq.mq_msgsize = 128; //max length of msg
     mq.mq_curmsgs = 0;

     mq_fd = mq_open("/vi",O_CREAT | O_RDWR, S_IRUSR | S_IWUSR,&mq);

     mq_send(mq_fd,"Hello Vinayak\n",15,0);
     
     mq_close(mq_fd);



     return 0;
 }