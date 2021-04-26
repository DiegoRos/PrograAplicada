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
	char palabra[50];

	fp = fopen("frases.txt", "w");

	if (fp == NULL){
		printf("\nArchivo no disponible.\n");
		return 1;
	}

	for (i = 0; i < 3; i++){
		printf("Dame frase: ");
		scanf(" %[^\n]", palabra);
		fprintf(fp, "%s\n", palabra);	
	}

	

		
	fclose(fp);
	return 0;
}
