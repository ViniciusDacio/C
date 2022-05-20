#include <stdio.h>
#include <stdlib.h>
//Algoritmos de ordenacao do Prof Joao Paulo Orlando

void imprime_lista(int v[], int tam);

int bubble_sort(int vetor[], int n);
//modificado, retorna o numero de trocas realizadas

void selection_sort(int vetor[], int n);

void insertion_sort(int vetor[], int n);

void merge(int vetor[], int comeco, int meio, int fim);

void quicksort(int vetor[], int comeco, int fim);
