#include "mod_lista1.h"

void tabuada(int num, int i){
    if(i > 10)
        return;
    else if(2 < num && num < 1000){
        printf("%d x %d = %d\n", i, num, (i * num));
        i++;
        tabuada(num, i);
   }
}

void senha_fixa(int *n){
    if(n == 2002)
        printf("Acesso Permitido\n");
    else{
        printf("Senha Invalida\n");
        scanf("%d",&n);
        senha_fixa(n);
    }
}

void fase(){
    int n, k;
    printf("Numero de competidores: ");
    scanf("%d", &n);
    printf("Classificados: ");
    scanf("%d",&k);
    if(k > n){
        while(k > n){
            printf("Dica: O numero de classificados nao pode ser maior que o de candidatos: ");
            scanf("%d",&k);
        }
    }

    printf("Digite a nota dos %d competidores:\n", n);
    int v[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    void bubble_sort(v, n);
    imprime_lista(v, n);
}

















