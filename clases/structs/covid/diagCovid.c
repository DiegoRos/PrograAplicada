/*
*	@file: diagCovid.c	
*	@brief: Diagnostica la severidad de un paciente y lo guarda en un archivo txt
*	@author: Clase Guillermo Gomez Abascal
*	@date:29/01/2021
*/

#include "defCovid.h"

int capturar(Paciente p[], int num);
int edadPaciente(Paciente *p);
int imprimir(Paciente *p);
int guardarArchTxt(Paciente *p);
int leerArchTxt(Paciente *p);
int lineas(char *file_name);

int main(int argc, char *argv[]){
	char opcion;
	printf("Entrar opción deseada: capturar(c) imprimir existentes (i)\n");
	scanf(" %c", &opcion);
	if (opcion == 'c'){
		Paciente expedientes[MAX];

		capturar(expedientes, MAX);
	
		int edad = edadPaciente(&expedientes[1]);
		
		for(int i = 0; i < MAX; i++){
			imprimir(expedientes + i);
			guardarArchTxt(expedientes + i);
		}
	}
	
	else if (opcion == 'i'){
		int bloque_lineas = 7;
		int num_lineas = lineas("pacientes.txt");
		int num_pacientes = (int) num_lineas / bloque_lineas;
		printf("\nNúmero de Pacientes Existentes: %d\n\n", num_pacientes);
		Paciente *p = (Paciente *)malloc(sizeof(Paciente) * num_pacientes);
		leerArchTxt(p);
		for (int i = 0; i < num_pacientes; i++){
			imprimir(p + i);
		}
	}
	
	else printf("\nOpción no válida. Intentar de Nuevo\n");

	return 0;
}
