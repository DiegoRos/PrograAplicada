#include "defLista.h"

/*
*	@brief: Inserta un nuevo nodo en la lista LIFO circular con un Ciudadano 
*	@author: 
*	@param Ciudadano nuevo
*	@param Lista *s
*	@return Lista *
*/
Lista * push2(Ciudadano nuevo, Lista *pt){
	Lista *aux = (Lista *)malloc(sizeof(Lista));

	aux->solicitud = nuevo;
	aux->next = pt;
	pt = aux;
	return pt;
}

Lista * funcion2(Lista * inicio1){
	Lista *inicio3 = NULL;
	char letra;
	Lista *aux = inicio1;
	
	printf("\nLetra en Mayúscula: ");
	scanf(" %c", &letra);

	do{
		if (aux->solicitud.nombre[0] == letra){
			inicio3 = push2(aux->solicitud, inicio3);
		}
		aux = aux->next;
	}while(aux != NULL);

	return inicio3;
}
