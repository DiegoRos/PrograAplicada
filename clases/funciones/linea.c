/*
*	@file: linea.c	
*	@brief: Este es un ejemplo del uso de la línea de comandos
*	@author: Clase de Guillermo Gómez
*	@date: 18/01/2021
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	
	printf("El usuario ingresió %d argumentos, sin incluir el ejecutable\n", argc - 1);
	for(int i = 1; i < argc; i++){
		printf("%s%c", argv[i], (i < (argc - 1)) ? ' ' : '\n');
	}

	return 0;
}

