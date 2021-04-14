#include <stdio.h>

int validarData( int dia, int mes, int ano );
int verificarBissexto(int ano);

int verificarBissexto(int ano){
    if( ano % 4 ){
		return 0;
	}
    else
        if(ano % 100){
			return 1;
		}
        else if( ano % 400){
			return 0;
		}
        else{
			return 1;
		}
}

int validarData( int dia, int mes, int ano )
{
	int valido = 1;
	if( dia > 31 || dia < 1 ){
		valido = 0;
	}
	if( mes > 12 || mes < 1){
		valido = 0;
	}
	
	if( ano > 2021 || ano < 1)
		valido = 0;
	if( (mes == 4 || mes == 6 ||  mes == 9 || mes == 11) && dia > 30)
		valido = 0;
	if( mes == 2 && dia > 29 && verificarBissexto( ano ))
		valido = 0;
	else if( mes == 2 && dia > 28)
		valido = 0;
	
	return valido;
}