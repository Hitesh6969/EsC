#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define DIM 20

int main()
{
    int fd, nread, nwrite, i;
    char buf[DIM];
    fd = open("F1.txt", O_RDWR);
    if (fd == -1)
    {
        printf("errore nell'apertura del file");
        return -1;
    }
    else
    {
        printf("Scrivi una parola\n");
        scanf("%s", buf);
        nwrite = write(fd, buf,strlen(buf));
        printf("%d\n", nwrite);
        i = close(fd);
    }
}