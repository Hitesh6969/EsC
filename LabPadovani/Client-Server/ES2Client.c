
#include <arpa/inet.h> 
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

#define DIM 512
#define ServerPort 40000

int main(int argc,char* argv[])
{

    struct sockaddr_in servizio;
    int socketfd;

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(ServerPort);

    socketfd = socket(AF_INET,SOCK_STREAM,0);

    connect(socketfd,(struct sockaddr*)&servizio,sizeof(servizio));

    


}