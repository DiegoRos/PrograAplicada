/*
*	@file: Funciones.c
*	@brief: Contiene todas las funciones para correr el valor de main entero
*	@author: Equipo 3
*	@date: 01/03/2021
*/

#include "defLista.h" 

/*
*	@brief:
*	@author:
*	@param 
*	@param
*	@return
*/
Queue * enQueue(char val, Queue *q){
	Queue *aux;
	aux = q;

	Queue *nodo_nuevo = (Queue *)malloc(sizeof(Queue));
	nodo_nuevo->val = val;
	nodo_nuevo->next = NULL;
	if (aux == NULL){
		return nodo_nuevo;
	}	

	while (aux->next != NULL){
		aux = aux->next;
	}
	aux->next = nodo_nuevo;
	
	return q;	
}

/*
*	@brief:
*	@author:
*	@param 
*	@param
*	@return
*/
Queue * deQueue(Queue *q){
	Queue *aux;
	if (q == NULL){
		printf("Lista vacía\n");
	}
	else{
		aux = q;
		q = q->next;
		free(aux);
	}
	return q;
}

/*
*	@brief: Esta función imprime un queue entero
*	@author: Equipo 3
*	@param Stack *q
*	@return Stack *q
*/
int imprimirQueue(Queue *q){
	while (s != NULL){
		printf("La letra es: %c\n", q->letra);
		q = q->next;
	}

	return 1;
}
