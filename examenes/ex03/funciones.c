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
void pushLista(GtkWidget *boton, base *pt){
	nodo *aux = (nodo *)malloc(sizeof(nodo));
 	char buffer[50];
  
	strcpy(aux->nombre, gtk_entry_get_text(GTK_ENTRY(pt->datoNom)));
 	sscanf(gtk_entry_get_text(GTK_ENTRY(pt->datoAge)), "%i", &aux->edad);

	printf("Push: %s %i\n", aux->nombre, aux->edad);

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
void popLista(GtkWidget *boton, base *pt){
  char buffer[50];
	nodo *aux = pt->ref;
	if (pt->ref != NULL){
    	++(pt->cantidad_pop);
		printf("Pop: %s %i\n", pt->ref->nombre, pt->ref->edad);
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
	gtk_button_ser_label(GTK_BITTON(boton), "Abdiel Cuevas");

	nodo *aux; 
	int contadorMayuscula = 0;
	int contadorEdad = 0;
	char buffer[50];
  
	aux = pt->ref; 
	


	if(aux == NULL){
		gtk_label_set_text(GTK_LABEL(pt->label3),"No hay nada");
  	}
	else{
		while(aux != NULL){
			if(isupper(aux->nombre[0]) == 1){
				contadorMayuscula++;
			}

			if(aux->edad > 20){
				contadorEdad++;
			}

	
			aux -> next;
	}

	sprintf(buffer, "Con Mayusculas: %i, Mayores de 20: %i", contadorMayuscula, contadorEdad);
	gtk_label_set_text(GTK_LABEL(pt->label3),buffer);
 }
 return;
}

/*
*	@brief: Esta función revisa si un caracter es una vocal minúscula
*	@author: Equipo 3
*	@param char c
*	@return int
*/
int isLowerVowel(char c){
	if ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'))
		return True;

	return False; 
}

/*
*	@brief: Esta función
*	@author: Equipo 3
*	@param GtkWidget *boton
*	@param base *pt
*	@return void
*/
extern void modulo2(GtkWidget *boton, base *pt){ 
	nodo *aux = pt->ref;
	char buffer[50];
	int num_modificadas = 0;
	
	gtk_button_set_label(GTK_BUTTON(boton), "Diego Rosenberg");
	
	while(aux != NULL){
		for(int i = 0; i < strlen(aux->nombre); ++i){
			if(isLowerVowel(aux->nombre[i])){
				aux->nombre[i] = toupper(aux->nombre[i]);
				++num_modificadas;
			}
		}
		printf("Nodo Cambiado: %s %i\n", aux->nombre, aux->edad);
		aux = aux->next;
	}
	
    sprintf(buffer, "Total de vocales modificadas: %i", num_modificadas);
    gtk_label_set_text(GTK_LABEL(pt->label3), buffer);
}

Arbol * insertar(Arbol *pt, nodo *s){
	
	if (pt == NULL){
		Arbol *nuevo = (Arbol *)malloc(sizeof(Arbol));
	
		strcpy(nuevo->nombre, s->edad);
		nuevo->edad = s->edad
		nuevo->left = NULL;
		nuevo->right = NULL;
		return nuevo;
	}

	if (pt->edad < s->edad){
		pt->right = insertar(pt->right, s);
	}
	else{
		pt->left = insertar(pt->left, s);	
	}

	return pt;
}

void recorrer(Arbol *pt){
	if(pt == NULL) return;

	recorrer(pt->left);
	printf("Nombre: %s Edad %i\n", pt->nombre, pt->edad);
	recorrer(pt->right);
}

/*
*	@brief: Esta función
*	@author: Equipo 3
*	@param GtkWidget *boton
*	@param base *pt
*	@return void
*/
extern void modulo3(GtkWidget *boton, base *pt){
	Arbol *root = NULL;
	nodo *aux = pt->ref;
	gtk_button_set_label(GTK_BUTTON(boton), "Santiago Cuesta");

	//Loop sobre la lista

	// Funcion recorrer
  
}
