#include <stdio.h>

void contarAntecessoresNaturais(int n){
	if( n <= 0)
		printf("0\n");
	else{
		printf("%d\n", n);
		contarAntecessoresNaturais( n - 1 );
	}
}