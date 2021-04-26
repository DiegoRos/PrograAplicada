#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define True 1
#define False 0

typedef struct Persona{
	int num_cuenta;
	char nombre[40];
	char carrera[80];
	float promedio;
}Alumno;

// Alumnos deben de ir ordenados por calificación (mayor a menor)
typedef struct Queue{
	Alumno val;
	struct Queue *next;
}Queue;

// Debe de ser una lista doble en que se insertan nodos como FIFO (stack) y carreras deben de ir en orden alfaético.
typedef struct ListaDoble{
	char carrera[80];
	int num_alumnos;
	float promedio;
	Alumno mejor_alumno;
	struct ListaDoble *next;
	struct ListaDoble *prev;	
	Queue *alumnos;
}ListaDoble;
