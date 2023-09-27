#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#define MAX 100 // dimesione stringhe

int main()
{
    FILE *f1;
    char P[MAX], S[MAX];
    int cont=0;
    f1=fopen("file.txt", "r");
    if (f1==NULL)
    {
        printf("Errore apertura del file!\n");
        return 0;
    }
    printf("\nParola da cercare ? ");
    scanf("%s", P);
    fscanf(f1, "%s", S); 
    while (!feof(f1))
    {
        if (strcmp(S,P)==0)
        {
            printf("\nHo trovato %s!\n", P);
            cont++;
        }
    fscanf(f1, "%s", S);
    }
    printf("Trovata %s %d volte \n", P, cont);
    fclose(f1);
}