#include <stdio.h>
#include <stdlib.h>

// Estructura de Lista LIFO (Last In First Out aka Stack)
typedef struct Stack{
	char letra;
	struct Stack *next;
}Stack;

/*
*	@brief: Inserta un nuevo nodo en la lista LIFO con un char
*	@author: Clase de Guillermo Gómez Abascal
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
*	@author: Clase de Guillermo Gómez Abascal
*	@param Stack *s
*	@return Stack *
*/
Stack * pop(struct Stack *s){
	Stack *aux;

	if (s == NULL){
		printf("La lista esta vacía");
	}
	else{	
		aux = s;
		s = s->next;
		free(aux);
	}
	return s;
}

/*
*	@brief:
*	@author:
*	@param 
*	@param
*	@return
*/
int imprimirLista(Stack *s){
	while (s != NULL){
		printf("La letra es: %c\n", s->letra);
		s = s->next;
	}

	return 0;
}
