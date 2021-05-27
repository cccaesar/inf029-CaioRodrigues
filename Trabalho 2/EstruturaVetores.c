#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

No *vetorPrincipal[TAM];

int ehPosicaoValida(int posicao);
int passarConteudoParaArray(int *v, No *strAuxiliar);
void ordenarInteiros(int *v, int tam);

void dobrar(int *x)
{

    *x = *x * 2;
}

void ordenarInteiros(int *v, int tam)
{
    int i, j, menor, aux;

    for(i=0; i < tam; i++)
    {
        menor = i;
        for(j=i + 1; j < tam; j++)
        {
            if(v[j] < v[menor]){
                menor = j;
            }
        }
        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
        
    }
}

int passarConteudoParaArray(int *v, No *strAuxiliar)
{   
    int i=0;
    do
    {
        if(strAuxiliar->conteudo != 0)
        {
            v[i] = strAuxiliar->conteudo;
            i++;
        }
        strAuxiliar = strAuxiliar->prox;
    }while(strAuxiliar->prox != NULL && strAuxiliar->conteudo != 0);
    return i;
}
/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'
Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho tem inteiro maior ou igual a 1
*/

No *criarCelulas()
{
    No *celula;
    
    celula = ( No* ) malloc(sizeof(No));
    if(!celula){
        exit;
    }
    celula->conteudo = 0;
    return celula;
}

