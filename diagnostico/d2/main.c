/*
*	@file: main.c	
*	@brief: Cotine el código principal del examen diagnóstio 2
*	@author: Equipo 3
*	@date: 26/03/2021
*/

#include "Diag02def.h"

Arbol *readTxt(char *nombre_file);
void recorrer(Arbol *pt);

int main(int argc, char *argv[]){
	if (argc != 2){
		printf("Número incorrecto de entradas\n");
		exit(1);
	}

	Arbol *root = NULL;

	root = readTxt(argv[1]);
	printf("\nPalabras: \n");	
	recorrer(root);

	return 0;
}

