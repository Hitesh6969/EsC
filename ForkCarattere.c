#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    int pid, status = 0;
    pid = fork();
    if (pid == 0)
    {
        for (int j = 1; j < argc - 1; j++)
        {
            for (int i = 0; i < strlen(argv[1]); i++)
            {
                printf("%c", toupper(argv[j][i]));
            }
            printf("\n");
        }
        exit(status);
    }
    wait(&status);
}