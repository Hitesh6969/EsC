#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stampa(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        printf("%d\n", atoi(argv[i]));
    }
}
int SommaMedia(int argc, char *argv[])
{
    int somma;
    double media;
    for (int i = 1; i < argc; i++)
    {
        somma = somma + atoi(argv[i]);
    }
    media = somma / argc;
    printf("la somma è : %d", somma);
    printf("la media è : %f", media);
}

void StampaInversa(int argc, char *argv[])
{
    for (int i = argc; i >= 1; i--)
    {
        printf("%d", atoi(argv[i]));
    }
}
void StampaPari(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        if (atoi(argv[i]) % 2 == 0)
        {
            printf("%d", atoi(argv[i]));
        }
    }
}
void StampaDispari(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        if (atoi(argv[i]) % 2 != 0)
        {
            printf("%d", atoi(argv[i]));
        }
    }
}
void Ricerca(int argc, char *argv[])
{
    int nCercato;
    scanf("%d", &nCercato);

    for (int i = 0; i < argc; i++)
    {
        if (nCercato == atoi(argv[i]))
        {
            printf("%d", atoi(argv[i]));
        }
    }
}
void EliminaElemento(int argc, char *argv[])
{
    int Eliminare;
    scanf("%d", &Eliminare);

    for (int i = 1; i < argc; i++)
    {
        if (atoi(argv[i]) == Eliminare)
        {
            argv[i] = argv[i - 1];
        }
        printf("%d", atoi(argv[i]));
    }
}
void Ordina(int argc,char*argv[])
{
    char*tmp;
    for(int i=0; i < argc - 1;i++)
    {
        for (int j = 0; j < argc -1 -i; i++)
        {
            if(atoi(argv[i]) > atoi(argv[j]))
            {
                tmp = argv[i];
                argv[i] = argv[j];
                argv[j] = tmp;
            }
        }
    }
    stampa(argc,argv);
}
void Alterna()
{
}

int main(int argc, char *argv[])
{
    int somma = 0;
    int media;
    int scelta;
    printf("GESTIONE VETTORE\n1)Stampa Elementi\n2)Inverti Elementi\n3)Somma e Media degli elementi\n4)Stampa Numeri Pari\n5)Stampa Numeri Dispari\n6)Ricerca Elemento\n7)Elimina Elemento\n8)Swap\n9)Ordina Elementi");
    scanf("%d", &scelta);
    do
    {
        switch (scelta)
        {
        case 1:
            stampa(argc, argv);
            break;
        case 2:
            StampaInversa(argc, argv);
            break;
        case 3:
            SommaMedia(argc, argv);
            break;
        case 4:
            StampaPari(argc, argv);
            break;
        case 5:
            StampaDispari(argc, argv);
            break;
        case 6:
            Ricerca(argc, argv);
            break;
        case 7:
            EliminaElemento(argc, argv);
            break;
        case 8:
            Ordina(argc,argv);
            break;
        case 9:

            break;
        default:
            break;
        }
    } while (scelta < 1 || scelta > 9);
}
