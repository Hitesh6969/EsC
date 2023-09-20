#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<ctype.h>
#include<fcntl.h>
#include<string.h>

int main(int argc,char*argv[])
{
    int p1p2[2], p2p3[2],p3p0[2];
    int pid;
    double sommaMs = 0;
    char buffer[1], strMs[100], *ptr;

    pipe(p1p2);
    pid = fork();
    if(pid == 0)
    {
        close(p1p2[0]);
        close(1);
        dup(p1p2[1]);
        close(p1p2[1]);
        execl("/usr/bin/cat","cat",argv[1],NULL);
        return -1;
    }
    pipe(p2p3);
    pid =fork();
    if(pid == 0)
    {
        close(p1p2[1]);
        close(0);
        dup(p1p2[0]);
        close(p1p2[0]);

        close(p2p3[0]);
        close(1);
        dup(p2p3[1]);
        close(p2p3[1]);
        execl("/usr/bin/awk","awk","{print $4}",NULL);
        return -1;
    }

    close(p1p2[0]);
    close(p1p2[1]);

    pipe(p3p0);
    pid = fork();
    if(pid == 0)
    {
        close(p2p3[1]);
        close(0);
        dup(p2p3[0]);
        close(p2p3[0]);

        close(p3p0[0]);
        close(1);
        dup(p3p0[1]);
        close(p3p0[1]);
        execl("/usr/bin/tail","tail","-n","+2",NULL);
        return -1;
    }


    close(p2p3[0]);
    close(p2p3[1]);
    close(p3p0[1]);
    while (read(p3p0[0],&buffer,sizeof(buffer)) > 0)
    {
        strncat(strMs,&buffer[0],sizeof(buffer));
        if(buffer[0] == '\n')
        {
            printf("Tempo Parziale: %s",strMs);
            sommaMs = sommaMs + strtod(strMs,&ptr);
            strMs[0] = '\n';
        }
    }
    close(p3p0[0]);
    printf("\nTempo totale: %.2lf ms\n",sommaMs);
    return 0;
}