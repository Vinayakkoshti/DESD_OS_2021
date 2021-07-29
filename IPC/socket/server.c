#include<stdio.h>

#include <sys/types.h> 
#include <sys/socket.h>
#include <unistd.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#include <linux/in.h>


#define SIZE 100

struct sockaddr_in server_detail;
struct sockaddr_in client_detail;

int server_fd;
int client_fd;
int len;
unsigned char buff[SIZE];
int main()
{
    //create socket to use over network and for tcp protocal
    server_fd = socket(AF_INET,SOCK_STREAM,0); //retruns fd 


    //server details
    server_detail.sin_family = AF_INET;//tails network
    server_detail.sin_addr.s_addr = inet_addr("127.0.0.1");//use ip or host (command namap localhost)
    server_detail.sin_port = htons(6000);//use between 5000 to 9000 coz 0-1000 reserved


    //bind server details to server i.e which port and ip
    bind(server_fd,(struct sockaddr *)&server_detail,sizeof(struct sockaddr_in));

    listen(server_fd,10); //allocates 10 resources

    len = sizeof(struct sockaddr_in);

    //accept client and  create fd of client  

    client_fd = accept(server_fd,(struct sockaddr *) &client_detail,&len); 
    //it like scanf it block or wait  till client not make connection and give detail


    write(client_fd,"Hi Vinayak this is server...\n",30);
    read(client_fd,buff,SIZE);
    printf("MSG : %s\n",buff);

    close(client_fd);
    close(server_fd);
    return 0;

}
