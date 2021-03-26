#include <stdio.h>
#define TAM 5
#define TAM_NOME 20
#define TAM_CPF 12

typedef struct{
	int ano;
	int mes;
	int dia;
} dma;

typedef struct{
	
} disciplina;

typedef struct {
	int matricula;
	char nome[TAM_NOME];
	char sexo;
	char cpf[12];
	dma data_nascimento;
} pessoa_dados;

void mostrarAluno(pessoa_dados aluno);
void inserirAluno( int qtd_alunos, pessoa_dados lista[] );
void removerEnter( char palavra[], int tam );

void mostrarAluno(pessoa_dados aluno){
	printf("-----\n");
	printf("Matricula: %d\n", aluno.matricula);
	printf("Nome do aluno: %s\n", aluno.nome);
	printf("%d/%d/%d\n", aluno.data_nascimento.ano, aluno.data_nascimento.mes, aluno.data_nascimento.dia);
	switch(aluno.sexo){
		case 'M':
		case 'm':{
			printf("Sexo: Masculino\n");
			break;
		}
		case 'F':
		case 'f':{
			printf("Sexo: Feminino\n");
			break;
		}
		default:{
			printf("Sexo: Outro\n");
			break;
		}
	}
	printf("CPF do aluno: %s\n", aluno.cpf);
	printf("-----\n");
}

void inserirAluno( int qtd_alunos, pessoa_dados lista[] ){
	pessoa_dados aluno;
	printf("Insira o numero de matricula do aluno:\n");
	scanf("%d",&aluno.matricula);
	getchar();
	printf("Insira o nome do aluno:\n");
	fgets(aluno.nome, TAM_NOME, stdin);
	removerEnter(aluno.nome , TAM_NOME);
	printf("Informe o sexo do aluno:\n");
	aluno.sexo = getchar();
	getchar();
	printf("Insira os numeros do CPF do aluno:\n");
	fgets(aluno.cpf, TAM_CPF, stdin);
	removerEnter(aluno.cpf , TAM_CPF);
	printf("Insira ano, mes e dia de nascimento do aluno, respectivamente\n");
	scanf("%d%d%d",&aluno.data_nascimento.ano,&aluno.data_nascimento.mes,&aluno.data_nascimento.dia);
	lista[qtd_alunos++] = aluno;
}

int main()
{
	
	pessoa_dados aluno, lista_alunos[TAM];
	int opcao = 1, i, qtd_alunos = 0;
	
	while(opcao){
		printf("Digite sua opção:\n");
		printf("0 - Sair\n");
		printf("1 - Listar alunos\n");
		printf("2 - Inserir aluno\n");
		scanf("%d",&opcao);
		switch(opcao){
			case 1:{
				for(i=0; i< qtd_alunos; i++){
					mostrarAluno(lista_alunos[i]);
				}
				break;
			}
			case 2:{
				
				inserirAluno( qtd_alunos, lista_alunos);
				qtd_alunos++;
				break;
			}
		}
	}
}

void removerEnter( char palavra[], int tam ){
	int i;
	for(i = 0; i < tam; i++){
		if( palavra[i] == '\n'){
			palavra[i] = '\0';
		}
	}
}