// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Caio César Rodrigues Costa
//  email: ccsrrdrgscosta@gmail.com
//  Matrícula: 2019116052
//  Semestre: 2021.1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>
#include <locale.h>

int tamanhoString( char *string );
/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma = 0;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
    int fat = 1;
    return fat;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd e mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */

int souUmNumero( char c ){
	switch(c){
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			return 1;
		
		default:
			return 0;
	}
}
 
int converterCharEmInt(char c){
	switch(c){
		case '0':{
			return 0;
		}
		case '1':{
			return 1;
		}
		case '2':{
			return 2;
		}
		case '3':{
			return 3;
		}
		case '4':{
			return 4;
		}
		case '5':{
			return 5;
		}
		case '6':{
			return 6;
		}
		case '7':{
			return 7;
		}
		case '8':{
			return 8;
		}
		case '9':{
			return 9;
		}
	}
}

int converterStringEmInt(char *string){
	int i, num = 0;
	
	for(i=0; string[i] != '\0'; i++){
		num = (num * 10) + converterCharEmInt(string[i]);
	}
	return num;
}

int converterAnoEmInt( char *sAno, int *iAno )
{
	int length;
	length = tamanhoString( sAno );
	if( length == 3 || length == 1 || length > 4)
		return 0;
	else{
		if( length == 2 )
			*iAno = 2000 + converterStringEmInt(sAno);
		else
			*iAno = converterStringEmInt(sAno);
		return 1;
	}
}

int verificarDataString(char *data){
	int i, qtd_barras = 0, qtd_numeros = 0;;
	
	for(i=0; data[i] != '\0'; i++){
		if(data[i] == '/' && qtd_numeros == 0)
			return 0;
		else if (data[i] == '/'){
			qtd_barras++;
			if( qtd_barras < 2 && (qtd_numeros < 1 || qtd_numeros > 2 )){
				return 0;
			}
			qtd_numeros = 0;
		}
		else if( souUmNumero( data[i] ) ){
			qtd_numeros++;
		}
	}
	if( qtd_numeros < 2 ){
		return 0;
	}
	return 1;
	
} 

int tamanhoString( char *string )
{
	int i;
	for(i=0; string[i] != '\0'; i++ );
	
	return i;
}

void quebrarData(char *data, char *dia, char *mes, char *ano)
{
	int i,j, estagio = 1;
	for(i=0, j=0; data[i] != '\0'; i++, j++){
		switch( estagio ){
			case 3:{
				ano[j] = data[i];
				if(data[i+1] == '\0')
					ano[j+1] = '\0';
				break;
			}
			case 2:{
				if( data[i] == '/' ){
					mes[j] = '\0';
					j = -1;
					estagio = 3;
				}
				else
					mes[j] = data[i];
				break;
			}
			case 1:{
				if( data[i] == '/' ){
					dia[j] = '\0';
					j = -1;
					estagio = 2;
				}
				else
					dia[j] = data[i];
				break;
			}
		}
	}
}

int verificarBissexto(int ano){
    if( ano % 4  != 0){
		return 0;
	}
    else if(ano % 100 != 0){
		return 1;
	}
    else if( ano % 400 != 0){
		return 0;
	}
    else{
		return 1;
	}
}

int ultimoDiaMes( int mes, int ano ){
	
	if( mes == 2 && verificarBissexto( ano )){
		return 29;
	}
	else if( mes == 2 && !verificarBissexto( ano )){
		return 28;
	}
	else if( mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12 ){
		return 31;
	}
	else
		return 30;
}

int verificarDataInt(int dia, int mes, int ano){
	
	if( dia <= 0 || mes <= 0 || ano < 10   || ( ano > 99 && ano < 999  ) || mes > 12)
		return 0;
	if( dia > ultimoDiaMes( mes, ano )  )
		return 0;
	else
		return 1;
	 
}

