#include <stdio.h>
#include "escolaFuncoes.h"
#define TAM 5
#define TAM_ALUNO 50
#define TAM_NOME 20
#define TAM_CPF 13

int menu_alunos( pessoa_dados lista_alunos[], int qtd_alunos );
void removerEnter( char palavra[], int tam );
int menu_prof( pessoa_dados lista_prof[], int qtd_prof );
int menu_disciplinas( disciplina lista_disciplinas[], int qtd_disciplinas, pessoa_dados lista_alunos[], int qtd_alunos );

int main()
{
	
	pessoa_dados lista_professores[TAM], lista_alunos[TAM_ALUNO];
	disciplina lista_disciplinas[TAM];
	int opcao = 1, i, qtd_alunos = 0, qtd_professores = 0, qtd_disciplinas = 0;
	
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
			case 3:{
				printf("Abrindo o menu de disciplinas\n");
				qtd_disciplinas = menu_disciplinas( lista_disciplinas, qtd_disciplinas, lista_alunos, qtd_alunos );
				break;
			}
			default:{
				printf("Comando não reconhecido. Tente de novo\n");
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
				lista_alunos[qtd_alunos++] = inserirConta( 0 );
				break;
			}
		}
	}
	return qtd_alunos;
}

int menu_disciplinas( disciplina lista_disciplinas[], int qtd_disciplinas, pessoa_dados lista_alunos[], int qtd_alunos )
{
	int opcao = 1, i;
	char confirmacao;
	
	while(opcao){
		printf("Digite sua opção:\n");
		printf("0 - Sair\n");
		printf("1 - Listar disciplinas\n");
		printf("2 - Inserir novas disciplinas\n");
		printf("3 - Adicionar aluno na disciplina\n");
		printf("4 - Remover aluno da disciplina\n");
		scanf("%d",&opcao);
		switch(opcao){
			case 1:{
				for(i=0; i< qtd_disciplinas; i++){
					mostrarDisciplina(lista_disciplinas[i]);
				}
				break;
			}
			case 2:{
				lista_disciplinas[qtd_disciplinas++] = inserirDisciplina();
				break;
			}
			case 3:{
				
				
			}
			default:
				break;
		}
	}
	return qtd_disciplinas;
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
				 lista_prof[qtd_prof++] = inserirConta( 1 );
				break;
			}
		}
	}
	return qtd_prof;
}

