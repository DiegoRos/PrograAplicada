#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

#define True 1
#define False 0

typedef struct Persona{
	int num_cuenta;
	char nombre[40];
	char carrera[80];
	float promedio;
}Alumno;

typedef struct Queue{
	Alumno val;
	struct Queue *next;
}Queue;

typedef struct ListaDoble{
	char carrera[80];
	int num_alumnos;
	float promedio;
	Alumno mejor_alumno;
	struct ListaDoble *next;
	struct ListaDoble *prev;	
	Queue *alumnos;
}ListaDoble;


struct elemento
{
  Alumno alumno;
  struct elemento *izq, *der;
};

typedef struct elemento nodo;

typedef struct Navegador{
	ListaDoble *inicio, *aux_lista;
	nodo *root, *aux_arbol;
}Navegador;

typedef struct LabelNav{
	Navegador *nav;
	GtkWidget *label;
}LabelNav;

typedef struct EntryLabelNav{
	Navegador *nav;
	GtkWidget *label;
	GtkWidget *entry;
}EntryLabelNav;
