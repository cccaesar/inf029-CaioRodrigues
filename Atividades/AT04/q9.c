#include <stdio.h>
#include <string.h>
#define TAM 20

typedef struct{
	int ano;
	int dia;
	int mes;
} dma;

typedef struct{
	char nome[TAM];
	dma dataNascimento;
	char cpf[12];
	char sexo;
} Cliente;

Cliente cadastrarCliente();
void validarSexo(char s);
void validarNome(char nome[]);
void validarData(int ano, int mes, int dia);
void validarCpf( char cpf[] );
int verificarBissexto(int ano);
int converterCharEmInt( char c);


int main(){
	Cliente user;
	int i;
	
	user = cadastrarCliente();
	
	printf("%s",user.nome);
	
	printf("\nData de nascimento do cliente: %d/%d/%d\n", user.dataNascimento.dia, user.dataNascimento.mes, user.dataNascimento.ano);
	printf("Cpf do cliente:");
	printf("%s",user.cpf);
	
	printf("\n");
	printf("Sexo do cliente do cliente: %c\n", user.sexo);
}

Cliente cadastrarCliente(){
	Cliente usuario;
	int i;
	

	printf("Insira o nome do cliente\n");
	fgets(usuario.nome, 20, stdin);
	usuario.nome[strlen(usuario.nome) - 1] = '\0';

	printf("Insira o ano de nascimento do cliente:\n");
	scanf("%d", &usuario.dataNascimento.ano);
	
	printf("Insira o mes de nascimento do cliente:\n");
	scanf("%d", &usuario.dataNascimento.mes);
	
	printf("Insira o dia de nascimento do cliente \n");
	scanf("%d", &usuario.dataNascimento.dia);
	
	validarData(usuario.dataNascimento.ano, usuario.dataNascimento.mes, usuario.dataNascimento.dia);
	getchar();
	printf("Insira apenas os numeros do CPF do cliente:\n");
	fgets(usuario.cpf, 12, stdin);
	validarCpf( usuario.cpf);
	getchar();
	printf("Informe o sexo do cliente utilizando 'M' para masculino e 'F' para feminino\n");
	scanf(" %c",&usuario.sexo);
	validarSexo( usuario.sexo );
	
	return usuario;
}

void validarSexo(char s){
	if( s != 'f' && s != 'F' && s != 'm' && s != 'M' && s != 'o' && s != 'O')
		printf("O caractere usado para informar o sexo esta incorreto.\n");
}

void validarNome(char nome[]){
	if( strlen(nome) > 20 )
		printf("O nome inserido possui caracteres demais");
}

int verificarBissexto(int ano){
    if( ano % 4 ){
		return 0;
	}
    else
        if(ano % 100){
			return 1;
		}
        else if( ano % 400){
			return 0;
		}
        else{
			return 1;
		}
}

int converterCharEmInt( char c){
	switch(c){
		case 0:{
			return 0;
		}
		case '1':{
			return 1;
		}
		case '2':{
			return 2;
		}
		case '3':{
			return 3;
		}
		case '4':{
			return 4;
		}
		case '5':{
			return 5;
		}
		case '6':{
			return 6;
		}
		case '7':{
			return 7;
		}
		case '8':{
			return 8;
		}
		case '9':{
			return 9;
		}
		default:{
			return -1;
		}
	}
}

void validarCpf( char cpf[] ){
	int num[12], i, valido = 1, digitoV1, digitoV2;
	
	for(i=0; i < 12; i++){
		num[i] = converterCharEmInt( cpf[i] );
	}
	

		 
		digitoV1 = (num[0] * 10 ) + ( num [1] * 9) + ( num [2] * 8) + ( num [3] * 7) + ( num [4] * 6) + ( num [5] * 5) + ( num [6] * 4) + ( num [7] * 3) + ( num [8] * 2);
		digitoV1 = digitoV1 % 11;
		if( (digitoV1 > 1) &&  (( 11 - digitoV1) == num[9] ))
			valido = 2;
		else if( digitoV1 < 2 && ((num[9] == 0) || (num[9] == 1) ))
			valido = 2;
		else
			valido = -1;
		if(valido == 2){
			digitoV2 = (num[0] * 11 ) + ( num [1] * 10) + ( num [2] * 9) + ( num [3] * 8) + ( num [4] * 7) + ( num [5] * 6) + ( num [6
			] * 5) + ( num [7] * 4) + ( num [8] * 3) + (num[9] * 2);
			digitoV2 = digitoV2 % 11;
			if( (digitoV1 > 1) &&  (( 11 - digitoV1) == num[9] ))
				valido = 2;
			else if( digitoV1 < 2 && ((num[9] == 0) || (num[9] == 1) ))
				valido = 2;
			else
				valido = -1;
		}
		else{
			printf("CPF Inválido\n");
		}
		
	
}

void validarData(int ano, int mes, int dia){
	int i, bissexto;
	
	if( dia > 31 || dia < 1 )
		printf("%d nao eh um dia valido.\n", dia);
	
	if(mes > 12 || mes < 1)
		printf("%d nao eh um mes valido.\n", mes);
	
	bissexto = verificarBissexto(ano);
	if( ano > 2021 || ano < 1)
		printf("%d eh um ano invalido.\n", ano);
	if( (mes == 4 || mes == 6 ||  mes == 9 || mes == 11) && dia > 30)
		printf("Nao existe dia %d no mes %d.\n", dia, mes);
	if( mes == 2 && dia > 29 && bissexto)
		printf("Nao existe dia %d no mes %d num ano bissexto.\n", dia, mes);
	else if( mes == 2 && dia > 28)
		printf("Nao existe dia %d no mes %d fora de um ano bissexto.\n", dia, mes);
}