#include <stdio.h>
#include <stdlib.h>

// Estructura de Lista Enlazada
struct LinkedList{
	int val;
	struct LinkedList *next;
};

// Estructura de Lista FIfo (First In First Out aka Queue)
typedef struct Queue{
	int num; // Puede ser lo que sea char, char[], float, etc.
	struct Queue *next;
}Queue;

Queue * enqueue(Queue *q, int val){
	Queue *aux;
	aux = q;

	Queue *nodo_nuevo = (Queue *)malloc(sizeof(Queue));
	nodo_nuevo->num = val;
	nodo_nuevo->next = NULL;
	if (aux == NULL){
		return nodo_nuevo;
	}	

	while (aux != NULL){
		aux = aux-> next;
	}
	aux->next = nodo_nuevo;
	
	return q;	
}

Queue * dequeue(Queue *q){
	int val;
	if (s == NULL)
		return NULL;

	val = q->letra;
	q = q->next;
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
	char val;
	if (s == NULL)
		return NULL;

	val = s->letra;
	s = s->next;
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
