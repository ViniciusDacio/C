#include "mod_algoritimos_ordenacao.h"
//Algoritmos de ordenacao do Prof Joao Paulo Orlando

void imprime_lista(int v[], int tam){

    for(int i = 0; i < tam; i++)
        printf("%d ", v[i]);
}

int bubble_sort(int vetor[], int n) {
    int k, j, aux;
    int cont = 0;

    for (k = 1; k < n; k++) {
        for (j = 0; j < n - 1; j++) {

            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
                cont++;
            }
        }
    }
    return cont;
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

//-------------------- Grafos --------------------//

tipo_grafo *criaGrafo(int nVert){

    int i, j;

    tipo_grafo *G = malloc(sizeof(tipo_grafo));
    G->numVertice = nVert;

    G->matriz_adj = (int**) malloc(nVert*sizeof(int *));

    for (i = 0; i < nVert; i++)
        G->matriz_adj[i] = (int *) malloc(nVert*sizeof(int));

    for (i = 0; i < nVert; i++)
        for (j = 0; j < nVert; j++)
            G->matriz_adj[i][j] = 0;

    return G;
}

void addAresta(tipo_grafo *G, int origem, int destino){
    G->matriz_adj[origem][destino] = 1;
    G->matriz_adj[destino][origem] = 1;
}

void removeAresta(tipo_grafo *G, int origem, int destino){
    G->matriz_adj[origem][destino] = 0;
    G->matriz_adj[destino][origem] = 0;
}

void mostra_grafo(tipo_grafo *G){
    int i, j;

    printf("\n Mostrando a matriz de adj do grafo\n   ");

    for (i = 0; i< G->numVertice; i++)
        printf("%d ", i);
    printf("\n");

    for (i = 0; i< G->numVertice; i++){
        printf("%d ", i);
        for (j = 0; j< G->numVertice; j++)
            printf(" %d", G->matriz_adj[i][j]);

        printf("\n");
    }
}

tipo_grafo *liberaGrafo(tipo_grafo *G){
    if (G){
        for (int i = 0; i < G->numVertice; i++)
            free(G->matriz_adj[i]);
        free(G->matriz_adj);

        free(G);
    }
    return NULL;
}

