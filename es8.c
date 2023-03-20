#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#define DIM 50

int main(int argc,char*argv[])
{
    char stringa[DIM];
    int p1p2[2], pid;
    
    pipe(p1p2);
    pid = fork();
    if(pid == 0)
    {
        close(p1p2[0]);
        printf("inserire le stringhe\n");
        do
        {
            scanf("%s",stringa);
            strcat(stringa,"\n");
            write(p1p2[1],stringa,strlen(stringa));

        }while(strcmp(stringa,"esci\n") != 0);
        close(p1p2[1]);
        printf("Esecuzione Terminata\n");
        exit(0);
    }
    close(p1p2[1]);
    pid = fork();
    if(pid == 0)
    {
        close(0);
        dup(p1p2[0]);
        close(p1p2[0]);

        close(1);                                   // Faccio il redirect per scrivere sul file invece che a video
        open(argv[1], O_WRONLY | O_CREAT, 0677);
        execl("/usr/bin/sort","sort", NULL);        // di norma stampa a video ma ora sul file grazie al redirect
        return -1;
    }

    close(p1p2[0]);

    wait(&pid);
    wait(&pid);
    return 0;

}