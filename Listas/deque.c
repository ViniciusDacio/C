#include "mod_deque.h"

//Vinicius Dacio

int main(){
    Deque* d;

    printf("-----Inicializa a lista-----\n");
    printf("-----Verifica se esta Vazio-----\n");
    d = cria_deque();
    if(vazio(d) == 1){
        printf("Deque esta Vazio\n");
    }
    printf("\n-----Insere 3 elementos no Inicio-----\n");
    d = inserir_inicio(d, 1);
    d = inserir_inicio(d, 2);
    d = inserir_inicio(d, 3);
    imprime(d);
    printf("\n-----Insere 2 elementos no Fim-----\n");
    d = inserir_fim(d, 4);
    d = inserir_fim(d, 5);
    imprime(d);
    printf("\n-----Remove o elemento do Inicio-----\n");
    remove_inicio(d);
    imprime(d);
    printf("\n-----Remove o elemento do Fim-----\n");
    remove_fim(d);
    imprime(d);
    printf("\n-----Por fim libera o Deque e termina-----\n");
    libera_deque(d);
    system("pause");

    return 0;
}
