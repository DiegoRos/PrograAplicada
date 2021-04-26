/*
*	@file: listSimpleCirc.c	
*	@brief: Se hará un programa que construya una lista simple circular ocn reglas:
*		Reglas o procesos para crear una COla de antención de solicitudes.
			1.- Una cola vacía en un inicio es NULL
			2.- Cuando tenga un solo nodo este se apunta a si mismo.
			3.- Cuand llega  un segundo y subsecuente nodo, debo ir al final de la lista e insertarlos ahí. 
				¿Cómo sé que es el final de la lista? Por que un puntero auxiliar recorre tod y  llega a auxiliar-> next = inicial
			4.- Para borrar un nodo atendido debo borrar el primero de la lista.
			5.- Si establezco una prioridad par borarr nodos del queue.
			6.- Nunca debo perder el inicio del queue. 
*	@author: Clase Guillermo Gómez Abascal
*	@date: 19/02/2021
*/

#include "defLista.h"

//nodo * anexaNodo(Info *dat, ListaCircular *pt);
//int imprimirCola(ListaCircular *pt);
//nodo * borrarNodo(ListaCircular *pt);

int main(int argc, char *argv[]){
	Info datos;
	ListaCircular *inicio;
	FILE *fp;
	
	inicio = NULL;
	fp = fopen(argv[1], "r");
	
	if (fp == NULL){
		printf("\nArchivo no disponible\n");
		exit(1);
	}
	while(fscanf(fp, "%[^\t]%i\n", datos.nombre, &datos.prioridad) == 2){
		inicio = anexarNodo(datos, inicio);
	}

	fclose(fp);

	printf("\nImpresión de la cola creada:\n");
	imprimirConPrioridad(inicio);

	printf("\nBorrar por prioridad.\n");
	inicio = borrarNodoPrioridad(inicio);
	imprimirCola(inicio);
	
	/*
	printf("\nAtender todas las solicitudes:\n");
	while (inicio != NULL){
		printf("\nNodo a borrar: %s\t%i\n", inicio->solicitud.nombre, inicio->solicitud.prioridad);
		inicio = borrarNodo(inicio);
		printf("\nLista Resultante:\n");
		imprimirCola(inicio);
	}
	*/

	return 0;
}
