#include <stdio.h>
#include <stdlib.h>

//Vinicius Dacio

typedef struct Lista{
    int dado; //dado da lista
    struct Lista *prox; //endereco do proximo no
}lista;

lista* nova_lista(void); //Seta a lista

lista* inserir(lista *ls, int num); //Insere um no no inicio da lista

void imprime(lista *ls); //Imprime cada elemento da lista

int vazia(lista *ls); //Verifica se a lista esta vazia

lista* busca(lista *ls, int elemento); //Busca um elemento

lista* remove_elemento(lista *ls, int remover); //Remove algum elemento

lista* maior(lista* ls); //Encontra o elemento de maior valor

lista* ordem_cresc(lista *ls, int valor); //Insere um elemento ordenado
