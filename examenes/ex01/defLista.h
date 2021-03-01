#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Persona{
	char nombre[80];
	int cp;
	int edad;
	char mes[20];
}Ciudadano;

// Estructura de Lista Genérica (Puede ser FIFO o LIFO)
typedef struct Lista{
	Ciudadano solicitud;
	struct Lista *next;
}Lista;


