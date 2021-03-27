#include <stdio.h>
#include "pessoaFuncoes.h"
#define TAM 5
#define TAM_NOME 20
#define TAM_CPF 12
#define MAX_DISCIPLINAS 2

typedef struct{
	char nome[TAM_NOME];
	int semestre;
	int codigo;
	int Matricula_professor;
	pessoa_dados alunos[TAM];
} disciplina;

int menu_alunos( pessoa_dados lista_alunos[], int qtd_alunos );
void removerEnter( char palavra[], int tam );
int menu_prof( pessoa_dados lista_prof[], int qtd_prof );

int main()
{
	
	pessoa_dados lista_professores[TAM], lista_alunos[TAM];
	disciplina lista_disciplinas[MAX_DISCIPLINAS];
	int opcao = 1, i, qtd_alunos = 0, qtd_professores = 0;
	
	while(opcao){
		printf("Digite sua opção:\n");
		printf("0 - Sair\n");
		printf("1 - Gerenciar Alunos\n");
		printf("2 - Gerenciar Professores\n");
		printf("3 - Gerenciar Disciplinas\n");
		scanf("%d",&opcao);
		switch(opcao){
			case 1:{
				printf("Abrindo o menu de alunos\n");
				qtd_alunos = menu_alunos( lista_alunos, qtd_alunos );
				break;
			}
			case 2:{
				printf("Abrindo o menu de professores\n");
				qtd_professores = menu_prof( lista_professores, qtd_professores );
				break;
			}
		}
	}
}

int menu_alunos( pessoa_dados lista_alunos[], int qtd_alunos )
{
	int opcao = 1, i;
	
	while(opcao){
		printf("Digite sua opção:\n");
		printf("0 - Sair\n");
		printf("1 - Listar alunos\n");
		printf("2 - Inserir aluno\n");
		scanf("%d",&opcao);
		switch(opcao){
			case 1:{
				for(i=0; i< qtd_alunos; i++){
					mostrarPerfil(lista_alunos[i]);
				}
				break;
			}
			case 2:{
				
				inserirConta( lista_alunos , qtd_alunos, 0 );
				qtd_alunos++;
				break;
			}
		}
	}
	return qtd_alunos;
}

int menu_prof( pessoa_dados lista_prof[], int qtd_prof )
{
	int opcao = 1, i;
	
	while(opcao){
		printf("Digite sua opção:\n");
		printf("0 - Sair\n");
		printf("1 - Listar professores\n");
		printf("2 - Inserir professores\n");
		scanf("%d",&opcao);
		switch(opcao){
			case 1:{
				for(i=0; i< qtd_prof; i++){
					mostrarPerfil(lista_prof[i]);
				}
				break;
			}
			case 2:{
				
				inserirConta( lista_prof , qtd_prof, 1 );
				qtd_prof++;
				break;
			}
		}
	}
	return qtd_prof;
}

