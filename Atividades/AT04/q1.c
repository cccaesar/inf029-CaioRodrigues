#include <stdio.h>

int soma(int x, int y);

int main(){
	int num1, num2, resultado;
	
	scanf("%d",&num1);
	scanf("%d",&num2);
	
	resultado = soma( num1, num2 );
	printf("%d\n",resultado);
}

int soma(int x, int y){
	return x + y;
}