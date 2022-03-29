#include <stdio.h>
#include <stdlib.h>

void fibonacci(int n){
    int i = 0;
    int a = 1;
    int b = 1;
    while(i<n){
        int soma;
        soma = a + b;
        printf("%d + %d = %d\n", a, b, soma);
        a = b;
        b = soma;
        i++;
    }
}

int fibonacci_recursivo(int n, int a, int b, int i){
    if(i > n){
        return 0;
    }
    else{
        int soma;
        soma = a + b;
        printf("%d + %d = %d\n", a, b, soma);
        a = b;
        b = soma;
        i++;
        fibonacci_recursivo(n, a, b, i);
    }
}

int fib(int x, int *cont){

    (*cont)++;

    if(x==0)
        return 0;
    if(x==1)
        return 1;

    return fib(x-1, cont)+fib(x-2, cont);
}

int main()
{
    //int n;
    //scanf("%d", &n);

    //fibonacci_recursivo(n, 1, 1, 1);



    int n, x;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
       scanf("%d", &x);

       int result;
       int cont = 0;

       result = fib(x, &cont);

       printf("fib(%d) = %d calls = %d", n, cont, result);
    }

    return 0;
}
