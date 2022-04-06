#include "mod_lista_encadeada.h"

//Vinicius Dacio

lista* nova_lista(void){
    return NULL;
}

lista* inserir(lista *ls, int num){
    lista *novo_elemento = (lista*)malloc(sizeof(lista)); //cria um novo de elemento
    novo_elemento->dado=num; //dado dentro de elemento recebe o valor de num

    if(ls == NULL){
        ls = novo_elemento; // se lista vazia ela recebe a struct passada por ls
        novo_elemento->prox = NULL; // define o valor de 'prox' dentro do novo elemento fim da lista;
    }
    else{
        novo_elemento->prox = ls; //Se a lista já tiver elementos, pega o endereco atual e aponta como o proximo, ou seja, adiciona no inicio da lista.
        ls = novo_elemento; // insere ele na lista
    }
}

void imprime(lista *ls){
    lista *i = ls;

    while(i!=NULL){
        printf("|%d| ",i->dado);
        i = i->prox;
    }
    printf("\n");
    free(i);
}

int vazia(lista *ls){
    if(ls == NULL){
        printf("A lista esta vazia\n");
    }else{
    return 0;
    }
}

lista* busca(lista *ls, int elemento){
    lista *i = ls;

    while(i != NULL){
        if(i->dado == elemento){
            return i;
        }
        i=i->prox;
    }
    free(i);
}

lista* remove_elemento(lista *ls, int remover){
    lista *i = ls;
    lista *dell = NULL;


    while(i != NULL && i->dado != remover){
        dell = i;
        i=i->prox;
    }
    if(i == NULL){
        printf("\nElemento nao encontrado\n");
        return ls;
    }
    if(dell == NULL){
        ls = i->prox;
    }else{
        dell->prox = i->prox;
    }
    free(i);
    return ls;

}

lista* maior(lista* ls){
    lista *i = ls->prox;
    lista *g = ls;
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

lista* ordem_cresc(lista *ls, int valor){
    lista *i = ls;
    lista *ant = NULL;
    lista *num = maior(ls);

    lista *novo_elemento = (lista*)malloc(sizeof(lista));
    novo_elemento->dado=valor;

    if(valor >= num->dado){
        ls = inserir(ls, valor);
        return ls;
    }

    while(i != NULL){
        ant = i;
        i = i->prox;

        if(i->dado >= valor && ant->dado < valor){
            ant->prox = novo_elemento;
            novo_elemento->prox = i;
            return ls;
        }
        if(i->dado <= valor && ant->dado > valor){
            ant->prox = novo_elemento;
            novo_elemento->prox = i;
            return ls;
        }
        if(i->prox == NULL){
            i->prox = novo_elemento;
            novo_elemento->prox = NULL;
            return ls;
        }
    }
}
