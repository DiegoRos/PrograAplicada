/*
*	@file: listaLetras.c	
*	@brief: Este archivo toma letras del usuario y las guarda en un stack.
*	@author: Clase de Guillermo Gómez Abascal
*	@date: 15/02/2021
*/

#include "defLista.h"


int main(int argc, char *argv[]){
	Queue *letras;
	char letra;
	letras = NULL;

	do{
		printf("Dame una letra:");
		scanf(" %c", &letra);
		if (letra != '.') letras = enQueue(letra, letras);
	}while(letra != '.');
	printf("\n");

	imprimirLista(letras);

	printf("\n");

	while (letras != NULL){
		printf("El nodo a borrar tiene la letra: %c\n", letras->val);
		letras = deQueue(letras);	
	}	

	return 0;
}

