#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<ctype.h>
#include<fcntl.h>
#include<string.h>

int main(int argc,char*argv[])
{
    int p1p2[2], pid;

    pipe(p1p2);

    if(pid = fork() == 0)
    {
        close(p1p2[0]);
        close(1);
        dup(p1p2[1]);
        close(p1p2[1]);
        execl("/usr/bin/ls","ls","-l",NULL);
        return -1;
    }

    if(pid = fork() == 0)
    {
        close(p1p2[1]);
        close(0);
        dup(p1p2[0]);
        close(p1p2[0]);
        execl("/usr/bin/sort","sort","-r",NULL);
        return -1;
    }

    close(p1p2[1]);
    close(p1p2[0]);
    wait(&pid);
    wait(&pid);
    return 0;

}