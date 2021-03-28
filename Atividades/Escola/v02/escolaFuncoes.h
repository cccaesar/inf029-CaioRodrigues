#define TAM_NOME 20
#define TAM_CPF 12
#define TAM 5

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
	int professor;
	dma data_nascimento;
} pessoa_dados;

typedef struct{
	char nome[TAM_NOME];
	int semestre;
	int codigo;
	int matricula_professor;
	pessoa_dados alunos[TAM];
} disciplina;

disciplina inserirDisciplina();
pessoa_dados inserirConta( int professor );
void mostrarPerfil(pessoa_dados aluno);
void mostrarDisciplina(disciplina materia);