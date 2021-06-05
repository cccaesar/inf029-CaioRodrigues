#include <stdio.h>
#include <stdlib.h>

int contarAlgarismos(int n)
{
    if(n / 10 == 0)
        return 1;
    else
        return 1 + contarAlgarismos(n /10);
}

int potenciacao(int base, int expoente)
{
    if(expoente == 0)
        return 1;
    else if(expoente == 1)
        return base;
    else
        return base * potenciacao(base, expoente - 1);
}

int inverterInteiro(int n)
{
    
    if(n < 10 )
        return n % 10;
    else
        return ((n%10) * potenciacao(10, contarAlgarismos( n / 10))) + inverterInteiro(n/10);
}


int main()
{
    int x;
    scanf("%d",&x);
    x = inverterInteiro(x);
    printf("%d\n",x);
}