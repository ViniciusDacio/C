#include "mod_deque.h"

//Vinicius Dacio

Deque* cria_deque(){
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    if(dq != NULL){
        dq->ini = dq->fim = NULL;
    }
    return dq;
}

int vazio(Deque* dq){
    if(dq->ini == NULL){
        return 1;
    }
    return 0;
}
void imprime(Deque *dq){
    No *i;

    for(i = dq->ini; i != NULL; i = i->prox){
        printf("|%d| ",i->dado);
    }
    printf("\n");
}

Deque* inserir_inicio(Deque* dq, int num){
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = num;
    novo->ant = NULL;

    if(dq->ini != NULL){
        novo->prox = dq->ini;
        dq->ini->ant = novo;
        dq->ini = novo;
    }else{
        novo->prox = NULL;
        dq->ini = dq->fim = novo;
    }
    return dq;
}

Deque* inserir_fim(Deque* dq, int num){
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = num;
    novo->prox = NULL;

    if(dq->ini != NULL){
        novo->ant = dq->fim;
        dq->fim->prox = novo;
        dq->fim = novo;
    }else{
        novo->ant = NULL;
        dq->ini = dq->fim = novo;
    }
    return dq;
}

int remove_inicio(Deque* dq){
    No* i;
    No* j;

    if(vazio(dq) == 1){
        printf("Deque Vazio");
        return 0;
    }
    i = dq->ini;
    j = dq->ini->prox;
    j->ant = NULL;
    dq->ini = j;
    free(i);

    return 0;
}

int remove_fim(Deque* dq){
    No* i;
    No* j;

    if(vazio(dq) == 1){
        printf("Deque Vazio");
        return 0;
    }
    i = dq->fim;
    j = dq->fim->ant;
    j->prox = NULL;
    dq->fim = j;
    free(i);

    return 0;
}

void libera_deque(Deque* dq){
    No* i = dq->ini;
    No* j = NULL;

    while(i != NULL){
        j = i->prox;
        free(i);
        i = j;
    }
    free(dq);
}
