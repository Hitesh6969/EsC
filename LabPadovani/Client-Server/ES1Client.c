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

#define DIM 512
#define SERVERPORT 1313

int main(int argc,char* argv[])
{

    // 1 - DICHIARO VARIABILI NECESSARIE PER IL SOCKET

    struct sockaddr_in servizio;
    int socketfd;

    // 2 - ASSEGNAZIONE DELLA FAMIGLIA, IP e PORTA AL SOCKET DEL CLIENT

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);

    // 3 - CREAZIONE SOCKET

    socketfd = socket(AF_INET,SOCK_STREAM,0);

    // 4 - CONNETTO AL SERVER

    connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));

    // 5 - AREA DI LAVORO

    write(socketfd,argv[2],strlen(argv[2]));

    // 6 - QUANDO FINITO DI SCRIVERE SUL SOCKET LO CHIUDO

    close(socketfd);

    return 0;
}
