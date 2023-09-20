#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc,char*argv[])
{
    int pid,p1p2[2];
    pipe(p1p2);
    pid = fork();
    if(pid == 0)
    {
        close(p1p2[0]);
        close(1);
        dup(p1p2[1]);
        close(p1p2[1]);
        execl("/bin/ls","ls",NULL);
        return -1;
    }
    pid = fork();
    if(pid == 0)
    {
        close(p1p2[0]);
        close(1);
        dup(p1p2[1]);
        close(p1p2[1]);
        execl("/bin/tee","tee",argv[2],NULL);
        return -1;
    }
    close(p1p2[1]);
    close(p1p2[0]);
    return 0;
}