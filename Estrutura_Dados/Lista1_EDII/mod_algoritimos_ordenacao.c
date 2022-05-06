#include "mod_algoritimos_ordenacao.h"

void imprime_lista(int v[], int tam){

    for(int i = 0; i < tam; i++)
        printf("%d ", v[i]);
}

void bubble_sort (int vetor[], int n) {
    int k, j, aux;

    for (k = 1; k < n; k++) {
        for (j = 0; j < n - 1; j++) {

            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void selection_sort(int vetor[], int n) {
  int i, j, min, aux;
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
     }
  }
}

void insertion_sort(int vetor[], int n){
    int i, chave, j;
    for (i = 1; i < n; i++){
        chave = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > chave){
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

void merge(int vetor[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }

    free(vetAux);
}

void mergeSort(int vetor[], int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

void quicksort(int vetor[], int comeco, int fim){
    int i, j, pivo, aux;
    i = comeco;
    j = fim-1;
    pivo = vetor[(comeco + fim) / 2];
    while(i <= j)    {
        while(vetor[i] < pivo && i < fim){
            i++;
        }
        while(vetor[j] > pivo && j > comeco)     {
            j--;
        }
        if(i <= j)
        {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }
    }
    if(j > comeco)
        quicksort(vetor, comeco, j+1);
    if(i < fim)
        quicksort(vetor, i, fim);
}
