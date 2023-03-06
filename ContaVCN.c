#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define DIM 100

int ContaConsonanti(FILE*fp, char stringa[])
{
    int consonanti = 0, i;
    fp = fopen("F2.txt","r");
    if (fp == NULL)
    {
        printf("Errore nell'apertura del File di testo");
    }
    while (!feof(fp))
    {
        fscanf(fp,"%s",stringa);
        for (i = 0; i < strlen(stringa); i++)
        {
            if (stringa[i] != 'a' && stringa[i] != 'e' && stringa[i] != 'i' && stringa[i] != 'o' && stringa[i] != 'u')
            {
                consonanti++;
            }
        }
    }
    fclose(fp);
    return consonanti;
}

int ContaVocali(FILE*fp,char stringa[])
{
    int vocali = 0, i;
    fp = fopen("F2.txt","r");
    if (fp == NULL)
    {
        printf("Errore nell'apertura del File di testo");
    }
    while (!feof(fp))
    {
        fscanf(fp,"%s",stringa);
        for (i = 0; i < strlen(stringa); i++)
        {
            if (stringa[i] == 'a' || stringa[i] == 'e' || stringa[i] == 'i' || stringa[i] == 'o' || stringa[i] == 'u')
            {
                vocali++;
            }
        }
    }
    fclose(fp);
    return vocali;
}



int ContaParole(FILE*fp, char stringa[])
{
    int cntParole = 0;
    fp = fopen("F2.txt","r");
    if (fp == NULL)
    {
        printf("Errore nell'apertura del File di testo");
    }
    while (!feof(fp))
    {
        fscanf(fp,"%s",stringa);
        cntParole++;
    }
    fclose(fp);
    return cntParole;
}

int main()
{
    FILE*fp;
    char stringa[DIM];
    printf("Il File contiene %d parole.\n", ContaParole(fp,stringa));
    printf("Il File contiene %d vocali.\n", ContaVocali(fp,stringa));
    printf("Il File contiene %d consonanti.\n", ContaConsonanti(fp,stringa));
}