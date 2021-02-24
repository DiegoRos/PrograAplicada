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
*	@author: Diego Rosenberg de Angoitia
*	@param Stack *s
*	@return Stack *s
*/
int imprimirQueue(Queue *q){
	while (s != NULL){
		printf("La letra es: %c\n", q->letra);
		q = q->next;
	}

	return 1;
}
