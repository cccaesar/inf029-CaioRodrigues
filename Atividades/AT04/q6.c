#include <stdio.h>

void ler3letras(char palavra[]);

int main(){
	char letras[3];
	
	ler3letras(letras);
	printf("Caracteres inseridos:\n");
	printf("%c\n%c\n%c\n",letras[0],letras[1],letras[2]);
}

void ler3letras(char palavra[]){
	int i;
	printf("Insira 3 caracteres:\n");
	scanf("%s",palavra);

}