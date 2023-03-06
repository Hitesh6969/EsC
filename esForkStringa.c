#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define BUFSIZE 100

int main(void) {
    int fd[2];
    pid_t pid;
    char buf[BUFSIZE];

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        close(fd[0]);
        printf("Figlio: invio la stringa 'ciao' al padre\n");
        write(fd[1], "ciao", strlen("ciao") + 1);
        close(fd[1]);
        exit(EXIT_SUCCESS);
    } else {
        close(fd[1]);
        wait(NULL);
        read(fd[0], buf, BUFSIZE);
        printf("Padre: ho ricevuto la stringa '%s' dal figlio\n", buf);
        close(fd[0]);
        exit(EXIT_SUCCESS);
    }

    return 0;
}
