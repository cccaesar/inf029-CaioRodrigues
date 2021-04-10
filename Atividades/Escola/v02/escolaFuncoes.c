#include <stdio.h>
#define TAM_NOME 20
#define TAM_CPF 13
#define TAM_ALUNO 50
#define TAM 5

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

typedef struct{
	char nome[TAM_NOME];
	char semestre[8];
	int codigo;
	int matricula_professor;
	int matricula_alunos[TAM_ALUNO];
} disciplina;

void mostrarDisciplina(disciplina materia);
disciplina removerAluno( disciplina materia, pessoa_dados aluno);
int alunoJaCadastrado(int matricula, disciplina materia);
void mostrarPerfil(pessoa_dados conta);
disciplina adicionarAluno( disciplina materia, pessoa_dados aluno);

pessoa_dados inserirConta( int professor ){
	pessoa_dados conta;
	conta.professor = professor;
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
	return conta;
}

disciplina inserirDisciplina(){
	disciplina materia;
	printf("Insira o codigo da disciplina:\n");
	scanf("%d",&materia.codigo);
	getchar();
	printf("Insira o nome da disciplina:\n");
	fgets(materia.nome, TAM_NOME, stdin);
	removerEnter(materia.nome , TAM_NOME);
	printf("Insira o semestre da materia:\n");
	fgets(materia.semestre, 8, stdin);
	printf("Insira o numero de matricula do professor:\n");
	scanf("%d",&materia.matricula_professor);
	return materia;
}

void removerAlunosDisciplina(disciplina lista_disciplinas[], int qtd_disciplinas, pessoa_dados lista_alunos[], int qtd_alunos){
	int i, j, escolha2 = 1, escolha1 = 1;
	printf("Listando disciplinas...\n");
	for(i=0; i< qtd_disciplinas && escolha1 != 0; i++){
		mostrarDisciplina(lista_disciplinas[i]);
		printf("0-Sair\n1-Selecionar %s\n2-Continuar a lista\n", lista_disciplinas[i].nome);
		scanf("%d",&escolha1);
		escolha2 = 1;
		if( escolha1 == 1){
			printf("Listando alunos...\n");
			for( j=0; j < qtd_alunos && (escolha2 != 0) && ( alunoJaCadastrado(lista_alunos[j].matricula ,lista_disciplinas[i]) != 0); j++){
				mostrarPerfil(lista_alunos[j]);
				printf("Aperte 1 para remover esse aluno a disciplina, 0 para parar a listagem de alunos ou 2 para continuar a lista");
				scanf("%d", &escolha2);
				if(escolha2 == 1 ){
					lista_disciplinas[i] = removerAluno( lista_disciplinas[i] ,lista_alunos[j] );
				}
			}
		}
	}
}

void cadastrarAlunoNaDisciplina(disciplina lista_disciplinas[], int qtd_disciplinas, pessoa_dados lista_alunos[], int qtd_alunos){
	int i, j, escolha2 = 1, escolha1 = 1;
	printf("Listando disciplinas...\n");
	for(i=0; i< qtd_disciplinas && escolha1 != 0; i++){
		mostrarDisciplina(lista_disciplinas[i]);
		printf("0-Sair\n1-Selecionar %s\n2-Continuar a lista\n", lista_disciplinas[i].nome);
		scanf("%d",&escolha1);
		escolha2 = 1;
		if( escolha1 == 'S' || escolha1 == 's'){
			printf("Listando alunos...\n");
			for( j=0; j < qtd_alunos && (escolha2 != 0) && ( alunoJaCadastrado(lista_alunos[j].matricula ,lista_disciplinas[i]) == 0); j++){
				mostrarPerfil(lista_alunos[j]);
				printf("Aperte 1 para adicionar esse aluno a disciplina 0 para parar a listagem de alunos ou 2 para continuar a lista");
				scanf("%d", &escolha2);
				if(escolha2 == 1 ){
					lista_disciplinas[i] = adicionarAluno( lista_disciplinas[i] ,lista_alunos[j] );
				}
			}
		}
	}
}

int alunoJaCadastrado(int matricula, disciplina materia){
	int i, jaCadastrado = 0;;
	for( i=0; i < TAM_ALUNO; i++){
		if( materia.matricula_alunos[i] == matricula ){
			jaCadastrado = 1;
		}
	}
	return jaCadastrado;
}

disciplina adicionarAluno( disciplina materia, pessoa_dados aluno){
	int i, adicionado = 0;
	
	for(i=0; i < TAM_ALUNO && (adicionado == 0); i++){
		if( materia.matricula_alunos[i] == 0 ){
			materia.matricula_alunos[i] = aluno.matricula;
			adicionado = 1;
		}
	}
	
	return materia;
}

disciplina removerAluno( disciplina materia, pessoa_dados aluno){
	int i, removido = 0;
	
	for(i=0; i < TAM_ALUNO && (removido == 0); i++){
		if( materia.matricula_alunos[i] == aluno.matricula ){
			materia.matricula_alunos[i] = 0;
			removido = 1;
		}
	}
	
	return materia;
}

void mostrarDisciplina(disciplina materia){
	printf("-----\n");
	printf("Nome da materia: %s\n", materia.nome);
	printf("Codigo: %d\n", materia.codigo);
	printf("Matricula do Professor: %d\n", materia.matricula_professor);
	printf("Semestre: %s\n", materia.semestre);
	printf("-----\n");
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