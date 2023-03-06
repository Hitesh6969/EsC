#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define DIM 20


int ContaParoleF2(FILE*fp, char stringa[])
{
    int cnt = 0;
    fp = fopen("F2.txt","r");
    if (fp == NULL)
    {
        printf("Errore");
        return -1;
    }
    else
    {
        while (!feof(fp))
        {
            fscanf(fp, "%s",stringa);
            cnt++;
        }
    }
    fclose(fp);
    return cnt;
}

int ContaParoleF1(FILE*fp, char stringa[])
{
    int cnt = 0;
    fp = fopen("F1.txt","r");
    if (fp == NULL)
    {
        printf("Errore");
        return -1;
    }
    else
    {
        while (!feof(fp))
        {
            fscanf(fp, "%s",stringa);
            cnt++;
        }
    }
    fclose(fp);
    return cnt;
}

void Comuni(FILE*fp,FILE*fp2,FILE*fp3)
{
    char P[DIM], S[DIM];
    int trovato = 0, cont = 0;
    fp = fopen("F1.txt", "r");
    fp2 = fopen("F2.txt","r");
    fp3 = fopen("F3.txt","w");
    while (!feof(fp))
    {
        fscanf(fp,"%s",P);
        rewind(fp2);
        trovato = 0;
        while (!feof(fp2))
        {
            fscanf(fp2,"%s",S);
            if(strcmp(P,S) == 0 && !trovato)
            {
                cont++;
                trovato=1;
            }
        }
        
    }
    printf("Le stringhe uguali sono: %d\n",cont);
    fprintf(fp3,"Le stringhe uguali sono: %d\n",cont);
    fclose(fp);
    fclose(fp2);
    fclose(fp3);
}

int main()
{
    FILE*fp,*fp2,*fp3;
    int paroleFp, paroleFp2, cnt;
    char stringafp[DIM], stringafp2[DIM];
    paroleFp = ContaParoleF1(fp,stringafp);
    paroleFp2 = ContaParoleF2(fp2, stringafp2);
    Comuni(fp,fp2,fp3);
}