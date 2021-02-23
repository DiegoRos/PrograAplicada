#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Persona{
	char nombre[80];
	char direccion[80];
	int telefono;
	char covid; //Booleano 's' o 'n'
}Paciente;

typedef struct ListaCircular{
	Paciente solicitud;
	struct ListaCircular *next;
}ListaCircular;
/*
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
*/
