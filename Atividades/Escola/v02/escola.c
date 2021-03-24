#include <stdio.h>
#define MAX_ALUNOS 10

typedef struct{
	int ano;
	int mes;
	int dia;
} dma;

typedef struct {
	int matricula;
	char nome[20];
	char sexo;
	char cpf[12];
	dma data_nascimento;
} dados_aluno;

void mostrarAluno(dados_aluno aluno){
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

int main()
{
	
	dados_aluno aluno, lista_alunos[MAX_ALUNOS];
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
				printf("Insira o numero de matricula do aluno:\n");
				scanf("%d",&aluno.matricula);
				getchar();
				printf("Insira o nome do aluno:\n");
				fgets(aluno.nome, 20, stdin);
				aluno.nome[strlen(aluno.nome) - 1] = '\0';
				printf("Informe o sexo do aluno:\n");
				aluno.sexo = getchar();
				getchar();
				printf("Insira os numeros do CPF do aluno:\n");
				fgets(aluno.cpf, 12, stdin);
				getchar();
				printf("Insira ano, mes e dia de nascimento do aluno, respectivamente\n");
				scanf("%d%d%d",&aluno.data_nascimento.ano,&aluno.data_nascimento.mes,&aluno.data_nascimento.dia);
				lista_alunos[qtd_alunos++] = aluno;
				break;
			}
		}
	}
}