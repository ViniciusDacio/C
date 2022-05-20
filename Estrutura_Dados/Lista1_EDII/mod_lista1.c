#include "mod_lista1.h"
//Vinicius Dacio

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
    while(n < 1 || n > 1000){
        printf("Digite um numero entre 1 e 1000: ");
        scanf("%d",&n);
    }
    printf("Classificados: ");
    scanf("%d",&k);

    while(k > n || k < 1){
        printf("Dica: O numero de classificados nao pode ser maior que o de candidatos ou menor que Zero: ");
        scanf("%d",&k);
    }

    int v[n];
    for(int i = 0; i < n; i++){
        printf("Digite a nota do %d competidor:\n", i+1);
        scanf("%d", &v[i]);
        if(v[i] < 1 || v[i] > 1000){
            printf("A nota deve ser entre 1 e 1000!\n");
            i--;
        }
    }
    quicksort(v, 0, n);
    imprime_lista(v, n);
    printf("\n");

    int sum = 0;
    for(int i=n; i>0; i--){
        if(sum >= k && v[i] > v[i-1]){
            break;
        }
        sum++;
    }
    printf("Classificados: %d\n",sum);
}

void grid(){
    int largada[24];
    int chegada[24];

    int n, i;

    printf("Numero de competidores: ");
    while(scanf("%d", &n) != EOF){
        for(i=0; i<n; i++){
            printf("Digite o numero dos competidores: ");
            scanf("%d",&largada[i]);

            while(largada[i] < 1 || largada[i] > 24){
            printf("Numero entre 1 e 24: ");
            scanf("%d",&largada[i]);
            }

        }for(i=0; i<n; i++){
            printf("Digite as posicoes de chegada: ");
            scanf("%d",&chegada[i]);

            while(chegada[i] < 1 || chegada[i] > 24){
            printf("Numero entre 1 e 24: ");
            scanf("%d",&chegada[i]);
            }
        }
        imprime_lista(largada, n); printf("\n");
        imprime_lista(chegada, n); printf("\n");

        int i, j, cont, aux;
        int v[24];

        for(i=0; i <n; i++){
            for(j=0; j<n; j++){
                if(largada[i] == chegada[j]){
                    v[i] = j;
                    break;
                }
            }
        }
        imprime_lista(v,n);
        int ordem = bubble_sort(v, n);
        printf("\n%d",ordem);
    }
}

void cordao_led(){
    int vertices, arestas;
    /*
    printf("Numero de segmentos: ");
    scanf("%d", &vertices);
    printf("Numero de ligacoes: ");
    scanf("%d", &arestas);

    int v1[arestas], v2[arestas];

    printf("Digite as ligacoes: \n");

    for(int i=0; i<arestas; i++){
        scanf("%d-%d", &v1[i], &v2[i]);
    }
    */
    vertices = 4;
    arestas = 3;
    int v1[3] = {1,1,2};
    int v2[3] = {2,3,4};
    imprime_lista(v1, arestas);
    printf("\n");
    imprime_lista(v2, arestas);

    printf("\n");

}


















