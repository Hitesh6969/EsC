#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>//definiscono la struttura degli indirizzi e funzione del tipo ntohl
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>
#include <arpa/inet.h>
#define DIM 512

void EliminaCaratteriSpeciali(char str[])
{

    int i,j;
    for(i = 0, j = 0; i < strlen(str); i++)
    {
        if((str[i]>= 32 && str[i] <= 47) || (str[i]>= 58 && str[i] <= 64))
        {
            str[j] = str[i];
            j++; 
        }
    }
    str[j] = '\0';
}

int main(int argc, char*argv[])
{
    struct sockaddr_in server, client;
    int socketfd, fromlen = sizeof(client);
    char buff[DIM];

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_port = htons(atoi(argv[2]));

    socketfd = socket(AF_INET,SOCK_STREAM,0);

    bind(socketfd,(struct sockaddr*)&server,sizeof(server));
    listen(socketfd,10);

    for(;;)
    {
        int soa = accept(socketfd,(struct sockaddr*)&client,&fromlen);

        read(soa,buff,sizeof(buff));

        int pid;

        if(pid = fork() == 0)
        {

        }

    }
    
}