#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid;
    printf("1) prima della fork \n");
    pid = fork(); // creo processo figlio
    printf(" 2) dopo della fork \n");
    if (pid == 0)
    {
        printf(" 3) sono il processo figlio e il mio PID è %d\n", getpid());
        sleep(3);
        printf(" il pid del mio padre è %d\n", getppid());
        exit(1); // termina il processo figlio
    }
    else
    {      
        printf(" 3) sono il processo padre e il mio pid è %d\n",getpid());
        exit(0); // non necessaria
    }
}
