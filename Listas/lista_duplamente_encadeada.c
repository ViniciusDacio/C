#include <stdio.h>
#include <stdlib.h>

//Vinicius Dacio

typedef struct ListaDupla{
    int dado;
    struct ListaDupla *prox;
    struct ListaDupla *ant;
}listaD;

listaD* nova_lista(void){
    return NULL;
}

listaD* insere(listaD* ls, int num){
    listaD* novo = (listaD*)malloc(sizeof(listaD));
    novo->dado = num;
    novo->prox = ls;
    novo->ant = NULL;

    if(ls != NULL){
        ls->ant = novo;
    }
    return novo;
}

void imprime_frente(listaD *ls){
    listaD *i = ls;

    while(i!=NULL){
        printf("|%d| ",i->dado);
        i = i->prox;
    }
    printf("\n");
}

void imprime_tras(listaD* ls){
    listaD *j = ls;
    listaD *i;

    while(j != NULL){
        if(j->prox == NULL){
            i = j;
            while(i != NULL){
                printf("|%d| ",i->dado);
                i = i->ant;
            }
        }
        j = j->prox;
    }
    printf("\n");
}

listaD* busca(listaD *ls, int elemento){
    listaD *i = ls;

    while(i != NULL){
        if(i->dado == elemento){
            return i;
        }
        i=i->prox;
    }
}

int vazia(listaD *ls){
    if(ls == NULL){
        printf("Lista vazia\n");
    }else{
    return 0;
    }
}

void libera(listaD* ls){
    listaD *j = ls;
    listaD *next = NULL;

    while(j != NULL){
        next = j->prox;
        free(j);
        j = next;
    }
}
listaD* maior(listaD* ls){
    listaD *i = ls->prox;
    listaD *g = ls;
    int maior = ls->dado;

    while(i != NULL){
        if(i->dado > maior){
            maior = i->dado;
            g = i;
        }
        i = i->prox;
    }
    return g;
}
listaD* menor_num(listaD *ls){
    listaD *i = ls->prox;
    listaD *h = ls;
    int menor = ls->dado;

    while(i != NULL){
        if(i->dado < menor){
            menor = i->dado;
            h = i;
        }
        i = i->prox;
    }
    return h;
}
listaD* ordenado(listaD *ls, int valor){
    listaD *i = ls;
    listaD *atual = NULL;
    listaD *num = maior(ls);
    listaD *menor = menor_num(ls);

    listaD *novo = (listaD*)malloc(sizeof(listaD*));
    novo->dado = valor;

    if(valor >= num->dado && (num->ant == NULL || num->prox == NULL)){
        if(num->prox == NULL){
            num->prox = novo;
            novo->ant = num;
            novo->prox = NULL;
            return ls;
        }else{
            ls = insere(ls, valor);
            return ls;
        }
    }
    while(i != NULL){
        atual = i;
        i = i->prox;

        if(i->dado >= valor && atual->dado <= valor){
            atual->prox = novo;
            novo->prox = i;
            return ls;
        }
        if(i->dado <= valor && atual->dado >= valor){
            atual->prox = novo;
            novo->prox = i;
            return ls;
        }
    }
}

int main(){
    listaD *l, *procura;
    l = nova_lista();
    l = insere(l,5);
    l = insere(l,3);
    l = insere(l,2);
    l = insere(l,7);
    imprime_frente(l);
    l = ordenado(l, 1);
    imprime_frente(l);

    return 0;
}
