/*
*	@file: main.c	
*	@brief: Programa de C que permita abrir archivo de texto o binario, los cuales contienen una lista de información de pacientes
*			y hace ciertas manipulaciones sobre de los pacientes.
*	@author: Equipo 3
*	@date: 01/03/2021
*/

#include "defP2.h"

ListaCircular * leerTxt(char nombre_file[], ListaCircular *pt); //-> lee un paciente -> acomodaLista() ret -> lista
ListaCircular * leerBinario(char nombre_file[], ListaCircular *pt); //-> lee un paciente -> acomodaLista() ret-> lista
int imprimirPaciente(ListaCircular *pt);
int modificarPaciente(ListaCircular *pt);
int imprimirPacientesCovid(ListaCircular *pt); // Intentar juntar imprimirPacientesCovid e imprimirPacientes
int guardarDatosTxt(ListaCircular *pt);
int guardarDatosBin(ListaCircular *pt);


int main(int argc, char *argv[]){
	if (argc < 2){
		printf("No se recibieron entradas adecuadas\n");
		exit(1);
	}
	
	char opcion;
	ListaCircular *inicio = NULL, *aux;
	if (strcmp(argv[1], "-t") == 0){
		inicio = leerTxt("pacientes.txt", inicio);
	}
	else if(strcmp(argv[1], "-b") == 0){
		inicio = leerBinario("pacientes.bin", inicio);
	}
	else{
		printf("Opción no válida.\n");
		exit(1);
	}
	/*
	aux = inicio;
	if (inicio != NULL){
		do{
			printf("Opciones:\n\tr: Imprimir todos los pacientes\n\tm: Modificar algún paciente\n\tc: Imprimir Pacientes con COVID.\n");
			scanf(" %c", &opcion);

			switch(opcion){
				case 'r':
					imprimirPaciente(aux);	
					aux = aux->next;
					break;

				case 'm':
					modificarPaciente(aux);
					aux = aux->next;
					break;

				case 'c':
					imprimirPacientesCovid(inicio);
					break;

				default:
					printf("\nOpción no válida.\n");
					break;
			}

		}while(opcion != 's');

		guardarDatosTxt(inicio);
		guardarDatosBin(inicio);
	}	
	*/
	return 0;
}

