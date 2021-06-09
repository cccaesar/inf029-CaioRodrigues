#include <stdio.h>

void numerosParesNaturaisCrescente(int n)
{   
    if((n % 2) == 0)
        printf("%d\n", n);
    if( n != 0)
        numerosParesNaturaisCrescente(n - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    numerosParesNaturaisCrescente(n);
}