#include <stdio.h>

int calcularSomatorioNaturais(int n)
{
    if(n < 1)
        return n;
    if(n == 1)
        return 1;
    else
        return n + calcularSomatorioNaturais(n - 1);
}

int main()
{
    int x, somatorio;
    scanf("%d",&x);
    somatorio = calcularSomatorioNaturais(x);
    printf("%d\n",somatorio);
}