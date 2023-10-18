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
#define SERVERPORT 1313


int main()
{
    // 1 - VARIABILI NECESSARIE PER LA CONNESSIONE

    struct sockaddr_in servizio, rem_addr;
    int socketfd, soa, fromlen = sizeof(servizio);

    // 1.5 - VARIABILI NECESSARIE PER SVOLGERE L'ESERCIZIO

    char str[DIM];
    
    // 2 - ASSEGNAZIONE DELLA FAMIGLIA, INDIRIZZO e PORTA DEL SOCKET

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);

    // 3 - CREAZIONE DELLA SOCKET

    socketfd = socket(AF_INET,SOCK_STREAM,0);

    // 4 - COLLEGO L'INDIRIZZO DELL'HOST A UN SOCKET IDENTIFIER

    bind(socketfd,(struct sockaddr *)&servizio,&fromlen);

    // 5 - SPECIFICO IL NUMERO DI CLIENT CHE POSSONO FARE RICHIESTA AL SERVER IN UNA VOLTA

    listen(socketfd,10);

    // 6 - AREA DI LAVORO

    for(;;)
    {

        printf("\nServer in ascolto...\n");
        fflush(stdout);

        // 7 - ACCETTO LA CONNESSIONE

        soa = accept(socketfd,(struct sockaddr *)&rem_addr,&fromlen);

        read(soa,str,sizeof(str));


    }

}