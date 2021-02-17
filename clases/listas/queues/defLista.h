#include <stdio.h>
#include <stdlib.h>

// Estructura de Lista FIfo (First In First Out aka Queue)
typedef struct Queue{
	char val; // Puede ser lo que sea char, char[], float, etc.
	struct Queue *next;
}Queue;

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

Queue * deQueue(Queue *q){
	if (q == NULL){
		printf("Lista vacía\n");
	}
	else{
		q = q->next;
	}
	return q;
}

/*
*	@brief:
*	@author:
*	@param 
*	@param
*	@return
*/
int imprimirLista(Queue *q){
	while (q != NULL){
		printf("La letra es: %c\n", q->val);
		q = q->next;
	}

	return 0;
}
