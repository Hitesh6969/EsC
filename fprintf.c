#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DIM 40

int main()
{
    FILE*fp,*fp2;
    char n1[DIM];
    fp = fopen("F1.txt","w");
    fp2 = fopen("F2.txt","r");

    while(!feof(fp2))
    {
        fscanf(fp2,"%s",n1);
    }
    fclose(fp2);
    if(fp != NULL)
    {
        fprintf(fp,"%s",n1);
    }
    fclose(fp);
}