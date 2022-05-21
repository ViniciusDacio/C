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

void verifica_elemento(tipo_grafo *G, int linha, int v[], int cor[], int posicao, int vertices){
    int cont = posicao;

    if(cor[linha] == 0)
        return;
    for(int i=0; i<vertices; i++){
        if(G->matriz_adj[linha][i] == 1){
            v[cont] = i;
            cont++;
        }
    }
    cor[linha] = 0;
}

void popula(int v[], int tam, int valor){
    for(int i=0; i<tam;i++){
        v[i] = valor;
    }
}

void cordao_led(){
    int vertices, arestas;
    /*
    printf("Numero de segmentos: ");
    scanf("%d", &vertices);
    printf("Numero de ligacoes: ");
    scanf("%d", &arestas);
    */
    vertices = 4;
    arestas = 3;

    tipo_grafo *G = criaGrafo(vertices);

    printf("Digite as ligacoes: \n");

    for(int i=0; i<arestas; i++){
        int j, k;
        scanf("%d-%d", &j, &k);
        addAresta(G, j-1, k-1);
    }

    int cor[vertices];
    int v[10];
    popula(v,10,0);
    popula(cor, vertices,1);

    int inicio = 0;
    int del_elem = 0, l=0;

    do{
        verifica_elemento(G, v[l], v, cor, del_elem, vertices);

        int it = del_elem;
        while(it < 10){
            if(v[it] == 0){
                del_elem = it;
                break;
            }
            it++;
        }
        l++;
    }while(v[l] != 0);

    printf("----------");
    imprime_lista(cor, vertices);
    printf("----------");
    imprime_lista(v, 10);
    mostra_grafo(G);

    G = liberaGrafo(G);

    printf("\n");

}


















