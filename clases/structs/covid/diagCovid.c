/*
*	@file: diagCovid.c	
*	@brief: Diagnostica la severidad de un paciente y lo guarda en un archivo txt
*	@author: Clase Guillermo Gomez Abascal
*	@date:29/01/2021
*/

#include "defCovid.h"

int capturar(Paciente p[], int num);
int edadPaciente(Paciente *p);

int main(int argc, char *argv[]){
	Paciente expedientes[1];
	
	capturar(expedientes, 1);
	
	int edad = edadPaciente(&expedientes[1]);	
		

	return 0;
}

