#include <stdio.h>

#include "contador.h"

int main(){
	int numero;
	printf("Insira um numero inteiro\n");
	scanf("%d",&numero);
	printf("Antecessores desse numero:\n");
	contarAntecessoresNaturais(numero - 1);
}