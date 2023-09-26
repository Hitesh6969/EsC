#include <stdio.h>
#include <string.h>
#include <ctype.h>

int contaVocali(const char *stringa)
{
    int count = 0;
    for (int i = 0; stringa[i] != '\0'; i++)
    {
        char carattere = tolower(stringa[i]);
        if (carattere == 'a' || carattere == 'e' || carattere == 'i' || carattere == 'o' || carattere == 'u')
        {
            count++;
        }
    }
    return count;
}

int contaConsonanti(const char *stringa)
{
    int count = 0;
    for (int i = 0; stringa[i] != '\0'; i++)
    {
        char carattere = tolower(stringa[i]);
        if (carattere >= 'a' && carattere <= 'z' && carattere != 'a' && carattere != 'e' && carattere != 'i' && carattere != 'o' && carattere != 'u')
        {
            count++;
        }
    }
    return count;
}

int contaOccorrenze(const char *stringa, char lettera)
{
    int count = 0;
    for (int i = 0; stringa[i] != '\0'; i++)
    {
        if (tolower(stringa[i]) == tolower(lettera))
        {
            count++;
        }
    }
    return count;
}

int haDoppie(const char *stringa)
{
    for (int i = 0; stringa[i] != '\0'; i++)
    {
        for (int j = i + 1; stringa[j] != '\0'; j++)
        {
            if (tolower(stringa[i]) == tolower(stringa[j]))
            {
                return 1;
            }
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Utilizzo: %s <stringa>\n", argv[0]);
        return 1;
    }

    char *stringa = argv[1];

    int vocali = contaVocali(stringa);
    int consonanti = contaConsonanti(stringa);

    printf("Numero di vocali: %d\n", vocali);
    printf("Numero di consonanti: %d\n", consonanti);

    char lettera;
    printf("Inserisci una lettera: ");
    scanf(" %c", &lettera);

    int occorrenze = contaOccorrenze(stringa, lettera);
    printf("Numero di occorrenze di %c: %d\n", lettera, occorrenze);

    if (haDoppie(stringa))
    {
        printf("La stringa contiene delle doppie.\n");
    }
    else
    {
        printf("La stringa non contiene doppie.\n");
    }

    return 0;
}
