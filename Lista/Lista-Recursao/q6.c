#include <stdio.h>
#include <stdlib.h>

int calcularPotencia(int base, int expoente)
{
    if(expoente == 0)
        return 1;
    else if(expoente == 1)
        return base;
    else
        return base * calcularPotencia(base, expoente - 1);
}

int main()
{
    int k, n, resultado;
    scanf("%d%d",&k,&n);
    resultado = calcularPotencia(k, n);
    printf("%d\n", resultado);
}