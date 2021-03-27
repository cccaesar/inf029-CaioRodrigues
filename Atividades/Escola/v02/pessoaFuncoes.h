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


void inserirConta( pessoa_dados lista[], int qtd_alunos, int professor );
void mostrarPerfil(pessoa_dados aluno);