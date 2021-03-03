#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
	int val;
	struct Lista *next;
}Lista;

Lista * enQueue(int val, Lista *pt){
	Lista *aux;
	aux = pt;

	Lista *nodo_nuevo = (Lista *)malloc(sizeof(Lista));
	nodo_nuevo->val = val;
	nodo_nuevo->next = NULL;
	if (pt == NULL){
		pt = nodo_nuevo;
	}	
	else{
		while (aux->next != NULL){
			aux = aux->next;
		}
		aux->next = nodo_nuevo;
	}
	
	return pt;	
}

/*
*	@brief: Inserta un nuevo nodo en la lista LIFO con un char
*	@author: Diego Rosenberg de Angoitia
*	@param char letra
*	@param Stack *s
*	@return Stack*
*/
Lista * push(int val, Lista *pt){
	Lista *nuevo = (Lista *)malloc(sizeof(Lista));
	
	neuvo->val = val;
	aux->next = pt;
	s = aux
	return s;
}

Lista * pop(Lista *pt){
	Lista *aux = pt;
	if (pt == NULL){
		printf("Lista vacía\n");
	}
	else{
		pt = pt->next;
		free(aux);
	}
	return pt;
}
