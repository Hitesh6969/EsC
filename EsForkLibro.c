#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid, uguale = 10, diversa = 10;
    printf("Prima della fork\n");
    pid = fork();
    printf("dopo la fork\n");
    if (pid == 0)
    {
        diversa = 20;
        printf("sono il processo figlio e il mio pid è : %d\n", getpid());
        printf("la variabile uguale contiene : %d\n", uguale);
        printf("la variabile diversa contiene : %d\n", diversa);
        exit(1);
    }
    else
    {
        uguale = 30;
        printf("sono il processo padre il mio pid è : %d\n", getpid());
        printf("la variabile uguale contiene : %d\n", uguale);
        printf("la variabile diversa contiene : %d\n", diversa);
    }
    return 0;
}