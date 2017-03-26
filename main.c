

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "funciones.h"




int main(){
	char caracteres[250];
	char nameFile[250];
	memset(caracteres,0,sizeof(caracteres));
	memset(nameFile,0,sizeof(nameFile));
	char option[250];
	do{
		printf("         MENU\n");
		printf("1) Generar palabras.\n");
		printf("2) Salir\n" );
		printf("\nIngrese una option: ");
		memset(option,0,sizeof(option));
		fflush(stdin);
		scanf("%s",option);
		if (!strcmp(option,"1")){
			memset(nameFile,'0',255);
			//char stringBuffer[LARGOLINE];
			printf("\nIngrese el nombre de un archivo: ");
			scanf("%s", nameFile);
					
			if (existsFile(nameFile)){
				buscarCaracteres(caracteres,nameFile);
				printf("Generando combinaciones...\n");
				generarCombinaciones(caracteres);
				printf("Combinaciones generadas.\n");
				printf("Las palabras se encuentran en el archivo 'salida.txt'.\n\n");
						
			}
			else{
				printf("El archivo ingresado no existe\n\n");
			}
		}

		}while(strcmp(option,"2"));
}























     
