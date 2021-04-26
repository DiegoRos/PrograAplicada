/*
*	@file: Parte2.c	
*	@brief: un archivo para crear una nueva lista LIFO apartir de una FIFO
*	@author: integrante 1
*	@date: 1/03/2021
*/

/*
*	@brief:Esta funcion crea una lista LIFO a partir de una FIFO
*	@author: integrante 1
*	@param: *pt que es de tipo Lista 
*	@return: inicio2 que es un apuntador de tipo Lista
*/

#include "defLista.h"

/*
*	@brief: Inserta un nuevo nodo en la lista LIFO circular con un Ciudadano 
*	@author: 
*	@param Ciudadano nuevo
*	@param Lista *s
*	@return Lista *
*/
Lista * push(Ciudadano nuevo, Lista *pt){
	Lista *aux = (Lista *)malloc(sizeof(Lista));

	aux->solicitud = nuevo;
	aux->next = pt;
	pt = aux;
	return pt;
}
Lista *fifoCodyMes(Lista *pt)
{
int codPostal;
char Mes[20];

Lista *inicio2,*inicio,*aux,*nuevo;
aux = pt;
nuevo = pt;


inicio = NULL;
inicio2 = NULL;

if(pt != NULL)
 {
  printf("\nFavor de ingresar codigo postal: ");
  scanf(" %i",&codPostal);
  printf("\nFavor de ingresar mes: ");
  scanf(" %s",Mes);

while(aux != NULL)
 {
  if((aux->solicitud.cp == codPostal) && (strcmp(aux->solicitud.mes, Mes) == 0))
   {
    inicio2 = push(aux->solicitud, inicio2);
   }
  aux = aux->next;
 }
}else{
  printf("lista vacia");
 }

return inicio2;
}
