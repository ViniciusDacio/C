#include <stdio.h>
#include <stdlib.h>

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
        printf("Acesso Permitido");
    else{
        printf("Senha Invalida\n");
        scanf("%d",&n);
        senha_fixa(n);
    }
}

int main()
{
    int n, *p;
    p = &n;
    scanf("%d",&n);
    senha_fixa(*p);
    return 0;
}
