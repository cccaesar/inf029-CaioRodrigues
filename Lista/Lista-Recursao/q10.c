#include <stdio.h>

int contarNumero(int k, int n)
{
    int ocorrencias = 0;
    if((n % 10) == k)
        ocorrencias++;
    if((n / 10) != 0)
        return ocorrencias + contarNumero(k, n / 10);
    else
        return ocorrencias;    
}

int main()
{
    int numero_n, numero_k, qtd_ocorrencias;
    scanf("%d%d", &numero_n,&numero_k);
    qtd_ocorrencias = contarNumero(numero_k, numero_n);
    printf("O algarismo %d aparece %d vezes em %d\n", numero_k, qtd_ocorrencias, numero_n);
}