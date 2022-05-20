#include <stdio.h>
#include <stdlib.h>
//Algoritmos de ordenacao do Prof Joao Paulo Orlando

typedef struct grafo{
    int numVertice;
    int **matriz_adj;

}tipo_grafo;

tipo_grafo *criaGrafo(int nVert);

void addAresta(tipo_grafo *G, int origem, int destino);

void removeAresta(tipo_grafo *G, int origem, int destino);

void mostra_grafo(tipo_grafo *G);

tipo_grafo *liberaGrafo(tipo_grafo *G);

void imprime_lista(int v[], int tam);

int bubble_sort(int vetor[], int n);
//modificado, retorna o numero de trocas realizadas

void selection_sort(int vetor[], int n);

void insertion_sort(int vetor[], int n);

void merge(int vetor[], int comeco, int meio, int fim);

void quicksort(int vetor[], int comeco, int fim);
