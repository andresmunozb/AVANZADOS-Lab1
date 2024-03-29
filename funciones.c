
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "funciones.h"

/*
 * Funcion existsFile
*/
int existsFile(char* filename) {
	FILE* f = NULL;
	f = fopen(filename,"r");
	if (f == NULL)
		return 0;
	else {
		fclose(f);
		return 1;
	}
	return 0;
}

/*
 * Funcion isIn
*/
int isIn(char string[],char caracter){
	int i=0;
	for (i=0;i<strlen(string);i++){
		if (string[i]==caracter){
			return 1;
		}
	}
	return 0;
}

/*
 * Funcion consecutive
*/
int consecutive(char* string){
	int i;
	for (i = 0; i < strlen(string)-2; ++i)
	{
		if (isLetter(string[i]) && isLetter(string[i+1]) && isLetter(string[i+2])){
			return 1;
		}
		if (isNumber(string[i]) && isNumber(string[i+1]) && isNumber(string[i+2])){
			return 1;
		}
	}
	return 0;
}

/*
 * Funcion isLetter
*/
int isLetter(char caracter){
	if (caracter>=97 && caracter<=122){
		return 1;
	}
	return 0;
}

/*
 * Funcion isNumber
*/
int isNumber(char c){
	if (c>= 48 && c<=57){
		return 1;
	}
	return 0;
}

/*
 * Funcion isVocal
*/
int isVocal(char c){
	if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
		return 1;
	}
	return 0;
}

/*
 * Funcion validWord
*/
int validWord(char* palabra){

	if(consecutive(palabra)){

		return 0;
	}
	if(isNumber(palabra[0]) && isNumber(palabra[strlen(palabra)-1])){
		return 0;
	}
	if (isVocal(palabra[0])){
		return 0;
	}
	return 1;
}

/*
 * Funcion searchCharacters
*/
void searchCharacters(char* caracteres, char* nombreFile){


    FILE* archivoEntrada;
	archivoEntrada = fopen(nombreFile,"r");
	char buffer;
	int contador=0;
	while (!feof(archivoEntrada)){

		fscanf(archivoEntrada,"%c\n",&buffer);
		//printf("%c\n",buffer );
		if(!isIn(caracteres,buffer) && (isLetter(buffer) || isNumber(buffer)) ){
			caracteres[contador]=buffer;
			contador++;
		}
		//printf("%s\n", caracteres);
	}
	fclose(archivoEntrada);

}

/*
 * Funcion generateCombinations
 * Aqui es donde se utiliza fuerza bruta.
*/
void generateCombinations(char* caracteres){

    FILE* archivoSalida;
	archivoSalida = fopen("salida.out","w");
	int cantidad = strlen(caracteres);
    char string[] = { '0', '0', '0', '0', '0','0', '0', '0', '\0' };
    int i,j,k,l,m,o,p,q;
    //printf("%s\n", caracteres);
    for (i=0;i<cantidad;i++){
		for (j=0;j<cantidad;j++){
    		for (k=0;k<cantidad;k++){
    			for (l=0;l<cantidad;l++){
    				for (m=0;m<cantidad;m++){
    					for (o=0;o<cantidad;o++){
    						for (p=0;p<cantidad;p++){
    							for (q=0;q<cantidad;q++){

    								string[0]=caracteres[i];
    								string[1]=caracteres[j];
    								string[2]=caracteres[k];
    								string[3]=caracteres[l];
    								string[4]=caracteres[m];
    								string[5]=caracteres[o];
    								string[6]=caracteres[p];
    								string[7]=caracteres[q];

    								if (validWord(string)){
    									//printf("%s\n",string );
										fputs(string,archivoSalida);
										fputs("\n",archivoSalida);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	fclose(archivoSalida);
}
