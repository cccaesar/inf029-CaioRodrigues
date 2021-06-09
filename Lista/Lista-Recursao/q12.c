#include <stdio.h>

void numerosNaturaisCrescente(int n)
{
    printf("%d\n", n);
    if( n != 0)
        numerosNaturaisCrescente(n - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    numerosNaturaisCrescente(n);
}