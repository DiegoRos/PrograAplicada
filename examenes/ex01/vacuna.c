/*
*	@file: main.c	
*	@brief:
*	@author:
*	@date:
*/

#include "defLista.h"

Lista * leerTxt(char nombre_archivo[], Lista *pt);
int imprimirLista(Lista *q);
Lista * reducirEdades(Lista *inicio1, Lista *inicio4);
int imprimirStackCirc(Lista *pt);
Lista * fifoCodyMes(Lista *pt);
Lista * funcion2(Lista *inicio1);

int main(int argc, char *argv[]){
	if (argc != 2){
		printf("Número incorrecto de entradas\n");
		exit(1);
	}

	Lista *inicio1 = NULL, *inicio2 = NULL, *inicio3 = NULL, *inicio4 = NULL;
	inicio1 = leerTxt(argv[1], inicio1);
	printf("Lista completa de pacientes\n");
	imprimirLista(inicio1);
	printf("\n");

	int opcion;
	printf("Ingrese opción deseada:\n");
	printf("\t1: Generar lista utilizando\n");
	printf("\t2: Reducir por letra\n");
	printf("\t3: Reducir por rango de edades\n");
	scanf(" %i", &opcion);
	switch(opcion){
		case 1:
			inicio2 = fifoCodyMes(inicio1);
			imprimirLista(inicio2);	
			break;

		case 2:
			inicio3 = funcion2(inicio1);
			imprimirLista(inicio3);
			break;

		case 3:
			inicio4 = reducirEdades(inicio1, inicio4);
			imprimirStackCirc(inicio4);
			break;

	}

	return 0;
}


