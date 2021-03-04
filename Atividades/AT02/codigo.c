#include <stdio.h>

void soma(int x, int y);
void subtracao(int x, int y);
void multiplicacao(int x, int y);
void divisao(int x, int y);

int main() {
	int num1, num2, opcao = 7;
	
	while(opcao){
		printf("Insira um numero inteiro\n");
		scanf("%d",&num1);
		printf("Insira um numero inteiro\n");
		scanf("%d",&num2);
		printf("\nSelecione uma opcao:\n[0] - Sair\n[1] - Somar\n[2] - Subtracao\n[3] - Multiplicacao\n[4] - Divisao\n");
		scanf("%d",&opcao);
		
		switch(opcao){
			case 1:
				soma(num1, num2);
				break;
			case 2:
				subtracao(num1, num2);
				break;
			case 3:
				multiplicacao(num1, num2);
				break;
			case 4:
				if(num2)
					divisao(num1, num2);
				else
					printf("Nao e possivel usar o zero como divisor\n");
				break;
			default:
				break;
		}
	}
}

void soma(int x, int y) {
	printf("%d + %d = %d\n", x, y, x + y);
}

void subtracao(int x, int y) {
	printf("%d - %d = %d\n", x, y, x - y);
}

void multiplicacao(int x, int y) {
	printf("%d * %d = %d\n", x, y, x*y);
}

void divisao(int x, int y) {
	printf("%d / %d = %d\n", x, y, x / y);	
}