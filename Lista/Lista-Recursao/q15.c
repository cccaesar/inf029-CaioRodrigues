#include <stdio.h>

void numerosParesNaturaisDecrescente(int n)
{   
    if( n != 0)
        numerosParesNaturaisDecrescente(n - 1);
    if((n % 2) == 0)
        printf("%d\n", n);
}

int main()
{
    int n;
    scanf("%d", &n);
    numerosParesNaturaisDecrescente(n);
}