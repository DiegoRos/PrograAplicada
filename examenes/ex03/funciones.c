/*
*	@file: funciones.c
*	@brief: Contiene las funciones necesarias para completar el examen3
*	@author: Equipo 3
*	@date: 10/05/2021
*/
#include "defGTK.h"

/*
*	@brief: Cierrra la aplicación
*	@author: Equipo 3
*	@param GtkWidget *window
*	@param gpointer data
*	@return void
*/
extern void closeTheApp(GtkWidget *window, gpointer data)
{
  gtk_main_quit();

  return;
}

/*
*	@brief: Inserta un nuevo nodo en la lista LIFO con un char
*	@author: Equipo 3
*	@param nodo nuevo
*	@param nodo *s
*	@return nodo*
*/
void push(GtkWidget *boton, base *pt){
	nodo *aux = (nodo *)malloc(sizeof(nodo));
  char buffer[50];
  
	strcpy(aux->val.nombre, gtk_entry_get_text(GTK_ENTRY(pt->datoNom)));
  sprintf(gtk_entry_get_text(GTK_ENTRY(pt->datoAge)), "%i", aux->val.edad);

  printf("Push: %s %i", aux->nombre, aux->edad);

  ++(pt->cantidad_push);
	aux->next = pt->ref;
	pt->ref = aux;
	
  sprintf(buffer, "Van %i Push y %i Pop", pt->cantidad_push, pt->cantidad_pop);
  gtk_label_set_text(GTK_LABEL(pt->label3), buffer);
}

/*
*	@brief: Quita el nodo mas nuevo de la lista LIFO
*	@author: Equipo 3
*	@param GtkWidget *boton
*	@param base *pt
*	@return void
*/
void pop(GtkWidget *boton, base *pt){
  char buffer[50];
	nodo *aux = pt->ref;
	if (s == NULL){
		printf("Lista vacía\n");
	}
	else{
    ++(pt->cantidad_pop);
    printf("Pop: %s %i", pt->ref->nombre, pt->ref->edad);
		pt->ref = pt->ref->next;
		free(aux);

    sprintf(buffer, "Van %i Push y %i Pop", pt->cantidad_push, pt->cantidad_pop);
    gtk_label_set_text(GTK_LABEL(pt->label3), buffer);
	}

}

/*
*	@brief: Esta función 
*	@author: Equipo 3
*	@param GtkWidget *boton
*	@param base *pt
*	@return void
*/
extern void modulo1(GtkWidget *boton, base *pt){

}

/*
*	@brief: Esta función
*	@author: Equipo 3
*	@param GtkWidget *boton
*	@param base *pt
*	@return void
*/
extern void modulo2(GtkWidget *boton, base *pt){
  
}

/*
*	@brief: Esta función
*	@author: Equipo 3
*	@param GtkWidget *boton
*	@param base *pt
*	@return void
*/
extern void modulo3(GtkWidget *boton, base *pt){
  
}