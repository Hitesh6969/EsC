#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#define DIM 100

int main()
{
    int pid, p1p0[2],p0p1[2],cnt = 0, nLetti, numero;
    int somma = 0;
    double media = 0.0;
    char numeri[DIM];

    pipe(p1p0);
    if(pid = fork() == 0)
    {
        close(p1p0[1]);
        printf("Inserire i numeri");
        do
        {
            numero = atoi(scanf("%d", numeri[cnt]));
            cnt++;
        }while (nLetti != 0);
        exit(0);
    }
    close(p1p0[1]);
    close(p1p0[0]);

    for (int i = 0; i < cnt; i++)
    {
        somma = somma + atoi(numeri[i]);
    }
    media = somma / cnt;
    printf("Somma: %d",somma);
    printf("Media: %f",media);
}