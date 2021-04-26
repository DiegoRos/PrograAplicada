#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Persona{
	char nombre[80];
	char direccion[80];
	int telefono;
	char covid; //Booleano 's' o 'n'
}Paciente;

typedef struct ListaCircular{
	Paciente solicitud;
	struct ListaCircular *next;
}ListaCircular;

