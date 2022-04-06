#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    int w[] = {4,3,1,2};
    int v[] = {5,4,2,3};
    selection_sort(v,w,4);

    int i = 0;
    while(i < 4){
        printf("%d ", w[i]);
        printf("%d \n", v[i]);
        i++;
    }

    return 0;
}
