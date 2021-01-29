#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define True 1
#define False 0

typedef struct{
	int dia;
	int mes;
	int anio;
}Fecha;

typedef struct{
	char nombre[50];
	Fecha fecha_nacimiento;
	char sexo;
	float peso;
	float estatura;
	int padecimientos[3]; //obesidad, diabetes o hipertensión.
	char *zona;
}Paciente;

