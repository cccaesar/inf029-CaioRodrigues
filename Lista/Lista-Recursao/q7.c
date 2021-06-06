#include <stdio.h>
#define TAM 100

void inverterVetor(int v[], int posicao)
{
    int cem = 100, aux;
    if(posicao > 50)
    {
        aux = v[posicao-1];
        v[posicao-1] = v[cem - posicao];
        v[cem - posicao] = aux;
        inverterVetor(v, posicao - 1);
    }
}

void exibirValores(int v[], int posicao)
{   
    if(posicao > 0)
    {
       printf("%d\n", v[posicao - 1]);
       exibirValores(v, posicao - 1);
    }
}

void inserirValores(int v[], int posicao)
{
    if(posicao > 0)
    {
        v[posicao - 1] = posicao;
        inserirValores(v, posicao - 1);
    }
}

int main()
{
    int v[TAM];
    inserirValores(v, TAM);
    printf("Valores antes da inversão:\n");
    exibirValores(v, TAM);
    inverterVetor(v, TAM);
    printf("Valores após a inversão:\n");
    exibirValores(v, TAM);

}