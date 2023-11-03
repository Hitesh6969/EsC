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

int main(int argc, char*argv[])
{
    struct sockaddr_in servizio;
    int socketfd, fromlen = sizeof(servizio);
    
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = inet_addr(argv[1]);
    servizio.sin_port = htons(atoi(argv[2]));

    socketfd = socket(AF_INET,SOCK_STREAM,0);

    connect(socketfd,(struct sockaddr*)&servizio,fromlen);

    write(socketfd,argv[3],sizeof(argv[3]));

    

}