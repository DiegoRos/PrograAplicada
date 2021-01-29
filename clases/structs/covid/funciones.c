/*
*	@file:funciones.c	
*	@brief: Contiene las funciones para diagCovid.c
*	@author: Clase de Guillermo Gómez
*	@date: 29/01/2021
*/

#include "defCovid.h"

/*
*	@brief: Función que captura las entradas de uno o varios pacientes
*	@author: Clase Guillermo Gómez Abascal
*	@param Pacientes p: lista de varios pacientes
*	@param int num: Número de pacientes que van a entrar datos
*	@return
*/
int capturar(Paciente p[], int num){
	int i;
	
	for (i = 0; i < num; i++){
		printf("\nCaptura del Paciente %d\n", i + 1);
		printf("Ingresar Nombre y Apellido: ");
		scanf(" %[^\n]", p[i].nombre);
		printf("Ingresar Día Mes Año de Nacimiento: ");
		scanf(" %d %d %d", &p[i].fecha_nacimiento.dia, &p[i].fecha_nacimiento.mes, &p[i].fecha_nacimiento.anio);	
		printf("Ingresar Sexo (M/F): ");
		scanf(" %c", &p[i].sexo);
		printf("Ingresar Peso en Kg: ");
		scanf(" %f", &p[i].peso);
		printf("Ingresar Estatura en Metros: ");
		scanf(" %f", &p[i].estatura);
		printf("Ingresar 1 si tiene el padecimiento o 0 si no\n");
		printf("Obesidad: ");
		scanf(" %d", &p[i].padecimientos[0]);
		printf("Diabetes: ");
		scanf(" %d", &p[i].padecimientos[1]);
		printf("Hipertensión: ");
		scanf(" %d", &p[i].padecimientos[2]);
		
	}

	return True;
}

/*
*	@brief: Función que calcula la edad de un paciente dado su expediente, regresa
*			su edad.
*	@author: Diego Rosenberg
*	@param Paciente *p: Expediente del paciente
*	@return int
*/
int edadPaciente(Paciente *p){
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int edad = (int)tm.tm_year + 1900 - (p -> fecha_nacimiento.anio);

	if (p -> fecha_nacimiento.mes < (tm.tm_mon + 1)){
		edad--;
	}
	
	else if (p -> fecha_nacimiento.mes == (tm.tm_mon + 1)){
		if (p -> fecha_nacimiento.dia < tm.tm_mday){
			edad--;
		}
	}
	
	return edad;
}
