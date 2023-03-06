#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define DIM 189819 //la parola più lunga al mondo ha 189819 caratteri

int main(char argc,char*argv[])
{
    char parola[DIM];
    int cntParole = 0;
    FILE*F1;
    F1=fopen("F1.txt", "r");
    if (F1 == NULL)
    {
        printf("Errore nell'apertura del File di testo");
    }
    while (!feof(F1))
    {
        fscanf(F1,"%s",parola);
        cntParole++;
    }
    printf("Ci sono %d parole\n", cntParole);
}