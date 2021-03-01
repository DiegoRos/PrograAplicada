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


Lista *fifoCodyMes(Lista *pt)
{
int codPostal = 0;
char Mes[20];

Lista *inicio2,*inicio,*aux,*nuevo;
aux = pt;
nuevo = pt;

inicio = (Lista *)malloc(sizeof(Lista);

if(inicio == NULL)
 {
  printf("memoria no disponible");
  exit(1);
 }
inicio = NULL;

if(pt != NULL)
 {
  printf("\nFavor de ingresar codigo postal:\n");
  scanf("%i",&codPostal);
  printf("\nFavor de ingresar mes: :\n");
  scanf(" %[^\n]",Mes);

while(pt != NULL)
 {
  if((aux->solicitud.cp == codPostal) && (aux->solicitud.mes == Mes)
   {
    nuevo->solicitud = pt->solicitud;
    nuevo->next = inicio;
    inicio = nuevo;
    inicio2 = inicio;
   }
 }
}else{
  printf("lista vacia");
 }

return inicio2;
}
