#include <stdio.h>

typedef struct{
		int num1;
		int num2;
		int num3;
		int num4;
	} quatro_numeros;

quatro_numeros ler4numeros( quatro_numeros variavel);

int main(){
	
	quatro_numeros x;
	
	printf("Insira quatro numeros inteiros:\n");
	x = ler4numeros( x );
	printf("Numeros inseridos:%d\n%d\n%d\n%d\n",x.num1,x.num2,x.num3,x.num4);
	
}

quatro_numeros ler4numeros( quatro_numeros variavel){
	
	scanf("%d%d%d%d",&variavel.num1,&variavel.num2,&variavel.num3,&variavel.num4);
	return variavel;
}