#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/fcntl.h>
#include <ctype.h>

int main(int argc, char *argv[])
{

    int pid, status = 0;

    pid = fork();

    if (pid == 0)
    {
        printf("Sono il processo figlio con pid %d\n", getpid());
        printf("il mio papi ha pid %d\n", getppid());
        exit(1);
    }
    else
    {
        printf("Sono il processo padre con pid %d\n", getpid());
        printf(" L'exit di mio figlio (%d) e' %d\n",wait(&pid),status);
        //printf(" L'exit di mio figlio (%d) e' %d", wait(&status), status);
        
        return 0;
    }
}