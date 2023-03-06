#include <stdio.h>
#include <string.h>
#define DIM 100

/*Scrittura di 2 valori di 2 variabili dentro un file*/

int main()
{
    FILE*fp;
    int var1 = 3, Var2 = 2, Var3 = 7;
    fp = fopen("F1.txt","w");
    fprintf(fp,"%d %d",var1,Var2);
    fclose(fp);
    fp = fopen("F1.txt","a");
    fprintf(fp," %d",Var3);
    return 0;
}