int q1(char *data)
{
    int datavalida = 0;
	char sDia[3], sMes[3], sAno[5];
	int iDia, iMes, iAno;
	
	datavalida = verificarDataString( data );
	if(datavalida == 0)
		return 0;
	quebrarData(data, sDia, sMes, sAno);
	
	iDia = converterStringEmInt(sDia);
	iMes = converterStringEmInt(sMes);
	datavalida = converterAnoEmInt(sAno, &iAno);
	
	if(datavalida == 0)
		return 0;
		
	datavalida = verificarDataInt( iDia, iMes, iAno );
    //quebrar a string data em strings sDia, sMes, sAno

    //converter sDia, sMes e sAno em inteiros (ex: atoi)

    //criar as variáveis iDia, iMes, iAno

    //printf("%s\n", data);

    return datavalida;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
 
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos)
{
	
    //calcule os dados e armazene nas três variáveis a seguir
    int nDias = 0, nMeses = 0, nAnos = 0;
	char sDia1[3], sMes1[3], sAno1[5]; 
	char sDia2[3], sMes2[3], sAno2[5];
	int iDia1, iMes1, iAno1, iDia2, iMes2, iAno2;
	int diaCont, mesCont, anoCont, mesCont2, anoCont2;
    if (q1(datainicial) == 0)
        return 2;
	if (q1(datafinal) == 0)
        return 3;
	
	quebrarData(datainicial, sDia1, sMes1, sAno1);
	quebrarData(datafinal, sDia2, sMes2, sAno2);
	iDia1 = converterStringEmInt(sDia1); iDia2 = converterStringEmInt(sDia2); iMes1 = converterStringEmInt(sMes1);
	iMes2 = converterStringEmInt(sMes2); iAno1 = converterStringEmInt(sAno1); iAno2 = converterStringEmInt(sAno2);
	if( iAno1 > iAno2)
		return 4;
	else if( iAno1 == iAno2 )
			if( iMes1 > iMes2 )
				return 4;
			else if( iMes1 == iMes2 && iDia1 > iDia2 )
				return 4;
	
	if( iDia1 == iDia2 && iMes1 == iMes2 ){
		nAnos = iAno2 - iAno1;
	}
	
	else if( iDia1 == iDia2 && iAno1 == iAno2 ){
		nMeses = iMes2 - iMes1;
	}
	else if(iMes1 == iMes2 && iDia1 == iDia2){
		nDias = iDia2 - iDia1;
	}
	
	diaCont = iDia1, mesCont = iMes1,  anoCont2 = anoCont = iAno1;
	nAnos = iAno2 - iAno1;
	nMeses = iMes2 - iMes1;
	nDias = iDia2 - iDia1;
	if( iDia1 > iDia2){
		nDias = (ultimoDiaMes( iMes1, iAno1 ) - iDia1) + iDia2;
		if( iMes2 > 1 && nDias >= ultimoDiaMes( iMes2, iAno2 ) ){
			nDias = ultimoDiaMes( iMes2, iAno2 ) - nDias;
			nMeses++;
		}
		else if( iMes2 == 1 && nDias >= 31){
			nDias = nDias - 31;
		}
			
	}
	if( iMes1 < iMes2 || ( iMes1 == iMes2 && iDia2 > iDia1) ){
		nAnos = iAno2 - iAno1;

	}
    /*mantenha o código abaixo, para salvar os dados em 
    nos parâmetros da funcao
    */
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;

    //coloque o retorno correto
    return 1;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
 
int verificarVogal( char c){
	setlocale(LC_ALL, "");
	int i;
	char vogais[99] = "AaÄäÁáÀàÃãÂâEeËëÉéÈèÊêIiÏïÍíÌìÎîUuÛûÙùÚúÜüOoÖöÔôÒòÓóÕõ";
	for(i=0; vogais[i] != '\0'; i++){
		if(c == vogais[i])
			return 1;
	}
	return 0;
}

char removerAcento( char c ){
	setlocale(LC_ALL, "");
	if(c == "á"[1] || c == "Á"[1] || c == "à"[1] || c == "À"[1] || c == "â"[1] || c == "Â"[1] || c == "Ã"[1] || c == "ã"[1] || c == "Ä"[1] || c == "ä"[1])
		return 'a';
	if(c == "Í"[1] || c == "í"[1] || c == "Ì"[1] || c == "ì"[1] || c == "Ï"[1] || c == "ï"[1] || c == "Î"[1] || c == "î"[1])
		return 'i';
	if(c == "Ú"[1] || c == "ú"[1] || c == "Ù"[1] || c == "ù"[1] || c == "Û"[1] || c == "û"[1] || c == "Ü"[1] || c == "ü"[1])
		return 'u';
	if(c == "Ô"[1] || c == "ô"[1] || c == "Ó"[1] || c == "ó"[1] || c == "Õ"[1] || c == "õ"[1] || c == "Ö"[1] || c == "ö"[1] || c == "Ò"[1] || c == "ò"[1])
		return 'o';
	if(c == "É"[1] || c == "é"[1] || c == "Ê"[1] || c == "ê"[1] || c == "È"[1] || c == "è"[1] || c == "Ë"[1] || c == "ë"[1])
		return 'e';
	else
		return c;
}

char removerAcentoCaseSensitive( char c ){
	setlocale(LC_ALL, "");
	// "ÇçÄäÁáÀàÃãÂâËëÉéÈèÊêÏïÍíÌìÎîÛûÙùÚúÜüÖöÔôÒòÓóÕõ";
	if(c == "á"[1] || c == "à"[1] || c == "â"[1] || c == "ã"[1] || c == "ä"[1])
		return 'a';
	if(c == "Á"[1] || c == "À"[1]|| c == "Â"[1] || c == "Ã"[1] || c == "Ä"[1])
		return 'A';
	if(c == "Í"[1] || c == "Ï"[1] || c == "Ì"[1] || c == "Î"[1])
		return 'I';
	if(c == "í"[1] || c == "ï"[1] || c == "ì"[1] || c == "î"[1])
		return 'i';
	if(c == "Ú"[1] || c == "Û"[1] || c == "Ù"[1] || c == "Ü"[1])
		return 'U';
	if(c == "ú"[1] || c == "ü"[1] || c == "û"[1] || c == "ù"[1])
		return 'u';
	if(c == "Ô"[1] || c == "Ó"[1] || c == "Õ"[1] || c == "Ö"[1] || c == "Ò"[1])
		return 'O';
	if(c == "ô"[1]|| c == "ó"[1]|| c == "õ"[1] || c == "ö"[1] || c == "ò"[1] )
		return 'o';
	if(c == "É"[1] || c == "Ê"[1] || c == "Ë"[1] || c == "È"[1])
		return 'E';
	if( c == "é"[1] || c == "ê"[1] || c == "ë"[1] || c == "è"[1] )
		return 'e';
	else
		return c;
}

int buscaCaracteres( char *string, char c, int isCaseSensitive ){
	setlocale(LC_ALL, "");
	int i, qtdOcorrencias = 0, vogal = 0;
	char c2 = c, str2[250];
	vogal = verificarVogal( c );
	if(vogal && isCaseSensitive){
		c2 = removerAcentoCaseSensitive(c);
	}
	else if( vogal )
		c2 = removerAcento( c );
	//printf("%c\n", c2);
	if(isCaseSensitive){
		if(c2 == "Ç"[1])
			c2 = 'C';
		else if(c2 == "ç"[1])
			c2 = 'c';
		for( i=0; string[i] != '\0'; i++){
			if( vogal )
				string[i] = removerAcentoCaseSensitive( string[i] );
			else if((c2 == 'c' && string[i] == "ç"[1]) || (c2 == 'C' && string[i] == "Ç"[1] )){
				qtdOcorrencias++;
			}
			if( string[i] == c2 )
				qtdOcorrencias++;
		}
	}
	else{
		if(c2 == "ç"[1] || c2 == "Ç"[1])
			c2 = 'c';
		if( c <= 90 && c >= 65)
			c2 = c + 32;
		for( i=0; string[i] != '\0'; i++){
			if( string[i] >= 65 && string[i] <= 90 && vogal == 0){
				str2[i] = string[i] + 32;
			}
			else if(string[i] == "ç"[1] || string[i] == "Ç"[1])
				str2[i] = 'c';
			else if((string[i] >= -128 && string[i] <= -100 ))
				str2[i] = removerAcento(string[i]);
			else /*if(string[i] != -61)*/{
				str2[i] = string[i];
			}
			if(str2[i] == c2){
				qtdOcorrencias++;
			}
		}
		str2[i] = '\0';
	}
	return qtdOcorrencias;
}

int q3(char *texto, char c, int isCaseSensitive)
{
	setlocale(LC_ALL, "");
    int qtdOcorrencias = -1, i;
	char caractere[2];
	qtdOcorrencias = buscaCaracteres( texto, c, isCaseSensitive);
    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = -1;

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int potenciacao(int base, int expoente){
	int resultado;
	if( base == 0 )
		resultado = -1;
	else if(expoente == 1)
		resultado = base;
	else if(expoente == 0)
		resultado = 1;
	else
		resultado = base * potenciacao(base , expoente - 1);
	return resultado;
}

int q5(int num)
{
	int i, j, numInvertido = 0;
	
	if(num / 10 != 0){
		
		for(i=1; num >= i; i *= 10){
		}
		i = i / 10;
		
		for(j = 0; i > 1; i = i / 10, j++){
			numInvertido += ((num / i) - ((num / ( i * 10) )* 10 )) *  potenciacao(10 , j);
		}
		numInvertido += (num % 10) * potenciacao(10 , j) ;
		num = numInvertido;
	}
    return num;
}

/*
 Q5 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias;
	
    return qtdOcorrencias;
}
