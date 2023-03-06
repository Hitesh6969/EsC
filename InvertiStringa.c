//Inserita una stringa invertirla e stamparla in output


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void leggi (char str1[100])
{ 
    printf("Inserisci una stringa: \n");
    scanf("%s", str1); //%d per INT, %s per STRING, %c per CHAR, %f per FLOAT
}

int lunga  (char str1[100]) //è int e non void pk deve restituire la lunghezza della stringa letta
{
    int l;
    l = strlen(str1); //strlen() restitusce la lunghezza della stringa
    return l;
}    


void inverti (int lung1,char str1[100]) //passo come parametri la stringa e la sua lunghezza. Si poteva anche fare String come Void
{
    int i,k; //servono per ciclo for
    char temp; //server per fare lo scambio
    k=lung1; //assegno la lunghezza della Stringa a k
     for (i = 0; i < lung1/2; i++) { // mi scansiona la lunghezza per metà se non divido mi stampa 2 volte la stessa stringa
        temp=str1[i];
        str1[i]=str1[k-1];
        str1[k-1]=temp;
        k--; // bisogna decrementare manualmente per scorrere all'indietro la stringa
     }
  printf("La stringa invertita e': %s \n",str1);
}  


    
int main()
{ 
  char str[100],let;
  int lung; // mi restituisce la lunghezza della stringa inserita;
  leggi(str);
  lung=lunga(str);
  printf("La stringa e': %s \n",str);
  printf("\n");
  printf("ed e' lunga : %d \n",lung);
  printf("\n");
  inverti(lung,str);
  
  
  return 0;
  
}
  
