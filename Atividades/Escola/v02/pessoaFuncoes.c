#include <stdio.h>
#define TAM_NOME 20
#define TAM_CPF 12

void removerEnter( char palavra[], int tam ){
	int i;
	for(i = 0; i < tam; i++){
		if( palavra[i] == '\n'){
			palavra[i] = '\0';
		}
	}
}

typedef struct{
	int ano;
	int mes;
	int dia;
} dma;

typedef struct {
	int matricula;
	char nome[TAM_NOME];
	char sexo;
	char cpf[12];
	int professor;
	dma data_nascimento;
} pessoa_dados;


void inserirConta( pessoa_dados lista[], int n, int professor ){
	pessoa_dados conta;
	printf("Insira o numero de matricula:\n");
	scanf("%d",&conta.matricula);
	getchar();
	printf("Insira o nome:\n");
	fgets(conta.nome, TAM_NOME, stdin);
	removerEnter(conta.nome , TAM_NOME);
	printf("Informe o sexo:\n");
	conta.sexo = getchar();
	getchar();
	printf("Insira os numeros do CPF:\n");
	fgets(conta.cpf, TAM_CPF, stdin);
	removerEnter(conta.cpf , TAM_CPF);
	printf("Insira ano, mes e dia de nascimento, respectivamente\n");
	scanf("%d%d%d",&conta.data_nascimento.ano,&conta.data_nascimento.mes,&conta.data_nascimento.dia);
	conta.professor = professor;
	lista[n++] = conta;
}

void mostrarPerfil(pessoa_dados conta){
	printf("-----\n");
	printf("Matricula: %d\n", conta.matricula);
	if( conta.professor != 0)
		printf("Nome do professor: %s\n", conta.nome);
	else
		printf("Nome do aluno: %s\n", conta.nome);
	printf("Data de nascimento: %d/%d/%d\n", conta.data_nascimento.dia, conta.data_nascimento.mes, conta.data_nascimento.ano);
	switch(conta.sexo){
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
	printf("CPF: %s\n", conta.cpf);
	printf("-----\n");
}