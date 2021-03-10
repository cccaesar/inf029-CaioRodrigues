#include <stdio.h>

void ler3Numeros(int numeros[]);

int main(){
	int num[3], i;
	
	ler3Numeros(num);
	
	printf("Valores inseridos:\n");
	for(i=0; i<3; i++)
		printf("%d\n",num[i]);
}

void ler3Numeros(int numeros[]){
	scanf("%d%d%d",&numeros[0],&numeros[1],&numeros[2]);
}