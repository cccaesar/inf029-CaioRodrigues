#include <stdio.h>

void numerosNaturaisDecrescente(int n)
{
    if( n != 0)
        numerosNaturaisDecrescente(n - 1);
    printf("%d\n", n);
}

int main()
{
    int n;
    scanf("%d",&n);
    numerosNaturaisDecrescente(n);
}