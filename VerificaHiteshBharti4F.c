#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#define DIM 100

int main()
{
    FILE*fp,*fpCarSpeciali,*fpNum,*fpMin,*fpMax;
    char stringa[DIM];
    int cntParole = 0;
    fp = fopen("F1.txt","r");
    fpCarSpeciali = fopen("CaratteriSpeciali.txt","w");
    fpNum = fopen("Numeri.txt","w");
    fpMin = fopen("LettereMinuscole.txt","w");
    fpMax = fopen("LettereMaiuscole.txt","w");
    if(fp == NULL || fpCarSpeciali == NULL || fpNum == NULL || fpMin == NULL || fpMax == NULL)
    {
        printf("Errore Nell'Apertura");
        return -1;
    }
    while (!feof(fp) && cntParole < DIM)
    {
        fscanf(fp,"%s",stringa);
        for(int i = 0; i < strlen(stringa); i++)
        {
            if(stringa[i]>33 && stringa[i]< 47 || stringa[i] > 57 && stringa[i] < 64 || stringa[i] > 91 && stringa[i] < 96 || stringa[i] > 123 && stringa[i] <127)
            {
                fprintf(fpCarSpeciali,"%c\n",stringa[i]);
            }else if (stringa[i] > 47 && stringa[i] < 58)
            {
                fprintf(fpNum,"%c\n",stringa[i]);
            }else if (stringa[i] > 96 && stringa[i] < 123)
            {
                fprintf(fpMin,"%c\n",stringa[i]);
            }else if (stringa[i] > 64 && stringa[i] <91)
            {
                fprintf(fpMax,"%c\n",stringa[i]);
            }           
        }
    }
    fclose(fp);
    fclose(fpCarSpeciali);
    fclose(fpNum);
    fclose(fpMin);
    fclose(fpMax);
}