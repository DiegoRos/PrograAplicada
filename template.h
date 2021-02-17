#include <stdio.h>
#include <stdlib.h>

// Estructura de Lista Enlazada
struct LinkedList{
	int val;
	struct LinkedList *next;
};

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

// Estructura de Lista LIFO (Last In First Out aka Stack)
typedef struct Stack{
	char letra;
	struct Stack *next;
}Stack;

/*
*	@brief: Inserta un nuevo nodo en la lista LIFO con un char
*	@author: Diego Rosenberg de Angoitia
*	@param char letra
*	@param Stack *s
*	@return Stack*
*/
Stack * push(char letra, struct Stack *s){
	Stack *aux = (Stack *)malloc(sizeof(Stack));
	
	aux->letra = letra;
	aux->next = s;
	s = aux;
	return s;
}

/*
*	@brief: Quita el nodo mas nuevo de la lista LIFO
*	@author: Diego Rosenberg de Angoitia
*	@param Stack *s
*	@return Stack *
*/
Stack * pop(Stack *s){
	if (s == NULL){
		printf("Lista vacía\n");
	}
	else{
		s = s->next;
	}
	return s;
}

/*
*	@brief: Esta función imprime un stack entero
*	@author: Diego Rosenberg de Angoitia
*	@param Stack *s
*	@return Stack *s
*/
int imprimirStack(Stack *s){
	while (s != NULL){
		printf("La letra es: %c\n", s->letra);
		s = s->next;
	}

	return 0;
}
