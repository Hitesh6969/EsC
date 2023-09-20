#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<ctype.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char*argv[])
{
    int pid,fd,p1p2[2],p2p0[2];
    char buff;

    if(argc != 2)
    {
        printf("Numero Parametri Errato");
        return -1;
    }

    pipe(p1p2);

    if(pid = fork() == 0)
    {
        close(p1p2[0]);
        close(1);
        dup(p1p2[1]);
        close(p1p2[1]);
        execl("/usr/bin/ps","ps",NULL);
        return -1;
    }

    pipe(p2p0);

    if(pid = fork() == 0)
    {
        close(p1p2[1]);
        close(0);
        dup(p1p2[0]);
        close(p1p2[0]);

        close(p2p0[0]);
        close(1);
        dup(p2p0[1]);
        close(p2p0[1]);
        execl("/usr/bin/wc","wc","-w",NULL);
        return -1;
    }

    close(p1p2[1]);
    close(p1p2[0]);
    close(p2p0[1]);

    fd = open("processi.txt", O_WRONLY | O_CREAT, 0644);

    while (read(p2p0[0],&buff,sizeof(buff)) > 0)
    {
        write(fd,&buff,sizeof(buff));
    }
    
    close(p2p0[0]);

    return 0;

}