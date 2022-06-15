#include <stdio.h>
#include <stdlib.h>

void divisao_resto(int *k){
    for(int i=0; i<13; i++){
        int chave = (k[i] + 3) % 13;
        printf("%d  %d\n",k[i], chave);
    }
}

void multiplicacao(int *k, int m, float a){
    for(int i=0; i<13; i++){
        float mod = k[i] * a;
        int chave = m * (mod - (int)mod);

        printf("%d  %d\n",k[i], chave);
    }
}

int main()
{
    int key[] = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5, 7, 32};
    //divisao_resto(key);
    multiplicacao(key, 13, 0.61);
    return 0;
}

