#include <stdio.h>

int subtrai(int x, int y, int z);

int main(){
	int num1, num2, num3, resultado;
	
	scanf("%d%d%d",&num1,&num2,&num3);
	resultado = subtrai( num1, num2, num3);
	printf("%d\n", resultado);
}

int subtrai(int x, int y, int z){
	return x - y - z;
}