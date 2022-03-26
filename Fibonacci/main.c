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

int main()
{
    int n;
    scanf("%d", &n);

    fibonacci(n);

    return 0;
}
