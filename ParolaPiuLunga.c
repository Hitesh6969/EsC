#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 100

int main()
{
    FILE*fp,*fpOut;
    char stringa[DIM] ,strSalvate[DIM][DIM], strFinale[DIM], strCorta[DIM];
    int indice = 0, lunghezzaStr = 0, lunghezzaStrCorta = 0;
    fp = fopen("F1.txt","r");
    if(fp == NULL)
    {
        printf("Errore nell'apertura");
        return -1;
    }
    else
    {
        while (!feof(fp) && indice < DIM)
        {
            fscanf(fp,"%s",stringa);
            strcpy(strSalvate[indice],stringa);
            indice++;
        }
        for(int i = 0; i < indice-1; i++)
        {
            if(strlen(strSalvate[i]) < strlen(strSalvate[i+1]))
            {   
                lunghezzaStr = strlen(strSalvate[i+1]);
                strcpy(strFinale, strSalvate[i+1]);
            }
            if(strlen(strSalvate[0]) > strlen(strSalvate[i+1]))
            {
                lunghezzaStrCorta = strlen(strSalvate[i]);
                strcpy(strCorta,strSalvate[i]);
            }            
        }
        fclose(fp);   
    }
    fpOut = fopen("F3.txt","w");
    if(fpOut == NULL)
    {
        printf("Errore nell'apertura");
        return -1;
    }
    else
    {
        fprintf(fpOut,"La Stringa più lunga ha %d caratteri ed è : %s\nLa String più corta ha %d caratteri ed è: %s", lunghezzaStr, strFinale,lunghezzaStrCorta,strCorta);
    }
}