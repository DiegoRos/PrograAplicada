#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define True 1
#define False 0

typedef struct Persona{
    char nombre[80];
    char fiebre, tos, moco;
    char ciudad[80];
}Paciente;

typedef struct Queue{
    Paciente val;
    struct Queue *next;
}Queue;

typedef struct ArbolCiudad{
	char ciudad[80];
    int num_covid;
    Queue pacientes_covid;
    Queue paceintes_gripa;
    Queue pacientes_resfriado;
	struct ArbolCiudad *left, *right;
}ArbolCiudad;

typedef struct ListaCiudad{
    int num_covid;
    char ciudad[80];
    struct ListaCiudad *next;
}ListaCiudad;