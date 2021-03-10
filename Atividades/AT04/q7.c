#include <stdio.h>
#define TAM_PALAVRA 4
#define QTD_PALAVRAS 4

void ler4palavras(char palavras[][TAM_PALAVRA]);

int main(){
	char palavras[QTD_PALAVRAS][TAM_PALAVRA];
	int i,j;
	
	ler4palavras( palavras);
	printf("Palavras inseridas\n");
	for(i=0; i < QTD_PALAVRAS; i++){
		for(j=0; j < TAM_PALAVRA; j++)
			printf("%c",palavras[i][j]);
		printf("\n");
	}
	
}

void ler4palavras(char palavras[][TAM_PALAVRA]){
	int i;
	for(i=0; i < 4; i++){
		scanf(" %s", palavras[i]);
	}
}