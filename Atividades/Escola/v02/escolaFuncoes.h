#define TAM_NOME 20
#define TAM_CPF 13
#define TAM_ALUNO 50
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
	char semestre[8];
	int codigo;
	int matricula_professor;
	int matricula_alunos[TAM_ALUNO];
} disciplina;

disciplina inserirDisciplina();
int inserirConta( pessoa_dados lista[], int qtd ,int professor );
void mostrarPerfil(pessoa_dados aluno);
void mostrarDisciplina(disciplina materia);