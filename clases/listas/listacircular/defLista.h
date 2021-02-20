#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Datos{
	char nombre[40];
	int prioridad;
}Info;

typedef struct ListaCircular{
	Info solicitud;
	struct ListaCircular *next;
}ListaCircular;

ListaCircular * anexarNodo(Info dato, ListaCircular *pt){
	ListaCircular *aux, *nodo_nuevo;
	aux = pt;

	nodo_nuevo = (ListaCircular *)malloc(sizeof(ListaCircular));
	nodo_nuevo->solicitud = dato;

	if (pt == NULL){
		nodo_nuevo->next = nodo_nuevo;
		return nodo_nuevo;
	}	

	while (aux->next != pt){
		aux = aux->next;
	}
	aux->next = nodo_nuevo;
	nodo_nuevo->next = pt;
	
	return pt;	
}

ListaCircular * borrarNodo(ListaCircular *pt){
	ListaCircular *nodo_inicial = pt->next;
	ListaCircular *aux = pt;
	ListaCircular *nodo_final = pt;

	if (pt == NULL){
		printf("Lista vacía\n");
	}
	else if(pt == pt->next){
		pt = NULL;
		free(aux);
	}
	else{
		while(nodo_final->next != pt){
			nodo_final = nodo_final->next;
		}
		nodo_final->next = nodo_inicial;
		pt = nodo_inicial;
		free(aux);
	}
	return pt;
}

ListaCircular * borrarNodoPrioridad(int prioridad, ListaCircular *pt){
	ListaCircular *aux = pt, *nodo_inicial = pt;
	if (pt == NULL){
		printf("Lista Vacía\n");
	}
	else{
		do{
			if (pt->solicitud.prioridad == prioridad){
				if(pt == nodo_inicial){
					nodo_inicial = pt->next;
				}
				pt = borrarNodo(pt);
			}
			else{
				pt = pt->next;
			}
			printf("\tNombre: %s \tP:%i\n", pt->solicitud.nombre, pt->solicitud.prioridad);
			printf("\t\tSiguiente: %s\tInicial: %s\n",pt->next->solicitud.nombre,nodo_inicial->solicitud.nombre);
		}while(pt->next != nodo_inicial);
	}

	if(pt->solicitud.prioridad == prioridad){
		pt = borrarNodo(pt);
	}
	else{
		pt = pt->next;
	}
	printf("\n");
	return pt;
}

/*
*	@brief: Esta función imprime un stack entero
*	@author: Diego Rosenberg de Angoitia
*	@param ListaCircular *pt
*	@return int
*/
int imprimirCola(ListaCircular *pt){
	ListaCircular *aux = pt;

	if (pt == NULL){
		printf("La lista está vacía.\n");
	}

	else{
		do{
			printf("\tNombre: %s \tPrioridad: %i\n", aux->solicitud.nombre, aux->solicitud.prioridad);
			aux = aux->next;
		}while(aux != pt);
	}
	return 1;
}

