#include <stdio.h>
#include <stdlib.h>

void imprime(int v[]){
    for(int i = 0; i < 5; i++){
        printf("%d ", v[i]);
    }
}

void selection_sort(int vetor[], int wetor[], int n) {
  int i, j, min, aux, aux1;
  for (i = 0; i < (n-1); i++){
     min = i;
     for (j = (i+1); j < n; j++){
       if(vetor[j] < vetor[min])
         min = j;
     }
     if (i != min){
       aux = vetor[i];
       vetor[i] = vetor[min];
       vetor[min] = aux;

       aux1 = wetor[i];
       wetor[i] = wetor[min];
       wetor[min] = aux1;
     }
  }
}

void ordenacao(int v[], int i){
    for(i = 0; i < )
}







int main()
{
    int w[] = {4,3,1,2};
    int v[] = {5,4,2,3};
    //selection_sort(v,w,4);
    int vetor[] = {7,8,10,8,260,4,10,10};
    imprime(vetor);
    //printf("%d",sizeof(vetor));
    int i = 0;
    //while(i < 4){
    //    printf("%d ", w[i]);
    //    printf("%d \n", v[i]);
    //    i++; }

    return 0;
}
