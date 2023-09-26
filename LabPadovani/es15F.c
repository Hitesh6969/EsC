#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int GetMax(int Random[],int size)
{
    int min = Random[0];

    for (int i = 0; i < size; i++)
    {

        if(min < Random[i])
        {
            min = Random[i];
        }
    }

    return min;
}

int GetMin(int Random[],int size)
{
    int max = Random[0];

    for (int i = 0; i < size; i++)
    {
        if(max > Random[i])
        {
            max = Random[i];
        }
    }

    return max;
}

int main(int argc,char*argv[])
{
    int nR, size = atoi(argv[1]);
    int arrRand[size];
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        nR = rand()%100;
        arrRand[i] = nR;
    }

    printf("Elementi dell'Array\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d\n",arrRand[i]);
    }
    

    printf("Il numero più piccolo generato è %d\n",GetMin(arrRand,size));
    printf("Il numero più grande generato è %d\n",GetMax(arrRand,size));

}