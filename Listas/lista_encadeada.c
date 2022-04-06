#include "mod_lista_encadeada.h"

//Vinicius Dacio

int main(void){
    lista *ls;

    lista *procura;
    printf("-----Inicializa a lista-----\n");
    ls = nova_lista();
    printf("\n-----Verifica se esta vazia-----\n");
    vazia(ls);
    printf("\n-----Insere 4 elementos-----\n");
    ls = inserir(ls, 1);
    ls = inserir(ls, 2);
    ls = inserir(ls, 4);
    ls = inserir(ls, 5);
    imprime(ls);
    printf("\n-----Procura pelo elemento 2-----\n");
    procura = busca(ls, 2);
    if(procura){
        printf("Achou o elemento %d\n", procura->dado);
    }else{
        printf("\nElemento nao encontrado\n");
        }
    printf("\n-----Remove o elemento 5-----\n");
    ls = remove_elemento(ls, 5);
    imprime(ls);
    printf("\n-----Insere o elemento 3 ordenado-----\n");
    ls = ordem_cresc(ls,3);
    imprime(ls);
    free(ls);
    system("pause");

    return 0;
}
