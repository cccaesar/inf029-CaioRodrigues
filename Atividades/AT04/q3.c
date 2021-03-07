#include <stdio.h>

int calc_fatorial(int n);

int main(){
	int num, resultado;
	
	scanf("%d",&num);
	
	resultado = calc_fatorial( num );
	
	if(resultado)
		printf("Fatorial: %d \n", resultado);
	else
		printf("Nao foi possivel calcular o fatorial de %d \n", num);
	
}

int calc_fatorial(int n){
	
	if( n < 0)
		return 0;
	else if( n > 1 )
		return n * calc_fatorial( n - 1);
	
	return 1;
}