#include "mod_pilha.h"

//Vinicius Dacio

int main(void){
    pilha *pl;

    pl = nova_pilha();
    printf("-----Verifica se vazia----\n");
    vazia(pl);
    printf("-----Adiciona 3 elementos----\n");
    pl = push(pl, 1);
    pl = push(pl, 2);
    pl = push(pl, 3);
    imprime(pl);
    printf("-----Remove um elemento----\n");
    pl = pop(pl);
    imprime(pl);

    return 0;
}
