#include "mod_pilha.h"

//Vinicius Dacio

pilha* nova_pilha(void){
    return NULL;
}

int vazia(pilha* p){
    if(p == NULL){
        printf("Pilha esta vazia\n");
    }else{
        return 0;
    }
}

pilha* push(pilha *p, int num){
    pilha *novo_no = (pilha*)malloc(sizeof(pilha));
    novo_no->dado = num;

    if(p == NULL){
        p = novo_no;
        novo_no->prox = NULL;
    }else{
        novo_no->prox = p;
        p = novo_no;
    }
}

void imprime(pilha* p){
    pilha *i = p;
    if(p == NULL){
        printf("Pilha esta vazia\n");
    }
    while(i != NULL){
        printf("|%d| ", i->dado);
        i = i->prox;
    }
    printf("\n");
    free(i);
}

pilha* pop(pilha* p){

    if(p != NULL){
        pilha *aux = p->prox;
        free(p);
        p = aux;
        if(p == NULL){
            printf("A pilha agora esta vazia\n");
        }
    }else{
        printf("Pilha Vazia\n");
    }
    return p;
}

void libera(pilha* p){
    pilha *j = p;
    pilha *next = NULL;

    while(j != NULL){
        next = j->prox;
        free(j);
        j = next;
    }
}
