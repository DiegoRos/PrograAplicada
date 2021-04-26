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
		nodo_final->next = pt->next;
		pt = pt->next;
		free(aux);
	}
	return pt;
}


/*
*	@brief: Esta función imprime una lista circulare entera.
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

int imprimirConPrioridad(ListaCircular *pt){
	ListaCircular *aux = pt;
	int prioridad;

	if (pt == NULL){
		printf("La lista está vacía.\n");
	}
	else{
		for (prioridad = 1; prioridad <= 4; prioridad++){
			do{
				if (aux->solicitud.prioridad == prioridad)
					printf("\tNombre: %s \tPrioridad: %i\n", aux->solicitud.nombre, aux->solicitud.prioridad);
				aux = aux->next;
			}while(aux != pt);
		}
	}
	
	return 1;
}

ListaCircular * borrarNodoPrioridad(ListaCircular *pt){
	ListaCircular *aux = pt;

	int prioridad;

	if (pt == NULL){
		printf("Lista Vacía\n");
	}
	else{
		for(prioridad = 1; prioridad <= 4; ++prioridad){
			printf("Prioridad %d:\n", prioridad);
			do{
				if (aux->solicitud.prioridad == prioridad){
					if((aux == pt) && (aux != NULL)){
						pt = aux->next;
					}
					printf("\tNombre: %s \tPrioridad: %i\n", aux->solicitud.nombre, aux->solicitud.prioridad);
					aux = borrarNodo(aux);
					if(aux == NULL)
						break;
				}
				else{
					aux = aux->next;
				}
					
			}while(aux->next != pt);
			if (aux == NULL)
				break;	
			if(aux->solicitud.prioridad == prioridad){
				printf("\tNombre: %s \tPrioridad: %i\n", aux->solicitud.nombre, aux->solicitud.prioridad);
				aux = borrarNodo(aux);
			}
			else{
				aux = aux->next;
			}
		}
	}
	pt = aux;
	return pt;
}
