#include <stdio.h>
#include <stdlib.h>

//Vinicius Dacio

typedef struct Pilha{
    int dado;
    struct Pilha *prox;
}pilha;

pilha* nova_pilha(void); //retorna NULL

int vazia(pilha* p); //Verifica se a pilha esta vazia

pilha* push(pilha *p, int num); //Inserer no inicio da pilha

void imprime(pilha* p); //Imprime cada um dos elementos

pilha* pop(pilha* p); //Remove o primeiro item da pilha

void libera(pilha* p); //Libera a pilha
