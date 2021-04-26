/*
*	@file: Ejemplo de archivos	
*	@brief: Mostramos como abrir un archivo de diferentes maneras y leerlo
*	@author: Clase Guillermo Gómez Abascal
*	@date: 03/02/2021
*/

#include <stdio.h>

int main(int argc, char *argv[]){
	int i;
	FILE *fp;
	char c;

	fp = fopen("letras.txt", "a");

	if (fp == NULL){
		printf("\nArchivo no disponible.\n");
		return 1;
	}

	for (i = 0; i < 10; i++){
		printf("Dame una letra: ");
		scanf(" %c", &c);
		fprintf(fp, "%c", c);	
	}

	

		
	fclose(fp);
	return 0;
}
