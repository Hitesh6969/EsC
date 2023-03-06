#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#define DIM_STRINGA 20


void LeggiStringa(char Stringa[])
{
    scanf("%s", Stringa);
}
int OnlyLetters(char Stringa[],int len)
{
    for (int i = 0; i < len; i++)
    {
        if(isdigit(Stringa[i]) > 0)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }

    
}
int ContaLettere(char Stringa[],int len)
{
    int cnt = 0;
    char car;
    scanf("%s", &car);
    for (int i = 0; i < len; i++)
    {
        if(Stringa[i] == car)
        {
            cnt++;
        }
    }
    return cnt;   
}
int ControllaDoppie(char Stringa[],int len)
{
    int cnt = 0;
    for (int i = 0; i < len - 1; i++)
    {
        if(Stringa[i] == Stringa[i+1])
        {
            cnt++;
        }
    }
    return cnt;
}
//NON VA
/*char carPari(char Stringa[], char sPari[], int len)
{
    for (int i = 0; i < len - 2; i = i+2)
    {
        Stringa[i] = sPari[i];
    }
}*/
int main()
{
    int cntLettere;
    char stringa[DIM_STRINGA], sPari[DIM_STRINGA],sDispari[DIM_STRINGA];
    printf("Inserire la Stringa\n");
    LeggiStringa(stringa);
    int len = strlen(stringa), cRep, nDoppie;
    /*for(int i = 0; i < len; i++)
    {
        if(isdigit(stringa[i]) > 0)
        {
            printf("Stringa Deve Contenere solo lettere!\n");
            return -1;
        }
    }*/
    printf("Inserire il Carattere che si vuole controllare\n");
    cRep = ContaLettere(stringa,len);
    printf("Il Carattere inserito si ripete %d volta/e.\n", cRep);
    nDoppie = ControllaDoppie(stringa,len);
    printf("la parola contiene %d doppia/e.\n", nDoppie);
    if(cntLettere = OnlyLetters(stringa,len) == 1)
    {
        printf("La stringa non contiene sono caratteri");
    }
    else
    {
        printf("La stringa contiene solo lettere\n");
    }
    /*carPari(stringa,sPari,len);
    printf("i caratteri alla posizione pari sono: %s", sPari);*/
}