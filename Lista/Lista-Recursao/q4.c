#include <stdio.h>
#include <stdlib.h>
#define TAM 4

void inserirElementos(int v[], int tam)
{

    if( tam > 0)
    {
        scanf("%d", &v[tam - 1]);
        inserirElementos(v, tam -1);
    }
}

int somarElementos(int v[], int tam)
{
    if( tam <= 0)
    {
        return 0;
    }
    else
        return v[tam - 1] +  somarElementos(v, tam -1);
}

int main()
{
    int v[TAM];
    int somatorio;
    inserirElementos(v, TAM);
    somatorio = somarElementos(v, TAM);
    printf("%d\n", somatorio);

}