int criarEstruturaAuxiliar(int posicao, int tamanho)
{

    int retorno = 0, i;
    No *cabeca;
    // a posicao pode já existir estrutura auxiliar
    if( ehPosicaoValida(posicao) == -5)
    {
        retorno = POSICAO_INVALIDA;
    }
    else if(vetorPrincipal[posicao - 1] != NULL)
    {
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    }
    // o tamanho ser muito grande
    else if( tamanho > 10 )
        retorno = SEM_ESPACO_DE_MEMORIA;
    // o tamanho nao pode ser menor que 1
    else if(tamanho < 1)
        retorno = TAMANHO_INVALIDO;
    // deu tudo certo, crie
    else 
    {   
        cabeca = malloc(sizeof(No));
        vetorPrincipal[posicao - 1] = cabeca;
        for( i=0; i < tamanho ;i++ )
        {   
            cabeca->conteudo = 0;
            if(i != (tamanho - 1))
            {
                cabeca->prox = malloc(sizeof(No));
                cabeca = cabeca->prox;
            }
            else
            {
                cabeca->prox = NULL;
            }
        }
        
        retorno = SUCESSO;
    }
    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int i;
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;
    No *ptrEstrAuxiliar;


    if( ehPosicaoValida(posicao) == -5)
        retorno = POSICAO_INVALIDA;
    else
    {
        // testar se existe a estrutura auxiliar
        posicao--;
        if(vetorPrincipal[posicao] != NULL){
            existeEstruturaAuxiliar = 1;
            ptrEstrAuxiliar = vetorPrincipal[posicao];
        }
        if (existeEstruturaAuxiliar)
        {
            while( 1 ){
                if( ptrEstrAuxiliar->conteudo == 0)
                {
                    temEspaco = 1;
                    break;
                }
                else if(ptrEstrAuxiliar->prox != NULL)
                {
                    ptrEstrAuxiliar = ptrEstrAuxiliar->prox;
                }
                else
                    break;
            }
            if (temEspaco)
            {
                //insere
                ptrEstrAuxiliar->conteudo = valor;
                retorno = SUCESSO;
            }
            else
            {
                retorno = SEM_ESPACO;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int retorno = SUCESSO;
    No *strAuxiliar, *strAuxiliar2;
    if( ehPosicaoValida(posicao) == POSICAO_INVALIDA)
        retorno = POSICAO_INVALIDA;
    else if(vetorPrincipal[posicao-1] == NULL)
        retorno = SEM_ESTRUTURA_AUXILIAR;
    else
    {
        strAuxiliar = vetorPrincipal[posicao-1];
        //printf("Valores dentro da estrutura:\n");
        //printf("%d\n", strAuxiliar->conteudo);
        if(strAuxiliar->conteudo == 0)
            retorno = ESTRUTURA_AUXILIAR_VAZIA;
        while(1)
        {

            if(strAuxiliar->prox != NULL)
                strAuxiliar2 = strAuxiliar->prox;
            else
                break;
            //printf("%d\n", strAuxiliar2->conteudo);
            //printf("%d\n", strAuxiliar->conteudo);
            if(strAuxiliar2->conteudo == 0)
            {
                strAuxiliar->conteudo = 0;
                break;
            }
            else if(strAuxiliar2->prox == NULL)
            {   
                //printf("%d\n", strAuxiliar2->conteudo);
                strAuxiliar2->conteudo = 0;
                //printf("Fim do laço.\n");
                break;
            }
            strAuxiliar = strAuxiliar2;
        }
    }
    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int retorno = SUCESSO, numeroExiste = 0;
    No *strAuxiliar,*strAuxiliar2;
    if( ehPosicaoValida(posicao) == POSICAO_INVALIDA)
        retorno = POSICAO_INVALIDA;
    else if( vetorPrincipal[posicao - 1] == NULL )
        retorno = SEM_ESTRUTURA_AUXILIAR;
    else
    {
        strAuxiliar = vetorPrincipal[posicao - 1];
        if(strAuxiliar->conteudo == 0)
            retorno = ESTRUTURA_AUXILIAR_VAZIA; 
        else
        {
            while(1)
            {   
                if(strAuxiliar->prox != NULL)
                    strAuxiliar2 = strAuxiliar->prox;
                if(strAuxiliar->conteudo == valor && numeroExiste == 0)
                {
                    numeroExiste = 1;
                    strAuxiliar->conteudo = 0;
                }
                if(numeroExiste && strAuxiliar2->conteudo != 0)
                {
                    strAuxiliar->conteudo = strAuxiliar2->conteudo;
                    strAuxiliar2->conteudo = 0;
                }
                else if(numeroExiste)
                    break;
                if(strAuxiliar->prox != NULL)
                    strAuxiliar = strAuxiliar->prox;
                else
                    break;
            }
            if(numeroExiste == 0)
                retorno = NUMERO_INEXISTENTE;
        }
    }
    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = 0, i;
    No *strAuxiliar;
    if( ehPosicaoValida(posicao) == POSICAO_INVALIDA )
        retorno = POSICAO_INVALIDA;
    else if(vetorPrincipal[posicao - 1] == NULL)
        retorno = SEM_ESTRUTURA_AUXILIAR;
    else
    {   i = -1;
        strAuxiliar = vetorPrincipal[posicao - 1];
        i = passarConteudoParaArray(vetorAux, strAuxiliar);
        retorno = SUCESSO;
    }
    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = 0, tamVetor;
    No *strAuxiliar;
    if( ehPosicaoValida(posicao) == POSICAO_INVALIDA )
        retorno = POSICAO_INVALIDA;
    else if(vetorPrincipal[posicao - 1] == NULL)
        retorno = SEM_ESTRUTURA_AUXILIAR;
    else
    {   
        strAuxiliar = vetorPrincipal[posicao - 1];
        tamVetor = passarConteudoParaArray( vetorAux, strAuxiliar);
        ordenarInteiros(vetorAux, tamVetor);
        retorno = SUCESSO;
    }
    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    
    int retorno = 0, i,j = 0;
    No *strAuxiliar;
    vetorAux[0] = 0;
    for(i=0; i < TAM; i++ ){
        strAuxiliar = vetorPrincipal[i];
        while(strAuxiliar != NULL && strAuxiliar->conteudo != 0)
        {
            if(strAuxiliar->conteudo != 0)
            {
                vetorAux[j] = strAuxiliar->conteudo;
                j++;
            }
            strAuxiliar = strAuxiliar->prox;
        }
    }
    
    if(vetorAux[0] == 0)
    {
        retorno =   TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    else
        retorno = SUCESSO;
    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = 0, i, tamanho = 0;
    vetorAux[0] = 0;
    for(i=1; i <= TAM; i++ ){
        tamanho = getDadosEstruturaAuxiliar(i, vetorAux);
    }
    if(vetorAux[0] == 0)
    {
        retorno =   TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    else
    {
        retorno = SUCESSO;
        if(tamanho)
            ordenarInteiros(vetorAux, tamanho);
    }
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1
Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

    int retorno = 0;
    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.
Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{

    int retorno = 0;

    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.
Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    No celula;
    int i;
    for(celula = *inicio, i=0; celula.prox != NULL; vetorAux[i] = celula.conteudo){
        i++;
        if(celula.prox != NULL)
            celula = *celula.prox;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.
Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 
*/

void inicializar()
{
    int i;
    for(i=1; i <= TAM; i++){
        vetorPrincipal[i] = NULL;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.
*/

void finalizar()
{
    int i;
    No *estrAux, *estrAux2;
    for(i=0; i > TAM; i++)
    {
        estrAux = vetorPrincipal[i];
        while(1)
        {
            estrAux2 = estrAux->prox;
            free(estrAux);
            estrAux = estrAux2;
            if(estrAux2->prox == NULL)
                break;
        }
    }
}