#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#define MAX 81 // dimesione stringhe

int main()
{
    FILE *f1;//è un indirizzo (Dichiarazione di File)
    char P[MAX], S[MAX]; // dichiarazione di 2 stringhe
    int cont=0;
    f1=fopen("F1.txt", "r"); //fopen() per la lettura del file in modalità "r" (read)
    if (f1==NULL) // se il file non è stato trovato (non ha aperto nulla) {perchè se fopen() non riesce aprire il file ritorna NULL}
    {
        printf("Errore apertura del file!\n");
        return 0;
    }
    printf("\nParola da cercare ? ");
    scanf("%s", P);
    fscanf(f1, "%s", S); // vado a leggere dal file fscanf(FILE,"Stringa %s",S); e salvo la stringa in S lo leggo qui perche dopo vado a confrontarlo on la stringa P in while
    while (!feof(f1)) // legge fino ad arrivare alla fine del file
    {
        if (strcmp(S,P)==0)
        {
            printf("\nHo trovato %s!\n", P);
            cont++;
        }
    fscanf(f1, "%s", S); // continuo a leggere fino alla fine del file
    }
    printf("Trovata %s %d volte \n", P, cont);
    fclose(f1);
}