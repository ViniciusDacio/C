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
    //n = competidores
    //k = classificados
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

    int v[n];
    for(int i = 0; i < n; i++){
        printf("Digite a nota do %d competidor:\n", i+1);
        scanf("%d", &v[i]);
        if(v[i] <= 1 || v[i] >= 1000){
            printf("A nota deve ser entre 1 e 1000!\n");
            i--;
        }
    }
    bubble_sort(v, n);
    imprime_lista(v, n);

    printf("\n");

    int sum = 0;
    for(int i=n; i>0; i--){
        if(sum >= k && v[i] > v[i-1]){
            break;
        }
        sum++;
    }
    printf("Soma: %d\n",sum);
}

















