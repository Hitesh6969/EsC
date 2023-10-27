#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define BUFFER_SIZE 100

int main() {
    
    struct sockaddr_in server, client;
    int socketfd, soa,fromlen = sizeof(server);
    char buffer[BUFFER_SIZE];
    char search_string[BUFFER_SIZE] = "allontano";
    int fd[2];
    int c;
    
    memset((char *)&server, 0, sizeof(server));


    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(40000);

    bind(socketfd, (struct sockaddr *)&server, sizeof(server));
    listen(socketfd, 3);

    while(1) {
      
        soa = accept(socketfd, (struct sockaddr *)&client, &fromlen);

        if (fork() == 0) {
            close(socketfd);

            // Leggi la stringa di ricerca dal client
            read(soa, search_string, sizeof(search_string));


            // Usa pipe, grep e wc per contare le occorrenze
            pipe(fd);
            if (fork() == 0) {
                close(fd[0]);
                close(1);
                dup(fd[1]);
                close(fd[1]);
                execl("/bin/grep", "grep", "-o", search_string, "temp.txt", NULL);
                return -1;
            }

            close(fd[1]);
            close(0);
            dup(fd[0]);
            close(fd[0]);
            execl("/usr/bin/wc", "wc", "-l", NULL);
            return -1;
        }
        close(soa);
    }
    return 0;
}