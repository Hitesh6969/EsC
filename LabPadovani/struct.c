#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define DIM 50


struct Auto
{
    char modelloAuto[DIM], marca[DIM];
    float prezzo, cilindrata;
    int AnnoImm;
    
};

struct Auto PrezzoPiuBasso(struct Auto ShowRoom[],int N)
{
    struct Auto AutoDaPoveri = ShowRoom[0];
    
    for(int i = 0; i < N; i++)
    {
        if(ShowRoom[i].prezzo < AutoDaPoveri.prezzo)
        {
            AutoDaPoveri = ShowRoom[i];
        }
    }
    return AutoDaPoveri;
}

struct Auto PrezzoPiuAlto(struct Auto ShowRoom[],int N)
{
    struct Auto AutoPiuCostosa = ShowRoom[0];
    
    for(int i = 0; i < N; i++)
    {
        if(ShowRoom[i].prezzo > AutoPiuCostosa.prezzo)
        {
            AutoPiuCostosa = ShowRoom[i];
        }
    }
    return AutoPiuCostosa;
}

int main()
{
    int N;

    printf("Inserire il numero delle auto");
    scanf("%d",&N);

    struct Auto ShowRoom[N];
    for(int i = 0; i < N; i++)
    {
        
        printf("Auto n°%d\n",i+1);
        printf("Inserire il modello dell'auto\n");
        scanf("%s",ShowRoom[i].modelloAuto);
        printf("Inserire la marca dell'auto\n");
        scanf("%s",ShowRoom[i].marca);
        printf("Inserire il prezzo dell'auto\n");
        scanf("%f",&ShowRoom[i].prezzo);
        printf("Inserire la cilindrata dell'auto\n");
        scanf("%f",&ShowRoom[i].cilindrata);
        printf("Inserire l'anno di immatricolazione dell'auto\n");
        scanf("%d",&ShowRoom[i].AnnoImm);
    }
    printf("La Auto più costosa è %s e costa: %.2f\n",PrezzoPiuAlto(ShowRoom,N).modelloAuto,PrezzoPiuAlto(ShowRoom,N).prezzo);
    printf("La Auto più costosa è %s e costa: %.2f",PrezzoPiuBasso(ShowRoom,N).modelloAuto,PrezzoPiuBasso(ShowRoom,N).prezzo);

}