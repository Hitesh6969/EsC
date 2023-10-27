#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>  // per open() e O_RDONLY

#define BUFFER_SIZE 100

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];
    int file_fd; // Descrittore di file per il file di input
    int nread;

    if (argc != 5) {
        printf("Uso: %s <percorso_file> <stringa_di_ricerca> <indirizzo_ip> <porta>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Impossibile creare il socket.\n");
        exit(1);
    }
    
    memset((char *)&server, 0, sizeof(server));

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[3]);
    server.sin_port = htons(atoi(argv[4]));

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Errore nella connessione al server.\n");
        exit(1);
    }

    int pid = fork();

    if(pid == 0)
    {
        close(1);
        dup(sock);
        close(sock);
        execl("/usr/bin/cat","cat",argv[1],NULL);
        return -1;
    }
    wait(&pid);
    // Invia la stringa di ricerca al server


    // Apri il file in modalità di sola lettura

    // Invia il contenuto del file al server usando read()
    close(sock);
    return 0;
}
