#include <stdio.h>
#define TAM 4

typedef struct{
	char nome[TAM];
	char dataNascimento[10];
	char cpf[11];
	char sexo;
} Cliente;

Cliente cadastrarCliente(Cliente usuario);

int main(){
	Cliente user;
	int i;
	
	user = cadastrarCliente(user);
	
	for(i = 0; i < TAM; i++)
		printf("%c",user.nome[i]);
	printf("\nData de nascimento do cliente:\n");
	for(i = 0; i < 10; i++)
		printf("%c",user.dataNascimento[i]);
	printf("\nCpf do cliente:");
	for(i = 0; i < 11; i++)
		printf("%c",user.cpf[i]);
	
	printf("\n");
	printf("Sexo do cliente do cliente: %c\n", user.sexo);
}

Cliente cadastrarCliente(Cliente usuario){
	int i;
	
	printf("Insira o nome do cliente\n");
	for(i=0; i < TAM; i++){
		scanf(" %c",&usuario.nome[i]);
	}
	
	usuario.dataNascimento[4] = '/';
	usuario.dataNascimento[7] = '/';
	printf("Insira a data de nascimento do cliente, enviando ano, mes e dia respectivamante:\n");
	for(i=0; i < 10; i++)
		if(i != 4 && i != 7)
			scanf(" %c",&usuario.dataNascimento[i]);
	
	printf("Insira o CPF do cliente:\n");
	for(i=0; i < 11; i++)
		scanf("  %c",&usuario.cpf[i]);
	printf("Informe o sexo do cliente utilizando 'M' para masculino e 'F' para feminino\n");
	scanf(" %c",&usuario.sexo);
	
	return usuario;
}