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
#define Server_Port 40000

int main(int argc, char*argv[])
{
    struct sockaddr_in server,client;
    int socketfd, soa, fromlen = sizeof(client);
    char car,result[DIM];

    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(argv[1]);

    socketfd = socket(AF_INET,SOCK_STREAM,0);
    
    bind(socketfd,(struct sockaddr*)&server, sizeof(server));

    listen(socketfd,10);

    for(;;)
    {

        printf("Server è in ascolto...\n");
        fflush(stdout);

        soa = accept(socketfd,(struct sockaddr*)&client, &fromlen);
        read(soa,&car,sizeof(car));

        printf("il Carattere Ricevuto è: %s\n", &car);
        sprintf(result,"il Carattere Ricevuto è: %s\n",&car);
        write(soa,result,strlen(result));

        close(soa);
    }
    close(socketfd);
}