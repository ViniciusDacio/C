#include <stdio.h>
#include <stdlib.h>

//Vinicius Dacio

typedef struct no{
    int dado;
    struct no* prox;
    struct no* ant;
}No;

typedef struct deque{
    No* ini;
    No* fim;
}Deque;

Deque* cria_deque(); //inicializa o deque

int vazio(Deque* dq); //Verifica se o deque esta vazio

void imprime(Deque *dq); //Impreime na tela os elementos

Deque* inserir_inicio(Deque* dq, int num); //insere no inicio do deque

Deque* inserir_fim(Deque* dq, int num); //insere no final do deque

int remove_inicio(Deque* dq); //remove o elemento do inicio do deque

int remove_fim(Deque* dq); //remove o elemento do fim do deque

void libera_deque(Deque* dq); //libera cada elemento do deque da memória
